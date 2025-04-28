void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);


void Syst_Plotter_simplified(double Rjet, int ptlow, int pthigh){

int R = int(Rjet*100);

TFile*fTrackEff = TFile::Open(Form("Systematic_%d_%d_PbPb_TrackEff.root",ptlow,pthigh));
TH1D*pro_trackeff=(TH1D*) fTrackEff->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_trackeff=(TH1D*) fTrackEff->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Ratio_stat=(TH1D*) fTrackEff->Get(Form("Statistic_Ratio_R%03d",R));
TH1D*Var_trackeff =(TH1D*) fTrackEff->Get(Form("Systematic_variation_R%03d",R));
TH1D*pro_base=(TH1D*) fTrackEff->Get(Form("pro_base_R%03d",R));


TFile*f_Prior_mod1 = TFile::Open(Form("Systematic_%d_%d_PbPb_PriorScalingDPt5percent_mod1.root",ptlow,pthigh));
TH1D*pro_Prior_mod1=(TH1D*) f_Prior_mod1->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_Prior_mod1=(TH1D*) f_Prior_mod1->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_Prior_mod1=(TH1D*) f_Prior_mod1->Get(Form("Systematic_variation_R%03d",R));

TFile*f_Prior_mod2 = TFile::Open(Form("Systematic_%d_%d_PbPb_PriorScalingDPt5percent_mod2.root",ptlow,pthigh));
TH1D*pro_Prior_mod2=(TH1D*) f_Prior_mod2->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_Prior_mod2=(TH1D*) f_Prior_mod2->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_Prior_mod2=(TH1D*) f_Prior_mod2->Get(Form("Systematic_variation_R%03d",R));

TFile*f_N4 = TFile::Open(Form("Systematic_%d_%d_PbPb_Niter4.root",ptlow,pthigh));
TH1D*pro_N4=(TH1D*) f_N4->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_N4=(TH1D*) f_N4->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_N4=(TH1D*) f_N4->Get(Form("Systematic_variation_R%03d",R));

TFile*f_N6 = TFile::Open(Form("Systematic_%d_%d_PbPb_Niter6.root",ptlow,pthigh));
TH1D*pro_N6=(TH1D*) f_N6->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_N6=(TH1D*) f_N6->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_N6=(TH1D*) f_N6->Get(Form("Systematic_variation_R%03d",R));


TFile*f_bkg005 = TFile::Open(Form("Systematic_%d_%d_PbPb_Bkgsub005.root",ptlow,pthigh));
TH1D*pro_bkg005=(TH1D*) f_bkg005->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_bkg005=(TH1D*) f_bkg005->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_bkg005=(TH1D*) f_bkg005->Get(Form("Systematic_variation_R%03d",R));

TFile*f_bkg03 = TFile::Open(Form("Systematic_%d_%d_PbPb_Bkgsub030.root",ptlow,pthigh));
TH1D*pro_bkg03=(TH1D*) f_bkg03->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_bkg03=(TH1D*) f_bkg03->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_bkg03=(TH1D*) f_bkg03->Get(Form("Systematic_variation_R%03d",R));

TFile*f_trunc = TFile::Open(Form("Systematic_%d_%d_PbPb_Truncation.root",ptlow,pthigh));
TH1D*pro_trunc=(TH1D*) f_trunc->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_trunc=(TH1D*) f_trunc->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_trunc=(TH1D*) f_trunc->Get(Form("Systematic_variation_R%03d",R));

TFile*f_LC = TFile::Open(Form("Systematic_%d_%d_PbPb_LC.root",ptlow,pthigh));
TH1D*pro_LC=(TH1D*) f_LC->Get(Form("pro_sys_R%03d",R));
TH1D*Ratio_LC=(TH1D*) f_LC->Get(Form("Systematic_Ratio_R%03d",R));
TH1D*Var_LC=(TH1D*) f_LC->Get(Form("Systematic_variation_R%03d",R));

TH1D* Ratio_Niter = (TH1D*)Ratio_LC->Clone(); Ratio_Niter->Reset();
TH1D* Ratio_Prior = (TH1D*)Ratio_LC->Clone(); Ratio_Prior->Reset();
TH1D* Ratio_BkgSub = (TH1D*)Ratio_LC->Clone(); Ratio_BkgSub->Reset();

Int_t Nbins = Ratio_N4->GetNbinsX();
double N4[11] = {}; double N6[11] = {};
double prior1[11] = {}; double prior2[11] = {};
double bkg005[11] = {}; double bkg03[11] = {};
double Prior[11] ={}; double Niter[11] = {};
double BkgSub[11] ={};

for(int i=1;i<=Nbins;i++){
        bkg005[i-1] = Ratio_bkg005->GetBinContent(i);
        bkg03[i-1] = Ratio_bkg03->GetBinContent(i);
        prior1[i-1] = Ratio_Prior_mod1->GetBinContent(i);
        prior2[i-1] = Ratio_Prior_mod2->GetBinContent(i);
        N4[i-1] = Ratio_N4->GetBinContent(i);
        N6[i-1] = Ratio_N6->GetBinContent(i);
        Prior[i-1] = abs(prior1[i-1] - prior2[i-1])/2;
        Niter[i-1] = abs(N6[i-1] - N4[i-1])/2;
        BkgSub[i-1] = abs(bkg03[i-1]-bkg005[i-1])/2;                
                        }

for(int ibin=1;ibin<=Nbins;ibin++){
        Ratio_Niter->SetBinContent(ibin,Niter[ibin-1]);
        Ratio_Prior->SetBinContent(ibin,Prior[ibin-1]);
        Ratio_BkgSub->SetBinContent(ibin,BkgSub[ibin-1]);
        }

SetStyle2();
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

TLatex lat;lat.SetNDC();lat.SetTextFont(42);

Ratio_stat->SetLineColor(colors[0]);Ratio_trackeff->SetLineColor(colors[1]);
Ratio_Niter->SetLineColor(colors[2]);Ratio_trunc->SetLineColor(colors[3]);
Ratio_LC->SetLineColor(colors[4]); Ratio_Prior->SetLineColor(colors[5]);
Ratio_BkgSub->SetLineColor(colors[6]);

Ratio_stat->SetLineWidth(3);Ratio_trackeff->SetLineWidth(3);
Ratio_Niter->SetLineWidth(3);Ratio_trunc->SetLineWidth(3);
Ratio_Prior->SetLineWidth(3);Ratio_LC->SetLineWidth(3);
Ratio_BkgSub->SetLineWidth(3);

TLine *l11 = new TLine(-1.5,0.,28.5,0.);
l11->SetLineColor(1);l11->SetLineStyle(1);l11->SetLineWidth(1);

TCanvas* c1= new TCanvas("c1","c1",1000,1000); 
TPad *pad1=new TPad("pad1","pad1",0.,0.,1.,1.);
  pad1->SetLeftMargin(0.15);
  pad1->SetBottomMargin(0.15);
  pad1->SetTopMargin(0.1);
  pad1->SetRightMargin(0.05);
  pad1->SetTicky(1);
  pad1->SetGridy(0);
  pad1->Draw();
  pad1->cd();
  pad1->DrawFrame(-1.5,-.5,28.5,.5,";#it{#Deltap}_{T} (GeV/#it{c});Systematic variation ratio");

 Ratio_stat->Draw("same");  Ratio_trackeff->Draw("same");
 Ratio_Niter->Draw("same"); Ratio_trunc->Draw("same");
 Ratio_Prior->Draw("same"); Ratio_LC->Draw("same");
 Ratio_BkgSub->Draw("same");
 l11->Draw("same");
  auto leg1 = new TLegend(.19,.18,.65,.45);
  leg1->AddEntry(Ratio_stat,"Statistical","l");
  leg1->AddEntry(Ratio_trackeff,"Tracking efficiency","l");
  leg1->AddEntry(Ratio_Niter,"Unfolding: N_{iter}","l");
  leg1->AddEntry(Ratio_trunc,"Unfolding: Truncation","l");
  leg1->AddEntry(Ratio_Prior,"Unfolding: Prior variation","l");
  leg1->AddEntry(Ratio_LC,"Leading track cut","l");
  leg1->AddEntry(Ratio_BkgSub,"Background subtraction","l");

  leg1->Draw("same");

  lat.DrawLatex(.2,.84,"This thesis");
  lat.DrawLatex(.2,.79,"ALICE Pb-Pb #sqrt{#it{s_{NN}}} =5.02 TeV");
  lat.DrawLatex(.2,.74,Form("R_{jet}=%0.2f to R_{jet}=%0.2f",Rjet,Rjet+0.05));
  lat.DrawLatex(.2,.69,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",ptlow,pthigh));


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
  gStyle->SetLineWidth(1);
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

void SetStyle(TH1* h1, int kColor){

                  h1->SetLineWidth(2); h1->SetLineColor(kColor);
                  h1->SetMarkerSize(3); h1->SetMarkerColor(kColor);
                  if(kColor<=4)h1->SetMarkerStyle(kFullDiamond);
                  else h1->SetMarkerStyle(kFullDiamond);
                 }
