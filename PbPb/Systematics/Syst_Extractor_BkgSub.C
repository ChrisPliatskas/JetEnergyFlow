void Syst_Extractor_BkgSub(TString fname1 = "analysisResults.root",TString fname2 = "analysisResults.root",int ptlow=60, int pthigh=80){


TFile*f_syst_dR005 = TFile::Open(fname1.Data());

TH1D* sys_R005_dR005 = (TH1D*) f_syst_dR005->Get("Systematic_Ratio_R005");

TH1D* sys_R010_dR005 = (TH1D*) f_syst_dR005->Get("Systematic_Ratio_R010");

TH1D* sys_R015_dR005 = (TH1D*) f_syst_dR005->Get("Systematic_Ratio_R015");

TH1D* sys_R020_dR005 = (TH1D*) f_syst_dR005->Get("Systematic_Ratio_R020");


Int_t Nbins = sys_R005_dR005->GetNbinsX();

TFile*f_syst_dR030 = TFile::Open(fname2.Data());

TH1D* sys_R005_dR030 = (TH1D*) f_syst_dR030->Get("Systematic_Ratio_R005");

TH1D* sys_R010_dR030 = (TH1D*) f_syst_dR030->Get("Systematic_Ratio_R010");

TH1D* sys_R015_dR030 = (TH1D*) f_syst_dR030->Get("Systematic_Ratio_R015");

TH1D* sys_R020_dR030 = (TH1D*) f_syst_dR030->Get("Systematic_Ratio_R020");


 double dR005_R005[11] = {}; double dR005_R010[11] = {}; double dR005_R015[11] = {};
 double dR005_R020[11] = {}; 


 for(int i=1;i<=Nbins;i++){
        dR005_R005[i-1] =  100*sys_R005_dR005->GetBinContent(i);
        dR005_R010[i-1] =  100*sys_R010_dR005->GetBinContent(i);
        dR005_R015[i-1] =  100*sys_R015_dR005->GetBinContent(i);
        dR005_R020[i-1] =  100*sys_R020_dR005->GetBinContent(i);
        }

 double dR030_R005[11] = {}; double dR030_R010[11] = {}; double dR030_R015[11] = {};
 double dR030_R020[11] = {};


 for(int i=1;i<=Nbins;i++){
        dR030_R005[i-1] =  100*sys_R005_dR030->GetBinContent(i);
        dR030_R010[i-1] =  100*sys_R010_dR030->GetBinContent(i);
        dR030_R015[i-1] =  100*sys_R015_dR030->GetBinContent(i);
        dR030_R020[i-1] =  100*sys_R020_dR030->GetBinContent(i);
        }

 double diff_R005[11] = {}; double diff_R010[11] = {}; double diff_R015[11] = {};
 double diff_R020[11] = {};

 for(int i=1;i<=Nbins;i++){
        diff_R005[i-1] = abs(dR030_R005[i-1]- dR005_R005[i-1])/2;
        diff_R010[i-1] = abs(dR030_R010[i-1]- dR005_R010[i-1])/2;
        diff_R015[i-1] = abs(dR030_R015[i-1]- dR005_R015[i-1])/2;
        diff_R020[i-1] = abs(dR030_R020[i-1]- dR005_R020[i-1])/2;
}



ofstream myfile;
myfile.open (Form("BkgSub_values_PbPb_%d_%d.txt",ptlow,pthigh));
myfile<<"#Deltap_{T} bins: [-1.5,1.5] [1.5,4.5] [4.5,7.5] [7.5,10.5] [10.5,13.5] [13.5,16.5] [16.5,19.5] [19.5,22.5] [22.5,25.5][28.5,28.5][28.5,31.5] \n";
myfile <<"R=0.05 to R=0.1 \n";
myfile <<"dRmax = 0.05 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR005_R005[i]<< " ";
myfile<<"\n";
myfile <<"dRmax = 0.30 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR030_R005[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R005[i]<< " ";
myfile<<"\n";
myfile <<"R=0.1 to R=0.15 \n";
myfile <<"dRmax = 0.05 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR005_R010[i]<< " ";
myfile<<"\n";
myfile <<"dRmax = 0.30 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR030_R010[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R010[i]<< " ";
myfile<<"\n";

myfile <<"R=0.15 to R=0.2 \n";
myfile <<"dRmax = 0.05 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR005_R015[i]<< " ";
myfile<<"\n";
myfile <<"dRmax = 0.30 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR030_R015[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R015[i]<< " ";
myfile<<"\n";

myfile <<"R=0.2 to R=0.25 \n";
myfile <<"dRmax = 0.05 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR005_R020[i]<< " ";
myfile<<"\n";
myfile <<"dRmax = 0.30 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<dR030_R020[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R020[i]<< " ";
myfile<<"\n";

myfile<<"\n";}
