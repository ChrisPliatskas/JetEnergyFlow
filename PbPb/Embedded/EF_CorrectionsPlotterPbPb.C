TH2D* RM_normalization(TH2D* input_RM);
void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);
void EF_CorrectionsPlotter(const char* f_unf,const char* f_unf2,int Ptlow, int Pthigh){

TFile* f_QA_smallR; TFile* f_QA_LargeR;
TFile* f_Closure_smallR; TFile* f_Closure_LargeR;
TFile* f_unfold;TFile* f_unfold2;

//Extraction section

        //Open the Files
f_QA_smallR = TFile::Open(Form("SmallR/EF_embed_smallR_pt_%d_%d.root", Ptlow, Pthigh));
f_QA_LargeR = TFile::Open(Form("LargeR/EF_embed_LargeR_pt_%d_%d.root", Ptlow, Pthigh));

//f_Closure_smallR = TFile::Open(Form("Closure/SmallR/ClosureTest_ConstSub_wFakes_LCJC_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter4.root", Ptlow, Pthigh);

//f_Closure_LargeR = TFile::Open(Form("Closure/LargeR/ClosureTest_ConstSub_wFakes_LCJC_LargeR_Binw3_LC8_pt_%d_%d_ptmin15_Dptmin-1_max25_Iter4.root", Ptlow, Pthigh);

f_unfold = TFile::Open(f_unf);
f_unfold2 = TFile::Open(f_unf2);

        //Extract JER projections
TH1D*pro_JER_R005;f_QA_smallR->GetObject("pro_JER_R005",pro_JER_R005);
TH1D*pro_JER_R010;f_QA_smallR->GetObject("pro_JER_R010",pro_JER_R010);
TH1D*pro_JER_R015;f_QA_smallR->GetObject("pro_JER_R015",pro_JER_R015);
TH1D*pro_JER_R020;f_QA_smallR->GetObject("pro_JER_R020",pro_JER_R020);
TH1D*pro_JER_R025;f_QA_LargeR->GetObject("pro_JER_R025",pro_JER_R025);
TH1D*pro_JER_R030;f_QA_LargeR->GetObject("pro_JER_R030",pro_JER_R030);
TH1D*pro_JER_R035;f_QA_LargeR->GetObject("pro_JER_R035",pro_JER_R035);

        //Extract the Dpt resolution projections
TH1D*pro_delta_R005;f_QA_smallR->GetObject("pro_delta_R005",pro_delta_R005);
TH1D*pro_delta_R010;f_QA_smallR->GetObject("pro_delta_R010",pro_delta_R010);
TH1D*pro_delta_R015;f_QA_smallR->GetObject("pro_delta_R015",pro_delta_R015);
TH1D*pro_delta_R020;f_QA_smallR->GetObject("pro_delta_R020",pro_delta_R020);
TH1D*pro_delta_R025;f_QA_LargeR->GetObject("pro_delta_R025",pro_delta_R025);
TH1D*pro_delta_R030;f_QA_LargeR->GetObject("pro_delta_R030",pro_delta_R030);
TH1D*pro_delta_R035;f_QA_LargeR->GetObject("pro_delta_R035",pro_delta_R035);

        //Extract the RM for pt
TH2D*Pt_RM_R005;f_QA_smallR->GetObject("Pt_RM_R005_norm",Pt_RM_R005);
TH2D*Pt_RM_R010;f_QA_smallR->GetObject("Pt_RM_R010_norm",Pt_RM_R010);
TH2D*Pt_RM_R015;f_QA_smallR->GetObject("Pt_RM_R015_norm",Pt_RM_R015);
TH2D*Pt_RM_R020;f_QA_smallR->GetObject("Pt_RM_R020_norm",Pt_RM_R020);
TH2D*Pt_RM_R025;f_QA_LargeR->GetObject("Pt_RM_R025_norm",Pt_RM_R025);
TH2D*Pt_RM_R030;f_QA_LargeR->GetObject("Pt_RM_R030_norm",Pt_RM_R030);
TH2D*Pt_RM_R035;f_QA_LargeR->GetObject("Pt_RM_R035_norm",Pt_RM_R035);

        //Extract the RM for Dpt
TH2D*Dpt_RM_R005;f_unfold->GetObject("DPt_ResponseMatrix_R005_0",Dpt_RM_R005);
TH2D*Dpt_RM_R010;f_unfold->GetObject("DPt_ResponseMatrix_R010_0",Dpt_RM_R010);
TH2D*Dpt_RM_R015;f_unfold->GetObject("DPt_ResponseMatrix_R015_0",Dpt_RM_R015);
TH2D*Dpt_RM_R020;f_unfold->GetObject("DPt_ResponseMatrix_R020_0",Dpt_RM_R020);
TH2D*Dpt_RM_R025;f_unfold2->GetObject("DPt_ResponseMatrix_R005_0",Dpt_RM_R025);
TH2D*Dpt_RM_R030;f_unfold2->GetObject("DPt_ResponseMatrix_R010_0",Dpt_RM_R030);
TH2D*Dpt_RM_R035;f_unfold2->GetObject("DPt_ResponseMatrix_R015_0",Dpt_RM_R035);

Dpt_RM_R005->Rebin2D(3,3);Dpt_RM_R010->Rebin2D(3,3);Dpt_RM_R015->Rebin2D(3,3);
Dpt_RM_R020->Rebin2D(3,3);Dpt_RM_R025->Rebin2D(3,3);Dpt_RM_R030->Rebin2D(3,3);
Dpt_RM_R035->Rebin2D(3,3);

TH2D* Dpt_RM_R005_norm =RM_normalization(Dpt_RM_R005);
TH2D* Dpt_RM_R010_norm =RM_normalization(Dpt_RM_R010);
TH2D* Dpt_RM_R015_norm =RM_normalization(Dpt_RM_R015);
TH2D* Dpt_RM_R020_norm =RM_normalization(Dpt_RM_R020);
TH2D* Dpt_RM_R025_norm =RM_normalization(Dpt_RM_R025);
TH2D* Dpt_RM_R030_norm =RM_normalization(Dpt_RM_R030);
TH2D* Dpt_RM_R035_norm =RM_normalization(Dpt_RM_R035);


        //Extract the Unfolded distribution
TH1D*pro_unf_Dpt_R005;f_unfold->GetObject("pro_unfolded_data_R005",pro_unf_Dpt_R005);
TH1D*pro_unf_Dpt_R010;f_unfold->GetObject("pro_unfolded_data_R010",pro_unf_Dpt_R010);
TH1D*pro_unf_Dpt_R015;f_unfold->GetObject("pro_unfolded_data_R015",pro_unf_Dpt_R015);
TH1D*pro_unf_Dpt_R020;f_unfold->GetObject("pro_unfolded_data_R020",pro_unf_Dpt_R020);

/*        //Extract the closure tests
TH1D*pro_unfolded_test_R005;f_Closure_smallR->GetObject("pro_unfolded_test_R005",pro_unfolded_test_R005);
TH1D*pro_unfolded_test_R010;f_Closure_smallR->GetObject("pro_unfolded_test_R010",pro_unfolded_test_R010);
TH1D*pro_unfolded_test_R015;f_Closure_smallR->GetObject("pro_unfolded_test_R015",pro_unfolded_test_R015);
TH1D*pro_unfolded_test_R020;f_Closure_smallR->GetObject("pro_unfolded_test_R020",pro_unfolded_test_R020);
TH1D*pro_unfolded_test_R025;f_Closure_LargeR->GetObject("pro_unfolded_test_R025",pro_unfolded_test_R025);
TH1D*pro_unfolded_test_R030;f_Closure_LargeR->GetObject("pro_unfolded_test_R010",pro_unfolded_test_R030);
TH1D*pro_unfolded_test_R035;f_Closure_LargeR->GetObject("pro_unfolded_test_R035",pro_unfolded_test_R035);


TH1D*pro_refolded_test_R005;f_Closure_smallR->GetObject("pro_refolded_test_R005",pro_refolded_test_R005);
TH1D*pro_refolded_test_R010;f_Closure_smallR->GetObject("pro_refolded_test_R010",pro_refolded_test_R010);
TH1D*pro_refolded_test_R015;f_Closure_smallR->GetObject("pro_refolded_test_R015",pro_refolded_test_R015);
TH1D*pro_refolded_test_R020;f_Closure_smallR->GetObject("pro_refolded_test_R020",pro_refolded_test_R020);
TH1D*pro_refolded_test_R025;f_Closure_LargeR->GetObject("pro_refolded_test_R025",pro_refolded_test_R025);
TH1D*pro_refolded_test_R030;f_Closure_LargeR->GetObject("pro_refolded_test_R010",pro_refolded_test_R030);
TH1D*pro_refolded_test_R035;f_Closure_LargeR->GetObject("pro_refolded_test_R035",pro_refolded_test_R035);
*/


//Histogram manipulation

        //Normalize the unfolded distributions
        int Dpt_low_bin = pro_unf_Dpt_R005->GetXaxis()->FindBin(0.);
        int Dpt_high_bin = pro_unf_Dpt_R005->GetXaxis()->FindBin(25.);

        pro_unf_Dpt_R005->GetXaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        pro_unf_Dpt_R010->GetXaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        pro_unf_Dpt_R015->GetXaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
        pro_unf_Dpt_R020->GetXaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);

        pro_unf_Dpt_R005->Scale(1./pro_unf_Dpt_R005->Integral("width"));
        pro_unf_Dpt_R010->Scale(1./pro_unf_Dpt_R010->Integral("width"));
        pro_unf_Dpt_R015->Scale(1./pro_unf_Dpt_R015->Integral("width"));
        pro_unf_Dpt_R020->Scale(1./pro_unf_Dpt_R020->Integral("width"));

        //Calculate unfolded Mean & RMS
