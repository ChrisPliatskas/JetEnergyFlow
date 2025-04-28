void SetStyle2(Bool_t graypalette=kFALSE);

void Final_Mean_plotter(){

//Open file
TFile* fin = TFile::Open("Final_Mean_Result_pp.root");

//Load graphs
TGraphErrors* mean_40; TGraphErrors* mean_60;
TGraphErrors* mean_sys_40; TGraphErrors* mean_sys_60;
TGraphErrors* rms_40; TGraphErrors* rms_60;
TGraphErrors* rms_sys_40; TGraphErrors* rms_sys_60;

fin->GetObject("Mean_graph_40_60",mean_40); fin->GetObject("Mean_graph_60_80",mean_60);
fin->GetObject("Mean_Sys_graph_40_60",mean_sys_40); fin->GetObject("Mean_Sys_graph_60_80",mean_sys_60);
fin->GetObject("RMS_graph_40_60",rms_40); fin->GetObject("RMS_graph_60_80",rms_60);
fin->GetObject("RMS_Sys_graph_40_60",rms_sys_40); fin->GetObject("RMS_Sys_graph_60_80",rms_sys_60);

//Plot mean
SetStyle2();
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7}; // for syst bands
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

TCanvas*mean = new TCanvas("mean","mean",1000,1000);
TPad *pad=new TPad("pad","pad",0.,0.,1.,1.);
pad->SetLeftMargin(0.15);
  pad->SetBottomMargin(0.15);
  pad->SetTopMargin(0.1);
  pad->SetRightMargin(0.05);
pad->SetTicky(1);pad->SetLogy(1);
pad->Draw();
pad->cd();
pad->SetLogy(1);
pad->DrawFrame(0,.5,.4,11,";#it{R}_{low};#LT#it{#Deltap}_{T}#GT (GeV/#it{c})");

mean_60->SetLineColor(colors[1]);mean_60->SetMarkerColor(colors[1]);
mean_sys_60->SetLineColor(colors[1]);mean_sys_60->SetMarkerColor(colors[1]);
rms_60->SetLineColor(colors[1]);rms_60->SetMarkerColor(colors[1]);
rms_sys_60->SetLineColor(colors[1]);rms_sys_60->SetMarkerColor(colors[1]);

mean_40->Draw("LPE"); mean_sys_40->Draw("same l E2");
mean_60->Draw("LPE"); mean_sys_60->Draw("same l E2");

auto leg = new TLegend(0.17, 0.17, 0.53, 0.35);
leg->AddEntry(mean_40,"40 < #it{p}_{T,ch jet} < 60 GeV/#it{c}","P");
leg->AddEntry(mean_60,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}","P");
leg->AddEntry(mean_sys_40,"System. unc.", "f");
leg->Draw("same");

TLatex lat;lat.SetNDC();lat.SetTextFont(42);
lat.DrawLatex(.42,.82,"This thesis");
lat.DrawLatex(.42,.77,"ALICE pp data");
lat.DrawLatex(.66,.77,"#sqrt{#it{s}} =13 TeV");

//Plot RMS

TCanvas*rms = new TCanvas("rms","rms",1000,1000);
TPad *pad2=new TPad("pad2","pad2",0.,0.,1.,1.);
pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.15);
  pad2->SetTopMargin(0.1);
  pad2->SetRightMargin(0.05);
pad2->SetTicky(1);pad->SetLogy(1);
pad2->Draw();
pad2->cd();
pad2->SetLogy(1);
pad2->DrawFrame(0,1,.4,11,";#it{R}_{low};#it{#sigma_{#Deltap}}_{T} (GeV/#it{c})");

rms_40->Draw("LPE"); rms_sys_40->Draw("same l E2");
rms_60->Draw("LPE"); rms_sys_60->Draw("same l E2");

leg->Draw("same");
lat.DrawLatex(.42,.82,"This thesis");
lat.DrawLatex(.42,.77,"ALICE pp data");
lat.DrawLatex(.66,.77,"#sqrt{#it{s}} =13 TeV");

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

