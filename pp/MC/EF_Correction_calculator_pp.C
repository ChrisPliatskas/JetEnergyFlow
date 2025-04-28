TH2D* RM_normalization(TH2D* input_RM);
void SetStyle(TH1*h1,int Color);
void EF_Correction_calculator_pp(const char* finput, int Ptlow, int Pthigh, int sqrts){

        //Open the file and extract the histogram list
        TFile* f_input;
        f_input= TFile::Open(finput);
        AliEmcalList*ali;
        f_input->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_tracks_caloClusters_emcalCells_ppMC_GenDet_histos",ali);

        //Retrieve the RM THn
        THnSparseD* RM_R005 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R005_0"));
        THnSparseD* RM_R010 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R010_0"));
        THnSparseD* RM_R015 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R015_0"));
        THnSparseD* RM_R020 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R020_0"));
        THnSparseD* RM_R025 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R025_0"));
        THnSparseD* RM_R030 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R030_0"));
        THnSparseD* RM_R035 = (THnSparseD*)(ali->FindObject("ResponseMatrix_R035_0"));


        //Retrieve the JER histograms(2D)
        TH2D* JER_R005 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R005_0"));
        TH2D* JER_R010 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R010_0"));
        TH2D* JER_R015 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R015_0"));
        TH2D* JER_R020 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R020_0"));
        TH2D* JER_R025 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R025_0"));
        TH2D* JER_R030 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R030_0"));
        TH2D* JER_R035 = (TH2D*)(ali->FindObject("hMatchedJetEnergyResponse_R035_0"));

        //Retrieve the Dpt Resolution
        TH3D* Delta_R005 = (TH3D*)(ali->FindObject("DeltaResponseMatrix_R005_0"));
        TH3D* Delta_R010 = (TH3D*) ali->FindObject("DeltaResponseMatrix_R010_0");
        TH3D* Delta_R015 = (TH3D*) ali->FindObject("DeltaResponseMatrix_R015_0");
        TH3D* Delta_R020 = (TH3D*) ali->FindObject("DeltaResponseMatrix_R020_0");
        TH3D* Delta_R025 = (TH3D*)(ali->FindObject("DeltaResponseMatrix_R025_0"));
        TH3D* Delta_R030 = (TH3D*) ali->FindObject("DeltaResponseMatrix_R030_0");
        TH3D* Delta_R035 = (TH3D*) ali->FindObject("DeltaResponseMatrix_R035_0");


        int ptlow_bin =Delta_R005->GetXaxis()->FindBin(Ptlow);
        int pthigh_bin = Delta_R005->GetXaxis()->FindBin(Pthigh)-1;

        //Calculate the RM projections
        Int_t Dptlow_bin_gen = RM_R005->GetAxis(2)->FindBin(0.);
        Int_t Dpthigh_bin_gen = RM_R005->GetAxis(2)->FindBin(30.);
        Int_t Dptlow_bin = RM_R005->GetAxis(3)->FindBin(0.);
        Int_t Dpthigh_bin = RM_R005->GetAxis(3)->FindBin(25.);
        //------------Pt response---------------//
        TH2D *Pt_RM_R005 = dynamic_cast<TH2D*>(RM_R005->Projection(0,1,"E"));
        Pt_RM_R005->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R005->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R005->SetTitle("Response Matrix for jet p_{T} of R = 0.05 jets");
        TH2D* Pt_RM_R005_norm = RM_normalization(Pt_RM_R005);

        TH2D *Pt_RM_R010 = dynamic_cast<TH2D*>(RM_R010->Projection(0,1,"E"));
        Pt_RM_R010->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R010->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R010->SetTitle("Response Matrix for jet p_{T} of R = 0.1 jets");
        TH2D* Pt_RM_R010_norm = RM_normalization(Pt_RM_R010);

        TH2D *Pt_RM_R015 = dynamic_cast<TH2D*>(RM_R015->Projection(0,1,"E"));
        Pt_RM_R015->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R015->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R015->SetTitle("Response Matrix for jet p_{T} of R = 0.15 jets");
        TH2D* Pt_RM_R015_norm = RM_normalization(Pt_RM_R015);

        TH2D *Pt_RM_R020 = dynamic_cast<TH2D*>(RM_R020->Projection(0,1,"E"));
        Pt_RM_R020->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R020->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R020->SetTitle("Response Matrix for jet p_{T} of R = 0.2 jets");
        TH2D* Pt_RM_R020_norm = RM_normalization(Pt_RM_R020);

        TH2D *Pt_RM_R025 = dynamic_cast<TH2D*>(RM_R025->Projection(0,1,"E"));
        Pt_RM_R025->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R025->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R025->SetTitle("Response Matrix for jet p_{T} of R = 0.05 jets");
        TH2D* Pt_RM_R025_norm = RM_normalization(Pt_RM_R025);

        TH2D *Pt_RM_R030 = dynamic_cast<TH2D*>(RM_R030->Projection(0,1,"E"));
        Pt_RM_R030->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R030->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R030->SetTitle("Response Matrix for jet p_{T} of R = 0.1 jets");
        TH2D* Pt_RM_R030_norm = RM_normalization(Pt_RM_R030);

        TH2D *Pt_RM_R035 = dynamic_cast<TH2D*>(RM_R035->Projection(0,1,"E"));
        Pt_RM_R035->GetXaxis()->SetTitle("p_{T} (Detector level)");
        Pt_RM_R035->GetYaxis()->SetTitle("p_{T} (Truth level)");
        Pt_RM_R035->SetTitle("Response Matrix for jet p_{T} of R = 0.15 jets");
        TH2D* Pt_RM_R035_norm = RM_normalization(Pt_RM_R035);


        //-----------Dpt response---------------//
        RM_R005->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);
        RM_R010->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);
        RM_R015->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);
        RM_R020->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);

        TH2D *Dpt_RM_R005 = dynamic_cast<TH2D*>(RM_R005->Projection(2,3,"E"));
        Dpt_RM_R005->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R005->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R005->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.05 and R = 0.1 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R005_norm = RM_normalization(Dpt_RM_R005);


        TH2D *Dpt_RM_R010 = dynamic_cast<TH2D*>(RM_R010->Projection(2,3,"E"));
        Dpt_RM_R010->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R010->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R010->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.1 and R = 0.15 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R010_norm = RM_normalization(Dpt_RM_R010);

        TH2D *Dpt_RM_R015 = dynamic_cast<TH2D*>(RM_R015->Projection(2,3,"E"));
        Dpt_RM_R015->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R015->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R015->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.15 and R = 0.2 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R015_norm = RM_normalization(Dpt_RM_R015);

        TH2D *Dpt_RM_R020 = dynamic_cast<TH2D*>(RM_R020->Projection(2,3,"E"));
        Dpt_RM_R020->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R020->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R020->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.2 and R = 0.25 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R020_norm = RM_normalization(Dpt_RM_R020);

        RM_R025->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);
        RM_R030->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);
        RM_R035->GetAxis(0)->SetRangeUser(Ptlow,Pthigh);

        TH2D *Dpt_RM_R025 = dynamic_cast<TH2D*>(RM_R025->Projection(2,3,"E"));
        Dpt_RM_R025->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R025->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R025->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.05 and R = 0.1 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R025_norm = RM_normalization(Dpt_RM_R025);


        TH2D *Dpt_RM_R030 = dynamic_cast<TH2D*>(RM_R030->Projection(2,3,"E"));
        Dpt_RM_R030->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R030->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R030->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.1 and R = 0.15 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R030_norm = RM_normalization(Dpt_RM_R030);

        TH2D *Dpt_RM_R035 = dynamic_cast<TH2D*>(RM_R035->Projection(2,3,"E"));
        Dpt_RM_R035->GetXaxis()->SetTitle("#Deltap_{T} (Detector level)");
        Dpt_RM_R035->GetYaxis()->SetTitle("#Deltap_{T} (Truth level)");
        Dpt_RM_R035->SetTitle(Form("Response Matrix for #Deltap_{T} of between R = 0.15 and R = 0.2 for [%d,%d] (GeV/c) jets",Ptlow,Pthigh));
        TH2D* Dpt_RM_R035_norm = RM_normalization(Dpt_RM_R035);


        //Calculate Kinematic Efficiency
        //Postponed for now

        //Calculate the JER projections
        TH1D*pro_JER_R005 =JER_R005->ProjectionY("pro_JER_R005",ptlow_bin,pthigh_bin);
        TH1D*pro_JER_R010 =JER_R010->ProjectionY("pro_JER_R010",ptlow_bin,pthigh_bin);
        TH1D*pro_JER_R015 =JER_R015->ProjectionY("pro_JER_R015",ptlow_bin,pthigh_bin);
        TH1D*pro_JER_R020 =JER_R020->ProjectionY("pro_JER_R020",ptlow_bin,pthigh_bin);
        TH1D*pro_JER_R025 =JER_R025->ProjectionY("pro_JER_R025",ptlow_bin,pthigh_bin);
        TH1D*pro_JER_R030 =JER_R030->ProjectionY("pro_JER_R030",ptlow_bin,pthigh_bin);
        TH1D*pro_JER_R035 =JER_R035->ProjectionY("pro_JER_R035",ptlow_bin,pthigh_bin);

        //Calculate the Dpt resolution projections
        TH1D* pro_delta_R005 = (TH1D*) Delta_R005->ProjectionZ("pro_delta_R005",ptlow_bin,pthigh_bin);
        TH1D* pro_delta_R010 = (TH1D*) Delta_R010->ProjectionZ("pro_delta_R010",ptlow_bin,pthigh_bin);
        TH1D* pro_delta_R015 = (TH1D*) Delta_R015->ProjectionZ("pro_delta_R015",ptlow_bin,pthigh_bin);
        TH1D* pro_delta_R020 = (TH1D*) Delta_R020->ProjectionZ("pro_delta_R020",ptlow_bin,pthigh_bin);
        TH1D* pro_delta_R025 = (TH1D*) Delta_R025->ProjectionZ("pro_delta_R025",ptlow_bin,pthigh_bin);
        TH1D* pro_delta_R030 = (TH1D*) Delta_R030->ProjectionZ("pro_delta_R030",ptlow_bin,pthigh_bin);
        TH1D* pro_delta_R035 = (TH1D*) Delta_R035->ProjectionZ("pro_delta_R035",ptlow_bin,pthigh_bin);


        //Drawing style histograms
       const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
        const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
        const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};


        SetStyle(pro_JER_R005,colors[0]); SetStyle(pro_JER_R010,colors[1]);
        SetStyle(pro_JER_R015,colors[2]); SetStyle(pro_JER_R020,colors[3]);
        SetStyle(pro_JER_R025,colors[4]); SetStyle(pro_JER_R030,colors[5]);
        SetStyle(pro_JER_R035,colors[6]);

        SetStyle(pro_delta_R005,colors[0]); SetStyle(pro_delta_R010,colors[1]);
        SetStyle(pro_delta_R015,colors[2]); SetStyle(pro_delta_R020,colors[3]);
        SetStyle(pro_delta_R025,colors[4]); SetStyle(pro_delta_R030,colors[5]);
        SetStyle(pro_delta_R035,colors[6]);

        //Saving output file