Double_t R[4] = {.05,.1,.15,.2};
Double_t R_err[4] = {0,0,0,0};

Double_t mean[4] ={pro_unf_Dpt_R005->GetMean(),pro_unf_Dpt_R010->GetMean(),pro_unf_Dpt_R015->GetMean(),pro_unf_Dpt_R020->GetMean()};
Double_t mean_err[4] ={pro_unf_Dpt_R005->GetMeanError(),pro_unf_Dpt_R010->GetMeanError(),pro_unf_Dpt_R015->GetMeanError(),pro_unf_Dpt_R020->GetMeanError()};

Double_t rms[4] ={pro_unf_Dpt_R005->GetRMS(),pro_unf_Dpt_R010->GetRMS(),pro_unf_Dpt_R015->GetRMS(),pro_unf_Dpt_R020->GetRMS()};
Double_t rms_err[4] ={pro_unf_Dpt_R005->GetRMSError(),pro_unf_Dpt_R010->GetRMSError(),pro_unf_Dpt_R015->GetRMSError(),pro_unf_Dpt_R020->GetRMSError()};

 auto Mean_gr = new TGraphErrors(4,R,mean,R_err,mean_err);
        Mean_gr->SetMarkerSize(3);
        Mean_gr->SetFillStyle(3001);
        Mean_gr->SetLineWidth(2);
