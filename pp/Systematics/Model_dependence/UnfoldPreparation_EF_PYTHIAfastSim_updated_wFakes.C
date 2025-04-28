void UnfoldPreparation_EF_PYTHIAfastSim_updated_wFakes(TString strIn="AnalysisResults.root",Double_t Rjet =0.1,Double_t PT_MIN = 0.0, Double_t DPT_MIN = -20.5,Double_t DPT_MAX=30.5,Int_t BinWidth=3,Int_t binWidthPt=5){

//Open the file and get the list where the response matrix is stored in THnSparse format
TFile *f = TFile::Open(strIn.Data());
THnSparseD* RM_thn = (THnSparseD*)(f->Get(Form("h_4D_R_%.2f",Rjet)));

//Secondary section about mismatch treatment- this is ignored for now
//THnSparseD* RM_miss = static_cast<THnSparseD*>(ali->FindObject(Form("MismatchResponseMatrix_R%03d_0",int(Rjet*100))));
//RM_thn->Add(RM_miss,-1.);

//Prepare the kinematic phase space for the unfolding
const Int_t ndim =4;
Int_t nDim = RM_thn->GetNdimensions();
Int_t iPt_gen   = 0;
Int_t iPt_det  = 1;
Int_t iDpt_gen  = 2;
Int_t iDpt_det = 3;

//Projections of the response matrix at truth level and reconstructed level prior to rebinning
TH2D *Dpt_pt_true = dynamic_cast<TH2D*>(RM_thn->Projection(iDpt_gen,iPt_gen,"E"));
Dpt_pt_true->SetName(Form("DeltaPt_Pt_gen_R%03d",int(Rjet*100)));
TH2D *Dpt_pt_meas = dynamic_cast<TH2D*>(RM_thn->Projection(iDpt_det,iPt_det,"E"));
Dpt_pt_meas->SetName(Form("DeltaPt_Pt_det_R%03d",int(Rjet*100)));

//Setup of the bin configuration for Measured & True

Double_t pt_min = PT_MIN; // Lower Pt limit for detector level, Perhaps we can change this to evaluate systematics
Double_t pt_max = 100.0;  //Upper Pt limit for detector level (Gen level is higher by 10 GeV (feed-in effect)).
Double_t pt_min_gen = PT_MIN;//PT_MIN-5.;// Lower Pt limit for generator level
Double_t Dpt_min = DPT_MIN; //Lower Dpt limit for detector level
Double_t Dpt_max = DPT_MAX; //Upper Dpt limit for detector level(Gen level is higher by 5 GeV (feed-in effect))
Double_t Dpt_max_gen = DPT_MAX+BinWidth; //Upper Dpt limit for truth level(Gen level is higher by 5 GeV (feed-in effect))

      //Detector, Particle level
Int_t nPtBinWidth[2] = {binWidthPt,binWidthPt};
Double_t ptmin[2] = {pt_min,pt_min_gen};
Double_t ptmax[2] = {pt_max, pt_max+5};//pt_max+10};
Int_t nBinPt[2] = {int(ptmax[0]-ptmin[0])/nPtBinWidth[0],int(ptmax[1]-ptmin[1])/nPtBinWidth[1]};

     //Detector, Particle level
Int_t nDptBinWidth[2] = {BinWidth,BinWidth};
//Double_t Dptmin[2] = {Dpt_min ,Dpt_min};
Double_t Dptmin[2] = {Dpt_min ,Dpt_min};//-double(BinWidth)/2};
Double_t Dptmax[2] = {Dpt_max,Dpt_max_gen};
Int_t nBinDpt[2] = {int(Dptmax[0]-Dptmin[0])/nDptBinWidth[0],int(Dptmax[1]-Dptmin[1])/nDptBinWidth[1]};

//Create the histograms that will hold the rebinned distributions as well as the ones that will represent the measured missed and fake distributions

//Configuration of the rebinned Detector level distribution
TH2D *h2Dpt_Rebined_Meas = new TH2D(Form("h2Dpt_Rebined_Meas_R%03d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (Detector level -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);
//Configuration of the rebinned truth level distribution
TH2D *h2Dpt_Rebined_True = new TH2D(Form("h2Dpt_Rebined_True_R%03d",int(Rjet*100)),Form("#DeltaP_{t} distribution R =%.2f (Generator level -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nBinPt[1],ptmin[1],ptmax[1],nBinDpt[1],Dptmin[1],Dptmax[1]);

//Detector level distribution within range for both true & detector level (Response->Fill)
TH2D *h2Det_meas = new TH2D(Form("h2Det_meas_R%03d",int(Rjet*100)),Form("h2Reconstructed (measured) R =%.2f",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);

//Truth level distribution within range for both true & detector level (Response->Fill) 
TH2D *h2True_meas = new TH2D(Form("h2True_meas_R%03d",int(Rjet*100)),Form("h2True (measured) R =%.2f",Rjet),nBinPt[0],ptmin[1],ptmax[1],nBinDpt[1],Dptmin[1],Dptmax[1]);
//Detector level distribution within detector but outside true range (Response->Fake)
TH2D *hFake = new TH2D(Form("hFake_R%03d",int(Rjet*100)),Form("hFake_R =%.2f",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);
//Truth level distribution within true but outside detector range (Response->Miss)
TH2D *h2True_miss = new TH2D(Form("h2True_miss_R%03d",int(Rjet*100)),Form("h2True (Missed) R =%.2f",Rjet),nBinPt[0],ptmin[1],ptmax[1],nBinDpt[1],Dptmin[1],Dptmax[1]);
//Truth level distribution within true but outside detector range (Response->Miss) [EMPTY]
TH2D *h2Det_miss = new TH2D(Form("h2Det_miss_R%03d",int(Rjet*100)),Form("h2Reconstructed (missed) R =%.2f",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);


//Rebinning the detector level distribution

for(Int_t ix=1;ix<=h2Dpt_Rebined_Meas->GetNbinsX();ix++){

      Double_t xlow = h2Dpt_Rebined_Meas->GetXaxis()->GetBinLowEdge(ix);
      Double_t xup = h2Dpt_Rebined_Meas->GetXaxis()->GetBinUpEdge(ix);
      Int_t jxlow = Dpt_pt_meas->GetXaxis()->FindBin(xlow+0.000001);
      Int_t jxup = Dpt_pt_meas->GetXaxis()->FindBin(xup-0.000001);
      for(Int_t iy = 1; iy<=h2Dpt_Rebined_Meas->GetNbinsY(); iy++) {
        Double_t ylow = h2Dpt_Rebined_Meas->GetYaxis()->GetBinLowEdge(iy);
        Double_t yup =h2Dpt_Rebined_Meas->GetYaxis()->GetBinUpEdge(iy);
        Int_t jylow = Dpt_pt_meas->GetYaxis()->FindBin(ylow+0.000001);
        Int_t jyup = Dpt_pt_meas->GetYaxis()->FindBin(yup-0.000001);
  
        Double_t err = 0.;
        Double_t con = Dpt_pt_meas->IntegralAndError(jxlow,jxup,jylow,jyup,err);
        h2Dpt_Rebined_Meas->SetBinContent(ix,iy,con);
        h2Dpt_Rebined_Meas->SetBinError(ix,iy,err);
         } //End of ybin loop
         } //End of xbin loop
                           
//Rebinning the truth level distribution

  for(Int_t ix = 1; ix<=h2Dpt_Rebined_True->GetNbinsX(); ix++) {
      Double_t xlow = h2Dpt_Rebined_True->GetXaxis()->GetBinLowEdge(ix);
      Double_t xup = h2Dpt_Rebined_True->GetXaxis()->GetBinUpEdge(ix);
      Int_t jxlow = Dpt_pt_true->GetXaxis()->FindBin(xlow+0.000001);
      Int_t jxup = Dpt_pt_true->GetXaxis()->FindBin(xup-0.000001);
      for(Int_t iy = 1; iy<=h2Dpt_Rebined_True->GetNbinsY(); iy++) {
        Double_t ylow = h2Dpt_Rebined_True->GetYaxis()->GetBinLowEdge(iy);
        Double_t yup = h2Dpt_Rebined_True->GetYaxis()->GetBinUpEdge(iy);
        Int_t jylow = Dpt_pt_true->GetYaxis()->FindBin(ylow+0.000001);
        Int_t jyup = Dpt_pt_true->GetYaxis()->FindBin(yup-0.000001);
  
        Double_t err = 0.;
        Double_t con = Dpt_pt_true->IntegralAndError(jxlow,jxup,jylow,jyup,err);
        h2Dpt_Rebined_True->SetBinContent(ix,iy,con);
        h2Dpt_Rebined_True->SetBinError(ix,iy,err);
      }
    }

//Fill the measured, missed and Fake distribution at each level and create the response object

    //RooUnfold response object setup
    RooUnfoldResponse *fResponse = new RooUnfoldResponse(Form("Response_R%03d",int(Rjet*100)),"RM");
    fResponse->Setup(h2Dpt_Rebined_Meas,h2Dpt_Rebined_True);
  
    //Fill RooUnfoldResponse object
    Int_t* coord = new Int_t[nDim]; //Carries the bin coordinates
    Int_t nbin = RM_thn->GetNbins();
    Bool_t TruthFlag = kFALSE; Bool_t DetectorFlag = kFALSE;

    for(Int_t bin=0; bin<nbin; bin++) {
      Double_t w = RM_thn->GetBinContent(bin,coord);
      TruthFlag = kFALSE; DetectorFlag = kFALSE;
      Double_t Dpt_meas = RM_thn->GetAxis(3)->GetBinCenter(coord[3]);
      Double_t Dpt_true = RM_thn->GetAxis(2)->GetBinCenter(coord[2]);
      Double_t pt_meas = RM_thn->GetAxis(1)->GetBinCenter(coord[1]);
      Double_t pt_true = RM_thn->GetAxis(0)->GetBinCenter(coord[0]);
    if((Dpt_meas>=Dptmin[0] && Dpt_meas<Dptmax[0]) && (pt_meas>=ptmin[0] && pt_meas<ptmax[0]))DetectorFlag=kTRUE;
    if((Dpt_true>=Dptmin[1] && Dpt_true<Dptmax[1]) && (pt_true>=ptmin[1] && pt_true<ptmax[1]))TruthFlag = kTRUE;
        if(TruthFlag && DetectorFlag){
        fResponse->Fill(pt_meas,Dpt_meas,pt_true,Dpt_true,w);
        h2Det_meas->Fill(pt_meas,Dpt_meas,w);
        h2True_meas->Fill(pt_true,Dpt_true,w);
        }
        else if (!DetectorFlag){
        fResponse->Miss(pt_true,Dpt_true,w);
        h2True_miss->Fill(pt_true,Dpt_true,w);
        h2Det_miss->Fill(pt_meas,Dpt_meas,w);
        }
        else if(DetectorFlag && (!TruthFlag)){
        fResponse->Fake(pt_meas,Dpt_meas,w);
        hFake->Fill(pt_meas,Dpt_meas,w);
        }
/*        else if(TruthFlag && (!DetectorFlag)){
        fResponse->Miss(pt_true,Dpt_true,w);
        h2True_miss->Fill(pt_true,Dpt_true,w);
        h2Det_miss->Fill(pt_meas,Dpt_meas,w);}
        else if(DetectorFlag && (!TruthFlag)){
        fResponse->Fake(pt_meas,Dpt_meas,w); 
        hFake->Fill(pt_meas,Dpt_meas,w);}*/
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

    TFile *fout = new TFile(Form("ResponseMatrix_pp_PYTHIAfastSim_wFakes_smallR_NewBinW%d_Ptw%d_ptmin%d_Dptmin%d_%d_2024.root",BinWidth,binWidthPt,int(PT_MIN),int(DPT_MIN),int(DPT_MAX)),"UPDATE");
    RM_thn->Write(Form("RM_THN%03d",int(Rjet*100)));
    fResponse->Write(Form("Response_R%03d",int(Rjet*100)));
    Dpt_pt_meas->Write(Dpt_pt_meas->GetName(),TObject::kOverwrite);
    Dpt_pt_true->Write(Dpt_pt_true->GetName(),TObject::kOverwrite);
    h2Dpt_Rebined_Meas->Write(h2Dpt_Rebined_Meas->GetName(),TObject::kOverwrite);
    h2Dpt_Rebined_True->Write(h2Dpt_Rebined_True->GetName(),TObject::kOverwrite);
    h2True_meas->Write(h2True_meas->GetName(),TObject::kOverwrite);
    h2Det_meas->Write(h2Det_meas->GetName(),TObject::kOverwrite);
    h2Det->Write(h2Det->GetName(),TObject::kOverwrite);
    h2True->Write(h2True->GetName(),TObject::kOverwrite);
    h2True_miss->Write(h2True_miss->GetName(),TObject::kOverwrite);
    h2Det_miss->Write(h2Det_miss->GetName(),TObject::kOverwrite);
    hFake->Write(hFake->GetName(),TObject::kOverwrite);

    fout->Write();
    fout->Close();


}