TFile*fout = new TFile(TString::Format("EF_ppMC_%dTeV_pt_%d_%d.root",sqrts,Ptlow,Pthigh),"RECREATE",TString::Format("EF_ppMC_%dTeV_pt_%d_%d.root",sqrts,Ptlow,Pthigh));

        RM_R005->Write("RM_R005",TObject::kOverwrite);RM_R010->Write("RM_R010",TObject::kOverwrite);
        RM_R015->Write("RM_R015",TObject::kOverwrite);RM_R020->Write("RM_R020",TObject::kOverwrite);
        RM_R025->Write("RM_R025",TObject::kOverwrite);RM_R030->Write("RM_R030",TObject::kOverwrite);
        RM_R035->Write("RM_R035",TObject::kOverwrite);


        Dpt_RM_R005->Write("Dpt_RM_R005",TObject::kOverwrite);Dpt_RM_R010->Write("Dpt_RM_R010",TObject::kOverwrite);
        Dpt_RM_R015->Write("Dpt_RM_R015",TObject::kOverwrite);Dpt_RM_R020->Write("Dpt_RM_R020",TObject::kOverwrite);
        Dpt_RM_R025->Write("Dpt_RM_R025",TObject::kOverwrite);Dpt_RM_R030->Write("Dpt_RM_R030",TObject::kOverwrite);
        Dpt_RM_R035->Write("Dpt_RM_R035",TObject::kOverwrite); 
       
        Pt_RM_R005->Write("Pt_RM_R005",TObject::kOverwrite);Pt_RM_R010->Write("Pt_RM_R010",TObject::kOverwrite);
        Pt_RM_R015->Write("Pt_RM_R015",TObject::kOverwrite);Pt_RM_R020->Write("Pt_RM_R020",TObject::kOverwrite);
        Pt_RM_R025->Write("Pt_RM_R025",TObject::kOverwrite);Pt_RM_R030->Write("Pt_RM_R030",TObject::kOverwrite);
        Pt_RM_R035->Write("Pt_RM_R035",TObject::kOverwrite);

        Dpt_RM_R005_norm->Write("Dpt_RM_R005_norm",TObject::kOverwrite);Dpt_RM_R010_norm->Write("Dpt_RM_R010_norm",TObject::kOverwrite);
        Dpt_RM_R015_norm->Write("Dpt_RM_R015_norm",TObject::kOverwrite);Dpt_RM_R020_norm->Write("Dpt_RM_R020_norm",TObject::kOverwrite);
        Dpt_RM_R025_norm->Write("Dpt_RM_R025_norm",TObject::kOverwrite);Dpt_RM_R030_norm->Write("Dpt_RM_R030_norm",TObject::kOverwrite);
        Dpt_RM_R035_norm->Write("Dpt_RM_R035_norm",TObject::kOverwrite);

        Pt_RM_R005_norm->Write("Pt_RM_R005_norm",TObject::kOverwrite);Pt_RM_R010_norm->Write("Pt_RM_R010_norm",TObject::kOverwrite);
        Pt_RM_R015_norm->Write("Pt_RM_R015_norm",TObject::kOverwrite);Pt_RM_R020_norm->Write("Pt_RM_R020_norm",TObject::kOverwrite);
        Pt_RM_R025_norm->Write("Pt_RM_R025_norm",TObject::kOverwrite);Pt_RM_R030_norm->Write("Pt_RM_R030_norm",TObject::kOverwrite);
        Pt_RM_R035_norm->Write("Pt_RM_R035_norm",TObject::kOverwrite);        

        pro_JER_R005->Write("pro_JER_R005",TObject::kOverwrite);pro_JER_R010->Write("pro_JER_R010",TObject::kOverwrite);
        pro_JER_R015->Write("pro_JER_R015",TObject::kOverwrite);pro_JER_R020->Write("pro_JER_R020",TObject::kOverwrite);
        pro_JER_R025->Write("pro_JER_R025",TObject::kOverwrite);pro_JER_R030->Write("pro_JER_R030",TObject::kOverwrite);
        pro_JER_R035->Write("pro_JER_R035",TObject::kOverwrite);

        pro_delta_R005->Write("pro_delta_R005",TObject::kOverwrite);pro_delta_R010->Write("pro_delta_R010",TObject::kOverwrite);
        pro_delta_R015->Write("pro_delta_R015",TObject::kOverwrite);pro_delta_R020->Write("pro_delta_R020",TObject::kOverwrite);
        pro_delta_R025->Write("pro_delta_R025",TObject::kOverwrite);pro_delta_R030->Write("pro_delta_R030",TObject::kOverwrite);
        pro_delta_R035->Write("pro_delta_R035",TObject::kOverwrite);

