void SetStyle(TH1*h1,int Color);

void EF_Calculator_ppMC(const char* finput, int Ptlow, int Pthigh, int sqrts){

//Open the file and retrieve the general list of the histograms
 TFile* f_input;
 f_input= TFile::Open(finput);
 AliEmcalList*ali;
 f_input->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_ppMC_GenDet_histos",ali);

        //Retrieving the DelatR histograms (2D) - Detector level
        TH2D* hDR005 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R005_0")); TH2D* hDR010 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R010_0"));
        TH2D* hDR015 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R015_0")); TH2D* hDR020 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R020_0"));
        TH2D* hDR025 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R025_0")); TH2D* hDR030 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R030_0"));
        TH2D* hDR035 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R035_0"));

        // Generator level
        TH2D* hDR005_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R005_gen_0")); TH2D* hDR010_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R010_gen_0"));
        TH2D* hDR015_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R015_gen_0")); TH2D* hDR020_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R020_gen_0"));
        TH2D* hDR025_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R025_gen_0")); TH2D* hDR030_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R030_gen_0"));
        TH2D* hDR035_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaR_R035_gen_0"));

        //Retrieving the Dpt histograms (2D)- Detector level
        TH2D* hDptR005 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R005_0")); TH2D* hDptR010 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R010_0"));
        TH2D* hDptR015 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R015_0")); TH2D* hDptR020 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R020_0"));
        TH2D* hDptR025 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R025_0")); TH2D* hDptR030 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R030_0"));
        TH2D* hDptR035 = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R035_0"));
        // Generator level
        TH2D* hDptR005_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R005_gen_0")); TH2D* hDptR010_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R010_gen_0"));
        TH2D* hDptR015_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R015_gen_0")); TH2D* hDptR020_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R020_gen_0"));
        TH2D* hDptR025_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R025_gen_0")); TH2D* hDptR030_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R030_gen_0"));
        TH2D* hDptR035_gen = static_cast<TH2D*>(ali->FindObject("hJetPtDeltaPt_R035_gen_0"));


       int Ptlow_bin =hDR010->GetXaxis()->FindBin(Ptlow);
       int Pthigh_bin = hDR010->GetXaxis()->FindBin(Pthigh);
        //Retrieving the matched jet spectra- Detector level
        TH1D* hJetPtMatched_R005 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R005_0")); TH1D* hJetPtMatched_R010 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R010_0"));
        TH1D* hJetPtMatched_R015 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R015_0")); TH1D* hJetPtMatched_R020 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R020_0"));
        TH1D* hJetPtMatched_R025 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R025_0")); TH1D* hJetPtMatched_R030 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R030_0"));
        TH1D* hJetPtMatched_R035 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R035_0")); TH1D* hJetPtMatched_R040 = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R040_0"));

        TH1D* hJetEtaMatched_R005 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R005_0")); TH1D* hJetEtaMatched_R010 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R010_0"));
        TH1D* hJetEtaMatched_R015 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R015_0")); TH1D* hJetEtaMatched_R020 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R020_0"));
        TH1D* hJetEtaMatched_R025 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R025_0")); TH1D* hJetEtaMatched_R030 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R030_0"));
        TH1D* hJetEtaMatched_R035 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R035_0")); TH1D* hJetEtaMatched_R040 = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R040_0"));
        //Generator level
        TH1D* hJetPtMatched_R005_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R005_gen_0")); TH1D* hJetPtMatched_R010_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R010_gen_0"));
        TH1D* hJetPtMatched_R015_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R015_gen_0")); TH1D* hJetPtMatched_R020_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R020_gen_0"));
        TH1D* hJetPtMatched_R025_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R025_gen_0")); TH1D* hJetPtMatched_R030_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R030_gen_0"));
        TH1D* hJetPtMatched_R035_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R035_gen_0")); TH1D* hJetPtMatched_R040_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetPt_R040_gen_0"));

        TH1D* hJetEtaMatched_R005_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R005_gen_0")); TH1D* hJetEtaMatched_R010_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R010_gen_0"));
        TH1D* hJetEtaMatched_R015_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R015_gen_0")); TH1D* hJetEtaMatched_R020_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R020_gen_0"));
        TH1D* hJetEtaMatched_R025_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R025_gen_0")); TH1D* hJetEtaMatched_R030_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R030_gen_0"));
        TH1D* hJetEtaMatched_R035_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R035_gen_0")); TH1D* hJetEtaMatched_R040_gen = static_cast<TH1D*>(ali->FindObject("hMatchedJetEta_R040_gen_0"));


        //Calculate the DR projections
                //Detector level
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
                //Truth level
        TH1D*pro_dR_R005_gen; TH1D*pro_dR_R010_gen; TH1D*pro_dR_R015_gen;TH1D*pro_dR_R020_gen;
        TH1D*pro_dR_R025_gen; TH1D*pro_dR_R030_gen; TH1D*pro_dR_R035_gen;

        pro_dR_R005_gen = hDR005_gen->ProjectionY("pro_dR_R005_gen",Ptlow_bin,Pthigh_bin);
        pro_dR_R010_gen = hDR010_gen->ProjectionY("pro_dR_R010_gen",Ptlow_bin,Pthigh_bin);
        pro_dR_R015_gen = hDR015_gen->ProjectionY("pro_dR_R015_gen",Ptlow_bin,Pthigh_bin);
        pro_dR_R020_gen = hDR020_gen->ProjectionY("pro_dR_R020_gen",Ptlow_bin,Pthigh_bin);
        pro_dR_R025_gen = hDR025_gen->ProjectionY("pro_dR_R025_gen",Ptlow_bin,Pthigh_bin);
        pro_dR_R030_gen = hDR030_gen->ProjectionY("pro_dR_R030_gen",Ptlow_bin,Pthigh_bin);
        pro_dR_R035_gen = hDR035_gen->ProjectionY("pro_dR_R035_gen",Ptlow_bin,Pthigh_bin);


        pro_dR_R005_gen->Scale(1./pro_dR_R005_gen->Integral("width"));
        pro_dR_R010_gen->Scale(1./pro_dR_R010_gen->Integral("width"));
        pro_dR_R015_gen->Scale(1./pro_dR_R015_gen->Integral("width"));
        pro_dR_R020_gen->Scale(1./pro_dR_R020_gen->Integral("width"));
        pro_dR_R025_gen->Scale(1./pro_dR_R025_gen->Integral("width"));
        pro_dR_R030_gen->Scale(1./pro_dR_R030_gen->Integral("width"));
        pro_dR_R035_gen->Scale(1./pro_dR_R035_gen->Integral("width"));

       //Calculate the Dpt projections
                //Detector level
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
        
                //Truth level
        TH1D*pro_dpt_R005_gen; TH1D*pro_dpt_R010_gen; TH1D*pro_dpt_R015_gen;TH1D*pro_dpt_R020_gen;
        TH1D*pro_dpt_R025_gen; TH1D*pro_dpt_R030_gen; TH1D*pro_dpt_R035_gen;

        pro_dpt_R005_gen = hDptR005_gen->ProjectionY("pro_dpt_R005_gen",Ptlow_bin,Pthigh_bin);
        pro_dpt_R010_gen = hDptR010_gen->ProjectionY("pro_dpt_R010_gen",Ptlow_bin,Pthigh_bin);
        pro_dpt_R015_gen = hDptR015_gen->ProjectionY("pro_dpt_R015_gen",Ptlow_bin,Pthigh_bin);
        pro_dpt_R020_gen = hDptR020_gen->ProjectionY("pro_dpt_R020_gen",Ptlow_bin,Pthigh_bin);
        pro_dpt_R025_gen = hDptR025_gen->ProjectionY("pro_dpt_R025_gen",Ptlow_bin,Pthigh_bin);
        pro_dpt_R030_gen = hDptR030_gen->ProjectionY("pro_dpt_R030_gen",Ptlow_bin,Pthigh_bin);
        pro_dpt_R035_gen = hDptR035_gen->ProjectionY("pro_dpt_R035_gen",Ptlow_bin,Pthigh_bin);


        pro_dpt_R005_gen->Scale(1./pro_dpt_R005_gen->Integral("width"));
        pro_dpt_R010_gen->Scale(1./pro_dpt_R010_gen->Integral("width"));
        pro_dpt_R015_gen->Scale(1./pro_dpt_R015_gen->Integral("width"));
        pro_dpt_R020_gen->Scale(1./pro_dpt_R020_gen->Integral("width"));
        pro_dpt_R025_gen->Scale(1./pro_dpt_R025_gen->Integral("width"));
        pro_dpt_R030_gen->Scale(1./pro_dpt_R030_gen->Integral("width"));
        pro_dpt_R035_gen->Scale(1./pro_dpt_R035_gen->Integral("width"));

        //Extract the mean and RMS graphs
