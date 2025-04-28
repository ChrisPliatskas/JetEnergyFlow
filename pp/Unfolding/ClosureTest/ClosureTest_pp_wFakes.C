void SetStyle(TH1* h1);
TH2D* RM_normalization(TH2D* input_RM);
void ClosureTest_pp_wFakes(TString TestfileName = "AnalysisResults.root", TString ResponsefileName = "ResponseMatrix_ppMC_ptmin0.root", Double_t Rjet = 0.1, Int_t Ptlow =0, Int_t Pthigh = 100, Int_t Niter = 1, Int_t BinWidth=1){

//Open the Response file to retrieve the response matrix and the binning configuration for the distributions at truth and detector level

TFile*ResponseFile = TFile::Open(ResponsefileName.Data());

TH2D* h2Dpt_Rebined_Meas = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_Meas_R%03d",int(Rjet*100))));

TH2D* h2Dpt_Rebined_True = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_True_R%03d",int(Rjet*100))));

Int_t nPtBins = h2Dpt_Rebined_Meas->GetNbinsX();
Double_t ptmin = h2Dpt_Rebined_Meas->GetXaxis()->GetXmin();
Double_t ptmax = h2Dpt_Rebined_Meas->GetXaxis()->GetXmax();

Int_t nDptBins = h2Dpt_Rebined_Meas->GetNbinsY();
Double_t Dptmin = h2Dpt_Rebined_Meas->GetYaxis()->GetXmin();
Double_t Dptmax = h2Dpt_Rebined_Meas->GetYaxis()->GetXmax();

 Int_t nPtBins_gen = h2Dpt_Rebined_True->GetNbinsX();
 Double_t ptmin_gen = h2Dpt_Rebined_True->GetXaxis()->GetXmin();
 Double_t ptmax_gen = h2Dpt_Rebined_True->GetXaxis()->GetXmax();

 Int_t nDptBins_gen = h2Dpt_Rebined_True->GetNbinsY();
 Double_t Dptmin_gen = h2Dpt_Rebined_True->GetYaxis()->GetXmin();
 Double_t Dptmax_gen = h2Dpt_Rebined_True->GetYaxis()->GetXmax();


Int_t Ptwidth = int(h2Dpt_Rebined_Meas->GetXaxis()->GetBinWidth(1));
Int_t Dptwidth = int(h2Dpt_Rebined_Meas->GetYaxis()->GetBinWidth(1));

Double_t Dptlow = Dptmin;
Double_t Dpthigh = Dptmax;

Double_t Dptlow_gen = Dptmin_gen;
Double_t Dpthigh_gen = Dptmax_gen;

//Visualization of the response matrix (This section is not vital for the closure test)
THnSparse* ResponseMatrix = static_cast<THnSparse*>(ResponseFile->Get(Form("ResponseMatrix_R%03d_0",int(Rjet*100))));
ResponseMatrix ->UseCurrentStyle();
Int_t Ptlow_bin_gen =ResponseMatrix->GetAxis(0)->FindBin(Ptlow);
Int_t Pthigh_bin_gen =ResponseMatrix->GetAxis(0)->FindBin(Pthigh+10)-1;
ResponseMatrix->GetAxis(0)->SetRange(Ptlow_bin_gen,Pthigh_bin_gen);
Int_t Ptlow_bin =ResponseMatrix->GetAxis(0)->FindBin(Ptlow);
Int_t Pthigh_bin =ResponseMatrix->GetAxis(0)->FindBin(Pthigh)-1;
ResponseMatrix->GetAxis(1)->SetRange(Ptlow_bin,Pthigh_bin);
TH2D *Pt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(0,1,"E"));
Pt_RM->SetName(Form("Pt_ResponseMatrix_R%03d_0",int(Rjet*100)));
Pt_RM->SetTitle(Form("Response Matrix for P_{t} of R_{jet}=%.2f;P_{t} (Detector level);P_{t}(Generator level)",Rjet));
RM_normalization(Pt_RM);
Pt_RM->SetMaximum(1);
Pt_RM->SetMinimum(1e-5);

