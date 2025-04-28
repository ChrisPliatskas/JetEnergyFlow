void SetStyle(TH1* h1);
TH2D* RM_normalization(TH2D* input_RM);

void Unfolding_macro_PbPb_updated_wFakes(TString DatafileName = "AnalysisResults.root",TString ResponsefileName = "ResponseMatrix_ppMC_ptmin0.root",Double_t Rjet = 0.1, Int_t Ptlow =0 , Int_t Pthigh = 100, Int_t BinWidth=3, Int_t Niter = 1){

//Response Matrix visualisation
TFile*ResponseFile = TFile::Open(ResponsefileName.Data());

TH2D* h2Dpt_Rebined_Meas = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_Meas_R%03d",int(Rjet*100))));

TH2D* h2Dpt_Rebined_True = static_cast<TH2D*>(ResponseFile->Get(Form("h2Dpt_Rebined_True_R%03d",int(Rjet*100))));

TH2D* hFakes = static_cast<TH2D*>(ResponseFile->Get(Form("hFake_R%03d",int(Rjet*100))));

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


Double_t Dptlow = Dptmin;
Double_t Dpthigh = Dptmax;

 
Double_t Dptlow_gen = Dptmin_gen;
Double_t Dpthigh_gen = Dptmax_gen;

Int_t Dptwidth = int(h2Dpt_Rebined_Meas->GetYaxis()->GetBinWidth(1));

          //Plotting the RM
          //Set drawing style
            gStyle->SetOptStat(0);
            gStyle->SetTextFont(42);
            gStyle->SetTitleFont(42);
            gStyle->SetTextSize(18);
            gStyle->SetOptTitle(1);
            gStyle->SetPadTickX(1);
            gStyle->SetPadTickY(1);
          gStyle->SetLabelOffset(.001);
          gStyle->SetTitleSize(0.05,"Y");
          gStyle->SetTitleSize(0.05,"X");
          gStyle->SetTitleSize(0.05);
          gStyle->SetTextSize(16);
          gStyle->SetHistLineWidth(2);
          gStyle->SetLegendTextSize(0.025);
          gStyle->SetTitleXOffset(.7);
          gStyle->SetTitleYOffset(.7);
          gStyle->SetTitleOffset(.7);


THnSparse* ResponseMatrix = static_cast<THnSparse*>(ResponseFile->Get(Form("ResponseMatrix_R%03d_0",int(Rjet*100))));
ResponseMatrix ->UseCurrentStyle();

Int_t Ptlow_bin_gen =ResponseMatrix->GetAxis(0)->FindBin(Ptlow);
Int_t Pthigh_bin_gen =ResponseMatrix->GetAxis(0)->FindBin(Pthigh+10)-1;
ResponseMatrix->GetAxis(0)->SetRange(Ptlow_bin_gen,Pthigh_bin_gen);
Int_t Ptlow_bin =ResponseMatrix->GetAxis(1)->FindBin(Ptlow);
Int_t Pthigh_bin =ResponseMatrix->GetAxis(1)->FindBin(Pthigh)-1;
ResponseMatrix->GetAxis(1)->SetRange(Ptlow_bin,Pthigh_bin);
TH2D *Pt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(0,1,"E"));
//Pt_RM->SetMinimum(1e-8);Pt_RM->SetMaximum(1e3);
Pt_RM->SetName(Form("Pt_ResponseMatrix_R%03d_0",int(Rjet*100)));
Pt_RM->SetTitle(Form("Response Matrix for P_{t} of R_{jet}=%.2f;P_{t} (Detector level);P_{t}(Generator level)",Rjet));
Pt_RM = RM_normalization(Pt_RM);

Int_t Dptlow_bin_gen = ResponseMatrix->GetAxis(2)->FindBin(Dptlow_gen);
Int_t Dpthigh_bin_gen = ResponseMatrix->GetAxis(2)->FindBin(Dpthigh_gen)-1;
ResponseMatrix->GetAxis(2)->SetRange(Dptlow_bin_gen,Dpthigh_bin_gen);
Int_t Dptlow_bin = ResponseMatrix->GetAxis(3)->FindBin(Dptlow);
Int_t Dpthigh_bin = ResponseMatrix->GetAxis(3)->FindBin(Dpthigh)-1;
ResponseMatrix->GetAxis(3)->SetRange(Dptlow_bin,Dpthigh_bin);
TH2D *DPt_RM = dynamic_cast<TH2D*>(ResponseMatrix->Projection(2,3,"E"));
//DPt_RM->SetMinimum(1e-8);DPt_RM->SetMaximum(1e3);
DPt_RM->SetName(Form("DPt_ResponseMatrix_R%03d_0",int(Rjet*100)));
DPt_RM->SetTitle(Form("Response Matrix for #DeltaP_{t} of R_{jet}=%.2f- P_{t} bin [%d,%d];#DeltaP_{t} (Detector level);#DeltaP_{t}(Generator level)",Rjet,Ptlow,Pthigh));
DPt_RM = RM_normalization(DPt_RM);