Double_t R[7] = {.05,.1,.15,.2,.25,.3,.35};
Double_t R_err[7] = {0.,0.,0.,0.,0.,0.,0.};
        //Detector level
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


        //Truth level
Double_t mean_gen[7] ={pro_dpt_R005_gen->GetMean(),pro_dpt_R010_gen->GetMean(),pro_dpt_R015_gen->GetMean(),pro_dpt_R020_gen->GetMean(),pro_dpt_R025_gen->GetMean(),pro_dpt_R030_gen->GetMean(),pro_dpt_R035_gen->GetMean()};
Double_t mean_err_gen[7] ={pro_dpt_R005_gen->GetMeanError(),pro_dpt_R010_gen->GetMeanError(),pro_dpt_R015_gen->GetMeanError(),pro_dpt_R020_gen->GetMeanError(),pro_dpt_R025_gen->GetMeanError(),pro_dpt_R030_gen->GetMeanError(),pro_dpt_R035_gen->GetMeanError()};

Double_t rms_gen[7] ={pro_dpt_R005_gen->GetRMS(),pro_dpt_R010_gen->GetRMS(),pro_dpt_R015_gen->GetRMS(),pro_dpt_R020_gen->GetRMS(),pro_dpt_R025_gen->GetRMS(),pro_dpt_R030_gen->GetRMS(),pro_dpt_R035_gen->GetRMS()};
Double_t rms_err_gen[7] ={pro_dpt_R005_gen->GetRMSError(),pro_dpt_R010_gen->GetRMSError(),pro_dpt_R015_gen->GetRMSError(),pro_dpt_R020_gen->GetRMSError(),pro_dpt_R025_gen->GetRMSError(),pro_dpt_R030_gen->GetRMSError(),pro_dpt_R035_gen->GetRMSError()};

 auto Mean_gr_gen = new TGraphErrors(7,R,mean_gen,R_err,mean_err_gen);
        Mean_gr_gen->SetMarkerSize(3);
        Mean_gr_gen->SetFillStyle(3001);
        Mean_gr_gen->SetLineWidth(2);
