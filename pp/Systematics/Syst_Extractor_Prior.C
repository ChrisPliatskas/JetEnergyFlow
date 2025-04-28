void Syst_Extractor_Prior(TString fname1 = "analysisResults.root",TString fname2 = "analysisResults.root",int ptlow=40, int pthigh=60){


TFile*f_syst_prior1 = TFile::Open(fname1.Data());

TH1D* sys_R005_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R005");

TH1D* sys_R010_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R010");

TH1D* sys_R015_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R015");

TH1D* sys_R020_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R020");

TH1D* sys_R025_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R025");

TH1D* sys_R030_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R030");

TH1D* sys_R035_prior1 = (TH1D*) f_syst_prior1->Get("Systematic_Ratio_R025");

Int_t Nbins = sys_R005_prior1->GetNbinsX();

TFile*f_syst_prior2 = TFile::Open(fname2.Data());

TH1D* sys_R005_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R005");

TH1D* sys_R010_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R010");

TH1D* sys_R015_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R015");

TH1D* sys_R020_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R020");

TH1D* sys_R025_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R025");

TH1D* sys_R030_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R030");

TH1D* sys_R035_prior2 = (TH1D*) f_syst_prior2->Get("Systematic_Ratio_R025");


 double prior1_R005[11] = {}; double prior1_R010[11] = {}; double prior1_R015[11] = {};
 double prior1_R020[11] = {}; double prior1_R025[11] = {}; double prior1_R030[11] = {};
 double prior1_R035[11] = {};


 for(int i=1;i<=Nbins;i++){
        prior1_R005[i-1] =  100*sys_R005_prior1->GetBinContent(i);
        prior1_R010[i-1] =  100*sys_R010_prior1->GetBinContent(i);
        prior1_R015[i-1] =  100*sys_R015_prior1->GetBinContent(i);
        prior1_R020[i-1] =  100*sys_R020_prior1->GetBinContent(i);
        prior1_R025[i-1] =  100*sys_R025_prior1->GetBinContent(i);
        prior1_R030[i-1] =  100*sys_R030_prior1->GetBinContent(i);
        prior1_R035[i-1] =  100*sys_R035_prior1->GetBinContent(i);
        }

 double prior2_R005[11] = {}; double prior2_R010[11] = {}; double prior2_R015[11] = {};
 double prior2_R020[11] = {}; double prior2_R025[11] = {}; double prior2_R030[11] = {};
 double prior2_R035[11] = {}; 


 for(int i=1;i<=Nbins;i++){
        prior2_R005[i-1] =  100*sys_R005_prior2->GetBinContent(i);
        prior2_R010[i-1] =  100*sys_R010_prior2->GetBinContent(i);
        prior2_R015[i-1] =  100*sys_R015_prior2->GetBinContent(i);
        prior2_R020[i-1] =  100*sys_R020_prior2->GetBinContent(i);
        prior2_R025[i-1] =  100*sys_R025_prior2->GetBinContent(i);
        prior2_R030[i-1] =  100*sys_R030_prior2->GetBinContent(i);
        prior2_R035[i-1] =  100*sys_R035_prior2->GetBinContent(i);
        }

 double diff_R005[11] = {}; double diff_R010[11] = {}; double diff_R015[11] = {};
 double diff_R020[11] = {}; double diff_R025[11] = {}; double diff_R030[11] = {};
 double diff_R035[11] = {};

 for(int i=1;i<=Nbins;i++){
        diff_R005[i-1] = abs(prior2_R005[i-1]- prior1_R005[i-1])/2;
        diff_R010[i-1] = abs(prior2_R010[i-1]- prior1_R010[i-1])/2;
        diff_R015[i-1] = abs(prior2_R015[i-1]- prior1_R015[i-1])/2;
        diff_R020[i-1] = abs(prior2_R020[i-1]- prior1_R020[i-1])/2;
        diff_R025[i-1] = abs(prior2_R025[i-1]- prior1_R025[i-1])/2;
        diff_R030[i-1] = abs(prior2_R030[i-1]- prior1_R030[i-1])/2;
        diff_R035[i-1] = abs(prior2_R035[i-1]- prior1_R035[i-1])/2;
}



ofstream myfile;
myfile.open (Form("Prior_values_pp_%d_%d.txt",ptlow,pthigh));
myfile<<"#Deltap_{T} bins: [-1.5,1.5] [1.5,4.5] [4.5,7.5] [7.5,10.5] [10.5,13.5] [13.5,16.5] [16.5,19.5] [19.5,22.5] [22.5,25.5][28.5,28.5][28.5,31.5] \n";
myfile <<"R=0.05 to R=0.1 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R005[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R005[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R005[i]<< " ";
myfile<<"\n";
myfile <<"R=0.1 to R=0.15 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R010[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R010[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R010[i]<< " ";
myfile<<"\n";

myfile <<"R=0.15 to R=0.2 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R015[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R015[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R015[i]<< " ";
myfile<<"\n";

myfile <<"R=0.2 to R=0.25 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R020[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R020[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R020[i]<< " ";
myfile<<"\n";

myfile <<"R=0.25 to R=0.3 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R025[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R025[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R025[i]<< " ";
myfile<<"\n";

myfile <<"R=0.3 to R=0.35 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R030[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R030[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R030[i]<< " ";
myfile<<"\n";

myfile <<"R=0.35 to R=0.4 \n";
myfile <<"Steeper prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior1_R035[i]<< " ";
myfile<<"\n";
myfile <<"Flatter prior \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<prior2_R035[i]<< " ";
myfile<<"\n";
myfile <<"Difference \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<diff_R035[i]<< " ";
myfile<<"\n";
myfile<<"\n";}
