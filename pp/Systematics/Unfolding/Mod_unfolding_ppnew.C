void SetStyle(TH1* h1);
TH2D* RM_normalization(TH2D* input_RM);

void Mod_unfolding_ppnew(TString DatafileName = "AnalysisResults.root",TString ResponsefileName = "Modified_Response_ppMC_pt.root",Double_t Rjet = 0.1, Int_t Ptlow =0 , Int_t Pthigh = 100,Int_t Niter = 1,double perc=0.05){

//Response Matrix visualisation
TFile*ResponseFile = TFile::Open(ResponsefileName.Data());
int R = int(100*Rjet);
TH2D* h2Dpt_Rebined_Meas_mod1 = static_cast<TH2D*>(ResponseFile->Get(Form("DeltaPt_Pt_det_R%03d_mod1",R)));
TH2D* h2Dpt_Rebined_True_mod1 = static_cast<TH2D*>(ResponseFile->Get(Form("DeltaPt_Pt_gen_R%03d_mod1",R)));

TH2D* h2Dpt_Rebined_Meas_mod2 = static_cast<TH2D*>(ResponseFile->Get(Form("DeltaPt_Pt_det_R%03d_mod2",R)));
TH2D* h2Dpt_Rebined_True_mod2 = static_cast<TH2D*>(ResponseFile->Get(Form("DeltaPt_Pt_gen_R%03d_mod2",R)));



TH2D* hFakes_mod1 = static_cast<TH2D*>(ResponseFile->Get(Form("hFake_R%03d_mod1",int(Rjet*100))));
TH2D* hFakes_mod2 = static_cast<TH2D*>(ResponseFile->Get(Form("hFake_R%03d_mod2",int(Rjet*100))));
Int_t nPtBins = h2Dpt_Rebined_Meas_mod1->GetNbinsX();
Double_t ptmin = h2Dpt_Rebined_Meas_mod1->GetXaxis()->GetXmin();
Double_t ptmax = h2Dpt_Rebined_Meas_mod1->GetXaxis()->GetXmax();

Int_t nDptBins = h2Dpt_Rebined_Meas_mod1->GetNbinsY();
Double_t Dptmin = h2Dpt_Rebined_Meas_mod1->GetYaxis()->GetXmin();
Double_t Dptmax = h2Dpt_Rebined_Meas_mod1->GetYaxis()->GetXmax();

 Int_t nPtBins_gen = h2Dpt_Rebined_True_mod1->GetNbinsX();
 Double_t ptmin_gen = h2Dpt_Rebined_True_mod1->GetXaxis()->GetXmin();
 Double_t ptmax_gen = h2Dpt_Rebined_True_mod1->GetXaxis()->GetXmax();

 Int_t nDptBins_gen = h2Dpt_Rebined_True_mod1->GetNbinsY();
 Double_t Dptmin_gen = h2Dpt_Rebined_True_mod1->GetYaxis()->GetXmin();
 Double_t Dptmax_gen = h2Dpt_Rebined_True_mod1->GetYaxis()->GetXmax();

Int_t Ptwidth = int(h2Dpt_Rebined_Meas_mod1->GetXaxis()->GetBinWidth(1));


Double_t Dptlow = Dptmin;
Double_t Dpthigh = Dptmax;

 
Double_t Dptlow_gen = Dptmin_gen;
Double_t Dpthigh_gen = Dptmax_gen;

Int_t Dptwidth = int(h2Dpt_Rebined_Meas_mod1->GetYaxis()->GetBinWidth(1));

//std::cout<<"CheckPoint A \n";
//Load & Rebin data distribution
TFile*Datafile = TFile::Open(DatafileName.Data());
AliEmcalList* ali;
Datafile->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_ppdata_smallR_ppdata_histos",ali);

TH2D*hDpt_data = static_cast<TH2D*>(ali->FindObject(Form("hJetPtDeltaPt_R%03d_0",R)));

TH2D *Dpt_Rebinned_Data = new TH2D(Form("Dpt_Rebinned_DataR%03d",R),Form("#DeltaP_{t} distribution R =%.2f (ALICE data -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nPtBins,ptmin,ptmax,nDptBins,Dptmin,Dptmax);

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
TH2D* Fake_Data_mod1 = (TH2D*) Dpt_Rebinned_Data->Clone(Form("Fake_DataR%03d_mod1",int(Rjet*100)));
Fake_Data_mod1->Reset();
TH2D* FakeRatio_mod1 = (TH2D*) h2Dpt_Rebined_Meas_mod1->Clone(Form("FakeRatio_R%03d_mod1",int(Rjet*100)));
FakeRatio_mod1->Reset();
//FakeRatio_mod1->Divide(hFakes_mod1,h2Dpt_Rebined_Meas_mod1);

TH2D* Fake_Data_mod2 = (TH2D*) Dpt_Rebinned_Data->Clone(Form("Fake_DataR%03d_mod2",int(Rjet*100)));
Fake_Data_mod2->Reset();
TH2D* FakeRatio_mod2 = (TH2D*) h2Dpt_Rebined_Meas_mod2->Clone(Form("FakeRatio_R%03d_mod2",int(Rjet*100)));
FakeRatio_mod2->Reset(); 
//FakeRatio_mod2->Divide(hFakes_mod2,h2Dpt_Rebined_Meas_mod2);

for(Int_t ix=1;ix<=Dpt_Rebinned_Data->GetNbinsX();ix++){
for(Int_t iy = 1; iy<=Dpt_Rebinned_Data->GetNbinsY(); iy++){
Double_t mod1 = FakeRatio_mod1->GetBinContent(ix,iy);
Double_t mod2 = FakeRatio_mod2->GetBinContent(ix,iy);
Double_t cont = Dpt_Rebinned_Data->GetBinContent(ix,iy);
Fake_Data_mod1->SetBinContent(ix,iy,mod1*cont);
Fake_Data_mod2->SetBinContent(ix,iy,mod2*cont);
        }//End of ybin loop
        }//End of xbin loop

//std::cout<<"CheckPoint B \n";

//Unfold rebinned data distro
RooUnfoldResponse* resp1 = static_cast<RooUnfoldResponse*>(ResponseFile->Get(Form("Response_R%03d_mod1",R)));
TString Unfoldname1 =Form("Bayesian_Unfolding_R%d_ptmin%d_mod1",R,int(ptmin));
RooUnfoldBayes Unfolding_bayes1(resp1,Dpt_Rebinned_Data,Niter,0,Unfoldname1,Unfoldname1);
TH2D* Unfolded_Dpt_data_mod1 = (TH2D*)Unfolding_bayes1.Hreco(RooUnfold::kCovToy);

RooUnfoldResponse* resp2 = static_cast<RooUnfoldResponse*>(ResponseFile->Get(Form("Response_R%03d_mod2",R)));
TString Unfoldname2 =Form("Bayesian_Unfolding_R%d_ptmin%d_mod2",R,int(ptmin));
RooUnfoldBayes Unfolding_bayes2(resp2,Dpt_Rebinned_Data,Niter,0,Unfoldname2,Unfoldname2);
TH2D* Unfolded_Dpt_data_mod2 = (TH2D*)Unfolding_bayes2.Hreco(RooUnfold::kCovToy);

//std::cout<<"CheckPoint C \n";
//Refold Unfolded data distro
TH2D* Refolded_Dpt_data_mod1 = (TH2D*) resp1->ApplyToTruth(Unfolded_Dpt_data_mod1,Form("Refolded_Dpt_data_R%03d_mod1",int(Rjet*100)));

TH2D* Refolded_Dpt_data_mod2 = (TH2D*) resp2->ApplyToTruth(Unfolded_Dpt_data_mod2,Form("Refolded_Dpt_data_R%03d_mod2",int(Rjet*100)));

TH2D* Refolded_Dpt_data_mod1_wFake = (TH2D*) Refolded_Dpt_data_mod1->Clone(Form("Refolded_Dpt_data_wFake_R%03d_mod1",int(Rjet*100)));
Refolded_Dpt_data_mod1_wFake->Add(Fake_Data_mod1);

TH2D* Refolded_Dpt_data_mod2_wFake = (TH2D*) Refolded_Dpt_data_mod2->Clone(Form("Refolded_Dpt_data_wFake_R%03d_mod2",int(Rjet*100)));
Refolded_Dpt_data_mod2_wFake->Add(Fake_Data_mod2);

Int_t Pro_bin_ptlow =Dpt_Rebinned_Data->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh =Dpt_Rebinned_Data->GetXaxis()->FindBin(Pthigh)-1;

Int_t Pro_bin_ptlow_gen =Unfolded_Dpt_data_mod1->GetXaxis()->FindBin(Ptlow);
Int_t Pro_bin_pthigh_gen =Unfolded_Dpt_data_mod1->GetXaxis()->FindBin(Pthigh)-1;
//std::cout<<"CheckPoint D \n";
        //Initial data distro
        TH1D*pro_data = Dpt_Rebinned_Data->ProjectionY(Form("pro_data_R%03d",int(Rjet*100)),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_data->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
//        pro_data->SetAxisRange(Dptmin,Dptmax,"X");
//        pro_data->Scale(1/pro_data->Integral());

        //Unfolded data
        TH1D*pro_unfolded_data_mod1 = Unfolded_Dpt_data_mod1->ProjectionY(Form("pro_unfolded_data_R%03d_mod1",R),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_unfolded_data_mod1->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Unfolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
  //      pro_unfolded_data_mod1->SetAxisRange(Dptmin,Dptmax+2.,"X");
 //       pro_unfolded_data_mod1->Scale(1/pro_unfolded_data_mod1->Integral());

        TH1D*pro_unfolded_data_mod2 = Unfolded_Dpt_data_mod2->ProjectionY(Form("pro_unfolded_data_R%03d_mod2",R),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_unfolded_data_mod2->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Unfolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
  //      pro_unfolded_data_mod2->SetAxisRange(Dptmin,Dptmax+2.,"X");
 //       pro_unfolded_data_mod2->Scale(1/pro_unfolded_data_mod2->Integral());
//std::cout<<"CheckPoint E \n";
        //Refolded data
        TH1D*pro_refolded_data_mod1 = Refolded_Dpt_data_mod1_wFake->ProjectionY(Form("pro_refolded_data_R%03d_mod1",R),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_refolded_data_mod1->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
//        pro_refolded_data_mod1->SetAxisRange(Dptmin,Dptmax,"X");
//        pro_refolded_data_mod1->Scale(1/pro_refolded_data_mod1->Integral());

        TH1D*pro_refolded_data_mod2 = Refolded_Dpt_data_mod2_wFake->ProjectionY(Form("pro_refolded_data_R%03d_mod2",R),Pro_bin_ptlow, Pro_bin_pthigh);
        pro_refolded_data_mod2->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Refolded ALICE data);#DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
 //       pro_refolded_data_mod2->SetAxisRange(Dptmin,Dptmax,"X");
 //       pro_refolded_data_mod2->Scale(1/pro_refolded_data_mod2->Integral());
//std::cout<<"CheckPoint F \n";
        //Unfolded data over data
          TH1D*Ratio_UnfoverData_mod1 =(TH1D*)pro_unfolded_data_mod1->Clone();
          Ratio_UnfoverData_mod1->Reset();
          for (int i_bin=0;i_bin<pro_data->GetNbinsX();i_bin++){
                  Ratio_UnfoverData_mod1->SetBinContent(i_bin,pro_data->GetBinContent(i_bin));
                  Ratio_UnfoverData_mod1->SetBinError(i_bin,pro_data->GetBinError(i_bin));}

          Ratio_UnfoverData_mod1->Divide(pro_unfolded_data_mod1,Ratio_UnfoverData_mod1);
          Ratio_UnfoverData_mod1->SetTitle(Form("Ratio of Unfolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Unfolded data}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
          Ratio_UnfoverData_mod1->SetName(Form("Ratio_UnfData_R%03d_mod1",R));

          TH1D*Ratio_UnfoverData_mod2 =(TH1D*)pro_unfolded_data_mod2->Clone();
          Ratio_UnfoverData_mod2->Reset();
          for (int i_bin=0;i_bin<pro_data->GetNbinsX();i_bin++){
                  Ratio_UnfoverData_mod2->SetBinContent(i_bin,pro_data->GetBinContent(i_bin));
                  Ratio_UnfoverData_mod2->SetBinError(i_bin,pro_data->GetBinError(i_bin));}

          Ratio_UnfoverData_mod2->Divide(pro_unfolded_data_mod2,Ratio_UnfoverData_mod2);
          Ratio_UnfoverData_mod2->SetTitle(Form("Ratio of Unfolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Unfolded data}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
          Ratio_UnfoverData_mod2->SetName(Form("Ratio_UnfData_R%03d_mod2",R));
//std::cout<<"CheckPoint G \n";
        //Refolded over data
          TH1D*Ratio_RefoverData_mod1 =(TH1D*)pro_refolded_data_mod1->Clone();
          Ratio_RefoverData_mod1->Reset();
          Ratio_RefoverData_mod1->Divide(pro_refolded_data_mod1,pro_data);
          Ratio_RefoverData_mod1->SetTitle(Form("Ratio of Refolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Refolded data}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
          Ratio_RefoverData_mod1->SetName(Form("Ratio_RefData_R%03d_mod1",R));
        
          TH1D*Ratio_RefoverData_mod2 =(TH1D*)pro_refolded_data_mod2->Clone();
          Ratio_RefoverData_mod2->Reset();
          Ratio_RefoverData_mod2->Divide(pro_refolded_data_mod2,pro_data);
          Ratio_RefoverData_mod2->SetTitle(Form("Ratio of Refolded over Data #DeltaP_{t} distributions from R=%.2f to R=%.2f at [%d,%d] GeV/c;#DeltaP_{t} (GeV/c);#frac{Refolded data}{Data}",Rjet,(Rjet+0.1),Ptlow,Pthigh));
          Ratio_RefoverData_mod2->SetName(Form("Ratio_RefData_R%03d_mod2",R));

//std::cout<<"CheckPoint H \n";
 TString Outputname = Form("UnfoldedResults_ppFinalSolution_ModResponse_DPt%d_pt_%d_%d_ptmin%d_Dptmin%d_ptmax%d_Dptmax%d_Iter%d.root",int(100*perc),Ptlow,Pthigh,int(ptmin),int(Dptmin),int(ptmax),int(Dptmax),Niter);
        TFile *fout = new TFile(Outputname.Data(),"UPDATE");

        Dpt_Rebinned_Data->Write(Dpt_Rebinned_Data->GetName(),TObject::kOverwrite);
     //  Pt_RM->Write(Pt_RM->GetName(),TObject::kOverwrite);
     //   DPt_RM->Write(DPt_RM->GetName(),TObject::kOverwrite);
     //    ResponseMatrix->Write(ResponseMatrix->GetName(),TObject::kOverwrite);
        Unfolded_Dpt_data_mod1->Write(Unfolded_Dpt_data_mod1->GetName(),TObject::kOverwrite);
        Unfolded_Dpt_data_mod2->Write(Unfolded_Dpt_data_mod2->GetName(),TObject::kOverwrite);
        Refolded_Dpt_data_mod1->Write(Refolded_Dpt_data_mod1->GetName(),TObject::kOverwrite);
        Refolded_Dpt_data_mod2->Write(Refolded_Dpt_data_mod2->GetName(),TObject::kOverwrite);
        pro_data->Write(pro_data->GetName(),TObject::kOverwrite);
  //      pro_mc_det->Write(pro_mc_det->GetName(),TObject::kOverwrite);
  //       pro_mc_gen->Write(pro_mc_gen->GetName(),TObject::kOverwrite);
        pro_unfolded_data_mod1->Write(pro_unfolded_data_mod1->GetName(),TObject::kOverwrite);
        pro_unfolded_data_mod2->Write(pro_unfolded_data_mod2->GetName(),TObject::kOverwrite);
        pro_refolded_data_mod1->Write(pro_refolded_data_mod1->GetName(),TObject::kOverwrite);
        pro_refolded_data_mod2->Write(pro_refolded_data_mod2->GetName(),TObject::kOverwrite);
 //       Ratio_MCgenoverdet->Write(Ratio_MCgenoverdet->GetName(),TObject::kOverwrite);
//        Ratio_UnfoverData_mod1->Write(Ratio_UnfoverData_mod1->GetName(),TObject::kOverwrite);
//        Ratio_UnfoverData_mod2->Write(Ratio_UnfoverData_mod2->GetName(),TObject::kOverwrite);
//        Ratio_RefoverData_mod1->Write(Ratio_RefoverData_mod1->GetName(),TObject::kOverwrite);
//        Ratio_RefoverData_mod2->Write(Ratio_RefoverData_mod2->GetName(),TObject::kOverwrite);
 //       Ratio_MCgenoverUnf->Write(Ratio_MCgenoverUnf->GetName(),TObject::kOverwrite);
//        Ratio_MCdetoverData->Write(Ratio_MCdetoverData->GetName(),TObject::kOverwrite);
        Datafile->Close();
        ResponseFile->Close();
        fout->Close();
}
