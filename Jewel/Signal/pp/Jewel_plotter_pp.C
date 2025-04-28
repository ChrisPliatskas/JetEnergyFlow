
//Date: November 21st 2024 Developer: Chris Pliatskas
// This analysis code is meant for post-processing and visualisation of the output from the analysis code processing JEWEL vacuum simulations. Due to the close dependence between the scripts some features are necessarily hardcoded. In principle, the execution of this code should directly produce the plots as they were presented in PhD thesis although some minor visualization adjustments may be needed.  

//Supporting plotting macros to maintain a robust style across the visual output of the codes. Code was inherited from the official ALICE guidelines even though adjustments for aesthetic optimization had to be made. Here the functions are only declared, definitions can be found at the end of the file.
void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);

//Main analysis function. It is advised that the main function should carry the name of the file. Inputs include the lower and upper limit for the analysis jet pt range with respect to distribution projections and the collision energy.
void Jewel_plotter_pp(int Ptlow,int Pthigh, int sqrts){

//Open the appropriate file
TFile* fin;
if(sqrts==5)fin=TFile::Open("Summary_jewel_pp_5TeV.root");
else if(sqrts==13)fin=TFile::Open("Summary_jewel_pp_13TeV.root");
else {std::cout<<"File could not be found";return;}

//----------------Extraction section----------------------------------//
//Retrieve the total event weight. This is important for the normalization of the jet spectra.
TH1F*h_Event;fin->GetObject("hNEvent",h_Event);
double e_weight=h_Event->GetBinContent(1);

//Retrieve the matched jet pt spectra for each jet radius
TH1F*hJetPtMatched_R005;fin->GetObject("hJetPtMatched_R005",hJetPtMatched_R005);
TH1F*hJetPtMatched_R010;fin->GetObject("hJetPtMatched_R010",hJetPtMatched_R010);
TH1F*hJetPtMatched_R015;fin->GetObject("hJetPtMatched_R015",hJetPtMatched_R015);
TH1F*hJetPtMatched_R020;fin->GetObject("hJetPtMatched_R020",hJetPtMatched_R020);
TH1F*hJetPtMatched_R025;fin->GetObject("hJetPtMatched_R025",hJetPtMatched_R025);
TH1F*hJetPtMatched_R030;fin->GetObject("hJetPtMatched_R030",hJetPtMatched_R030);
TH1F*hJetPtMatched_R035;fin->GetObject("hJetPtMatched_R035",hJetPtMatched_R035);
TH1F*hJetPtMatched_R040;fin->GetObject("hJetPtMatched_R040",hJetPtMatched_R040);

//Retrieve the matched jet eta distributions for each jet radius
TH1F*hJetEtaMatched_R005;fin->GetObject("hJetEtaMatched_R005",hJetEtaMatched_R005);
TH1F*hJetEtaMatched_R010;fin->GetObject("hJetEtaMatched_R010",hJetEtaMatched_R010);
TH1F*hJetEtaMatched_R015;fin->GetObject("hJetEtaMatched_R015",hJetEtaMatched_R015);
TH1F*hJetEtaMatched_R020;fin->GetObject("hJetEtaMatched_R020",hJetEtaMatched_R020);
TH1F*hJetEtaMatched_R025;fin->GetObject("hJetEtaMatched_R025",hJetEtaMatched_R025);
TH1F*hJetEtaMatched_R030;fin->GetObject("hJetEtaMatched_R030",hJetEtaMatched_R030);
TH1F*hJetEtaMatched_R035;fin->GetObject("hJetEtaMatched_R035",hJetEtaMatched_R035);
TH1F*hJetEtaMatched_R040;fin->GetObject("hJetEtaMatched_R040",hJetEtaMatched_R040);

//Retrieve the 2-dimensional DR histograms for each jet radial pair
TH2F*hPtJetDeltaR_R005;fin->GetObject("hPtJetDeltaR_R005",hPtJetDeltaR_R005);
TH2F*hPtJetDeltaR_R010;fin->GetObject("hPtJetDeltaR_R010",hPtJetDeltaR_R010);
TH2F*hPtJetDeltaR_R015;fin->GetObject("hPtJetDeltaR_R015",hPtJetDeltaR_R015);
TH2F*hPtJetDeltaR_R020;fin->GetObject("hPtJetDeltaR_R020",hPtJetDeltaR_R020);
TH2F*hPtJetDeltaR_R025;fin->GetObject("hPtJetDeltaR_R025",hPtJetDeltaR_R025);
TH2F*hPtJetDeltaR_R030;fin->GetObject("hPtJetDeltaR_R030",hPtJetDeltaR_R030);
TH2F*hPtJetDeltaR_R035;fin->GetObject("hPtJetDeltaR_R035",hPtJetDeltaR_R035);

//Get the 2-dimensional Dpt histograms for each jet radial pair
TH2F*hPtJetDeltaPt_R005;fin->GetObject("hPtJetDeltaPt_R005",hPtJetDeltaPt_R005);
TH2F*hPtJetDeltaPt_R010;fin->GetObject("hPtJetDeltaPt_R010",hPtJetDeltaPt_R010);
TH2F*hPtJetDeltaPt_R015;fin->GetObject("hPtJetDeltaPt_R015",hPtJetDeltaPt_R015);
TH2F*hPtJetDeltaPt_R020;fin->GetObject("hPtJetDeltaPt_R020",hPtJetDeltaPt_R020);
TH2F*hPtJetDeltaPt_R025;fin->GetObject("hPtJetDeltaPt_R025",hPtJetDeltaPt_R025);
TH2F*hPtJetDeltaPt_R030;fin->GetObject("hPtJetDeltaPt_R030",hPtJetDeltaPt_R030);
TH2F*hPtJetDeltaPt_R035;fin->GetObject("hPtJetDeltaPt_R035",hPtJetDeltaPt_R035);

//--------------Calculation section------------------------------------//
        //----Determine the bins corresponding the jet pt and Dpt lower and upper limits.

        int Ptlow_bin;
        int Pthigh_bin;
        int Dpt_low_bin;
        int Dpt_high_bin;
//Calculate the DR projections in one dimension for each jet radial pair
Ptlow_bin=hPtJetDeltaR_R005->GetXaxis()->FindBin(Ptlow);
Pthigh_bin=hPtJetDeltaR_R005->GetXaxis()->FindBin(Pthigh)-1;
TH1D*pro_dR_R005; TH1D*pro_dR_R010; TH1D*pro_dR_R015;
TH1D*pro_dR_R020; TH1D*pro_dR_R025; TH1D*pro_dR_R030;TH1D*pro_dR_R035;

pro_dR_R005= hPtJetDeltaR_R005->ProjectionY("pro_dR_R005",Ptlow_bin,Pthigh_bin);
pro_dR_R010= hPtJetDeltaR_R010->ProjectionY("pro_dR_R010",Ptlow_bin,Pthigh_bin);
pro_dR_R015= hPtJetDeltaR_R015->ProjectionY("pro_dR_R015",Ptlow_bin,Pthigh_bin);
pro_dR_R020= hPtJetDeltaR_R020->ProjectionY("pro_dR_R020",Ptlow_bin,Pthigh_bin);
pro_dR_R025= hPtJetDeltaR_R025->ProjectionY("pro_dR_R025",Ptlow_bin,Pthigh_bin);
pro_dR_R030= hPtJetDeltaR_R030->ProjectionY("pro_dR_R030",Ptlow_bin,Pthigh_bin);
pro_dR_R035= hPtJetDeltaR_R035->ProjectionY("pro_dR_R035",Ptlow_bin,Pthigh_bin);

//Calculate the Dpt projections in one dimension for each radial pair
// Delta pt limits are at this version hardcoded to maintain a simple macro definition. This can easily be amended.
Dpt_low_bin=hPtJetDeltaPt_R005->GetYaxis()->FindBin(0.);
Dpt_high_bin=hPtJetDeltaPt_R005->GetYaxis()->FindBin(35.);

TH1D*pro_R005; TH1D*pro_R010; TH1D*pro_R015;
TH1D*pro_R020; TH1D*pro_R025; TH1D*pro_R030;TH1D*pro_R035;

// Adjust the Dpt range to be projected. Since the reported distributions are self-normalized and compared to data this is an important step.
hPtJetDeltaPt_R005->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
hPtJetDeltaPt_R010->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
hPtJetDeltaPt_R015->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
hPtJetDeltaPt_R020->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
hPtJetDeltaPt_R025->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
hPtJetDeltaPt_R030->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
hPtJetDeltaPt_R035->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);

