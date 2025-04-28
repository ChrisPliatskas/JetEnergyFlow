void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);

void EF_DataPlotterPbPb(int Ptlow, int Pthigh){

TFile* f_smallR;
TFile* f_largeR;

f_smallR = TFile::Open(Form("SmallR/EF_PbPbdata_smallR_pt_%d_%d.root",Ptlow,Pthigh));
f_largeR = TFile::Open(Form("LargeR/EF_PbPbdata_largeR_pt_%d_%d.root",Ptlow,Pthigh));

//-----------------------Extraction section----------------------//

//Get the matched jet pt spectra
TH1D*hJetPtMatched_R005;f_smallR->GetObject("hJetPtMatched_R005",hJetPtMatched_R005);
TH1D*hJetPtMatched_R010;f_smallR->GetObject("hJetPtMatched_R010",hJetPtMatched_R010);
TH1D*hJetPtMatched_R015;f_smallR->GetObject("hJetPtMatched_R015",hJetPtMatched_R015);
TH1D*hJetPtMatched_R020;f_smallR->GetObject("hJetPtMatched_R020",hJetPtMatched_R020);
TH1D*hJetPtMatched_R025;f_largeR->GetObject("hJetPtMatched_R025",hJetPtMatched_R025);
TH1D*hJetPtMatched_R030;f_largeR->GetObject("hJetPtMatched_R030",hJetPtMatched_R030);
TH1D*hJetPtMatched_R035;f_largeR->GetObject("hJetPtMatched_R035",hJetPtMatched_R035);
TH1D*hJetPtMatched_R040;f_largeR->GetObject("hJetPtMatched_R040",hJetPtMatched_R040);
//Get the matched jet eta distributions
TH1D*hJetEtaMatched_R005;f_smallR->GetObject("hJetEtaMatched_R005",hJetEtaMatched_R005);
TH1D*hJetEtaMatched_R010;f_smallR->GetObject("hJetEtaMatched_R010",hJetEtaMatched_R010);
TH1D*hJetEtaMatched_R015;f_smallR->GetObject("hJetEtaMatched_R015",hJetEtaMatched_R015);
TH1D*hJetEtaMatched_R020;f_smallR->GetObject("hJetEtaMatched_R020",hJetEtaMatched_R020);
TH1D*hJetEtaMatched_R025;f_largeR->GetObject("hJetEtaMatched_R025",hJetEtaMatched_R025);
TH1D*hJetEtaMatched_R030;f_largeR->GetObject("hJetEtaMatched_R030",hJetEtaMatched_R030);
TH1D*hJetEtaMatched_R035;f_largeR->GetObject("hJetEtaMatched_R035",hJetEtaMatched_R035);
TH1D*hJetEtaMatched_R040;f_largeR->GetObject("hJetEtaMatched_R040",hJetEtaMatched_R040);
//Get the Dpt projections
TH1D*pro_dpt_R005;f_smallR->GetObject("pro_dpt_R005",pro_dpt_R005);
TH1D*pro_dpt_R010;f_smallR->GetObject("pro_dpt_R010",pro_dpt_R010);
TH1D*pro_dpt_R015;f_smallR->GetObject("pro_dpt_R015",pro_dpt_R015);
TH1D*pro_dpt_R020;f_smallR->GetObject("pro_dpt_R020",pro_dpt_R020);
TH1D*pro_dpt_R025;f_largeR->GetObject("pro_dpt_R025",pro_dpt_R025);
TH1D*pro_dpt_R030;f_largeR->GetObject("pro_dpt_R030",pro_dpt_R030);
TH1D*pro_dpt_R035;f_largeR->GetObject("pro_dpt_R035",pro_dpt_R035);

//Get the DR projections
TH1D*pro_dR_R005;f_smallR->GetObject("pro_dR_R005",pro_dR_R005);
TH1D*pro_dR_R010;f_smallR->GetObject("pro_dR_R010",pro_dR_R010);
TH1D*pro_dR_R015;f_smallR->GetObject("pro_dR_R015",pro_dR_R015);
TH1D*pro_dR_R020;f_smallR->GetObject("pro_dR_R020",pro_dR_R020);
TH1D*pro_dR_R025;f_largeR->GetObject("pro_dR_R025",pro_dR_R025);
TH1D*pro_dR_R030;f_largeR->GetObject("pro_dR_R030",pro_dR_R030);
TH1D*pro_dR_R035;f_largeR->GetObject("pro_dR_R035",pro_dR_R035);

//-----------------------Calculation section-------------------//
//Extraction of Mean & RMS
Double_t R[7] = {.05,.1,.15,.2,.25,.3,.35};
Double_t R_err[7] = {0,0,0,0,0,0,0};
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

//-----------------------Plotting section---------------------//
//Histogram manipulation
SetStyle2();
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

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
pad->DrawFrame(0,1,200,1e8,";#it{p}_{T,jet} (GeV/#it{c});#it{N}_{jets}");

 hJetPtMatched_R005->Draw("same E1");hJetPtMatched_R010->Draw("same E1");
 hJetPtMatched_R015->Draw("same E1");hJetPtMatched_R020->Draw("same E1");
 hJetPtMatched_R025->Draw("same E1");hJetPtMatched_R030->Draw("same E1");
 hJetPtMatched_R035->Draw("same E1");hJetPtMatched_R040->Draw("same E1");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"ALICE Pb-Pb raw data");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.71,.72,"|#it{#eta}_{jet}| < 0.5");