Mean_gr->SetTitle(TString::Format("Mean of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; Mean value",Ptlow,Pthigh));

 auto RMS_gr = new TGraphErrors(4,R,rms,R_err,rms_err);
        RMS_gr->SetMarkerSize(3);
        RMS_gr->SetFillStyle(3001);
RMS_gr->SetTitle(TString::Format("Width of the #Deltap_{T} distributions for jet p_{T}[%d,%d];R_{low}; #sigma_{#Deltap_{T}}",Ptlow,Pthigh));

TLatex lat;lat.SetNDC();lat.SetTextFont(42);
TLatex lat1;lat1.SetNDC();lat1.SetTextFont(42);

SetStyle2();
const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

        SetStyle(pro_unf_Dpt_R005,colors[0]); SetStyle(pro_unf_Dpt_R010,colors[1]);
        SetStyle(pro_unf_Dpt_R015,colors[2]); SetStyle(pro_unf_Dpt_R020,colors[3]);


        Mean_gr->SetLineColor(colors[0]);Mean_gr->SetMarkerColor(colors[0]);
        Mean_gr->SetMarkerStyle(markers[4]);
        RMS_gr->SetLineColor(colors[0]);RMS_gr->SetMarkerColor(colors[0]);
        RMS_gr->SetMarkerStyle(markers[4]);


//Plotting section

        //Plotting JER plots
TCanvas*c1 = new TCanvas("c1","c1",1000,1000);
TPad *pad=new TPad("pad","pad",0.,0.,1.,1.);
pad->SetLeftMargin(0.15);
  pad->SetBottomMargin(0.15);
  pad->SetTopMargin(0.1);
  pad->SetRightMargin(0.05);
