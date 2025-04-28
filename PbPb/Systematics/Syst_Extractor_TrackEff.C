void Syst_Extractor_TrackEff(TString fname = "analysisResults.root",int ptlow=60, int pthigh=80){


TFile*f_syst = TFile::Open(fname.Data());

TH1D* sys_R005 = (TH1D*) f_syst->Get("Systematic_Ratio_R005");

TH1D* sys_R010 = (TH1D*) f_syst->Get("Systematic_Ratio_R010");

TH1D* sys_R015 = (TH1D*) f_syst->Get("Systematic_Ratio_R015");

TH1D* sys_R020 = (TH1D*) f_syst->Get("Systematic_Ratio_R020");

Int_t Nbins = sys_R005->GetNbinsX();


 double TrackEff_R005[11] = {}; double TrackEff_R010[11] = {}; double TrackEff_R015[11] = {};
 double TrackEff_R020[11] = {}; 


 for(int i=1;i<=Nbins;i++){
        TrackEff_R005[i-1] =  100*sys_R005->GetBinContent(i);
        TrackEff_R010[i-1] =  100*sys_R010->GetBinContent(i);
        TrackEff_R015[i-1] =  100*sys_R015->GetBinContent(i);
        TrackEff_R020[i-1] =  100*sys_R020->GetBinContent(i);
        }

ofstream myfile;
myfile.open (Form("Track_Eff_values_PbPb_%d_%d.txt",ptlow,pthigh));
myfile<<"#Deltap_{T} bins: [-1.5,1.5] [1.5,4.5] [4.5,7.5] [7.5,10.5] [10.5,13.5] [13.5,16.5] [16.5,19.5] [19.5,22.5] [22.5,25.5][28.5,28.5][28.5,31.5] \n";
myfile <<"R=0.05 to R=0.1 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<TrackEff_R005[i]<< " ";
myfile<<"\n";
myfile <<"R=0.1 to R=0.15 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<TrackEff_R010[i]<< " ";
myfile<<"\n";
myfile <<"R=0.15 to R=0.2 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<TrackEff_R015[i]<< " ";
  myfile<<"\n";
myfile <<"R=0.2 to R=0.25 \n";
for(int i=0;i<Nbins;i++) myfile<<" "<<TrackEff_R020[i]<< " ";
myfile<<"\n";}
