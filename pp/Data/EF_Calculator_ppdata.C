void SetStyle(TH1*h1,int Color);
void EF_Calculator_ppdata(const char* finput, int Ptlow, int Pthigh, int sqrts){

        //Open the file and retrieve the general list of the histograms
        TFile* f_input;
        f_input= TFile::Open(finput);
        AliEmcalList*ali;
        f_input->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_ppdata_smallR_ppdata_histos",ali);

        //Retrieving the DelatR histograms (2D)
        TH2D* hDR005 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R005_0"));
        TH2D* hDR010 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R010_0"));
        TH2D* hDR015 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R015_0"));
        TH2D* hDR020 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R020_0"));
        TH2D* hDR025 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R025_0"));
        TH2D* hDR030 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R030_0"));
        TH2D* hDR035 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R035_0"));

        //Retrieving the Dpt histograms (2D)
        TH2D* hDptR005 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R005_0"));
        TH2D* hDptR010 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R010_0"));
        TH2D* hDptR015 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R015_0"));
        TH2D* hDptR020 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R020_0"));
        TH2D* hDptR025 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R025_0"));
        TH2D* hDptR030 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R030_0"));
        TH2D* hDptR035 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R035_0"));

        //Retrieving the small Dpt histograms (2D)
        TH2D* hDptR005_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R005_0"));
        TH2D* hDptR010_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R010_0"));
        TH2D* hDptR015_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R015_0"));
        TH2D* hDptR020_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R020_0"));
        TH2D* hDptR025_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R025_0"));
        TH2D* hDptR030_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R030_0"));
        TH2D* hDptR035_small = (TH2D*)(ali->FindObject("hJetPtSmallDeltaPt_R035_0"));

       int Ptlow_bin =hDR010->GetXaxis()->FindBin(Ptlow);
       int Pthigh_bin = hDR010->GetXaxis()->FindBin(Pthigh)-1;

        //Retrieving the matched jet spectra
        //------------pt---------------------//
        TH1D* hJetPtMatched_R005 = (TH1D*)(ali->FindObject("hMatchedJetPt_R005_0"));
        TH1D* hJetPtMatched_R010 = (TH1D*)(ali->FindObject("hMatchedJetPt_R010_0"));
        TH1D* hJetPtMatched_R015 = (TH1D*)(ali->FindObject("hMatchedJetPt_R015_0"));
        TH1D* hJetPtMatched_R020 = (TH1D*)(ali->FindObject("hMatchedJetPt_R020_0"));
        TH1D* hJetPtMatched_R025 = (TH1D*)(ali->FindObject("hMatchedJetPt_R025_0"));
        TH1D* hJetPtMatched_R030 = (TH1D*)(ali->FindObject("hMatchedJetPt_R030_0"));
        TH1D* hJetPtMatched_R035 = (TH1D*)(ali->FindObject("hMatchedJetPt_R035_0"));
        TH1D* hJetPtMatched_R040 = (TH1D*)(ali->FindObject("hMatchedJetPt_R040_0"));

        //------------eta--------------------//
        TH1D* hJetEtaMatched_R005 = (TH1D*)(ali->FindObject("hMatchedJetEta_R005_0"));
        TH1D* hJetEtaMatched_R010 = (TH1D*)(ali->FindObject("hMatchedJetEta_R010_0"));
        TH1D* hJetEtaMatched_R015 = (TH1D*)(ali->FindObject("hMatchedJetEta_R015_0"));
        TH1D* hJetEtaMatched_R020 = (TH1D*)(ali->FindObject("hMatchedJetEta_R020_0"));
        TH1D* hJetEtaMatched_R025 = (TH1D*)(ali->FindObject("hMatchedJetEta_R025_0"));
        TH1D* hJetEtaMatched_R030 = (TH1D*)(ali->FindObject("hMatchedJetEta_R030_0"));
        TH1D* hJetEtaMatched_R035 = (TH1D*)(ali->FindObject("hMatchedJetEta_R035_0"));
        TH1D* hJetEtaMatched_R040 = (TH1D*)(ali->FindObject("hMatchedJetEta_R040_0"));

        //Calculate the DR projections
        TH1D*pro_dR_R005; TH1D*pro_dR_R010; TH1D*pro_dR_R015;TH1D*pro_dR_R020;
        TH1D*pro_dR_R025; TH1D*pro_dR_R030; TH1D*pro_dR_R035;

        pro_dR_R005 = hDR005->ProjectionY("pro_dR_R005",Ptlow_bin,Pthigh_bin);
        pro_dR_R010 = hDR010->ProjectionY("pro_dR_R010",Ptlow_bin,Pthigh_bin);
        pro_dR_R015 = hDR015->ProjectionY("pro_dR_R015",Ptlow_bin,Pthigh_bin);
        pro_dR_R020 = hDR020->ProjectionY("pro_dR_R020",Ptlow_bin,Pthigh_bin);
        pro_dR_R025 = hDR025->ProjectionY("pro_dR_R025",Ptlow_bin,Pthigh_bin);
        pro_dR_R030 = hDR030->ProjectionY("pro_dR_R030",Ptlow_bin,Pthigh_bin);
        pro_dR_R035 = hDR035->ProjectionY("pro_dR_R035",Ptlow_bin,Pthigh_bin);


        pro_dR_R005->Scale(1./pro_dR_R005->Integral("width"));
        pro_dR_R010->Scale(1./pro_dR_R010->Integral("width"));
        pro_dR_R015->Scale(1./pro_dR_R015->Integral("width"));
        pro_dR_R020->Scale(1./pro_dR_R020->Integral("width")); 
        pro_dR_R025->Scale(1./pro_dR_R025->Integral("width"));
        pro_dR_R030->Scale(1./pro_dR_R030->Integral("width"));
        pro_dR_R035->Scale(1./pro_dR_R035->Integral("width"));

       //Calculate the Dpt projections
        TH1D*pro_dpt_R005; TH1D*pro_dpt_R010; TH1D*pro_dpt_R015;TH1D*pro_dpt_R020;
        TH1D*pro_dpt_R025; TH1D*pro_dpt_R030; TH1D*pro_dpt_R035;

        int Dpt_low_bin = hDptR005->GetYaxis()->FindBin(0.);
        int Dpt_high_bin = hDptR005->GetYaxis()->FindBin(25.);

        hDptR005->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR010->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR015->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR020->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR025->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR030->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR035->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);

        pro_dpt_R005=hDptR005->ProjectionY("pro_dpt_R005",Ptlow_bin,Pthigh_bin);
        pro_dpt_R010=hDptR010->ProjectionY("pro_dpt_R010",Ptlow_bin,Pthigh_bin);
        pro_dpt_R015=hDptR015->ProjectionY("pro_dpt_R015",Ptlow_bin,Pthigh_bin);
        pro_dpt_R020=hDptR020->ProjectionY("pro_dpt_R020",Ptlow_bin,Pthigh_bin);
        pro_dpt_R025=hDptR025->ProjectionY("pro_dpt_R025",Ptlow_bin,Pthigh_bin);
        pro_dpt_R030=hDptR030->ProjectionY("pro_dpt_R030",Ptlow_bin,Pthigh_bin);
        pro_dpt_R035=hDptR035->ProjectionY("pro_dpt_R035",Ptlow_bin,Pthigh_bin);

        pro_dpt_R005->Scale(1./pro_dpt_R005->Integral("width"));
        pro_dpt_R010->Scale(1./pro_dpt_R010->Integral("width"));
        pro_dpt_R015->Scale(1./pro_dpt_R015->Integral("width"));
        pro_dpt_R020->Scale(1./pro_dpt_R020->Integral("width"));
        pro_dpt_R025->Scale(1./pro_dpt_R025->Integral("width"));
        pro_dpt_R030->Scale(1./pro_dpt_R030->Integral("width"));
        pro_dpt_R035->Scale(1./pro_dpt_R035->Integral("width"));


       //Calculate the Dpt projections(small)
        TH1D*pro_dpt_R005_small; TH1D*pro_dpt_R010_small; TH1D*pro_dpt_R015_small;
        TH1D*pro_dpt_R020_small; TH1D*pro_dpt_R025_small; TH1D*pro_dpt_R030_small;
        TH1D*pro_dpt_R035_small;

        pro_dpt_R005_small=hDptR005_small->ProjectionY("pro_dpt_R005_small",Ptlow_bin,Pthigh_bin);
        pro_dpt_R010_small=hDptR010_small->ProjectionY("pro_dpt_R010_small",Ptlow_bin,Pthigh_bin);
        pro_dpt_R015_small=hDptR015_small->ProjectionY("pro_dpt_R015_small",Ptlow_bin,Pthigh_bin);
        pro_dpt_R020_small=hDptR020_small->ProjectionY("pro_dpt_R020_small",Ptlow_bin,Pthigh_bin);
        pro_dpt_R025_small=hDptR025_small->ProjectionY("pro_dpt_R025_small",Ptlow_bin,Pthigh_bin);
        pro_dpt_R030_small=hDptR030_small->ProjectionY("pro_dpt_R030_small",Ptlow_bin,Pthigh_bin);
        pro_dpt_R035_small=hDptR035_small->ProjectionY("pro_dpt_R035_small",Ptlow_bin,Pthigh_bin);



        pro_dR_R005->SetTitle(TString::Format("#DeltaR between R=0.05 and R=0.1 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R010->SetTitle(TString::Format("#DeltaR between R=0.1 and R=0.15 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R015->SetTitle(TString::Format("#DeltaR between R=0.15 and R=0.2 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R020->SetTitle(TString::Format("#DeltaR between R=0.2 and R=0.25 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R025->SetTitle(TString::Format("#DeltaR between R=0.25 and R=0.3 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R030->SetTitle(TString::Format("#DeltaR between R=0.3 and R=0.35 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R035->SetTitle(TString::Format("#DeltaR between R=0.35 and R=0.4 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));

        pro_dpt_R005->SetTitle(TString::Format("#Deltap_{T} between R=0.05 and R=0.1 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R010->SetTitle(TString::Format("#Deltap_{T} between R=0.1 and R=0.15 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R015->SetTitle(TString::Format("#Deltap_{T} between R=0.15 and R=0.2 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R020->SetTitle(TString::Format("#Deltap_{T} between R=0.2 and R=0.25 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R025->SetTitle(TString::Format("#Deltap_{T} between R=0.25 and R=0.3 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R030->SetTitle(TString::Format("#Deltap_{T} between R=0.3 and R=0.35 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R035->SetTitle(TString::Format("#Deltap_{T} between R=0.35 and R=0.4 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));

        //Extract the mean and RMS graphs
Double_t R[7] = {.05,.1,.15,.2,.25,.3,.35};
Double_t R_err[7] = {0.,0.,0.,0.,0.,0.,0.};
Double_t mean[7] ={pro_dpt_R005->GetMean(),pro_dpt_R010->GetMean(),pro_dpt_R015->GetMean(),pro_dpt_R020->GetMean(),pro_dpt_R025->GetMean(),pro_dpt_R030->GetMean(),pro_dpt_R035->GetMean()};
Double_t mean_err[7] ={pro_dpt_R005->GetMeanError(),pro_dpt_R010->GetMeanError(),pro_dpt_R015->GetMeanError(),pro_dpt_R020->GetMeanError(),pro_dpt_R025->GetMeanError(),pro_dpt_R030->GetMeanError(),pro_dpt_R035->GetMeanError()};

Double_t rms[7] ={pro_dpt_R005->GetRMS(),pro_dpt_R010->GetRMS(),pro_dpt_R015->GetRMS(),pro_dpt_R020->GetRMS(),pro_dpt_R025->GetRMS(),pro_dpt_R030->GetRMS(),pro_dpt_R035->GetRMS()};
Double_t rms_err[7] ={pro_dpt_R005->GetRMSError(),pro_dpt_R010->GetRMSError(),pro_dpt_R015->GetRMSError(),pro_dpt_R020->GetRMSError(),pro_dpt_R025->GetRMSError(),pro_dpt_R030->GetRMSError(),pro_dpt_R035->GetRMSError()};

 auto Mean_gr = new TGraphErrors(7,R,mean,R_err,mean_err);
        Mean_gr->SetMarkerSize(3);
        Mean_gr->SetFillStyle(3001);
        Mean_gr->SetLineWidth(2);
Mean_gr->SetTitle(TString::Format("Mean of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; Mean value",Ptlow,Pthigh));

 auto RMS_gr = new TGraphErrors(7,R,rms,R_err,rms_err);
        RMS_gr->SetMarkerSize(3);
        RMS_gr->SetFillStyle(3001);
RMS_gr->SetTitle(TString::Format("Width of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; #sigma_{#Deltap_{T}}",Ptlow,Pthigh));

        //Draw style options
        const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
        const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
        const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

        SetStyle(hJetPtMatched_R005,colors[0]); SetStyle(hJetPtMatched_R010,colors[1]);
        SetStyle(hJetPtMatched_R015,colors[2]); SetStyle(hJetPtMatched_R020,colors[3]);
        SetStyle(hJetPtMatched_R025,colors[4]); SetStyle(hJetPtMatched_R030,colors[5]);
        SetStyle(hJetPtMatched_R035,colors[6]); SetStyle(hJetPtMatched_R040,colors[7]);

        SetStyle(hJetEtaMatched_R005,colors[0]); SetStyle(hJetEtaMatched_R010,colors[1]);
        SetStyle(hJetEtaMatched_R015,colors[2]); SetStyle(hJetEtaMatched_R020,colors[3]);
        SetStyle(hJetEtaMatched_R025,colors[4]); SetStyle(hJetEtaMatched_R030,colors[5]);
        SetStyle(hJetEtaMatched_R035,colors[6]); SetStyle(hJetEtaMatched_R040,colors[7]);

        SetStyle(pro_dR_R005,colors[0]); SetStyle(pro_dR_R010,colors[1]);
        SetStyle(pro_dR_R015,colors[2]); SetStyle(pro_dR_R020,colors[3]);
        SetStyle(pro_dR_R025,colors[4]); SetStyle(pro_dR_R030,colors[5]);
        SetStyle(pro_dR_R035,colors[6]);


        SetStyle(pro_dpt_R005,colors[0]); SetStyle(pro_dpt_R010,colors[1]);
        SetStyle(pro_dpt_R015,colors[2]); SetStyle(pro_dpt_R020,colors[3]);
        SetStyle(pro_dpt_R025,colors[4]); SetStyle(pro_dpt_R030,colors[5]);
        SetStyle(pro_dpt_R035,colors[6]);

        SetStyle(pro_dpt_R005_small,colors[0]); SetStyle(pro_dpt_R010_small,colors[1]);
        SetStyle(pro_dpt_R015_small,colors[2]); SetStyle(pro_dpt_R020_small,colors[3]);
        SetStyle(pro_dpt_R025_small,colors[4]); SetStyle(pro_dpt_R030_small,colors[5]);
        SetStyle(pro_dpt_R035_small,colors[6]);



        Mean_gr->SetLineColor(colors[0]);Mean_gr->SetMarkerColor(colors[0]);
        Mean_gr->SetMarkerStyle(markers[4]);
        RMS_gr->SetLineColor(colors[0]);RMS_gr->SetMarkerColor(colors[0]);
        RMS_gr->SetMarkerStyle(markers[4]);


        //Saving section
TFile*fout = new TFile(TString::Format("EF_ppdata_%dTeV_pt_%d_%d.root",sqrts,Ptlow,Pthigh),"RECREATE",TString::Format("EF_ppdata_%dTeV_pt_%d_%d.root",Ptlow,Pthigh,sqrts));


hJetPtMatched_R005->Write("hJetPtMatched_R005",TObject::kOverwrite);hJetPtMatched_R010->Write("hJetPtMatched_R010",TObject::kOverwrite);
hJetPtMatched_R015->Write("hJetPtMatched_R015",TObject::kOverwrite);hJetPtMatched_R020->Write("hJetPtMatched_R020",TObject::kOverwrite);
hJetPtMatched_R025->Write("hJetPtMatched_R025",TObject::kOverwrite);hJetPtMatched_R030->Write("hJetPtMatched_R030",TObject::kOverwrite);
hJetPtMatched_R035->Write("hJetPtMatched_R035",TObject::kOverwrite);hJetPtMatched_R040->Write("hJetPtMatched_R040",TObject::kOverwrite);

hJetEtaMatched_R005->Write("hJetEtaMatched_R005",TObject::kOverwrite);hJetEtaMatched_R010->Write("hJetEtaMatched_R010",TObject::kOverwrite);
hJetEtaMatched_R015->Write("hJetEtaMatched_R015",TObject::kOverwrite);hJetEtaMatched_R020->Write("hJetEtaMatched_R020",TObject::kOverwrite);
hJetEtaMatched_R025->Write("hJetEtaMatched_R025",TObject::kOverwrite);hJetEtaMatched_R030->Write("hJetEtaMatched_R030",TObject::kOverwrite);
hJetEtaMatched_R035->Write("hJetEtaMatched_R035",TObject::kOverwrite);hJetEtaMatched_R040->Write("hJetEtaMatched_R040",TObject::kOverwrite);

pro_dpt_R005->Write("pro_dpt_R005",TObject::kOverwrite);pro_dpt_R010->Write("pro_dpt_R010",TObject::kOverwrite);
pro_dpt_R015->Write("pro_dpt_R015",TObject::kOverwrite);pro_dpt_R020->Write("pro_dpt_R020",TObject::kOverwrite);
pro_dpt_R025->Write("pro_dpt_R025",TObject::kOverwrite);pro_dpt_R030->Write("pro_dpt_R030",TObject::kOverwrite);
pro_dpt_R035->Write("pro_dpt_R035",TObject::kOverwrite);

pro_dR_R005->Write("pro_dR_R005",TObject::kOverwrite);pro_dR_R010->Write("pro_dR_R010",TObject::kOverwrite);
pro_dR_R015->Write("pro_dR_R015",TObject::kOverwrite);pro_dR_R020->Write("pro_dR_R020",TObject::kOverwrite);
pro_dR_R025->Write("pro_dR_R025",TObject::kOverwrite);pro_dR_R030->Write("pro_dR_R030",TObject::kOverwrite);
pro_dR_R035->Write("pro_dR_R035",TObject::kOverwrite);

pro_dpt_R005_small->Write("pro_dpt_R005_small",TObject::kOverwrite);
pro_dpt_R010_small->Write("pro_dpt_R010_small",TObject::kOverwrite);
pro_dpt_R015_small->Write("pro_dpt_R015_small",TObject::kOverwrite);
pro_dpt_R020_small->Write("pro_dpt_R020_small",TObject::kOverwrite);
pro_dpt_R025_small->Write("pro_dpt_R025_small",TObject::kOverwrite);
pro_dpt_R030_small->Write("pro_dpt_R030_small",TObject::kOverwrite);
pro_dpt_R035_small->Write("pro_dpt_R035_small",TObject::kOverwrite);


Mean_gr->Write(Form("Mean_gr_%d_%d",Ptlow,Pthigh),TObject::kOverwrite);
RMS_gr->Write(Form("RMS_gr_%d_%d",Ptlow,Pthigh),TObject::kOverwrite);
fout->Write();

}

void SetStyle(TH1* h1, int kColor){

                  h1->SetLineWidth(2); h1->SetLineColor(kColor);
                  h1->SetMarkerSize(3); h1->SetMarkerColor(kColor);
                  if(kColor<=4)h1->SetMarkerStyle(kFullDiamond);
                  else h1->SetMarkerStyle(kFullDiamond);
                 }
