void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);
void EF_ClosurePlotterpp(double Rjet, int Ptlow, int Pthigh){

TFile* f_N2; TFile* f_N3; TFile* f_N4; TFile* f_N5; TFile* f_N6; TFile* f_N8; TFile* f_N12;

TH1D* pro_unf_N2; TH1D* pro_unf_N3; TH1D* pro_unf_N4; TH1D* pro_unf_N5; TH1D* pro_unf_N6; TH1D* pro_unf_N8; TH1D* pro_unf_N12;
TH1D* pro_ref_N2; TH1D* pro_ref_N3; TH1D* pro_ref_N4; TH1D* pro_ref_N5; TH1D* pro_ref_N6; TH1D* pro_ref_N8; TH1D* pro_ref_N12;
TH1D* Ratio_unf_N2; TH1D* Ratio_unf_N3; TH1D* Ratio_unf_N4; TH1D* Ratio_unf_N5; TH1D* Ratio_unf_N6; TH1D* Ratio_unf_N8; TH1D* Ratio_unf_N12;
TH1D* Ratio_Ref_N2; TH1D* Ratio_Ref_N3; TH1D* Ratio_Ref_N4; TH1D* Ratio_Ref_N5; TH1D* Ratio_Ref_N6; TH1D* Ratio_Ref_N8; TH1D* Ratio_Ref_N12;

TH1D*pro_test_truth;TH1D*pro_test;
f_N2 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter2.root",Ptlow,Pthigh));

f_N3 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter3.root",Ptlow,Pthigh));

f_N4 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter4.root",Ptlow,Pthigh));

f_N5 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter5.root",Ptlow,Pthigh));

f_N6 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter6.root",Ptlow,Pthigh));

f_N8 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter8.root",Ptlow,Pthigh));

f_N12 = TFile::Open(Form("ClosureTest_pp_wFakes_2016_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter12.root",Ptlow,Pthigh));

        //Extraction Section
 pro_test_truth = (TH1D*)(f_N2->Get(Form("pro_test_truth_R%03d",int(Rjet*100))));
 pro_test = (TH1D*)(f_N2->Get(Form("pro_test_R%03d",int(Rjet*100))));

 pro_unf_N2 = (TH1D*)(f_N2->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));
 pro_unf_N3 = (TH1D*)(f_N3->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));
 pro_unf_N4 = (TH1D*)(f_N4->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));
 pro_unf_N5 = (TH1D*)(f_N5->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));
 pro_unf_N6 = (TH1D*)(f_N6->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));
 pro_unf_N8 = (TH1D*)(f_N8->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));
 pro_unf_N12 = (TH1D*)(f_N12->Get(Form("pro_unfolded_test_R%03d",int(Rjet*100))));

 pro_ref_N2 = (TH1D*)(f_N2->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));
 pro_ref_N3 = (TH1D*)(f_N3->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));
 pro_ref_N4 = (TH1D*)(f_N4->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));
 pro_ref_N5 = (TH1D*)(f_N5->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));
 pro_ref_N6 = (TH1D*)(f_N6->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));
 pro_ref_N8 = (TH1D*)(f_N8->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));
 pro_ref_N12 = (TH1D*)(f_N12->Get(Form("pro_refolded_test_R%03d",int(Rjet*100))));


 Ratio_unf_N2 = (TH1D*)(f_N2->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));
 Ratio_unf_N3 = (TH1D*)(f_N3->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));
 Ratio_unf_N4 = (TH1D*)(f_N4->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));
 Ratio_unf_N5 = (TH1D*)(f_N5->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));
 Ratio_unf_N6 = (TH1D*)(f_N6->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));
 Ratio_unf_N8 = (TH1D*)(f_N8->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));
 Ratio_unf_N12 = (TH1D*)(f_N12->Get(Form("Ratio_Unftest_truth_R%03d",int(Rjet*100))));


 Ratio_Ref_N2 = (TH1D*)(f_N2->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));
 Ratio_Ref_N3 = (TH1D*)(f_N3->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));
 Ratio_Ref_N4 = (TH1D*)(f_N4->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));
 Ratio_Ref_N5 = (TH1D*)(f_N5->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));
 Ratio_Ref_N6 = (TH1D*)(f_N6->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));
 Ratio_Ref_N8 = (TH1D*)(f_N8->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));
 Ratio_Ref_N12 = (TH1D*)(f_N12->Get(Form("Ratio_Reftest_R%03d",int(Rjet*100))));

        //Statistical Ratio calculation
        TH1D*Stat_Ratio = (TH1D*)Ratio_unf_N2->Clone("Stat_Ratio");Stat_Ratio->Reset();
        for(int k=1;k<=Stat_Ratio->GetNbinsX();k++){
        Stat_Ratio->SetBinContent(k,1);
        Stat_Ratio->SetBinError(k,pro_test_truth->GetBinError(k)/pro_test_truth->GetBinContent(k)    );
                                                }

        TH1D*Stat_Ratio_det = (TH1D*)Ratio_Ref_N2->Clone("Stat_Ratio_det");Stat_Ratio_det->Reset();
        for(int k=1;k<=Stat_Ratio_det->GetNbinsX();k++){
        Stat_Ratio_det->SetBinContent(k,1);
        Stat_Ratio_det->SetBinError(k,pro_test->GetBinError(k)/pro_test->GetBinContent(k));}

        Stat_Ratio_det->SetLineColor(1);Stat_Ratio_det->SetLineWidth(2);Stat_Ratio_det->SetMarkerStyle(1);
        Stat_Ratio->SetLineColor(1);Stat_Ratio->SetLineWidth(2);Stat_Ratio->SetMarkerStyle(1);

        //Histogram manipulation
