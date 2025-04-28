void SetStyle(TH1*h1,int Color);
void EF_Calculator_PbPbdata_LargeR(const char* finput, int Ptlow, int Pthigh){

        //Open the file and retrieve the general list of the histograms
        TFile* f_input;
        f_input= TFile::Open(finput);
        AliEmcalList*ali;
        f_input->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_PbPbdata_PbPbdataLargeR_ConstSub_histos",ali);

        //Retrieving the DelatR histograms (2D)
        TH2D* hDR025 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R005_0"));
        TH2D* hDR030 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R010_0"));
        TH2D* hDR035 = (TH2D*)(ali->FindObject("hJetPtDeltaR_R015_0"));

        //Retrieving the Dpt histograms (2D)
        TH2D* hDptR025 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R005_0"));
        TH2D* hDptR030 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R010_0"));
        TH2D* hDptR035 = (TH2D*)(ali->FindObject("hJetPtDeltaPt_R015_0"));

       int Ptlow_bin =hDR030->GetXaxis()->FindBin(Ptlow);
       int Pthigh_bin = hDR030->GetXaxis()->FindBin(Pthigh)-1;

        //Retrieving the matched jet spectra
        //------------pt---------------------//
        TH1D* hJetPtMatched_R025 = (TH1D*)(ali->FindObject("hMatchedJetPt_R005_0"));
        TH1D* hJetPtMatched_R030 = (TH1D*)(ali->FindObject("hMatchedJetPt_R010_0"));
        TH1D* hJetPtMatched_R035 = (TH1D*)(ali->FindObject("hMatchedJetPt_R015_0"));
        TH1D* hJetPtMatched_R040 = (TH1D*)(ali->FindObject("hMatchedJetPt_R020_0"));

        //------------eta--------------------//
        TH1D* hJetEtaMatched_R025 = (TH1D*)(ali->FindObject("hMatchedJetEta_R005_0"));
        TH1D* hJetEtaMatched_R030 = (TH1D*)(ali->FindObject("hMatchedJetEta_R010_0"));
        TH1D* hJetEtaMatched_R035 = (TH1D*)(ali->FindObject("hMatchedJetEta_R015_0"));
        TH1D* hJetEtaMatched_R040 = (TH1D*)(ali->FindObject("hMatchedJetEta_R020_0"));


        //Calculate the DR projections
        TH1D*pro_dR_R025; TH1D*pro_dR_R030; TH1D*pro_dR_R035;
        pro_dR_R025 = hDR025->ProjectionY("pro_dR_R025",Ptlow_bin,Pthigh_bin);
        pro_dR_R030 = hDR030->ProjectionY("pro_dR_R030",Ptlow_bin,Pthigh_bin);
        pro_dR_R035 = hDR035->ProjectionY("pro_dR_R035",Ptlow_bin,Pthigh_bin);

        pro_dR_R025->Scale(1./pro_dR_R025->Integral("width"));
        pro_dR_R030->Scale(1./pro_dR_R030->Integral("width"));
        pro_dR_R035->Scale(1./pro_dR_R035->Integral("width"));

       //Calculate the Dpt projections
        TH1D*pro_dpt_R025; TH1D*pro_dpt_R030; TH1D*pro_dpt_R035;
        int Dpt_low_bin = hDptR025->GetYaxis()->FindBin(0.);
        int Dpt_high_bin = hDptR025->GetYaxis()->FindBin(25.);

        hDptR025->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR030->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        hDptR035->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        
        pro_dpt_R025=hDptR025->ProjectionY("pro_dpt_R025",Ptlow_bin,Pthigh_bin);
        pro_dpt_R030=hDptR030->ProjectionY("pro_dpt_R030",Ptlow_bin,Pthigh_bin);
        pro_dpt_R035=hDptR035->ProjectionY("pro_dpt_R035",Ptlow_bin,Pthigh_bin);

        pro_dpt_R025->Scale(1./pro_dpt_R025->Integral("width"));
        pro_dpt_R030->Scale(1./pro_dpt_R030->Integral("width"));
        pro_dpt_R035->Scale(1./pro_dpt_R035->Integral("width"));

        pro_dR_R025->SetTitle(TString::Format("#DeltaR between R=0.25 and R=0.3 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R030->SetTitle(TString::Format("#DeltaR between R=0.3 and R=0.35 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));
        pro_dR_R035->SetTitle(TString::Format("#DeltaR between R=0.35 and R=0.4 for jet p_{T} [%d,%d] GeV/c;#DeltaR (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#DeltaR}",Ptlow,Pthigh));


        pro_dpt_R025->SetTitle(TString::Format("#Deltap_{T} between R=0.25 and R=0.3 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R030->SetTitle(TString::Format("#Deltap_{T} between R=0.3 and R=0.35 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));
        pro_dpt_R035->SetTitle(TString::Format("#Deltap_{T} between R=0.35 and R=0.4 for jet p_{T} [%d,%d] GeV/c ;#Deltap_{T} (GeV/c); #frac{1}{N_{jets}}#frac{dN}{d#Deltap_{T}}",Ptlow,Pthigh));

        //Extract the mean and RMS graphs
Double_t R[3] = {.25,.3,.35};
Double_t R_err[3] = {0,0,0};
Double_t mean[3] ={pro_dpt_R025->GetMean(),pro_dpt_R030->GetMean(),pro_dpt_R035->GetMean()};
Double_t mean_err[3] ={pro_dpt_R025->GetMeanError(),pro_dpt_R030->GetMeanError(),pro_dpt_R035->GetMeanError()};

Double_t rms[3] ={pro_dpt_R025->GetRMS(),pro_dpt_R030->GetRMS(),pro_dpt_R035->GetRMS()};
Double_t rms_err[3] ={pro_dpt_R025->GetRMSError(),pro_dpt_R030->GetRMSError(),pro_dpt_R035->GetRMSError()};

 auto Mean_gr = new TGraphErrors(3,R,mean,R_err,mean_err);
        Mean_gr->SetMarkerSize(3);
        Mean_gr->SetFillStyle(3001);
        Mean_gr->SetLineWidth(2);
Mean_gr->SetTitle(TString::Format("Mean of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; Mean value",Ptlow,Pthigh));

 auto RMS_gr = new TGraphErrors(3,R,rms,R_err,rms_err);
        RMS_gr->SetMarkerSize(3);
        RMS_gr->SetFillStyle(3001);
RMS_gr->SetTitle(TString::Format("Width of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; #sigma_{#Deltap_{T}}",Ptlow,Pthigh));

        //Draw style options
        const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
        const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
        const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

        SetStyle(hJetPtMatched_R025,colors[4]); SetStyle(hJetPtMatched_R030,colors[5]);
        SetStyle(hJetPtMatched_R035,colors[6]); SetStyle(hJetPtMatched_R040,colors[7]);

        SetStyle(hJetEtaMatched_R025,colors[4]); SetStyle(hJetEtaMatched_R030,colors[5]);
        SetStyle(hJetEtaMatched_R035,colors[6]); SetStyle(hJetEtaMatched_R040,colors[7]);

        SetStyle(pro_dR_R025,colors[4]); SetStyle(pro_dR_R030,colors[5]);
        SetStyle(pro_dR_R035,colors[6]); 

        SetStyle(pro_dpt_R025,colors[4]); SetStyle(pro_dpt_R030,colors[5]);
        SetStyle(pro_dpt_R035,colors[6]); 

        Mean_gr->SetLineColor(colors[0]);Mean_gr->SetMarkerColor(colors[0]);
        Mean_gr->SetMarkerStyle(markers[4]);
        RMS_gr->SetLineColor(colors[0]);RMS_gr->SetMarkerColor(colors[0]);
        RMS_gr->SetMarkerStyle(markers[4]);


        //Saving section
TFile*fout = new TFile(TString::Format("EF_PbPbdata_largeR_pt_%d_%d.root",Ptlow,Pthigh),"RECREATE",TString::Format("EF_PbPbdata_largeR_pt_%d_%d.root",Ptlow,Pthigh));


hJetPtMatched_R025->Write("hJetPtMatched_R025",TObject::kOverwrite);hJetPtMatched_R030->Write("hJetPtMatched_R030",TObject::kOverwrite);
hJetPtMatched_R035->Write("hJetPtMatched_R035",TObject::kOverwrite);hJetPtMatched_R040->Write("hJetPtMatched_R040",TObject::kOverwrite);

hJetEtaMatched_R025->Write("hJetEtaMatched_R025",TObject::kOverwrite);hJetEtaMatched_R030->Write("hJetEtaMatched_R030",TObject::kOverwrite);
hJetEtaMatched_R035->Write("hJetEtaMatched_R035",TObject::kOverwrite);hJetEtaMatched_R040->Write("hJetEtaMatched_R040",TObject::kOverwrite);

pro_dpt_R025->Write("pro_dpt_R025",TObject::kOverwrite);pro_dpt_R030->Write("pro_dpt_R030",TObject::kOverwrite);
pro_dpt_R035->Write("pro_dpt_R035",TObject::kOverwrite);

pro_dR_R025->Write("pro_dR_R025",TObject::kOverwrite);pro_dR_R030->Write("pro_dR_R030",TObject::kOverwrite);
pro_dR_R035->Write("pro_dR_R035",TObject::kOverwrite);

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