pro_R005= hPtJetDeltaPt_R005->ProjectionY("pro_R005",Ptlow_bin,Pthigh_bin);
pro_R010= hPtJetDeltaPt_R010->ProjectionY("pro_R010",Ptlow_bin,Pthigh_bin);
pro_R015= hPtJetDeltaPt_R015->ProjectionY("pro_R015",Ptlow_bin,Pthigh_bin);
pro_R020= hPtJetDeltaPt_R020->ProjectionY("pro_R020",Ptlow_bin,Pthigh_bin);
pro_R025= hPtJetDeltaPt_R025->ProjectionY("pro_R025",Ptlow_bin,Pthigh_bin);
pro_R030= hPtJetDeltaPt_R030->ProjectionY("pro_R030",Ptlow_bin,Pthigh_bin);
pro_R035= hPtJetDeltaPt_R035->ProjectionY("pro_R035",Ptlow_bin,Pthigh_bin);

// Normalize the Dpt projections to an integral of unity while taking into account the bin width of the distributions
pro_R005->Scale(1./pro_R005->Integral("width"));
pro_R010->Scale(1./pro_R010->Integral("width"));
pro_R015->Scale(1./pro_R015->Integral("width"));
pro_R020->Scale(1./pro_R020->Integral("width"));
pro_R025->Scale(1./pro_R025->Integral("width"));
pro_R030->Scale(1./pro_R030->Integral("width"));
pro_R035->Scale(1./pro_R035->Integral("width"));