SetStyle2();
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

        SetStyle(pro_unf_N2,colors[1]);SetStyle(pro_unf_N3,colors[2]);
        SetStyle(pro_unf_N4,colors[3]);SetStyle(pro_unf_N5,colors[4]);
        SetStyle(pro_unf_N6,colors[5]);SetStyle(pro_unf_N8,colors[6]);
        SetStyle(pro_unf_N12,colors[7]);

        SetStyle(pro_ref_N2,colors[1]);SetStyle(pro_ref_N3,colors[2]);
        SetStyle(pro_ref_N4,colors[3]);SetStyle(pro_ref_N5,colors[4]);
        SetStyle(pro_ref_N6,colors[5]);SetStyle(pro_ref_N8,colors[6]);
        SetStyle(pro_ref_N12,colors[7]);

        SetStyle(Ratio_unf_N2,colors[1]);SetStyle(Ratio_unf_N3,colors[2]);
        SetStyle(Ratio_unf_N4,colors[3]);SetStyle(Ratio_unf_N5,colors[4]);
        SetStyle(Ratio_unf_N6,colors[5]);SetStyle(Ratio_unf_N8,colors[6]);
        SetStyle(Ratio_unf_N12,colors[7]);

        SetStyle(Ratio_Ref_N2,colors[1]);SetStyle(Ratio_Ref_N3,colors[2]);
        SetStyle(Ratio_Ref_N4,colors[3]);SetStyle(Ratio_Ref_N5,colors[4]);
        SetStyle(Ratio_Ref_N6,colors[5]);SetStyle(Ratio_Ref_N8,colors[6]);
        SetStyle(Ratio_Ref_N12,colors[7]);

        pro_test_truth->SetMarkerStyle(markers[2]);pro_test_truth->SetMarkerColor(1);
        pro_test_truth->SetLineColor(1);pro_test_truth->SetLineWidth(2);
        pro_test_truth->SetMarkerSize(3);

        pro_test->SetMarkerStyle(markers[2]);pro_test->SetMarkerColor(1);
        pro_test->SetLineColor(1);pro_test->SetLineWidth(2);pro_test->SetMarkerSize(3);

        //Plotting Section
TH1F* H_top = new TH1F("H_top","",10,-1.5,25.5);H_top->GetYaxis()->SetRangeUser(1e-5,2);
H_top->GetYaxis()->SetTitle("#frac{1}{#it{#sigma}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}");
H_top->GetYaxis()->SetTitleOffset(0.85);
H_top->GetYaxis()->SetLabelSize(0.06);
H_top->GetYaxis()->SetTitleSize(0.06);
TH1F* H_bot = new TH1F("H_bot","",10,-1.5,25.5);H_bot->GetYaxis()->SetRangeUser(.9,1.1);
H_bot->GetYaxis()->SetLabelSize(0.1);//gStyle->GetLabelSize("Y")*.7/.3);
H_bot->GetXaxis()->SetLabelSize(0.13);//gStyle->GetLabelSize("X")*.7/.3);
H_bot->GetYaxis()->SetNdivisions(505);
H_bot->GetYaxis()->SetTitle("#frac{Unfolded}{Truth}");
H_bot->GetYaxis()->SetTitleSize(0.14);H_bot->GetYaxis()->SetTitleOffset(0.45);
H_bot->GetXaxis()->SetTitle("#it{#Deltap}_{T} (GeV/#it{c})");H_bot->GetXaxis()->SetTitleSize(0.14);H_bot->GetXaxis()->SetTitleOffset(0.95);
H_bot->GetXaxis()->SetTickLength(0.07);

       //Plotting of closure on truth level
