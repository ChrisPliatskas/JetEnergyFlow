 void Systematics(TString BaseFile= "AnalysisResults.root",TString TestFile= "AnalysisResults.root", Double_t Rjet=0.05,Int_t Ptlow =0 , Int_t Pthigh = 100, int mod=1){
TFile*base = TFile::Open(BaseFile.Data());
TFile*test= TFile::Open(TestFile.Data());

int R = int(Rjet*100);
TH1D* Hbase = static_cast<TH1D*>(base->Get(Form("pro_unfolded_data_R%03d",R)));
Int_t Nbins = Hbase->GetNbinsX();
Hbase->Scale(1./Hbase->Integral("width"));
Hbase->SetName(Form("pro_base_R%03d",R));
TH1D* HSys = (TH1D*) Hbase->Clone();HSys->Reset();
HSys->SetName(Form("pro_sys_R%03d",R));
HSys->SetTitle(Form("#DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c (Systematic variation); #DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));

Double_t StatErrors[Nbins];Double_t SystErrors[Nbins];Bool_t Check[Nbins];
TH1D* Htest;
//for(int i=1;i<=Nbins;i++)StatErrors[i]=Hbase->GetBinError(i);
if(TestFile.Contains("ModResponse"))Htest = static_cast<TH1D*>(test->Get(Form("pro_unfolded_data_R%03d_mod%d",R,mod)));
else Htest = static_cast<TH1D*>(test->Get(Form("pro_unfolded_data_R%03d",R)));
Htest->Scale(1./Htest->Integral("width"));

TH1D* Ratio = (TH1D*) Hbase->Clone();Ratio->Reset();
Ratio->SetName(Form("Systematic_Ratio_R%03d",R));
Ratio->SetTitle(Form("Ratio of systematic variation on #DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c; #DeltaP_{t} (GeV/c);Ratio",Rjet,Ptlow,Pthigh));
TH1D* Ratio2 = (TH1D*) Hbase->Clone();Ratio2->Reset();
Ratio2->SetName(Form("Statistic_Ratio_R%03d",R));
Ratio2->SetTitle(Form("Ratio of statistic uncertainty on #DeltaP_{t} distribution for R=%.2f at [%d,%d] GeV/c; #DeltaP_{t} (GeV/c);Ratio",Rjet,Ptlow,Pthigh));
TH1D* dA = (TH1D*) Hbase->Clone();dA->Reset();
dA->SetName(Form("Systematic_variation_R%03d",R));


for(int ibin=1;ibin<=Nbins;ibin++){
        StatErrors[ibin]=Hbase->GetBinError(ibin);
        Double_t cont = Hbase->GetBinContent(ibin);
        Double_t mod = Htest->GetBinContent(ibin);
        HSys->SetBinContent(ibin,cont);
        HSys->SetBinError(ibin,mod-cont);
        Ratio->SetBinContent(ibin,(mod-cont)/cont);
        Ratio2->SetBinContent(ibin,StatErrors[ibin]/cont);
          SystErrors[ibin]=mod-cont;
        if(SystErrors[ibin]>=3*StatErrors[ibin])Check[ibin]=kTRUE;      
        dA->SetBinContent(ibin,SystErrors[ibin]);
      //  Double_t Sigma =TMath::Sqrt((TMath::Power(StatErrors[ibin],2)+TMath::Power(Htest->GetBinError(ibin),2))); <-Fix this
      //  dA->SetBinError(ibin,Sigma);
                        }

TH1D* HCheck =(TH1D*) Htest->Clone();HCheck->Reset();
HCheck->SetName(Form("SysOverStat_R%03d",R));
HCheck->SetTitle(Form("Systematic versus Statistic error for R=%.2f at [%d,%d] GeV/c ; #DeltaP_{t} (GeV/c)",Rjet,Ptlow,Pthigh));
for(int ibin=1;ibin<=Nbins;ibin++)if(Check[ibin])HCheck->Fill(ibin);

//TString Outputname=TString::Format("Systematic_%d_%d_pp_TrackEff.root",Ptlow,Pthigh);
TString Outputname;
if(TestFile.Contains("TrackEff")) Outputname =TString::Format("Systematic_%d_%d_PbPb_TrackEff.root",Ptlow,Pthigh);
else if(!TestFile.Contains("Iter5")){std::string STR =TestFile.Data(); Outputname =TString::Format("Systematic_%d_%d_PbPb_Niter%s.root",Ptlow,Pthigh,TString(STR.substr(126,1)).Data());}
else if(TestFile.Contains("Trunc")) Outputname =TString::Format("Systematic_%d_%d_PbPb_Truncation.root",Ptlow,Pthigh);
else if(TestFile.Contains("LC10")) Outputname =TString::Format("Systematic_%d_%d_PbPb_LC.root",Ptlow,Pthigh);
/*
else if(TestFile.Contains("ModResponse_Pt")){
        if(TestFile.Contains("ModResponse_Pt50"))Outputname =TString::Format("Systematic_%d_%d_pp_Dptmax_%dPriorScalingPt50percent_mod1.root",Ptlow,Pthigh,Dptmax);
        else if(TestFile.Contains("ModResponse_Pt10"))Outputname =TString::Format("Systematic_%d_%d_pp_Dptmax_%dPriorScalingPt10percent_mod1.root",Ptlow,Pthigh,Dptmax);
        else if(TestFile.Contains("ModResponse_Pt20"))Outputname =TString::Format("Systematic_%d_%d_pp_Dptmax_%dPriorScalingPt20percent_mod1.root",Ptlow,Pthigh,Dptmax);
        else if(TestFile.Contains("ModResponse_Pt5"))Outputname =TString::Format("Systematic_%d_%d_pp_Dptmax_%dPriorScalingPt5percent_mod1.root",Ptlow,Pthigh,Dptmax);
        }
*/
else if(TestFile.Contains("ModResponse_DPt5"))Outputname =TString::Format("Systematic_%d_%d_PbPb_PriorScalingDPt5percent_mod%d.root",Ptlow,Pthigh,mod);
else if(TestFile.Contains("dRmax")){std::string STR =TestFile.Data();Outputname =TString::Format("Systematic_%d_%d_PbPb_Bkgsub%s.root",Ptlow,Pthigh,TString(STR.substr(56,3)).Data());}

TFile*Result = new TFile(Outputname.Data(),"UPDATE",Outputname.Data());
HCheck->Write();
Hbase->Write();
HSys->Write();
Ratio->Write();
Ratio2->Write();
dA->Write();
Result->Close();
base->Close();
test->Close();
}