// Normalize the DR projections to an integral of unity while taking into account the bin width of the distributions
pro_dR_R005->Scale(1./pro_dR_R005->Integral("width"));
pro_dR_R010->Scale(1./pro_dR_R010->Integral("width"));
pro_dR_R015->Scale(1./pro_dR_R015->Integral("width"));
pro_dR_R020->Scale(1./pro_dR_R020->Integral("width"));
pro_dR_R025->Scale(1./pro_dR_R025->Integral("width"));
pro_dR_R030->Scale(1./pro_dR_R030->Integral("width"));
pro_dR_R035->Scale(1./pro_dR_R035->Integral("width"));

// Title adjustment for the Dpt projections. In the current visualization format these are not displayed
pro_R005->SetTitle(TString::Format("#Deltap_{T} between R=0.05 and R=0.1 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));
pro_R010->SetTitle(TString::Format("#Deltap_{T} between R=0.1 and R=0.15 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));
pro_R015->SetTitle(TString::Format("#Deltap_{T} between R=0.15 and R=0.2 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));
pro_R020->SetTitle(TString::Format("#Deltap_{T} between R=0.2 and R=0.25 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));
pro_R025->SetTitle(TString::Format("#Deltap_{T} between R=0.25 and R=0.3 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));
pro_R030->SetTitle(TString::Format("#Deltap_{T} between R=0.3 and R=0.35 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));
pro_R035->SetTitle(TString::Format("#Deltap_{T} between R=0.35 and R=0.4 for jet p_{T} [%d,%d] GeV/c (JEWEL);#Deltap_{T} (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#Deltap_{T}}",Ptlow,Pthigh));

// Title adjustment for the DR projections. In the current visualization format these are not displayed
pro_dR_R005->SetTitle(TString::Format("#DeltaR between R=0.05 and R=0.1 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
pro_dR_R010->SetTitle(TString::Format("#DeltaR between R=0.1 and R=0.15 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
pro_dR_R015->SetTitle(TString::Format("#DeltaR between R=0.15 and R=0.2 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
pro_dR_R020->SetTitle(TString::Format("#DeltaR between R=0.2 and R=0.25 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
pro_dR_R025->SetTitle(TString::Format("#DeltaR between R=0.25 and R=0.3 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
pro_dR_R030->SetTitle(TString::Format("#DeltaR between R=0.3 and R=0.35 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));
pro_dR_R035->SetTitle(TString::Format("#DeltaR between R=0.35 and R=0.4 for jet p_{T} [%d,%d] GeV/c (JEWEL);#DeltaR (GeV/c); #frac{1}{#sigma_{tot}}#frac{d#sigma}{d#DeltaR}",Ptlow,Pthigh));

// Normalizing the spectra with the event weight and the bin width. This choice should facilitate comparison of the jet pt spectra accross collision systems
double pt_bin_width =hJetPtMatched_R005->GetBinWidth(2);
double eta_bin_width =hJetEtaMatched_R005->GetBinWidth(2);
// Normalization of jet pt spectra
hJetPtMatched_R005->Scale(1./(pt_bin_width*e_weight)); hJetPtMatched_R010->Scale(1./(pt_bin_width*e_weight)); hJetPtMatched_R015->Scale(1./(pt_bin_width*e_weight));
hJetPtMatched_R020->Scale(1./(pt_bin_width*e_weight)); hJetPtMatched_R025->Scale(1./(pt_bin_width*e_weight)); hJetPtMatched_R030->Scale(1./(pt_bin_width*e_weight));
hJetPtMatched_R035->Scale(1./(pt_bin_width*e_weight));hJetPtMatched_R040->Scale(1./(pt_bin_width*e_weight));

// Normalization of jet eta distributions
hJetEtaMatched_R005->Scale(1./(eta_bin_width*e_weight)); hJetEtaMatched_R010->Scale(1./(eta_bin_width*e_weight)); hJetEtaMatched_R015->Scale(1./(eta_bin_width*e_weight));
hJetEtaMatched_R020->Scale(1./(eta_bin_width*e_weight)); hJetEtaMatched_R025->Scale(1./(eta_bin_width*e_weight)); hJetEtaMatched_R030->Scale(1./(eta_bin_width*e_weight));
hJetEtaMatched_R035->Scale(1./(eta_bin_width*e_weight)); hJetEtaMatched_R040->Scale(1./(eta_bin_width*e_weight));

//Calculate the mean and RMS graphs

// Constructor arrays for the mean and RMS graphs
Double_t R[7] = {.05,.1,.15,.2,.25,.3,.35};
Double_t R_err[7] = {0,0,0,0,0,0,0};
Double_t mean[7] ={pro_R005->GetMean(),pro_R010->GetMean(),pro_R015->GetMean(),pro_R020->GetMean(),pro_R025->GetMean(),pro_R030->GetMean(),pro_R035->GetMean()};

Double_t mean_err[7] ={pro_R005->GetMeanError(),pro_R010->GetMeanError(),pro_R015->GetMeanError(),pro_R020->GetMeanError(),pro_R025->GetMeanError(),pro_R030->GetMeanError(),pro_R035->GetMeanError()};

Double_t rms[7] ={pro_R005->GetRMS(),pro_R010->GetRMS(),pro_R015->GetRMS(),pro_R020->GetRMS(),pro_R025->GetRMS(),pro_R030->GetRMS(),pro_R035->GetRMS()};

Double_t rms_err[7] ={pro_R005->GetRMSError(),pro_R010->GetRMSError(),pro_R015->GetRMSError(),pro_R020->GetRMSError(),pro_R025->GetRMSError(),pro_R030->GetRMSError(),pro_R035->GetRMSError()};

// TGraph for the mean Dpt versus jet radius
 auto Mean_gr = new TGraphErrors(7,R,mean,R_err,mean_err);
        Mean_gr->SetMarkerSize(3);
        Mean_gr->SetFillStyle(3001);
        Mean_gr->SetLineWidth(2);
Mean_gr->SetTitle(TString::Format("Mean of the #Deltap_{T} distributions for jet p_{T}[%d,%d](JEWEL);R_{low}; Mean value",Ptlow,Pthigh));

// TGraph for the Dpt standard deviation versus jet radius
 auto RMS_gr = new TGraphErrors(7,R,rms,R_err,rms_err);
        RMS_gr->SetMarkerSize(3);
        RMS_gr->SetFillStyle(3001);
RMS_gr->SetTitle(TString::Format("Width of the #Deltap_{T} distributions for jet p_{T}[%d,%d](JEWEL);R_{low}; #sigma_{#Deltap_{T}}",Ptlow,Pthigh));


//-----------------------Plotting section--------------------------------//
//Histogram style choices
// Function to include general plotting choices
SetStyle2();

// Drawing options inherited from the official ALICE guidelines to improve visualisation
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

        //Set the plotting options for the jet pt spectra
        SetStyle(hJetPtMatched_R005,colors[0]); SetStyle(hJetPtMatched_R010,colors[1]);
        SetStyle(hJetPtMatched_R015,colors[2]); SetStyle(hJetPtMatched_R020,colors[3]);
        SetStyle(hJetPtMatched_R025,colors[4]); SetStyle(hJetPtMatched_R030,colors[5]);
        SetStyle(hJetPtMatched_R035,colors[6]); SetStyle(hJetPtMatched_R040,colors[7]);

        //Set the plotting options for the jet eta distributions
        SetStyle(hJetEtaMatched_R005,colors[0]); SetStyle(hJetEtaMatched_R010,colors[1]);
        SetStyle(hJetEtaMatched_R015,colors[2]); SetStyle(hJetEtaMatched_R020,colors[3]);
        SetStyle(hJetEtaMatched_R025,colors[4]); SetStyle(hJetEtaMatched_R030,colors[5]);
        SetStyle(hJetEtaMatched_R035,colors[6]); SetStyle(hJetEtaMatched_R040,colors[7]);

        //Set the plotting options for the normalized DR projections
        SetStyle(pro_dR_R005,colors[0]); SetStyle(pro_dR_R010,colors[1]);
        SetStyle(pro_dR_R015,colors[2]); SetStyle(pro_dR_R020,colors[3]);
        SetStyle(pro_dR_R025,colors[4]); SetStyle(pro_dR_R030,colors[5]);
        SetStyle(pro_dR_R035,colors[6]);

        //Set the plotting options for the normalized Dpt distributions
        SetStyle(pro_R005,colors[0]); SetStyle(pro_R010,colors[1]);
        SetStyle(pro_R015,colors[2]); SetStyle(pro_R020,colors[3]);
        SetStyle(pro_R025,colors[4]); SetStyle(pro_R030,colors[5]);
        SetStyle(pro_R035,colors[6]);


        Mean_gr->SetLineColor(colors[0]);Mean_gr->SetMarkerColor(colors[0]);
        Mean_gr->SetMarkerStyle(markers[4]);
        RMS_gr->SetLineColor(colors[0]);RMS_gr->SetMarkerColor(colors[0]);
        RMS_gr->SetMarkerStyle(markers[4]);

TLatex lat;lat.SetNDC();lat.SetTextFont(42);
TLatex lat1;lat1.SetNDC();lat1.SetTextFont(42);

//Plot Mjet pt spectra
TCanvas*c1 = new TCanvas("c1","c1",1000,1000);
TPad *pad=new TPad("pad","pad",0.,0.,1.,1.);
pad->SetLeftMargin(0.15);
  pad->SetBottomMargin(0.15);
  pad->SetTopMargin(0.1);
  pad->SetRightMargin(0.05);
pad->SetTicky(1);pad->SetLogy(1);
pad->Draw();
pad->cd();
pad->DrawFrame(0,1e-9,200,1,";#it{p}_{T,jet} (GeV/#it{c});#frac{1}{#it{#sigma}_{jets}} #frac{d#it{#sigma}}{d#it{p}_{T,jet}}");

 hJetPtMatched_R005->Draw("same E1");hJetPtMatched_R010->Draw("same E1");
 hJetPtMatched_R015->Draw("same E1");hJetPtMatched_R020->Draw("same E1");
 hJetPtMatched_R025->Draw("same E1");hJetPtMatched_R030->Draw("same E1");
 hJetPtMatched_R035->Draw("same E1");hJetPtMatched_R040->Draw("same E1");

//lat.DrawLatex(.42,.82,"This thesis");
lat.DrawLatex(.42,.75,"JEWEL pp");
if(sqrts==5)lat.DrawLatex(.64,.75,"#sqrt{#it{s}} =5.02 TeV");
else lat.DrawLatex(.64,.75,"#sqrt{#it{s}} =13 TeV");
lat.DrawLatex(.42,.68,"|#it{#eta}_{jet}| < 0.5");

auto leg1 = new TLegend(.6,.48,.91,.65); leg1->SetNColumns(2);
leg1->AddEntry(hJetPtMatched_R005,"#it{R} = 0.05","p"); leg1->AddEntry(hJetPtMatched_R010,"#it{R} = 0.1","p");
leg1->AddEntry(hJetPtMatched_R015,"#it{R} = 0.15","p"); leg1->AddEntry(hJetPtMatched_R020,"#it{R} = 0.2","p");
leg1->AddEntry(hJetPtMatched_R025,"#it{R} = 0.25","p"); leg1->AddEntry(hJetPtMatched_R030,"#it{R} = 0.3","p");
leg1->AddEntry(hJetPtMatched_R035,"#it{R} = 0.35","p"); leg1->AddEntry(hJetPtMatched_R040,"#it{R} = 0.4","p");
leg1->Draw();

//Plot Mjet eta distributions
TCanvas*c2 = new TCanvas("c2","c2",1000,1000);
TPad *pad2=new TPad("pad2","pad2",0.,0.,1.,1.);
pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.15);
  pad2->SetTopMargin(0.1);
  pad2->SetRightMargin(0.05);
pad2->SetTicky(1);//pad2->SetLogy(1);
pad2->Draw();
pad2->cd();
pad2->DrawFrame(-.6,5e-6,.6,1,";#it{#eta}_{jet};#frac{1}{#it{#sigma}_{jets}} #frac{d#it{#sigma}}{d#it{p}_{T,jet}}");
pad2->SetTicky(1);pad2->SetLogy(1);

 hJetEtaMatched_R005->Draw("same E1");hJetEtaMatched_R010->Draw("same E1");
 hJetEtaMatched_R015->Draw("same E1");hJetEtaMatched_R020->Draw("same E1");
 hJetEtaMatched_R025->Draw("same E1");hJetEtaMatched_R030->Draw("same E1");
 hJetEtaMatched_R035->Draw("same E1");hJetEtaMatched_R040->Draw("same E1");

//lat.DrawLatex(.42,.82,"This thesis");
lat.DrawLatex(.4,.76,"JEWEL pp");
if(sqrts==5)lat.DrawLatex(.63,.76,"#sqrt{#it{s}} =5.02 TeV");
else lat.DrawLatex(.63,.76,"#sqrt{#it{s}} =13 TeV");

auto leg12 = new TLegend(.6,.22,.91,.4); leg12->SetNColumns(2);
leg12->AddEntry(hJetEtaMatched_R005,"#it{R} = 0.05","p"); leg12->AddEntry(hJetEtaMatched_R010,"#it{R}= 0.1","p");
leg12->AddEntry(hJetEtaMatched_R015,"#it{R} = 0.15","p"); leg12->AddEntry(hJetEtaMatched_R020,"#it{R} = 0.2","p");
leg12->AddEntry(hJetEtaMatched_R025,"#it{R} = 0.25","p"); leg12->AddEntry(hJetEtaMatched_R030,"#it{R} = 0.3","p");
leg12->AddEntry(hJetEtaMatched_R035,"#it{R} = 0.35","p"); leg12->AddEntry(hJetEtaMatched_R040,"#it{R} = 0.4","p");
leg12->Draw();

//Plot DR projections
TCanvas*c3 = new TCanvas("c3","c3",1000,1000);
TPad *pad3=new TPad("pad3","pad3",0.,0.,1.,1.);
pad3->SetLeftMargin(0.15);
  pad3->SetBottomMargin(0.15);
  pad3->SetTopMargin(0.1);
  pad3->SetRightMargin(0.05);
pad3->SetTicky(1);
pad3->Draw();
pad3->cd();
pad3->DrawFrame(0,1e-4,.3,5e2,Form(";#it{#DeltaR}; #frac{1}{#it{#sigma}_{jets}} #frac{d#it{#sigma}}{d#it{#DeltaR}}"));
pad3->SetLogy(1);
pro_dR_R005->Draw("same E1");pro_dR_R010->Draw("same E1");
pro_dR_R015->Draw("same E1");pro_dR_R020->Draw("same E1");
pro_dR_R025->Draw("same E1");pro_dR_R030->Draw("same E1");
pro_dR_R035->Draw("same E1");

auto leg2_dR = new TLegend(.44,.46,.91,.66); leg2_dR->SetNColumns(2);
leg2_dR->AddEntry(pro_dR_R005,"#it{R}=0.05 to 0.1","p");leg2_dR->AddEntry(pro_dR_R010,"#it{R}=0.1 to 0.15","p");
leg2_dR->AddEntry(pro_dR_R015,"#it{R}=0.15 to 0.2","p");leg2_dR->AddEntry(pro_dR_R020,"#it{R}=0.2 to 0.25","p");
leg2_dR->AddEntry(pro_dR_R025,"#it{R}=0.25 to 0.3","p");leg2_dR->AddEntry(pro_dR_R030,"#it{R}=0.3 to 0.35","p");
leg2_dR->AddEntry(pro_dR_R035,"#it{R}=0.35 to 0.4","p");
leg2_dR->Draw();

//lat1.DrawLatex(.23,.82,"This thesis");
lat1.DrawLatex(.42,.76,"JEWEL pp");
if(sqrts==5)lat1.DrawLatex(.64,.76,"#sqrt{#it{s}} =5.02 TeV");
else lat1.DrawLatex(.64,.76,"#sqrt{#it{s}} =13 TeV");
//lat1.DrawLatex(.74,.76,"|#it{#eta}_{jet}| < 0.5");
lat1.DrawLatex(.42,.7,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

//Plot Dpt projections(all)
TCanvas*c4 = new TCanvas("c4","c4",1000,1000);
TPad *pad4=new TPad("pad4","pad4",0.,0.,1.,1.);
pad4->SetLeftMargin(0.15);pad4->SetBottomMargin(0.15);
pad4->SetTopMargin(0.1);pad4->SetRightMargin(0.05);
pad4->SetTicky(1);pad4->Draw();
pad4->cd();
pad4->DrawFrame(-0.5,1e-5,30.5,2,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{#sigma}_{jet}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}"));
pad4->SetLogy(1);

auto leg2 = new TLegend(.18,.18,.65,.33); leg2->SetNColumns(2);
leg2->AddEntry(pro_R005,"#it{R}=0.05 to 0.1","p");leg2->AddEntry(pro_R010,"#it{R}=0.1 to 0.15","p");
leg2->AddEntry(pro_R015,"#it{R}=0.15 to 0.2","p");leg2->AddEntry(pro_R020,"#it{R}=0.2 to 0.25","p");
leg2->AddEntry(pro_R025,"#it{R}=0.25 to 0.3","p");leg2->AddEntry(pro_R030,"#it{R}=0.3 to 0.35","p");
leg2->AddEntry(pro_R035,"#it{R}=0.35 to 0.4","p");

pro_R005->Draw("same E1");pro_R010->Draw("same E1");
pro_R015->Draw("same E1");pro_R020->Draw("same E1");
pro_R025->Draw("same E1");pro_R030->Draw("same E1");
pro_R035->Draw("same E1");
leg2->Draw();

//lat1.DrawLatex(.43,.84,"This thesis");
lat1.DrawLatex(.42,.78,"JEWEL pp");
if(sqrts==5) lat1.DrawLatex(.64,.78,"#sqrt{#it{s}} =5.02 TeV");
else lat1.DrawLatex(.64,.78,"#sqrt{#it{s}} =13 TeV");
//lat1.DrawLatex(.72,.78,"|#it{#eta}_{jet}| < 0.5");
lat1.DrawLatex(.42,.71,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

//Plot Dpt projections(Selection)
TCanvas*c4_sel = new TCanvas("c4_sel","c4_sel",1000,1000);
TPad *pad4_sel=new TPad("pad4_sel","pad4_sel",0.,0.,1.,1.);
pad4_sel->SetLeftMargin(0.15);pad4_sel->SetBottomMargin(0.15);
pad4_sel->SetTopMargin(0.1);pad4_sel->SetRightMargin(0.05);
pad4_sel->SetTicky(1);pad4_sel->Draw();
pad4_sel->cd();
pad4_sel->DrawFrame(-0.5,1e-5,30.5,2,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{#sigma}_{jet}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}"));
pad4_sel->SetLogy(1);
        
pro_R005->Draw("same E1");pro_R020->Draw("same E1");pro_R035->Draw("same E1");
auto leg2_sel = new TLegend(.18,.2,.45,.35);
leg2_sel->AddEntry(pro_R005,"#it{R}=0.05 to 0.1","p");
leg2_sel->AddEntry(pro_R020,"#it{R}=0.2 to 0.25","p");
leg2_sel->AddEntry(pro_R035,"#it{R}=0.35 to 0.4","p");
leg2_sel->Draw("same");
//lat1.DrawLatex(.43,.84,"This thesis");
lat1.DrawLatex(.42,.78,"JEWEL pp");
if (sqrts==5) lat1.DrawLatex(.64,.78,"#sqrt{#it{s}} =5.02 TeV");
else lat1.DrawLatex(.64,.78,"#sqrt{#it{s}} =13 TeV");
//lat1.DrawLatex(.72,.78,"|#it{#eta}_{jet}| < 0.5");
lat1.DrawLatex(.42,.71,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

//Plot Mean & RMS graphs (?)

//------------------Saving section-------------------------------------//
TFile*fout = new TFile(TString::Format("EF_jewel_pp_Sqrt%d_pt_%d_%d.root",sqrts,Ptlow,Pthigh),"RECREATE",TString::Format("EF_jewel_pp_Sqrt%d_pt_%d_%d.root",sqrts,Ptlow,Pthigh));
fout->cd();
pro_R005->Write("pro_R005",TObject::kOverwrite);pro_R010->Write("pro_R010",TObject::kOverwrite);
pro_R015->Write("pro_R015",TObject::kOverwrite);pro_R020->Write("pro_R020",TObject::kOverwrite);
pro_R025->Write("pro_R025",TObject::kOverwrite);pro_R030->Write("pro_R030",TObject::kOverwrite);
pro_R035->Write("pro_R035",TObject::kOverwrite);

pro_dR_R005->Write("pro_dR_R005",TObject::kOverwrite);pro_dR_R010->Write("pro_dR_R010",TObject::kOverwrite);
pro_dR_R015->Write("pro_dR_R015",TObject::kOverwrite);pro_dR_R020->Write("pro_dR_R020",TObject::kOverwrite);
pro_dR_R025->Write("pro_dR_R025",TObject::kOverwrite);pro_dR_R030->Write("pro_dR_R030",TObject::kOverwrite);
pro_dR_R035->Write("pro_dR_R035",TObject::kOverwrite);

hJetPtMatched_R005->Write("hJetPtMatched_R005",TObject::kOverwrite);hJetPtMatched_R010->Write("hJetPtMatched_R010",TObject::kOverwrite);hJetPtMatched_R015->Write("hJetPtMatched_R015",TObject::kOverwrite);
hJetPtMatched_R020->Write("hJetPtMatched_R020",TObject::kOverwrite);hJetPtMatched_R025->Write("hJetPtMatched_R025",TObject::kOverwrite);hJetPtMatched_R030->Write("hJetPtMatched_R030",TObject::kOverwrite);
hJetPtMatched_R035->Write("hJetPtMatched_R035",TObject::kOverwrite);hJetPtMatched_R040->Write("hJetPtMatched_R040",TObject::kOverwrite);




Mean_gr->Write(Form("Mean_gr_%d",sqrts),TObject::kOverwrite);
RMS_gr->Write(Form("RMS_gr_%d",sqrts),TObject::kOverwrite);
fout->Write();
                                                        }

void SetStyle(TH1* h1, int kColor){

                  h1->SetLineWidth(2); h1->SetLineColor(kColor);
                  h1->SetMarkerSize(3); h1->SetMarkerColor(kColor);
                  if(kColor<=4)h1->SetMarkerStyle(kFullDiamond);
                  else h1->SetMarkerStyle(kFullDiamond);
                 }
void SetStyle2(Bool_t graypalette) {
 gStyle->Reset("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  if(graypalette) gStyle->SetPalette(8,0);
  else gStyle->SetPalette(1);
  gStyle->SetTitleYOffset(1.0);
  gStyle->SetTitleXOffset(1.0);
  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPadColor(10);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineColor(kBlack);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(kGreen);
  gStyle->SetLineWidth(2);
  gStyle->SetLabelSize(0.04,"xyz");
  gStyle->SetLabelOffset(0.01,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelColor(kBlack,"xyz");
  gStyle->SetTitleSize(0.05,"xz");
  gStyle->SetTitleSize(0.04,"y");
  gStyle->SetTitleOffset(1.35,"y");
  gStyle->SetTitleOffset(1.1,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(30);
  gStyle->SetTextFont(42);
 gStyle->SetLegendBorderSize(1);
  gStyle->SetLegendFillColor(kWhite);
  gStyle->SetLegendFont(42);
}
     