fout->Write();
}

void SetStyle(TH1* h1, int kColor){

                  h1->SetLineWidth(2); h1->SetLineColor(kColor);
                  h1->SetMarkerSize(3); h1->SetMarkerColor(kColor);
                  if(kColor<=4)h1->SetMarkerStyle(kFullDiamond);
                  else h1->SetMarkerStyle(kFullDiamond);
                 }
TH2D* RM_normalization(TH2D* input_RM){

          Int_t nBinsDpt[2]= {input_RM->GetXaxis()->GetNbins(),input_RM->GetYaxis()->GetNbins()};
          TH2D* RM_norm =(TH2D*)input_RM->Clone();
          RM_norm->Reset();
          for(int iy=1;iy<=nBinsDpt[1];iy++){
                  Double_t sum = input_RM->Integral(1,nBinsDpt[0],iy,iy);
                  for(int ix=1;ix<=nBinsDpt[0];ix++){
                          Double_t con = input_RM->GetBinContent(ix,iy);
                          RM_norm->SetBinContent(ix,iy,con/sum);
                                } }
                RM_norm->SetMaximum(1.0);RM_norm->SetMinimum(1e-3);
          //        RM_norm->Draw("colz");
        //  TString name = Form("%s_norm",input_RM->GetName());
        //  RM_norm->SetName(name);
        // RM_norm->Write(RM_norm->GetName(),TObject::kOverwrite);
        return RM_norm;
  }