Mean_gr_gen->SetTitle(TString::Format("Mean of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; Mean value",Ptlow,Pthigh));

 auto RMS_gr_gen = new TGraphErrors(7,R,rms,R_err,rms_err);
        RMS_gr_gen->SetMarkerSize(3);
        RMS_gr_gen->SetFillStyle(3001);
RMS_gr_gen->SetTitle(TString::Format("Width of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; #sigma_{#Deltap_{T}}",Ptlow,Pthigh));


        //Draw style options
        const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
        const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
        const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};


        SetStyle(hJetPtMatched_R005,colors[0]); SetStyle(hJetPtMatched_R010,colors[1]);
        SetStyle(hJetPtMatched_R015,colors[2]); SetStyle(hJetPtMatched_R020,colors[3]);
        SetStyle(hJetPtMatched_R025,colors[4]); SetStyle(hJetPtMatched_R030,colors[5]);
        SetStyle(hJetPtMatched_R035,colors[6]); SetStyle(hJetPtMatched_R040,colors[7]);

        SetStyle(hJetPtMatched_R005_gen,colors[0]); SetStyle(hJetPtMatched_R010_gen,colors[1]);
        SetStyle(hJetPtMatched_R015_gen,colors[2]); SetStyle(hJetPtMatched_R020_gen,colors[3]);
        SetStyle(hJetPtMatched_R025_gen,colors[4]); SetStyle(hJetPtMatched_R030_gen,colors[5]);
        SetStyle(hJetPtMatched_R035_gen,colors[6]); SetStyle(hJetPtMatched_R040_gen,colors[7]);

        SetStyle(pro_dR_R005,colors[0]); SetStyle(pro_dR_R010,colors[1]);
        SetStyle(pro_dR_R015,colors[2]); SetStyle(pro_dR_R020,colors[3]);
        SetStyle(pro_dR_R025,colors[4]); SetStyle(pro_dR_R030,colors[5]);
        SetStyle(pro_dR_R035,colors[6]);

        SetStyle(pro_dR_R005_gen,colors[0]); SetStyle(pro_dR_R010_gen,colors[1]);
        SetStyle(pro_dR_R015_gen,colors[2]); SetStyle(pro_dR_R020_gen,colors[3]);
        SetStyle(pro_dR_R025_gen,colors[4]); SetStyle(pro_dR_R030_gen,colors[5]);
        SetStyle(pro_dR_R035_gen,colors[6]);

        SetStyle(pro_dpt_R005,colors[0]); SetStyle(pro_dpt_R010,colors[1]);
        SetStyle(pro_dpt_R015,colors[2]); SetStyle(pro_dpt_R020,colors[3]);
        SetStyle(pro_dpt_R025,colors[4]); SetStyle(pro_dpt_R030,colors[5]);
        SetStyle(pro_dpt_R035,colors[6]);

        SetStyle(pro_dpt_R005_gen,colors[0]); SetStyle(pro_dpt_R010_gen,colors[1]);
        SetStyle(pro_dpt_R015_gen,colors[2]); SetStyle(pro_dpt_R020_gen,colors[3]);
        SetStyle(pro_dpt_R025_gen,colors[4]); SetStyle(pro_dpt_R030_gen,colors[5]);
        SetStyle(pro_dpt_R035_gen,colors[6]);


        Mean_gr->SetLineColor(colors[0]);Mean_gr->SetMarkerColor(colors[0]);
        Mean_gr->SetMarkerStyle(markers[4]);
        RMS_gr->SetLineColor(colors[0]);RMS_gr->SetMarkerColor(colors[0]);
        RMS_gr->SetMarkerStyle(markers[4]);

