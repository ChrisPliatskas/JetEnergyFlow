void Syst_Extractor_Niter(TString fname1 = "analysisResults.root",TString fname2 = "analysisResults.root",int ptlow=60, int pthigh=80){


TFile*f_syst_N4 = TFile::Open(fname1.Data());

TH1D* sys_R005_N4 = (TH1D*) f_syst_N4->Get("Systematic_Ratio_R005");

TH1D* sys_R010_N4 = (TH1D*) f_syst_N4->Get("Systematic_Ratio_R010");

TH1D* sys_R015_N4 = (TH1D*) f_syst_N4->Get("Systematic_Ratio_R015");

TH1D* sys_R020_N4 = (TH1D*) f_syst_N4->Get("Systematic_Ratio_R020");


Int_t Nbins = sys_R005_N4->GetNbinsX();

TFile*f_syst_N6 = TFile::Open(fname2.Data());

TH1D* sys_R005_N6 = (TH1D*) f_syst_N6->Get("Systematic_Ratio_R005");

TH1D* sys_R010_N6 = (TH1D*) f_syst_N6->Get("Systematic_Ratio_R010");

TH1D* sys_R015_N6 = (TH1D*) f_syst_N6->Get("Systematic_Ratio_R015");

TH1D* sys_R020_N6 = (TH1D*) f_syst_N6->Get("Systematic_Ratio_R020");


 double N4_R005[11] = {}; double N4_R010[11] = {}; double N4_R015[11] = {};
 double N4_R020[11] = {}; 


 for(int i=1;i<=Nbins;i++){
        N4_R005[i-1] =  100*sys_R005_N4->GetBinContent(i);
        N4_R010[i-1] =  100*sys_R010_N4->GetBinContent(i);
        N4_R015[i-1] =  100*sys_R015_N4->GetBinContent(i);
        N4_R020[i-1] =  100*sys_R020_N4->GetBinContent(i);
        }

 double N6_R005[11] = {}; double N6_R010[11] = {}; double N6_R015[11] = {};
 double N6_R020[11] = {};


 for(int i=1;i<=Nbins;i++){
        N6_R005[i-1] =  100*sys_R005_N6->GetBinContent(i);
        N6_R010[i-1] =  100*sys_R010_N6->GetBinContent(i);
        N6_R015[i-1] =  100*sys_R015_N6->GetBinContent(i);
        N6_R020[i-1] =  100*sys_R020_N6->GetBinContent(i);
        }

 double diff_R005[11] = {}; double diff_R010[11] = {}; double diff_R015[11] = {};
 double diff_R020[11] = {};

 for(int i=1;i<=Nbins;i++){
        diff_R005[i-1] = abs(N6_R005[i-1]- N4_R005[i-1])/2;
        diff_R010[i-1] = abs(N6_R010[i-1]- N4_R010[i-1])/2;
        diff_R015[i-1] = abs(N6_R015[i-1]- N4_R015[i-1])/2;
        diff_R020[i-1] = abs(N6_R020[i-1]- N4_R020[i-1])/2;
}



ofstream myfile;
myfile.open (Form("Niter_values_PbPb_%d_%d.txt",ptlow,pthigh));
myfile<<"#Deltap_{T} bins: [-1.5,1.5] [1.5,4.5] [4.5,7.5] [7.5,10.5] [10.5,13.5] [13.5,16.5] [16.5,19.5] [19.5,22.5] [22.5,25.5][28.5,28.5][28.5,31.5] \n";
myfile <<"R=0.05 to R=0.1 \n";
myfile <<"N=4 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N4_R005[i]<< " ";
myfile<<"\n";
myfile <<"N=6 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N6_R005[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R005[i]<< " ";
myfile<<"\n";
myfile <<"R=0.1 to R=0.15 \n";
myfile <<"N=4 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N4_R010[i]<< " ";
myfile<<"\n";
myfile <<"N=6 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N6_R010[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R010[i]<< " ";
myfile<<"\n";

myfile <<"R=0.15 to R=0.2 \n";
myfile <<"N=4 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N4_R015[i]<< " ";
myfile<<"\n";
myfile <<"N=6 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N6_R015[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R015[i]<< " ";
myfile<<"\n";

myfile <<"R=0.2 to R=0.25 \n";
myfile <<"N=4 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N4_R020[i]<< " ";
myfile<<"\n";
myfile <<"N=6 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<N6_R020[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R020[i]<< " ";
myfile<<"\n";

myfile<<"\n";}
