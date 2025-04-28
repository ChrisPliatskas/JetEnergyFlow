void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);

void EF_DataPlotter_pp(int Ptlow, int Pthigh, int sqrts){

TFile* f_in;

f_in = TFile::Open(Form("EF_ppdata_%dTeV_pt_%d_%d.root", sqrts, Ptlow, Pthigh));

//------------------------Extraction  section--------------------------//

//Get the matched jet pt spectra
TH1D*hJetPtMatched_R005;f_in->GetObject("hJetPtMatched_R005",hJetPtMatched_R005);
TH1D*hJetPtMatched_R010;f_in->GetObject("hJetPtMatched_R010",hJetPtMatched_R010);
TH1D*hJetPtMatched_R015;f_in->GetObject("hJetPtMatched_R015",hJetPtMatched_R015);
TH1D*hJetPtMatched_R020;f_in->GetObject("hJetPtMatched_R020",hJetPtMatched_R020);
TH1D*hJetPtMatched_R025;f_in->GetObject("hJetPtMatched_R025",hJetPtMatched_R025);
TH1D*hJetPtMatched_R030;f_in->GetObject("hJetPtMatched_R030",hJetPtMatched_R030);
TH1D*hJetPtMatched_R035;f_in->GetObject("hJetPtMatched_R035",hJetPtMatched_R035);
TH1D*hJetPtMatched_R040;f_in->GetObject("hJetPtMatched_R040",hJetPtMatched_R040);
//Get the matched jet eta distributions
TH1D*hJetEtaMatched_R005;f_in->GetObject("hJetEtaMatched_R005",hJetEtaMatched_R005);
TH1D*hJetEtaMatched_R010;f_in->GetObject("hJetEtaMatched_R010",hJetEtaMatched_R010);
TH1D*hJetEtaMatched_R015;f_in->GetObject("hJetEtaMatched_R015",hJetEtaMatched_R015);
TH1D*hJetEtaMatched_R020;f_in->GetObject("hJetEtaMatched_R020",hJetEtaMatched_R020);
TH1D*hJetEtaMatched_R025;f_in->GetObject("hJetEtaMatched_R025",hJetEtaMatched_R025);
TH1D*hJetEtaMatched_R030;f_in->GetObject("hJetEtaMatched_R030",hJetEtaMatched_R030);
TH1D*hJetEtaMatched_R035;f_in->GetObject("hJetEtaMatched_R035",hJetEtaMatched_R035);
TH1D*hJetEtaMatched_R040;f_in->GetObject("hJetEtaMatched_R040",hJetEtaMatched_R040);
//Get the Dpt projections
TH1D*pro_dpt_R005;f_in->GetObject("pro_dpt_R005",pro_dpt_R005);
TH1D*pro_dpt_R010;f_in->GetObject("pro_dpt_R010",pro_dpt_R010);
TH1D*pro_dpt_R015;f_in->GetObject("pro_dpt_R015",pro_dpt_R015);
TH1D*pro_dpt_R020;f_in->GetObject("pro_dpt_R020",pro_dpt_R020);
TH1D*pro_dpt_R025;f_in->GetObject("pro_dpt_R025",pro_dpt_R025);
TH1D*pro_dpt_R030;f_in->GetObject("pro_dpt_R030",pro_dpt_R030);
TH1D*pro_dpt_R035;f_in->GetObject("pro_dpt_R035",pro_dpt_R035);

//Get the Dpt projections(small)
TH1D*pro_dpt_R005_small;f_in->GetObject("pro_dpt_R005_small",pro_dpt_R005_small);
TH1D*pro_dpt_R010_small;f_in->GetObject("pro_dpt_R010_small",pro_dpt_R010_small);
TH1D*pro_dpt_R015_small;f_in->GetObject("pro_dpt_R015_small",pro_dpt_R015_small);
TH1D*pro_dpt_R020_small;f_in->GetObject("pro_dpt_R020_small",pro_dpt_R020_small);
TH1D*pro_dpt_R025_small;f_in->GetObject("pro_dpt_R025_small",pro_dpt_R025_small);
TH1D*pro_dpt_R030_small;f_in->GetObject("pro_dpt_R030_small",pro_dpt_R030_small);
TH1D*pro_dpt_R035_small;f_in->GetObject("pro_dpt_R035_small",pro_dpt_R035_small);

double binw =pro_dpt_R005_small->GetBinWidth(1);
for(int j=1;j<=pro_dpt_R005_small->GetNbinsX();j++){
        if(j>1){
        pro_dpt_R005_small->SetBinContent(j,pro_dpt_R005_small->GetBinContent(j)/0.15);
        pro_dpt_R010_small->SetBinContent(j,pro_dpt_R010_small->GetBinContent(j)/0.15);
        pro_dpt_R015_small->SetBinContent(j,pro_dpt_R015_small->GetBinContent(j)/0.15);
        pro_dpt_R020_small->SetBinContent(j,pro_dpt_R020_small->GetBinContent(j)/0.15);
        pro_dpt_R025_small->SetBinContent(j,pro_dpt_R025_small->GetBinContent(j)/0.15);
        pro_dpt_R030_small->SetBinContent(j,pro_dpt_R030_small->GetBinContent(j)/0.15);
        pro_dpt_R035_small->SetBinContent(j,pro_dpt_R035_small->GetBinContent(j)/0.15);
                }
        else{
        pro_dpt_R005_small->SetBinContent(j,pro_dpt_R005_small->GetBinContent(j)/binw);
        pro_dpt_R010_small->SetBinContent(j,pro_dpt_R010_small->GetBinContent(j)/binw);
        pro_dpt_R015_small->SetBinContent(j,pro_dpt_R015_small->GetBinContent(j)/binw);
        pro_dpt_R020_small->SetBinContent(j,pro_dpt_R020_small->GetBinContent(j)/binw);
        pro_dpt_R025_small->SetBinContent(j,pro_dpt_R025_small->GetBinContent(j)/binw);
        pro_dpt_R030_small->SetBinContent(j,pro_dpt_R030_small->GetBinContent(j)/binw);
        pro_dpt_R035_small->SetBinContent(j,pro_dpt_R035_small->GetBinContent(j)/binw);
        }
}


//Get the DR projections
TH1D*pro_dR_R005;f_in->GetObject("pro_dR_R005",pro_dR_R005);
TH1D*pro_dR_R010;f_in->GetObject("pro_dR_R010",pro_dR_R010);
TH1D*pro_dR_R015;f_in->GetObject("pro_dR_R015",pro_dR_R015);
TH1D*pro_dR_R020;f_in->GetObject("pro_dR_R020",pro_dR_R020);
TH1D*pro_dR_R025;f_in->GetObject("pro_dR_R025",pro_dR_R025);
TH1D*pro_dR_R030;f_in->GetObject("pro_dR_R030",pro_dR_R030);
TH1D*pro_dR_R035;f_in->GetObject("pro_dR_R035",pro_dR_R035);

//Extract mean & RMS graphs
/*
TGraphErrors* mean_pp;TGraphErrors* rms_pp;
f_in->GetObject("Mean_gr",mean_pp);
f_in->GetObject("RMS_gr",rms_pp);
*/

//-------------------------------Plotting section------------------------//
//Histogram manipulation
SetStyle2();
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

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
lat.DrawLatex(.38,.78,"ALICE pp raw data");
//lat.DrawLatex(.38,.72,"0-10\% Centrality");
if(sqrts==5)lat.DrawLatex(.61,.84,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat.DrawLatex(.61,.84,"#sqrt{#it{s}} =13 TeV");
lat.DrawLatex(.71,.72,"|#it{#eta}_{jet}| < 0.5");
//lat.DrawLatex(.38,.65,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");

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
pad2->DrawFrame(-.6,2e4,.6,2e6,";#it{#eta}_{jet};#it{N}_{jets}");
pad2->SetTicky(1);pad2->SetLogy(1);

 hJetEtaMatched_R005->Draw("same E1");hJetEtaMatched_R010->Draw("same E1");
 hJetEtaMatched_R015->Draw("same E1");hJetEtaMatched_R020->Draw("same E1");
 hJetEtaMatched_R025->Draw("same E1");hJetEtaMatched_R030->Draw("same E1");
 hJetEtaMatched_R035->Draw("same E1");hJetEtaMatched_R040->Draw("same E1");

lat.DrawLatex(.2,.84,"This thesis");
lat.DrawLatex(.43,.84,"ALICE pp raw data");
if(sqrts==5)lat.DrawLatex(.2,.78,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat.DrawLatex(.2,.78,"#sqrt{#it{s}} =13 TeV");
//lat.DrawLatex(.2,.72,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");

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
lat1.DrawLatex(.42,.79,"ALICE pp raw data");
if(sqrts==5)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =13 TeV");
lat1.DrawLatex(.42,.69,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

//Plot Dpt projections(all)
TCanvas*c4 = new TCanvas("c4","c4",1000,1000);
TPad *pad4=new TPad("pad4","pad4",0.,0.,1.,1.);
pad4->SetLeftMargin(0.15);pad4->SetBottomMargin(0.15);
pad4->SetTopMargin(0.1);pad4->SetRightMargin(0.05);
pad4->SetTicky(1);pad4->Draw();
pad4->cd();
pad4->DrawFrame(-0.5,1e-5,25.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{N}_{jet}} #frac{d#it{N}}{d#it{#Deltap}_{T}}"));
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
lat1.DrawLatex(.42,.79,"ALICE pp raw data");
if(sqrts==5)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =13 TeV");
lat1.DrawLatex(.42,.74,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

//Plot Dpt projections(Selection)
TCanvas*c4_sel = new TCanvas("c4_sel","c4_sel",1000,1000);
TPad *pad4_sel=new TPad("pad4_sel","pad4_sel",0.,0.,1.,1.);
pad4_sel->SetLeftMargin(0.15);pad4_sel->SetBottomMargin(0.15);
pad4_sel->SetTopMargin(0.1);pad4_sel->SetRightMargin(0.05);
pad4_sel->SetTicky(1);pad4_sel->Draw();
pad4_sel->cd();
pad4_sel->DrawFrame(-0.5,1e-5,25.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{N}_{jet}} #frac{d#it{N}}{d#it{#Deltap}_{T}}"));
pad4_sel->SetLogy(1);

pro_dpt_R005->Draw("same E1");pro_dpt_R020->Draw("same E1");pro_dpt_R035->Draw("same E1");
auto leg2_sel = new TLegend(.18,.22,.46,.37);
leg2_sel->AddEntry(pro_dpt_R005,"#it{R}=0.05 to 0.1","p");
leg2_sel->AddEntry(pro_dpt_R020,"#it{R}=0.2 to 0.25","p");
leg2_sel->AddEntry(pro_dpt_R035,"#it{R}=0.35 to 0.4","p");
leg2_sel->Draw("same");

lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE pp raw data");
if(sqrts==5)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =13 TeV");
lat1.DrawLatex(.42,.74,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

//Plot small Dpt projections(Selection)
TCanvas*c5_sel = new TCanvas("c5_sel","c5_sel",1000,1000);
TPad *pad5_sel=new TPad("pad5_sel","pad5_sel",0.,0.,1.,1.);
pad5_sel->SetLeftMargin(0.15);pad5_sel->SetBottomMargin(0.15);
pad5_sel->SetTopMargin(0.1);pad5_sel->SetRightMargin(0.05);
pad5_sel->SetTicky(1);pad5_sel->Draw();
pad5_sel->cd();
pad5_sel->DrawFrame(0.,1,2,1e4,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{d#it{N}}{d#it{#Deltap}_{T}}"));
pad5_sel->SetLogy(1);

pro_dpt_R005_small->Draw("same E1");pro_dpt_R010_small->Draw("same E1");
pro_dpt_R015_small->Draw("same E1");

auto leg_small1 =new TLegend(.18,.22,.46,.37);
leg_small1->AddEntry(pro_dpt_R005_small,"#it{R}=0.05 to 0.1","p");
leg_small1->AddEntry(pro_dpt_R010_small,"#it{R}=0.1 to 0.15","p");
leg_small1->AddEntry(pro_dpt_R015_small,"#it{R}=0.15 to 0.2","p");
leg_small1->Draw("same");

lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE pp raw data");
if(sqrts==5)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =13 TeV");
lat1.DrawLatex(.42,.74,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

TCanvas*c5_sel2 = new TCanvas("c5_sel2","c5_sel2",1000,1000);
TPad *pad5_sel2=new TPad("pad5_sel2","pad5_sel2",0.,0.,1.,1.);
pad5_sel2->SetLeftMargin(0.15);pad5_sel2->SetBottomMargin(0.15);
pad5_sel2->SetTopMargin(0.1);pad5_sel2->SetRightMargin(0.05);
pad5_sel2->SetTicky(1);pad5_sel2->Draw();
pad5_sel2->cd();
pad5_sel2->DrawFrame(0.,1,2,1e4,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{d#it{N}}{d#it{#Deltap}_{T}}"));
pad5_sel2->SetLogy(1);

pro_dpt_R020_small->Draw("same E1");pro_dpt_R025_small->Draw("same E1");
pro_dpt_R030_small->Draw("same E1");pro_dpt_R035_small->Draw("same E1");


auto leg_small2 =new TLegend(.18,.22,.46,.37);
leg_small2->AddEntry(pro_dpt_R020_small,"#it{R}=0.2 to 0.25","p");
leg_small2->AddEntry(pro_dpt_R025_small,"#it{R}=0.25 to 0.3","p");
leg_small2->AddEntry(pro_dpt_R030_small,"#it{R}=0.3 to 0.35","p");
leg_small2->AddEntry(pro_dpt_R035_small,"#it{R}=0.35 to 0.4","p");
leg_small2->Draw("same");


lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE pp raw data");
if(sqrts==5)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =5.02 TeV");
if(sqrts==13)lat1.DrawLatex(.62,.84,"#sqrt{#it{s}} =13 TeV");
lat1.DrawLatex(.42,.74,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));


//Plot Mean & RMS graphs?

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