TFile*fout = new TFile(TString::Format("EF_ppMC_%dTeV_pt_%d_%d.root",sqrts,Ptlow,Pthigh),"RECREATE",TString::Format("EF_ppMC_%dTeV_pt_%d_%d.root",Ptlow,Pthigh,sqrts));

hJetPtMatched_R005->Write("hJetPtMatched_R005",TObject::kOverwrite);hJetPtMatched_R010->Write("hJetPtMatched_R010",TObject::kOverwrite);
hJetPtMatched_R015->Write("hJetPtMatched_R015",TObject::kOverwrite);hJetPtMatched_R020->Write("hJetPtMatched_R020",TObject::kOverwrite);
hJetPtMatched_R025->Write("hJetPtMatched_R025",TObject::kOverwrite);hJetPtMatched_R030->Write("hJetPtMatched_R030",TObject::kOverwrite);
hJetPtMatched_R035->Write("hJetPtMatched_R035",TObject::kOverwrite);hJetPtMatched_R040->Write("hJetPtMatched_R040",TObject::kOverwrite);

hJetEtaMatched_R005->Write("hJetEtaMatched_R005",TObject::kOverwrite);hJetEtaMatched_R010->Write("hJetEtaMatched_R010",TObject::kOverwrite);
hJetEtaMatched_R015->Write("hJetEtaMatched_R015",TObject::kOverwrite);hJetEtaMatched_R020->Write("hJetEtaMatched_R020",TObject::kOverwrite);
hJetEtaMatched_R025->Write("hJetEtaMatched_R025",TObject::kOverwrite);hJetEtaMatched_R030->Write("hJetEtaMatched_R030",TObject::kOverwrite);
hJetEtaMatched_R035->Write("hJetEtaMatched_R035",TObject::kOverwrite);hJetEtaMatched_R040->Write("hJetEtaMatched_R040",TObject::kOverwrite);

hJetPtMatched_R005_gen->Write("hJetPtMatched_R005_gen",TObject::kOverwrite);hJetPtMatched_R010_gen->Write("hJetPtMatched_R010_gen",TObject::kOverwrite);
hJetPtMatched_R015_gen->Write("hJetPtMatched_R015_gen",TObject::kOverwrite);hJetPtMatched_R020_gen->Write("hJetPtMatched_R020_gen",TObject::kOverwrite);
hJetPtMatched_R025_gen->Write("hJetPtMatched_R025_gen",TObject::kOverwrite);hJetPtMatched_R030_gen->Write("hJetPtMatched_R030_gen",TObject::kOverwrite);
hJetPtMatched_R035_gen->Write("hJetPtMatched_R035_gen",TObject::kOverwrite);hJetPtMatched_R040_gen->Write("hJetPtMatched_R040_gen",TObject::kOverwrite);