TCanvas* Closure_Truth =new TCanvas("Closure_Truth","Closure_Truth",1000,1000);
  TPad *pad_top=new TPad("pad_top","pad_top",0.,0.3,1.,1.);
  pad_top->SetLeftMargin(0.15);
  pad_top->SetBottomMargin(0.001);
  pad_top->SetRightMargin(0.05);
  pad_top->SetTopMargin(0.1);
  pad_top->SetNumber(1);
  pad_top->Draw();
  TPad *pad_bot=new TPad("pad_bot","pad_bot",0.,0.,1.,0.3);
  pad_bot->SetLeftMargin(0.15);
  pad_bot->SetBottomMargin(0.3);
  pad_bot->SetTopMargin(0.04);
  pad_bot->SetRightMargin(0.05);
  pad_bot->SetNumber(2);
pad_bot->Draw();
TLatex lat;lat.SetNDC();lat.SetTextFont(42);

auto leg = new TLegend(0.2, 0.13, 0.53, 0.33);
        leg->SetNColumns(2);
        leg->AddEntry(pro_test_truth,"Truth","p");
        leg->AddEntry(pro_unf_N2,"N_{iter}=2","p");
        leg->AddEntry(pro_unf_N3,"N_{iter}=3","p");
        leg->AddEntry(pro_unf_N4,"N_{iter}=4","p");
        leg->AddEntry(pro_unf_N5,"N_{iter}=5","p");
        leg->AddEntry(pro_unf_N6,"N_{iter}=6","p");
        leg->AddEntry(pro_unf_N8,"N_{iter}=8","p");
        leg->AddEntry(pro_unf_N12,"N_{iter}=12","p");