Int_t Dptlow_bin_gen = ResponseMatrix->GetAxis(2)->FindBin(Dptlow_gen);
Int_t Dpthigh_bin_gen = ResponseMatrix->GetAxis(2)->FindBin(Dpthigh_gen)-1;
ResponseMatrix->GetAxis(2)->SetRange(Dptlow_bin_gen,Dpthigh_bin_gen);
Int_t Dptlow_bin = ResponseMatrix->GetAxis(2)->FindBin(Dptlow);
Int_t Dpthigh_bin = ResponseMatrix->GetAxis(2)->FindBin(Dpthigh)-1;
ResponseMatrix->GetAxis(3)->SetRange(Dptlow_bin,Dpthigh_bin);
TH2D *DPt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(2,3,"E"));
DPt_RM->SetName(Form("DPt_ResponseMatrix_R%03d_0",int(Rjet*100)));
DPt_RM->SetTitle(Form("Response Matrix for #DeltaP_{t} of R_{jet}=%.2f- P_{t} bin [%d,%d];#DeltaP_{t} (Detector level);#DeltaP_{t}(Generator level)",Rjet,Ptlow,Pthigh));
RM_normalization(DPt_RM);
DPt_RM->SetMaximum(1);
DPt_RM->SetMinimum(1e-5);

//Introducing the test or pseudodata distributions (If the closure is trivial then the input here is the same as it was used in the UnfoldPreparation macro
        //Creating the histograms needed for the closure test
       //Detector level distribution within range for both true & detector level (Response->Fill)