hJetEtaMatched_R005_gen->Write("hJetEtaMatched_R005_gen",TObject::kOverwrite);hJetEtaMatched_R010_gen->Write("hJetEtaMatched_R010_gen",TObject::kOverwrite);
hJetEtaMatched_R015_gen->Write("hJetEtaMatched_R015_gen",TObject::kOverwrite);hJetEtaMatched_R020_gen->Write("hJetEtaMatched_R020_gen",TObject::kOverwrite);
hJetEtaMatched_R025_gen->Write("hJetEtaMatched_R025_gen",TObject::kOverwrite);hJetEtaMatched_R030_gen->Write("hJetEtaMatched_R030_gen",TObject::kOverwrite);
hJetEtaMatched_R035_gen->Write("hJetEtaMatched_R035_gen",TObject::kOverwrite);hJetEtaMatched_R040_gen->Write("hJetEtaMatched_R040_gen",TObject::kOverwrite);

pro_dpt_R005->Write("pro_dpt_R005",TObject::kOverwrite);pro_dpt_R010->Write("pro_dpt_R010",TObject::kOverwrite);
pro_dpt_R015->Write("pro_dpt_R015",TObject::kOverwrite);pro_dpt_R020->Write("pro_dpt_R020",TObject::kOverwrite);
pro_dpt_R025->Write("pro_dpt_R025",TObject::kOverwrite);pro_dpt_R030->Write("pro_dpt_R030",TObject::kOverwrite);
pro_dpt_R035->Write("pro_dpt_R035",TObject::kOverwrite);

pro_dpt_R005_gen->Write("pro_dpt_R005_gen",TObject::kOverwrite);pro_dpt_R010_gen->Write("pro_dpt_R010_gen",TObject::kOverwrite);
pro_dpt_R015_gen->Write("pro_dpt_R015_gen",TObject::kOverwrite);pro_dpt_R020_gen->Write("pro_dpt_R020_gen",TObject::kOverwrite);
pro_dpt_R025_gen->Write("pro_dpt_R025_gen",TObject::kOverwrite);pro_dpt_R030_gen->Write("pro_dpt_R030_gen",TObject::kOverwrite);
pro_dpt_R035_gen->Write("pro_dpt_R035_gen",TObject::kOverwrite);

pro_dR_R005->Write("pro_dR_R005",TObject::kOverwrite);pro_dR_R010->Write("pro_dR_R010",TObject::kOverwrite);
pro_dR_R015->Write("pro_dR_R015",TObject::kOverwrite);pro_dR_R020->Write("pro_dR_R020",TObject::kOverwrite);
pro_dR_R025->Write("pro_dR_R025",TObject::kOverwrite);pro_dR_R030->Write("pro_dR_R030",TObject::kOverwrite);
pro_dR_R035->Write("pro_dR_R035",TObject::kOverwrite);


pro_dR_R005_gen->Write("pro_dR_R005_gen",TObject::kOverwrite);pro_dR_R010_gen->Write("pro_dR_R010_gen",TObject::kOverwrite);
pro_dR_R015_gen->Write("pro_dR_R015_gen",TObject::kOverwrite);pro_dR_R020_gen->Write("pro_dR_R020_gen",TObject::kOverwrite);
pro_dR_R025_gen->Write("pro_dR_R025_gen",TObject::kOverwrite);pro_dR_R030_gen->Write("pro_dR_R030_gen",TObject::kOverwrite);
pro_dR_R035_gen->Write("pro_dR_R035_gen",TObject::kOverwrite);



Mean_gr->Write(Form("Mean_gr_%d_%d",Ptlow,Pthigh),TObject::kOverwrite);
RMS_gr->Write(Form("RMS_gr_%d_%d",Ptlow,Pthigh),TObject::kOverwrite);
Mean_gr_gen->Write(Form("Mean_gr_%d_%d_gen",Ptlow,Pthigh),TObject::kOverwrite);
RMS_gr_gen->Write(Form("RMS_gr_%d_%d_gen",Ptlow,Pthigh),TObject::kOverwrite);


fout->Write();




}
void SetStyle(TH1* h1, int kColor){

                  h1->SetLineWidth(2); h1->SetLineColor(kColor);
                  h1->SetMarkerSize(3); h1->SetMarkerColor(kColor);
                  if(kColor<=4)h1->SetMarkerStyle(kFullDiamond);
                  else h1->SetMarkerStyle(kFullDiamond);
                 }
                