pad_top->cd();pad_top->SetLogy(1);
pad_top->DrawFrame(-1.5,2e-5,25.5,2,";#Deltap_{T} (GeV/#it{c}); #frac{1}{#sigma} #frac{d#sigma}{d#Deltap_{T}}");
H_top->SetMinimum(2e-5);H_top->SetMaximum(2);H_top->Draw();
pro_test_truth->Draw("same E1");pro_unf_N2->Draw("same E1");pro_unf_N3->Draw("same E1");
pro_unf_N4->Draw("same E1");pro_unf_N5->Draw("same E1");pro_unf_N6->Draw("same E1");
pro_unf_N8->Draw("same E1");pro_unf_N12->Draw("same E1");
leg->Draw();
lat.DrawLatex(.35,.82,"This thesis");
lat.DrawLatex(.56,.82,"ALICE PYTHIA");
//lat.DrawLatex(.59,.79,"0-10\% Centrality");
lat.DrawLatex(.35,.75,"#sqrt{#it{s}} =13 TeV");
//lat.DrawLatex(.35,.73,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.56,.75,Form("#it{R}_{jet} = %.2f to %.2f",Rjet,Rjet+0.05));
lat.DrawLatex(.35,.68,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

pad_bot->cd();
pad_bot->DrawFrame(-1.5,0.9,25.5,1.1,";#Deltap_{T} (GeV/#it{c});#frac{Unfolded}{Truth};");
H_bot->SetMaximum(1.1);
H_bot->Draw();
 Ratio_unf_N2->Draw("same hist p");Ratio_unf_N3->Draw("same hist p");Ratio_unf_N4->Draw("same hist p");
Ratio_unf_N5->Draw("same hist p");Ratio_unf_N6->Draw("same hist p");Ratio_unf_N8->Draw("same hist p");
Ratio_unf_N12->Draw("same hist p");Stat_Ratio->Draw("same E1");

        //Plotting of closure on detector level
TH1F* H_top2 = new TH1F("H_top2","",10,-1.5,25.5);H_top2->GetYaxis()->SetRangeUser(1e-5,2);
H_top2->GetYaxis()->SetTitle("#frac{1}{#it{#sigma}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}");
H_top2->GetYaxis()->SetTitleOffset(0.85);
H_top2->GetYaxis()->SetLabelSize(0.06);
H_top2->GetYaxis()->SetTitleSize(0.06);
TH1F* H_bot2 = new TH1F("H_bot2","",10,-1.5,25.5);H_bot2->GetYaxis()->SetRangeUser(.9,1.1);
H_bot2->GetYaxis()->SetLabelSize(0.1);//gStyle->GetLabelSize("Y")*.7/.3);
H_bot2->GetXaxis()->SetLabelSize(0.13);//gStyle->GetLabelSize("X")*.7/.3);
H_bot2->GetYaxis()->SetNdivisions(505);
H_bot2->GetYaxis()->SetTitle("#frac{Refolded}{Recon.}");
H_bot2->GetYaxis()->SetTitleSize(0.14);H_bot2->GetYaxis()->SetTitleOffset(0.45);
H_bot2->GetXaxis()->SetTitle("#it{#Deltap}_{T} (GeV/#it{c})");H_bot2->GetXaxis()->SetTitleSize(0.14);H_bot2->GetXaxis()->SetTitleOffset(0.95);
H_bot2->GetXaxis()->SetTickLength(0.07);

TCanvas* Closure_Detector =new TCanvas("Closure_Detector","Closure_Detector",1000,1000);
  TPad *pad_top2=new TPad("pad_top2","pad_top2",0.,0.3,1.,1.);
  pad_top2->SetLeftMargin(0.15);
  pad_top2->SetBottomMargin(0.001);
  pad_top2->SetRightMargin(0.05);
  pad_top2->SetTopMargin(0.1);
  pad_top2->SetNumber(1);
  pad_top2->Draw();
  TPad *pad_bot2=new TPad("pad_bot2","pad_bot2",0.,0.,1.,0.3);
  pad_bot2->SetLeftMargin(0.15);
  pad_bot2->SetBottomMargin(0.3);
  pad_bot2->SetTopMargin(0.04);
  pad_bot2->SetRightMargin(0.05);
  pad_bot2->SetNumber(2);
  pad_bot2->Draw();
auto leg2 = new TLegend(0.2, 0.13, 0.57, 0.33);
        leg2->SetNColumns(2);
        leg2->AddEntry(pro_test,"Reconstructed","p");
        leg2->AddEntry(pro_ref_N2,"N_{iter}=2","p");
        leg2->AddEntry(pro_ref_N3,"N_{iter}=3","p");
        leg2->AddEntry(pro_ref_N4,"N_{iter}=4","p");
        leg2->AddEntry(pro_ref_N5,"N_{iter}=5","p");
        leg2->AddEntry(pro_ref_N6,"N_{iter}=6","p");
        leg2->AddEntry(pro_ref_N8,"N_{iter}=8","p");
        leg2->AddEntry(pro_ref_N12,"N_{iter}=12","p");
pad_top2->cd();pad_top2->SetLogy(1);

pad_top2->DrawFrame(-1.5,2e-5,25.5,2,";#Deltap_{T} (GeV/#it{c}); #frac{1}{#sigma} #frac{d#sigma}{d#Deltap_{T}}");
H_top2->SetMinimum(2e-5);H_top2->SetMaximum(2);H_top2->Draw();
pro_test->Draw("same E1");pro_ref_N2->Draw("same E1");pro_ref_N3->Draw("same E1");
pro_ref_N4->Draw("same E1");pro_ref_N5->Draw("same E1");pro_ref_N6->Draw("same E1");
pro_ref_N8->Draw("same E1");pro_ref_N12->Draw("same E1");
leg2->Draw();
lat.DrawLatex(.35,.82,"This thesis");
lat.DrawLatex(.56,.82,"ALICE PYTHIA");
//lat.DrawLatex(.59,.79,"0-10\% Centrality");
lat.DrawLatex(.35,.75,"#sqrt{#it{s}} =13 TeV");
//lat.DrawLatex(.35,.73,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.56,.75,Form("#it{R}_{jet} = %.2f to %.2f",Rjet,Rjet+0.05));
lat.DrawLatex(.35,.68,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));
pad_bot2->cd();
pad_bot2->DrawFrame(-1.5,0.9,25.5,1.1,";#Deltap_{T} (GeV/#it{c});#frac{Refolded}{Recon.};");
H_bot2->SetMaximum(1.1);
H_bot2->Draw();
 Ratio_Ref_N2->Draw("same hist p");Ratio_Ref_N3->Draw("same hist p");Ratio_Ref_N4->Draw("same hist p");
Ratio_Ref_N5->Draw("same hist p");Ratio_Ref_N6->Draw("same hist p");Ratio_Ref_N8->Draw("same hist p");
Ratio_Ref_N12->Draw("same hist p");Stat_Ratio_det->Draw("same E1");



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