TH2D *h2Det_meas = new TH2D(Form("h2Det_meas_R%03d",int(Rjet*100)),Form("h2Reconstructed (measured)  R =%.2f",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);
      //Truth level distribution within range for both true & detector level (Response->Fill) 
TH2D *h2True_meas = new TH2D(Form("h2True_meas_R%03d",int(Rjet*100)),Form("h2True (measured) R =%.2f",Rjet),nPtBins_gen,ptmin_gen,ptmax_gen,nDptBins_gen,Dptmin_gen,Dptmax_gen);
      //Detector level distribution within detector but outside true range (Response->Fake)
TH2D *hFake = new TH2D(Form("hFake_R%03d",int(Rjet*100)),Form("hFake_R =%.2f",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);
      //Truth level distribution within true but outside detector range (Response->Miss)
        TH2D *h2True_miss = new TH2D(Form("h2True_miss_R%03d",int(Rjet*100)),Form("h2True (Missed) R =%.2f",Rjet),nPtBins_gen,ptmin_gen,ptmax_gen,nDptBins_gen,Dptmin_gen,Dptmax_gen);
      //Truth level distribution within true but outside detector range (Response->Miss) [EMPTY]
        TH2D *h2Det_miss = new TH2D(Form("h2Det_miss_R%03d",int(Rjet*100)),Form("h2Reconstructed (missed) R =%.2f",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);

//Open the test/pseudodata file to retrieve the ResponseMatrix, its projections and to fill the above histograms
TFile*Testfile = TFile::Open(TestfileName.Data());
AliEmcalList* ali_test;
Testfile->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_ppMC_GenDet_histos",ali_test);
THnSparseD* RM_thn_test = static_cast<THnSparseD*>(ali_test->FindObject(Form("ResponseMatrix_R%03d_0",int(Rjet*100))));
const Int_t nDim =4;

  Int_t iPt_gen   = 0;
  Int_t iPt_det  = 1;
  Int_t iDpt_gen  = 2;
  Int_t iDpt_det = 3;

        //Response matrix projections from the test file before rebinning
TH2D*hDpt_test_truth = dynamic_cast<TH2D*>(RM_thn_test->Projection(iDpt_gen,iPt_gen,"E"));
  hDpt_test_truth->SetName(Form("DeltaPt_Pt_gen_R%03d",int(Rjet*100)));
TH2D *hDpt_test = dynamic_cast<TH2D*>(RM_thn_test->Projection(iDpt_det,iPt_det,"E"));
  hDpt_test->SetName(Form("DeltaPt_Pt_det_R%03d",int(Rjet*100)));

        //Rebinning the detector level distribution from the test file
TH2D *Dpt_Rebinned_test = new TH2D(Form("Dpt_Rebinned_testR%03d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (Test -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);


          for(Int_t ix=1;ix<=Dpt_Rebinned_test->GetNbinsX();ix++){
          Double_t xlow = Dpt_Rebinned_test->GetXaxis()->GetBinLowEdge(ix);
          Double_t xup = Dpt_Rebinned_test->GetXaxis()->GetBinUpEdge(ix);
          Int_t jxlow = hDpt_test->GetXaxis()->FindBin(xlow+0.000001);
          Int_t jxup = hDpt_test->GetXaxis()->FindBin(xup-0.000001);
          for(Int_t iy = 1; iy<=Dpt_Rebinned_test->GetNbinsY(); iy++) {
            Double_t ylow = Dpt_Rebinned_test->GetYaxis()->GetBinLowEdge(iy);
            Double_t yup =Dpt_Rebinned_test->GetYaxis()->GetBinUpEdge(iy);
            Int_t jylow = hDpt_test->GetYaxis()->FindBin(ylow+0.000001);
            Int_t jyup = hDpt_test->GetYaxis()->FindBin(yup-0.000001);

            Double_t err = 0.;
            Double_t con = hDpt_test->IntegralAndError(jxlow,jxup,jylow,jyup,err);
            Dpt_Rebinned_test->SetBinContent(ix,iy,con);
            Dpt_Rebinned_test->SetBinError(ix,iy,err);
             } //End of ybin loop
             } //End of xbin loop

        //Rebinning the truth level distribution from the test file
TH2D *Dpt_Rebinned_test_truth = new TH2D(Form("Dpt_Rebinned_test_truthR%03d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (Test-Truth -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nPtBins_gen,ptmin_gen,ptmax_gen,nDptBins_gen,Dptmin_gen,Dptmax_gen);

        for(Int_t ix=1;ix<=Dpt_Rebinned_test_truth->GetNbinsX();ix++){
        Double_t xlow = Dpt_Rebinned_test_truth->GetXaxis()->GetBinLowEdge(ix);
        Double_t xup = Dpt_Rebinned_test_truth->GetXaxis()->GetBinUpEdge(ix);
        Int_t jxlow = hDpt_test_truth->GetXaxis()->FindBin(xlow+0.000001);
        Int_t jxup = hDpt_test_truth->GetXaxis()->FindBin(xup-0.000001);
        for(Int_t iy = 1; iy<=Dpt_Rebinned_test_truth->GetNbinsY(); iy++) {
          Double_t ylow = Dpt_Rebinned_test_truth->GetYaxis()->GetBinLowEdge(iy);
          Double_t yup =Dpt_Rebinned_test_truth->GetYaxis()->GetBinUpEdge(iy);
          Int_t jylow = hDpt_test_truth->GetYaxis()->FindBin(ylow+0.000001);
          Int_t jyup = hDpt_test_truth->GetYaxis()->FindBin(yup-0.000001);

          Double_t err = 0.;
          Double_t con = hDpt_test_truth->IntegralAndError(jxlow,jxup,jylow,jyup,err);
          Dpt_Rebinned_test_truth->SetBinContent(ix,iy,con);
          Dpt_Rebinned_test_truth->SetBinError(ix,iy,err);
           } //End of ybin loop
           } //End of xbin loop

        //Fill the measured, missed and Fake distribution at each level
    Int_t* coord = new Int_t[nDim]; //Carries the bin coordinates
    Int_t nbin = RM_thn_test->GetNbins();
    Bool_t TruthFlag = kFALSE; Bool_t DetectorFlag = kFALSE; 

    for(Int_t bin=0; bin<nbin; bin++) {
      Double_t w = RM_thn_test->GetBinContent(bin,coord);
      TruthFlag = kFALSE; DetectorFlag = kFALSE;
      Double_t Dpt_meas = RM_thn_test->GetAxis(3)->GetBinCenter(coord[3]);
      Double_t Dpt_true = RM_thn_test->GetAxis(2)->GetBinCenter(coord[2]);
      Double_t pt_meas = RM_thn_test->GetAxis(1)->GetBinCenter(coord[1]);
      Double_t pt_true = RM_thn_test->GetAxis(0)->GetBinCenter(coord[0]);
    if((Dpt_meas>=Dptmin && Dpt_meas<Dptmax) && (pt_meas>=ptmin && pt_meas<ptmax))DetectorFlag=kTRUE;
    if((Dpt_true>=Dptmin_gen && Dpt_true<Dptmax_gen) && (pt_true>=ptmin_gen && pt_true<ptmax_gen))TruthFlag = kTRUE;
        if(TruthFlag && DetectorFlag){
        h2Det_meas->Fill(pt_meas,Dpt_meas,w);
        h2True_meas->Fill(pt_true,Dpt_true,w);}
        else if(TruthFlag && (!DetectorFlag)){
        h2True_miss->Fill(pt_true,Dpt_true,w);
        h2Det_miss->Fill(pt_meas,Dpt_meas,w);}
        else if (DetectorFlag && (!TruthFlag)){
         hFake->Fill(pt_meas,Dpt_meas,w);}            
                                       }
delete [] coord;

        // Complete truth distribution
        TH2D* h2True = (TH2D*) h2True_meas->Clone();
        h2True->Add(h2True_miss,1);
        h2True->SetName(Form("h2True_R%03d",int(Rjet*100)));
        //Complete measured distribution
        TH2D* h2Det = (TH2D*) h2Det_meas->Clone();
        h2Det->Add(hFake,1);
        h2Det->SetName(Form("h2Det_R%03d",int(Rjet*100)));

//This is the section where the actual unfolding starts and RooUnfold is involved
        //Load the response object from the Response file
RooUnfoldResponse* resp = static_cast<RooUnfoldResponse*>(ResponseFile->Get(Form("Response_R%03d",int(Rjet*100))));
TString Unfoldname =Form("Bayesian_Unfolding_R%d_ptmin%d",int(Rjet*100),int(ptmin));
        //Create the Bayesian unfolding object
RooUnfoldBayes Unfolding_bayes(resp,Dpt_Rebinned_test,Niter,0,Unfoldname,Unfoldname);
        //Extracting the unfolded distribution as a histogram
TH2D* Unfolded_Dpt_test = (TH2D*)Unfolding_bayes.Hreco(RooUnfold::kCovToy);
Unfolded_Dpt_test->SetName(Form("Unfolded_Dpt_test_R%03d",int(Rjet*100)));
auto Unf_Bayes = &Unfolding_bayes;
        //Applying the Response matrix to the unfolded result
        TH2D* Refolded_Dpt_test = (TH2D*) resp->ApplyToTruth(Unfolded_Dpt_test,Form("Refolded_Dpt_test_R%03d",int(Rjet*100)));
        //Include the fakes in order to compare with the input distribution
        Refolded_Dpt_test->Add(hFake);

// The unfolding is complete, the following sections refer to projections in one dimension and calculating the ratio between distributions
 
        //Projection bins
Int_t Pro_bin_ptlow =h2Dpt_Rebined_Meas->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh =h2Dpt_Rebined_Meas->GetXaxis()->FindBin(Pthigh)-1;

Int_t Pro_bin_ptlow_gen =h2Dpt_Rebined_True->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh_gen =h2Dpt_Rebined_True->GetXaxis()->FindBin(Pthigh)-1;

        //Projections
        //--------------Training sample (Sample creating the response)--------------------//
        //Truth level
        TH1D*pro_mc_gen = h2Dpt_Rebined_True->ProjectionY(Form("pro_mc_gen_R%03d",int(Rjet*100)),Pro_bin_ptlow_gen, Pro_bin_pthigh_gen);
        pro_mc_gen->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC Generator level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_mc_gen->Scale(1/pro_mc_gen->Integral("width"));

        //Detector level
        TH1D*pro_mc_det = h2Dpt_Rebined_Meas->ProjectionY(Form("pro_mc_det_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_mc_det->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC DEtector level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_mc_det->Scale(1/pro_mc_det->Integral("width"));
        //--------------Test sample (MC sample treated as pseudodata)--------------------//
        //Truth level
        TH1D*pro_test_truth = Dpt_Rebinned_test_truth->ProjectionY(Form("pro_test_truth_R%03d",int(Rjet*100)),Pro_bin_ptlow_gen, Pro_bin_pthigh_gen);
        pro_test_truth->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (ALICE test truth);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_test_truth->Scale(1/pro_test_truth->Integral("width"));        
        //Detector level
        TH1D*pro_test =Dpt_Rebinned_test->ProjectionY(Form("pro_test_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_test->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (ALICE test);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_test->Scale(1/pro_test->Integral("width"));        
        //Unfolded
        TH1D*pro_unfolded_test = Unfolded_Dpt_test->ProjectionY(Form("pro_unfolded_test_R%03d",int(Rjet*100)),Pro_bin_ptlow_gen, Pro_bin_pthigh_gen);
        pro_unfolded_test->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Unfolded ALICE test);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_unfolded_test->Scale(1/pro_unfolded_test->Integral("width"));        
        //Refolded
        TH1D*pro_refolded_test = Refolded_Dpt_test->ProjectionY(Form("pro_refolded_test_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_refolded_test->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE test);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
        pro_refolded_test->Scale(1/pro_refolded_test->Integral("width"));

        //Ratios of the projections
        //Training distributions- Detector response corrections
        TH1D*Ratio_MCgenoverdet =(TH1D*)pro_mc_gen->Clone();
        Ratio_MCgenoverdet->Reset();
        for (int i_bin=0;i_bin<pro_mc_det->GetNbinsX();i_bin++){
                Ratio_MCgenoverdet->SetBinContent(i_bin,pro_mc_det->GetBinContent(i_bin));
                Ratio_MCgenoverdet->SetBinError(i_bin,pro_mc_det->GetBinError(i_bin));}
        Ratio_MCgenoverdet->Divide(pro_mc_gen,Ratio_MCgenoverdet);
        Ratio_MCgenoverdet->SetTitle(Form("Ratio of Truth over Detector level #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c- Training;#DeltaP_{t} (GeV/c);#frac{Truth}{Detector}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
        Ratio_MCgenoverdet->SetName(Form("Ratio_GenDet_R%03d",int(Rjet*100)));

        //Test distributions- Detector response corrections
          TH1D*Ratio_Unfovertest =(TH1D*)pro_unfolded_test->Clone();
          Ratio_Unfovertest->Reset();
          for (int i_bin=0;i_bin<pro_test->GetNbinsX();i_bin++){
                  Ratio_Unfovertest->SetBinContent(i_bin,pro_test->GetBinContent(i_bin));
                  Ratio_Unfovertest->SetBinError(i_bin,pro_test->GetBinError(i_bin));}
          Ratio_Unfovertest->Divide(pro_unfolded_test,Ratio_Unfovertest);
          Ratio_Unfovertest->SetTitle(Form("Ratio of unfolded over test #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Unfolded test}{test}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
          Ratio_Unfovertest->SetName(Form("Ratio_Unftest_R%03d",int(Rjet*100)));
        //Closure on the truth level
          TH1D*Ratio_Unfovertest_truth =(TH1D*)pro_unfolded_test->Clone();
          Ratio_Unfovertest_truth->Reset();
          Ratio_Unfovertest_truth->Divide(pro_unfolded_test,pro_test_truth);
          Ratio_Unfovertest_truth->SetTitle(Form("Ratio of unfolded test over test truth #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Unfolded test}{Truth test}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
          Ratio_Unfovertest_truth->SetName(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100)));
        //Closure on the detector level
         TH1D*Ratio_Refovertest =(TH1D*)pro_refolded_test->Clone();
          Ratio_Refovertest->Reset();
          Ratio_Refovertest->Divide(pro_refolded_test,pro_test);
          Ratio_Refovertest->SetTitle(Form("Ratio of Refolded over test #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Refolded test}{test}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
          Ratio_Refovertest->SetName(Form("Ratio_Reftest_R%03d",int(Rjet*100)));

        //Saving the output in a new file
        TString Outputname = Form("ClosureTest_pp_wFakes_2018_Binw%d_LC8_pt_%d_%d_ptmin%d_Dptmin%d_max%d_Iter%d.root",BinWidth,Ptlow,Pthigh,int(ptmin),int(Dptmin),int(Dptmax),Niter);
        TFile *fout = new TFile(Outputname.Data(),"UPDATE");
        Pt_RM->Write(Pt_RM->GetName(),TObject::kOverwrite);
        DPt_RM->Write(DPt_RM->GetName(),TObject::kOverwrite);
        ResponseMatrix->Write(ResponseMatrix->GetName(),TObject::kOverwrite);
        h2True_meas->Write(h2True_meas->GetName(),TObject::kOverwrite);
        h2Det_meas->Write(h2Det_meas->GetName(),TObject::kOverwrite);
        h2Det->Write(h2Det->GetName(),TObject::kOverwrite);
        h2True->Write(h2True->GetName(),TObject::kOverwrite);
        h2True_miss->Write(h2True_miss->GetName(),TObject::kOverwrite);
        h2Det_miss->Write(h2Det_miss->GetName(),TObject::kOverwrite);
        hFake->Write(hFake->GetName(),TObject::kOverwrite);
        Unfolded_Dpt_test->Write(Unfolded_Dpt_test->GetName(),TObject::kOverwrite);
        Refolded_Dpt_test->Write(Refolded_Dpt_test->GetName(),TObject::kOverwrite);
        Dpt_Rebinned_test_truth->Write(Dpt_Rebinned_test_truth->GetName(),TObject::kOverwrite);
        Dpt_Rebinned_test->Write(Dpt_Rebinned_test->GetName(),TObject::kOverwrite);
        Unf_Bayes->Write(Unf_Bayes->GetName(),TObject::kOverwrite);
        pro_test->Write(pro_test->GetName(),TObject::kOverwrite);
        pro_test_truth->Write(pro_test_truth->GetName(),TObject::kOverwrite);
        pro_mc_det->Write(pro_mc_det->GetName(),TObject::kOverwrite);
        pro_mc_gen->Write(pro_mc_gen->GetName(),TObject::kOverwrite);
        pro_unfolded_test->Write(pro_unfolded_test->GetName(),TObject::kOverwrite);
        pro_refolded_test->Write(pro_refolded_test->GetName(),TObject::kOverwrite);
        Ratio_MCgenoverdet->Write(Ratio_MCgenoverdet->GetName(),TObject::kOverwrite);
        Ratio_Unfovertest->Write(Ratio_Unfovertest->GetName(),TObject::kOverwrite);
        Ratio_Unfovertest_truth->Write(Ratio_Unfovertest_truth->GetName(),TObject::kOverwrite);
        Ratio_Refovertest->Write(Ratio_Refovertest->GetName(),TObject::kOverwrite);
        Testfile->Close();
        ResponseFile->Close();
        fout->Close();     
}

void SetStyle(TH1* h1){
        gStyle->SetOptStat(0); gStyle->SetTextFont(42); gStyle->SetTitleFont(42);
        gStyle->SetOptTitle(1); gStyle->SetPadTickX(1); gStyle->SetPadTickY(1);
        gStyle->SetTextSize(18);gStyle->SetLabelOffset(.001); gStyle->SetTitleSize(0.05,"Y");
        gStyle->SetTitleSize(0.05,"X"); gStyle->SetTitleSize(0.05); 
        gStyle->SetLegendTextSize(0.025); gStyle->SetTitleXOffset(.7); 
        gStyle->SetTitleYOffset(.7); gStyle->SetTitleOffset(.7); 
        h1->SetMarkerStyle(33); h1->SetMarkerSize(2); h1->SetLineWidth(2);
        }

TH2D* RM_normalization(TH2D* input_RM){
          Int_t nBinsDpt[2]= {input_RM->GetXaxis()->GetNbins(),input_RM->GetYaxis()->GetNbins()};
          TH2D* RM_norm =(TH2D*)input_RM->Clone();
          RM_norm->Reset();
          for(int iy=1;iy<=nBinsDpt[1];iy++){
                  Double_t sum = input_RM->Integral(1,nBinsDpt[0],iy,iy);
                  for(int ix=1;ix<=nBinsDpt[0];ix++){
                          Double_t con = input_RM->GetBinContent(ix,iy);
                          RM_norm->SetBinContent(ix,iy,con/sum);
                                } }
            return RM_norm;             }