pad->SetTicky(1);//pad->SetLogy(1);
pad->Draw();
pad->cd();
pad->DrawFrame(-1,0,1,1e-5,";#frac{#it{p}_{T,hyb}-#it{p}_{T,truth}}{#it{p}_{T,truth}};#it{#sigma}_{jets}");

 pro_JER_R005->Draw("same E1");pro_JER_R010->Draw("same E1");
 pro_JER_R015->Draw("same E1");pro_JER_R020->Draw("same E1");
 pro_JER_R025->Draw("same E1");pro_JER_R030->Draw("same E1");
 pro_JER_R035->Draw("same E1");

lat.DrawLatex(.2,.84,"This thesis");
lat.DrawLatex(.4,.84,"Embedded ALICE PYTHIA");
lat.DrawLatex(.47,.79,"0-10\% Centrality");
lat.DrawLatex(.2,.79,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.2,.74,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");

auto leg1 = new TLegend(.62,.4,.93,.57); leg1->SetNColumns(2);
leg1->AddEntry(pro_JER_R005,"#it{R} = 0.05","p"); leg1->AddEntry(pro_JER_R010,"#it{R} = 0.1","p");
leg1->AddEntry(pro_JER_R015,"#it{R} = 0.15","p"); leg1->AddEntry(pro_JER_R020,"#it{R} = 0.2","p");
leg1->AddEntry(pro_JER_R025,"#it{R} = 0.25","p"); leg1->AddEntry(pro_JER_R030,"#it{R} = 0.3","p");
leg1->AddEntry(pro_JER_R035,"#it{R} = 0.35","p"); 
leg1->Draw();

        //Plotting the Dpt resolution projections
TCanvas*c2 = new TCanvas("c2","c2",1000,1000);
TPad *pad2=new TPad("pad2","pad2",0.,0.,1.,1.);
pad2->SetLeftMargin(0.15);
  pad2->SetBottomMargin(0.15);
  pad2->SetTopMargin(0.1);
  pad2->SetRightMargin(0.05);
pad2->SetTicky(1);//pad->SetLogy(1);
pad2->Draw();
pad2->cd();
pad2->DrawFrame(-30.,0,30,4e-5,";#it{#Deltap}_{T,hyb}- #it{#Deltap}_{T,truth} (GeV/#it{c});#it{#sigma}_{jets}");

 pro_delta_R005->Draw("same E1");pro_delta_R010->Draw("same E1");
 pro_delta_R015->Draw("same E1");pro_delta_R020->Draw("same E1");
 pro_delta_R025->Draw("same E1");pro_delta_R030->Draw("same E1");
 pro_delta_R035->Draw("same E1");

lat.DrawLatex(.2,.84,"This thesis");
lat.DrawLatex(.4,.84,"Embedded ALICE PYTHIA");
lat.DrawLatex(.47,.79,"0-10\% Centrality");
lat.DrawLatex(.2,.79,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.2,.74,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");

auto leg2 = new TLegend(.18,.18,.49,.35); leg2->SetNColumns(1);
leg2->AddEntry(pro_delta_R005,"#it{R}=0.05 to 0.1","p");leg2->AddEntry(pro_delta_R010,"#it{R}=0.1 to 0.15","p");
leg2->AddEntry(pro_delta_R015,"#it{R}=0.15 to 0.2","p");leg2->AddEntry(pro_delta_R020,"#it{R}=0.2 to 0.25","p");
leg2->AddEntry(pro_delta_R025,"#it{R}=0.25 to 0.3","p");leg2->AddEntry(pro_delta_R030,"#it{R}=0.3 to 0.35","p");
leg2->AddEntry(pro_delta_R035,"#it{R}=0.35 to 0.4","p");
leg2->Draw();

        //Plotting the RM for pt

        //R =0.05
TCanvas*c_pt_RM_r005 = new TCanvas("c_pt_RM_r005","c_pt_RM_r005",1000,1000);
TPad *pad_pt_RM_r005=new TPad("pad_pt_RM_r005","pad_pt_RM_r005",0.,0.,1.,1.);
pad_pt_RM_r005->SetLeftMargin(0.15);pad_pt_RM_r005->SetBottomMargin(0.15);
pad_pt_RM_r005->SetTopMargin(0.1);pad_pt_RM_r005->SetRightMargin(0.13);
pad_pt_RM_r005->SetTicky(1);pad_pt_RM_r005->Draw();
pad_pt_RM_r005->cd();
pad_pt_RM_r005->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r005->SetLogz(1);

Pt_RM_R005->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.05");


        //R=0.1
TCanvas*c_pt_RM_r010 = new TCanvas("c_pt_RM_r010","c_pt_RM_r010",1000,1000);
TPad *pad_pt_RM_r010=new TPad("pad_pt_RM_r010","pad_pt_RM_r010",0.,0.,1.,1.);
pad_pt_RM_r010->SetLeftMargin(0.15);pad_pt_RM_r010->SetBottomMargin(0.15);
pad_pt_RM_r010->SetTopMargin(0.1);pad_pt_RM_r010->SetRightMargin(0.13);
pad_pt_RM_r010->SetTicky(1);pad_pt_RM_r010->Draw();
pad_pt_RM_r010->cd();
pad_pt_RM_r010->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r010->SetLogz(1);

Pt_RM_R010->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.1");

        //R=0.15
TCanvas*c_pt_RM_r015 = new TCanvas("c_pt_RM_r015","c_pt_RM_r015",1000,1000);
TPad *pad_pt_RM_r015=new TPad("pad_pt_RM_r015","pad_pt_RM_r015",0.,0.,1.,1.);
pad_pt_RM_r015->SetLeftMargin(0.15);pad_pt_RM_r015->SetBottomMargin(0.15);
pad_pt_RM_r015->SetTopMargin(0.1);pad_pt_RM_r015->SetRightMargin(0.13);
pad_pt_RM_r015->SetTicky(1);pad_pt_RM_r015->Draw();
pad_pt_RM_r015->cd();
pad_pt_RM_r015->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r015->SetLogz(1);

Pt_RM_R015->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.15");
        //R=0.2
TCanvas*c_pt_RM_r020 = new TCanvas("c_pt_RM_r020","c_pt_RM_r020",1000,1000);
TPad *pad_pt_RM_r020=new TPad("pad_pt_RM_r020","pad_pt_RM_r020",0.,0.,1.,1.);
pad_pt_RM_r020->SetLeftMargin(0.15);pad_pt_RM_r020->SetBottomMargin(0.15);
pad_pt_RM_r020->SetTopMargin(0.1);pad_pt_RM_r020->SetRightMargin(0.13);
pad_pt_RM_r020->SetTicky(1);pad_pt_RM_r020->Draw();
pad_pt_RM_r020->cd();
pad_pt_RM_r020->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r020->SetLogz(1);

Pt_RM_R020->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.2");

//R=0.25
TCanvas*c_pt_RM_r025 = new TCanvas("c_pt_RM_r025","c_pt_RM_r025",1000,1000);
TPad *pad_pt_RM_r025=new TPad("pad_pt_RM_r025","pad_pt_RM_r025",0.,0.,1.,1.);
pad_pt_RM_r025->SetLeftMargin(0.15);pad_pt_RM_r025->SetBottomMargin(0.15);
pad_pt_RM_r025->SetTopMargin(0.1);pad_pt_RM_r025->SetRightMargin(0.13);
pad_pt_RM_r025->SetTicky(1);pad_pt_RM_r025->Draw();
pad_pt_RM_r025->cd();
pad_pt_RM_r025->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r025->SetLogz(1);

Pt_RM_R025->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.25");
//R=0.3

TCanvas*c_pt_RM_r030 = new TCanvas("c_pt_RM_r030","c_pt_RM_r030",1000,1000);
TPad *pad_pt_RM_r030=new TPad("pad_pt_RM_r030","pad_pt_RM_r030",0.,0.,1.,1.);
pad_pt_RM_r030->SetLeftMargin(0.15);pad_pt_RM_r030->SetBottomMargin(0.15);
pad_pt_RM_r030->SetTopMargin(0.1);pad_pt_RM_r030->SetRightMargin(0.13);
pad_pt_RM_r030->SetTicky(1);pad_pt_RM_r030->Draw();
pad_pt_RM_r030->cd();
pad_pt_RM_r030->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r030->SetLogz(1);

Pt_RM_R030->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.3");
//R=0.35
TCanvas*c_pt_RM_r035 = new TCanvas("c_pt_RM_r035","c_pt_RM_r035",1000,1000);
TPad *pad_pt_RM_r035=new TPad("pad_pt_RM_r035","pad_pt_RM_r035",0.,0.,1.,1.);
pad_pt_RM_r035->SetLeftMargin(0.15);pad_pt_RM_r035->SetBottomMargin(0.15);
pad_pt_RM_r035->SetTopMargin(0.1);pad_pt_RM_r035->SetRightMargin(0.13);
pad_pt_RM_r035->SetTicky(1);pad_pt_RM_r035->Draw();
pad_pt_RM_r035->cd();
pad_pt_RM_r035->DrawFrame(15,8,120,200,";#it{p}_{T,hyb}(GeV/#it{c});#it{p}_{T,truth}(GeV/#it{c})");
pad_pt_RM_r035->SetLogz(1);

Pt_RM_R035->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.35");

        //Plotting the RM for Dpt
        //R=0.05
TCanvas*c_dpt_RM_r005 = new TCanvas("c_dpt_RM_r005","c_dpt_RM_r005",1000,1000);
TPad *pad_dpt_RM_r005=new TPad("pad_pt_RM_r005","pad_pt_RM_r005",0.,0.,1.,1.);
pad_dpt_RM_r005->SetLeftMargin(0.15);pad_dpt_RM_r005->SetBottomMargin(0.15);
pad_dpt_RM_r005->SetTopMargin(0.1);pad_dpt_RM_r005->SetRightMargin(0.13);
pad_dpt_RM_r005->SetTicky(1);pad_dpt_RM_r005->Draw();
pad_dpt_RM_r005->cd();
pad_dpt_RM_r005->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r005->SetLogz(1);

Dpt_RM_R005_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.05");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //R=0.1
TCanvas*c_dpt_RM_r010 = new TCanvas("c_dpt_RM_r010","c_dpt_RM_r010",1000,1000);
TPad *pad_dpt_RM_r010=new TPad("pad_pt_RM_r010","pad_pt_RM_r010",0.,0.,1.,1.);
pad_dpt_RM_r010->SetLeftMargin(0.15);pad_dpt_RM_r010->SetBottomMargin(0.15);
pad_dpt_RM_r010->SetTopMargin(0.1);pad_dpt_RM_r010->SetRightMargin(0.13);
pad_dpt_RM_r010->SetTicky(1);pad_dpt_RM_r010->Draw();
pad_dpt_RM_r010->cd();
pad_dpt_RM_r010->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r010->SetLogz(1);

Dpt_RM_R010_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.1");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //R=0.15
TCanvas*c_dpt_RM_r015 = new TCanvas("c_dpt_RM_r015","c_dpt_RM_r015",1000,1000);
TPad *pad_dpt_RM_r015=new TPad("pad_pt_RM_r015","pad_pt_RM_r015",0.,0.,1.,1.);
pad_dpt_RM_r015->SetLeftMargin(0.15);pad_dpt_RM_r015->SetBottomMargin(0.15);
pad_dpt_RM_r015->SetTopMargin(0.1);pad_dpt_RM_r015->SetRightMargin(0.13);
pad_dpt_RM_r015->SetTicky(1);pad_dpt_RM_r015->Draw();
pad_dpt_RM_r015->cd();
pad_dpt_RM_r015->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r015->SetLogz(1);

Dpt_RM_R015_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.15");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //R=0.2
TCanvas*c_dpt_RM_r020 = new TCanvas("c_dpt_RM_r020","c_dpt_RM_r020",1000,1000);
TPad *pad_dpt_RM_r020=new TPad("pad_pt_RM_r020","pad_pt_RM_r020",0.,0.,1.,1.);
pad_dpt_RM_r020->SetLeftMargin(0.15);pad_dpt_RM_r020->SetBottomMargin(0.15);
pad_dpt_RM_r020->SetTopMargin(0.1);pad_dpt_RM_r020->SetRightMargin(0.13);
pad_dpt_RM_r020->SetTicky(1);pad_dpt_RM_r020->Draw();
pad_dpt_RM_r020->cd();
pad_dpt_RM_r020->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r020->SetLogz(1);

Dpt_RM_R020_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.2");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //R=0.25 
TCanvas*c_dpt_RM_r025 = new TCanvas("c_dpt_RM_r025","c_dpt_RM_r025",1000,1000);
TPad *pad_dpt_RM_r025=new TPad("pad_pt_RM_r025","pad_pt_RM_r025",0.,0.,1.,1.);
pad_dpt_RM_r025->SetLeftMargin(0.15);pad_dpt_RM_r025->SetBottomMargin(0.15);
pad_dpt_RM_r025->SetTopMargin(0.1);pad_dpt_RM_r025->SetRightMargin(0.13);
pad_dpt_RM_r025->SetTicky(1);pad_dpt_RM_r025->Draw();
pad_dpt_RM_r025->cd();
pad_dpt_RM_r025->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r025->SetLogz(1);

Dpt_RM_R025_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.25");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //R=0.3 
TCanvas*c_dpt_RM_r030 = new TCanvas("c_dpt_RM_r030","c_dpt_RM_r030",1000,1000);
TPad *pad_dpt_RM_r030=new TPad("pad_pt_RM_r030","pad_pt_RM_r030",0.,0.,1.,1.);
pad_dpt_RM_r030->SetLeftMargin(0.15);pad_dpt_RM_r030->SetBottomMargin(0.15);
pad_dpt_RM_r030->SetTopMargin(0.1);pad_dpt_RM_r030->SetRightMargin(0.13);
pad_dpt_RM_r030->SetTicky(1);pad_dpt_RM_r030->Draw();
pad_dpt_RM_r030->cd();
pad_dpt_RM_r030->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r030->SetLogz(1);

Dpt_RM_R030_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.3");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //R=0.35    
TCanvas*c_dpt_RM_r035 = new TCanvas("c_dpt_RM_r035","c_dpt_RM_r035",1000,1000);
TPad *pad_dpt_RM_r035=new TPad("pad_pt_RM_r035","pad_pt_RM_r035",0.,0.,1.,1.);
pad_dpt_RM_r035->SetLeftMargin(0.15);pad_dpt_RM_r035->SetBottomMargin(0.15);
pad_dpt_RM_r035->SetTopMargin(0.1);pad_dpt_RM_r035->SetRightMargin(0.13);
pad_dpt_RM_r035->SetTicky(1);pad_dpt_RM_r035->Draw();
pad_dpt_RM_r035->cd();
pad_dpt_RM_r035->DrawFrame(-1.5,-1.5,25.5,31.5,";#it{#Deltap}_{T,hyb}(GeV/#it{c});#it{#Deltap}_{T,truth}(GeV/#it{c})");
pad_dpt_RM_r035->SetLogz(1);

Dpt_RM_R035_norm->Draw("same colz");

lat.DrawLatex(.38,.84,"This thesis");
lat.DrawLatex(.38,.78,"Embedded ALICE PYTHIA");
lat.DrawLatex(.38,.72,"0-10\% Centrality");
lat.DrawLatex(.61,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat.DrawLatex(.38,.66,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat.DrawLatex(.38,.6,"#it{R}_{jet} = 0.35");
lat.DrawLatex(.38,.54,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));

        //Plotting the Unfolded distributions
TCanvas*c4 = new TCanvas("c4","c4",1000,1000);
TPad *pad4=new TPad("pad4","pad4",0.,0.,1.,1.);
pad4->SetLeftMargin(0.15);pad4->SetBottomMargin(0.15);
pad4->SetTopMargin(0.1);pad4->SetRightMargin(0.05);
pad4->SetTicky(1);pad4->Draw();
pad4->cd();
pad4->DrawFrame(-1.5,5e-5,25.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{#sigma}_{jet}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}"));
pad4->SetLogy(1);

auto leg2_dr = new TLegend(.16,.17,.6,.32); leg2_dr->SetNColumns(2);
leg2_dr->AddEntry(pro_unf_Dpt_R005,"#it{R}=0.05 to 0.1","p");leg2_dr->AddEntry(pro_unf_Dpt_R010,"#it{R}=0.1 to 0.15","p");
leg2_dr->AddEntry(pro_unf_Dpt_R015,"#it{R}=0.15 to 0.2","p");leg2_dr->AddEntry(pro_unf_Dpt_R020,"#it{R}=0.2 to 0.25","p");

pro_unf_Dpt_R005->Draw("same E1");pro_unf_Dpt_R010->Draw("same E1");
pro_unf_Dpt_R015->Draw("same E1");pro_unf_Dpt_R020->Draw("same E1");
leg2_dr->Draw();

lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE Pb-Pb unfolded data");
lat1.DrawLatex(.62,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat1.DrawLatex(.42,.74,"Lead #it{p}_{T,track} > 8 GeV/#it{c}");
lat1.DrawLatex(.42,.69,Form("%d < #it{p}_{T,ch jet} < %d GeV/#it{c}",Ptlow,Pthigh));


//Saving section

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