//Load & Rebin data distribution
TFile*Datafile = TFile::Open(DatafileName.Data());
AliEmcalList* ali;
Datafile->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_PbPbdata_PbPbdataSmallR_ConstSub_histos",ali);

TH2D*hDpt_data = static_cast<TH2D*>(ali->FindObject(Form("hJetPtDeltaPt_R%03d_0",int(Rjet*100))));

TH2D *Dpt_Rebinned_Data = new TH2D(Form("Dpt_Rebinned_DataR%03d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (ALICE data -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);

        for(Int_t ix=1;ix<=Dpt_Rebinned_Data->GetNbinsX();ix++){
        Double_t xlow = Dpt_Rebinned_Data->GetXaxis()->GetBinLowEdge(ix);
        Double_t xup = Dpt_Rebinned_Data->GetXaxis()->GetBinUpEdge(ix);
        Int_t jxlow = hDpt_data->GetXaxis()->FindBin(xlow+0.000001);
        Int_t jxup = hDpt_data->GetXaxis()->FindBin(xup-0.000001);
        for(Int_t iy = 1; iy<=Dpt_Rebinned_Data->GetNbinsY(); iy++) {
          Double_t ylow = Dpt_Rebinned_Data->GetYaxis()->GetBinLowEdge(iy);
          Double_t yup =Dpt_Rebinned_Data->GetYaxis()->GetBinUpEdge(iy);
          Int_t jylow = hDpt_data->GetYaxis()->FindBin(ylow+0.000001);
          Int_t jyup = hDpt_data->GetYaxis()->FindBin(yup-0.000001);
    
          Double_t err = 0.; 
          Double_t con = hDpt_data->IntegralAndError(jxlow,jxup,jylow,jyup,err);
          Dpt_Rebinned_Data->SetBinContent(ix,iy,con);
          Dpt_Rebinned_Data->SetBinError(ix,iy,err);
           } //End of ybin loop
           } //End of xbin loop

//Estimation of fakes
TH2D* Fake_Data = (TH2D*) Dpt_Rebinned_Data->Clone(Form("Fake_DataR%03d",int(Rjet*100)));
Fake_Data->Reset();
TH2D* FakeRatio = (TH2D*) h2Dpt_Rebined_Meas->Clone(Form("FakeRatio_R%03d",int(Rjet*100)));
FakeRatio->Reset();
FakeRatio->Divide(hFakes,h2Dpt_Rebined_Meas);

for(Int_t ix=1;ix<=Dpt_Rebinned_Data->GetNbinsX();ix++){
for(Int_t iy = 1; iy<=Dpt_Rebinned_Data->GetNbinsY(); iy++){
Double_t mod = FakeRatio->GetBinContent(ix,iy);
Double_t cont = Dpt_Rebinned_Data->GetBinContent(ix,iy);
Fake_Data->SetBinContent(ix,iy,mod*cont); 
	}//End of ybin loop
	}//End of xbin loop


//Unfold rebinned data distro
RooUnfoldResponse* resp = static_cast<RooUnfoldResponse*>(ResponseFile->Get(Form("Response_R%03d",int(Rjet*100))));
TString Unfoldname =Form("Bayesian_Unfolding_R%d_ptmin%d",int(Rjet*100),int(ptmin));
RooUnfoldBayes Unfolding_bayes(resp,Dpt_Rebinned_Data,Niter,0,Unfoldname,Unfoldname);
TH2D* Unfolded_Dpt_data = (TH2D*)Unfolding_bayes.Hreco(RooUnfold::kCovToy);
Unfolded_Dpt_data->SetName(Form("Unfolded_Dpt_data_R%03d",int(Rjet*100)));
auto Unf_Bayes = &Unfolding_bayes;
//Refold Unfolded data distro
TH2D* Refolded_Dpt_data = (TH2D*) resp->ApplyToTruth(Unfolded_Dpt_data,Form("Refolded_Dpt_data_R%03d",int(Rjet*100)));

TH2D* Refolded_Dpt_data_wFake = (TH2D*) Refolded_Dpt_data->Clone(Form("Refolded_Dpt_data_wFake_R%03d",int(Rjet*100)));
Refolded_Dpt_data_wFake->Add(Fake_Data);

Int_t Pro_bin_ptlow =Dpt_Rebinned_Data->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh =Dpt_Rebinned_Data->GetXaxis()->FindBin(Pthigh)-1;

Int_t Pro_bin_ptlow_gen =Unfolded_Dpt_data->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh_gen =Unfolded_Dpt_data->GetXaxis()->FindBin(Pthigh)-1;

//Projections

        //Initial data distro
        TH1D*pro_data = Dpt_Rebinned_Data->ProjectionY(Form("pro_data_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
    //    pro_data->Scale(1/pro_data->Integral("width"));

        //Det level MC
        TH1D*pro_mc_det = h2Dpt_Rebined_Meas->ProjectionY(Form("pro_mc_det_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_mc_det->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC DEtector level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
   //     pro_mc_det->Scale(1/pro_mc_det->Integral("width"));

        //Gen level MC
        TH1D*pro_mc_gen = h2Dpt_Rebined_True->ProjectionY(Form("pro_mc_gen_R%03d",int(Rjet*100)),Pro_bin_ptlow_gen, Pro_bin_pthigh_gen);
        pro_mc_gen->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (MC Generator level);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
  //      pro_mc_gen->Scale(1/pro_mc_gen->Integral("width"));

        //Unfolded data
        TH1D*pro_unfolded_data = Unfolded_Dpt_data->ProjectionY(Form("pro_unfolded_data_R%03d",int(Rjet*100)),Pro_bin_ptlow_gen, Pro_bin_pthigh_gen);
        pro_unfolded_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Unfolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
    //    pro_unfolded_data->Scale(1/pro_unfolded_data->Integral("width"));

        //Refolded data
        TH1D*pro_refolded_data = Refolded_Dpt_data->ProjectionY(Form("pro_refolded_data_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_refolded_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
    //    pro_refolded_data->Scale(1/pro_refolded_data->Integral("width"));

        TH1D*pro_refolded_data_wFake = Refolded_Dpt_data_wFake->ProjectionY(Form("pro_refolded_data_wFake_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_refolded_data_wFake->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE data with Fakes);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
    //    pro_refolded_data_wFake->Scale(1/pro_refolded_data_wFake->Integral("width"));


//Ratios

        //MC Truth over detector level
        TH1D*Ratio_MCgenoverdet =(TH1D*)pro_mc_gen->Clone();
        Ratio_MCgenoverdet->Reset();
        for (int i_bin=0;i_bin<pro_mc_det->GetNbinsX();i_bin++){
                Ratio_MCgenoverdet->SetBinContent(i_bin,pro_mc_det->GetBinContent(i_bin)); 
                Ratio_MCgenoverdet->SetBinError(i_bin,pro_mc_det->GetBinError(i_bin));}
  
        Ratio_MCgenoverdet->Divide(pro_mc_gen,Ratio_MCgenoverdet);
        Ratio_MCgenoverdet->SetTitle(Form("Ratio of Truth over Detector level #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Truth}{Detector}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
        Ratio_MCgenoverdet->SetName(Form("Ratio_GenDet_R%03d",int(Rjet*100)));
  
        //Unfolded data over data
          TH1D*Ratio_UnfoverData =(TH1D*)pro_unfolded_data->Clone();
          Ratio_UnfoverData->Reset();
          for (int i_bin=0;i_bin<pro_data->GetNbinsX();i_bin++){
                  Ratio_UnfoverData->SetBinContent(i_bin,pro_data->GetBinContent(i_bin)); 
                  Ratio_UnfoverData->SetBinError(i_bin,pro_data->GetBinError(i_bin));}
    
          Ratio_UnfoverData->Divide(pro_unfolded_data,Ratio_UnfoverData);
          Ratio_UnfoverData->SetTitle(Form("Ratio of Unfolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Unfolded data}{Data}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
          Ratio_UnfoverData->SetName(Form("Ratio_UnfData_R%03d",int(Rjet*100)));

        //Refolded over data
          TH1D*Ratio_RefoverData =(TH1D*)pro_refolded_data->Clone();
          Ratio_RefoverData->Reset();
          Ratio_RefoverData->Divide(pro_refolded_data,pro_data);
          Ratio_RefoverData->SetTitle(Form("Ratio of Refolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Refolded data}{Data}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
          Ratio_RefoverData->SetName(Form("Ratio_RefData_R%03d",int(Rjet*100)));

          TH1D*Ratio_RefoverData_wFake =(TH1D*)pro_refolded_data_wFake->Clone();
          Ratio_RefoverData_wFake->Reset();
          Ratio_RefoverData_wFake->Divide(pro_refolded_data_wFake,pro_data);
          Ratio_RefoverData_wFake->SetTitle(Form("Ratio of Refolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c (With fakes);#DeltaP_{t} (GeV/c);#frac{Refolded data}{Data}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
          Ratio_RefoverData_wFake->SetName(Form("Ratio_RefData_wFake_R%03d",int(Rjet*100)));


        //MC Truth over Unfolded data
        TH1D*Ratio_MCgenoverUnf =(TH1D*)pro_mc_gen->Clone();
        Ratio_MCgenoverUnf->Reset();
        Ratio_MCgenoverUnf->Divide(pro_mc_gen,pro_unfolded_data);
        Ratio_MCgenoverUnf->SetTitle(Form("Ratio of Truth level MC over Unfolded data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{MC Truth level}{Unfolded Data}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
        Ratio_MCgenoverUnf->SetName(Form("Ratio_MCgenUnfData_R%03d",int(Rjet*100)));

        //MC Detector level over Data
        TH1D*Ratio_MCdetoverData =(TH1D*)pro_mc_det->Clone();
        Ratio_MCdetoverData->Reset();
        Ratio_MCdetoverData->Divide(pro_mc_det,pro_data);
        Ratio_MCdetoverData->SetTitle(Form("Ratio of Detector level MC over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{MC Detector level}{Data}",Rjet,(Rjet+0.05),Ptlow,Pthigh));
        Ratio_MCdetoverData->SetName(Form("Ratio_MCdetData_R%03d",int(Rjet*100)));


        //Saving the output
        TString Outputname = Form("UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_dRmax005_smallR_Binw%d_pt_%d_%d_ptmin%d_%d_Dptmin%d_max%d_Iter%d.root",BinWidth,Ptlow,Pthigh,int(ptmin),int(ptmax),int(Dptmin),int(Dptmax),Niter);
        TFile *fout = new TFile(Outputname.Data(),"UPDATE");
        
        Dpt_Rebinned_Data->Write(Dpt_Rebinned_Data->GetName(),TObject::kOverwrite);
	Fake_Data->Write(Fake_Data->GetName(),TObject::kOverwrite);
	FakeRatio->Write(FakeRatio->GetName(),TObject::kOverwrite);
	hFakes->Write(hFakes->GetName(),TObject::kOverwrite);
        Pt_RM->Write(Pt_RM->GetName(),TObject::kOverwrite);
        DPt_RM->Write(DPt_RM->GetName(),TObject::kOverwrite);
        ResponseMatrix->Write(ResponseMatrix->GetName(),TObject::kOverwrite);
        Unfolded_Dpt_data->Write(Unfolded_Dpt_data->GetName(),TObject::kOverwrite);
        Refolded_Dpt_data->Write(Refolded_Dpt_data->GetName(),TObject::kOverwrite);
	Refolded_Dpt_data_wFake->Write(Refolded_Dpt_data_wFake->GetName(),TObject::kOverwrite);	
        pro_data->Write(pro_data->GetName(),TObject::kOverwrite);
        pro_mc_det->Write(pro_mc_det->GetName(),TObject::kOverwrite);
        pro_mc_gen->Write(pro_mc_gen->GetName(),TObject::kOverwrite);
        pro_unfolded_data->Write(pro_unfolded_data->GetName(),TObject::kOverwrite);
        pro_refolded_data->Write(pro_refolded_data->GetName(),TObject::kOverwrite);
	pro_refolded_data_wFake->Write(pro_refolded_data_wFake->GetName(),TObject::kOverwrite);
        Ratio_MCgenoverdet->Write(Ratio_MCgenoverdet->GetName(),TObject::kOverwrite);
        Ratio_UnfoverData->Write(Ratio_UnfoverData->GetName(),TObject::kOverwrite);
        Ratio_RefoverData->Write(Ratio_RefoverData->GetName(),TObject::kOverwrite);
	Ratio_RefoverData_wFake->Write(Ratio_RefoverData_wFake->GetName(),TObject::kOverwrite);
        Ratio_MCgenoverUnf->Write(Ratio_MCgenoverUnf->GetName(),TObject::kOverwrite);
        Ratio_MCdetoverData->Write(Ratio_MCdetoverData->GetName(),TObject::kOverwrite);
        Unf_Bayes->Write(Unf_Bayes->GetName(),TObject::kOverwrite);
        Datafile->Close();
        ResponseFile->Close();
        fout->Close();
}

void SetStyle(TH1* h1){
        gStyle->SetOptStat(0);
        gStyle->SetTextFont(42);
        gStyle->SetTitleFont(42);
        gStyle->SetOptTitle(1);
        gStyle->SetPadTickX(1);
        gStyle->SetPadTickY(1);
        h1->SetMarkerStyle(33);
        h1->SetMarkerSize(2);
        h1->SetLineWidth(2);
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
          //        RM_norm->Draw("colz");
        //  TString name = Form("%s_norm",input_RM->GetName());
        //  RM_norm->SetName(name);
        // RM_norm->Write(RM_norm->GetName(),TObject::kOverwrite);
        return RM_norm;
  } 