lat.DrawLatex(.38,.65,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");

auto leg1 = new TLegend(.18,.18,.49,.35); leg1->SetNColumns(2);
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
pad2->DrawFrame(-.6,5.5e5,.6,1e6,";#it{#eta}_{jet};#it{N}_{jets}");
pad2->SetTicky(1);pad2->SetLogy(1);

 hJetEtaMatched_R005->Draw("same E1");hJetEtaMatched_R010->Draw("same E1");
 hJetEtaMatched_R015->Draw("same E1");hJetEtaMatched_R020->Draw("same E1");
 hJetEtaMatched_R025->Draw("same E1");hJetEtaMatched_R030->Draw("same E1");
 hJetEtaMatched_R035->Draw("same E1");hJetEtaMatched_R040->Draw("same E1");

lat.DrawLatex(.2,.84,"This thesis");
lat.DrawLatex(.43,.84,"ALICE Pb-Pb raw data");
lat.DrawLatex(.53,.78,"0-10\% Centrality");
lat.DrawLatex(.2,.78,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.2,.72,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");

auto leg12 = new TLegend(.2,.2,.51,.38); leg12->SetNColumns(2);
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
pad3->DrawFrame(0,1e-4,.3,5e2,Form(";#it{#DeltaR}; #frac{1}{#it{N}_{jets}} #frac{d#it{N}}{d#it{#DeltaR}}"));
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

lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE Pb-Pb raw data");
lat1.DrawLatex(.62,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat1.DrawLatex(.42,.74,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat1.DrawLatex(.42,.69,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));



//Plot Dpt projections(all)
TCanvas*c4 = new TCanvas("c4","c4",1000,1000);
TPad *pad4=new TPad("pad4","pad4",0.,0.,1.,1.);
pad4->SetLeftMargin(0.15);pad4->SetBottomMargin(0.15);
pad4->SetTopMargin(0.1);pad4->SetRightMargin(0.05);
pad4->SetTicky(1);pad4->Draw();
pad4->cd();
pad4->DrawFrame(-0.5,5e-5,25.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{N}_{jet}} #frac{d#it{N}}{d#it{#Deltap}_{T}}"));
pad4->SetLogy(1);

auto leg2 = new TLegend(.16,.17,.6,.32); leg2->SetNColumns(2);
leg2->AddEntry(pro_dpt_R005,"#it{R}=0.05 to 0.1","p");leg2->AddEntry(pro_dpt_R010,"#it{R}=0.1 to 0.15","p");
leg2->AddEntry(pro_dpt_R015,"#it{R}=0.15 to 0.2","p");leg2->AddEntry(pro_dpt_R020,"#it{R}=0.2 to 0.25","p");
leg2->AddEntry(pro_dpt_R025,"#it{R}=0.25 to 0.3","p");leg2->AddEntry(pro_dpt_R030,"#it{R}=0.3 to 0.35","p");
leg2->AddEntry(pro_dpt_R035,"#it{R}=0.35 to 0.4","p");

pro_dpt_R005->Draw("same E1");pro_dpt_R010->Draw("same E1");
pro_dpt_R015->Draw("same E1");pro_dpt_R020->Draw("same E1");
pro_dpt_R025->Draw("same E1");pro_dpt_R030->Draw("same E1");
pro_dpt_R035->Draw("same E1");
leg2->Draw();

lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE Pb-Pb raw data");
lat1.DrawLatex(.62,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat1.DrawLatex(.42,.74,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat1.DrawLatex(.42,.69,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));



//Plot Dpt projections(Selection)
TCanvas*c4_sel = new TCanvas("c4_sel","c4_sel",1000,1000);
TPad *pad4_sel=new TPad("pad4_sel","pad4_sel",0.,0.,1.,1.);
pad4_sel->SetLeftMargin(0.15);pad4_sel->SetBottomMargin(0.15);
pad4_sel->SetTopMargin(0.1);pad4_sel->SetRightMargin(0.05);
pad4_sel->SetTicky(1);pad4_sel->Draw();
pad4_sel->cd();
pad4_sel->DrawFrame(-0.5,5e-5,25.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{N}_{jet}} #frac{d#it{N}}{d#it{#Deltap}_{T}}"));
pad4_sel->SetLogy(1);

pro_dpt_R005->Draw("same E1");pro_dpt_R020->Draw("same E1");pro_dpt_R035->Draw("same E1");
auto leg2_sel = new TLegend(.18,.22,.46,.37);
leg2_sel->AddEntry(pro_dpt_R005,"#it{R}=0.05 to 0.1","p");
leg2_sel->AddEntry(pro_dpt_R020,"#it{R}=0.2 to 0.25","p");
leg2_sel->AddEntry(pro_dpt_R035,"#it{R}=0.35 to 0.4","p");
leg2_sel->Draw("same");

lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE Pb-Pb raw data");
lat1.DrawLatex(.62,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat1.DrawLatex(.42,.74,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat1.DrawLatex(.42,.69,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));


/*
//Plot Mean & RMS graphs?
TCanvas*MEAN= new TCanvas("MEAN","MEAN",1000,1000);
TPad *pad_mean=new TPad("pad_mean","pad_mean",0.,0.,1.,1.);
pad_mean->SetLeftMargin(0.15);pad_mean->SetBottomMargin(0.15);
pad_mean->SetTopMargin(0.05);pad_mean->SetRightMargin(0.1);
pad_mean->SetTicky(1);pad_mean->Draw();
pad_mean->SetLogy(1);
pad_mean->cd();
pad_mean->DrawFrame(0,.7,.4,13,";#it{R}_{low};#LT#it{#Deltap}_{T}#GT (GeV/#it{c})");
mean_pp->Draw("LPE");

auto leg_mean = new TLegend(.2,.25,.45,.38);
leg_mean->AddEntry(mean_pp,"pp","p");
//leg_mean->AddEntry(mean_norec,"AA w/o recoil","p");
//leg_mean->AddEntry(mean_recoil,"AA w recoil","p");
leg_mean->Draw("same");

lat.DrawLatex(.38,.86,"JEWEL #sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.79,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}");

TCanvas*RMS= new TCanvas("RMS","RMS",1000,1000);
TPad *pad_rms=new TPad("pad_rms","pad_rms",0.,0.,1.,1.);
pad_rms->SetLeftMargin(0.15);pad_rms->SetBottomMargin(0.15);
pad_rms->SetTopMargin(0.05);pad_rms->SetRightMargin(0.1);
pad_rms->SetTicky(1);pad_rms->Draw();
pad_rms->SetLogy(1);
pad_rms->cd();
pad_rms->DrawFrame(0,.7,.4,12,";#it{R}_{low};#it{#sigma_{#Deltap}}_{T} (GeV/#it{c})");

rms_pp->Draw("LPE"); rms_norec->Draw("LPE"); rms_recoil->Draw("LPE");

auto leg_rms = new TLegend(.2,.25,.45,.38);
leg_rms->AddEntry(rms_pp,"pp","p");
//leg_rms->AddEntry(rms_norec,"AA w/o recoil","p");
//leg_rms->AddEntry(rms_recoil,"AA w recoil","p");
leg_rms->Draw("same");

lat.DrawLatex(.38,.86,"JEWEL #sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.79,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}");
*/
//------------------Saving section-------------------------------------//



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
  gStyle->SetHistLineColor(kRed);
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
