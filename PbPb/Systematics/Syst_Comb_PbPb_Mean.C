void SetStyle(Bool_t graypalette=kFALSE);

void Syst_Comb_PbPb_Mean(int ptlow, int pthigh){

//Open input files
TFile* f_def = TFile::Open("../UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_FinalSolution_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter5.root");

TFile* f_trackeff =TFile::Open("../TrackEff/UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_TrackEff_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter5.root");

TFile* f_trunc =TFile::Open("../Unfolding/Trunc/UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_Trunc_smallR_Binw3_pt_60_80_ptmin15_140_Dptmin-1_max28_Iter5.root");

TFile* f_niter6 =TFile::Open("../Unfolding/Niter/UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_FinalSolution_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter4.root");

TFile* f_niter4 =TFile::Open("../Unfolding/Niter/UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_FinalSolution_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter6.root");

TFile* f_prior =TFile::Open("../Unfolding/Prior_Scaling/UnfoldedResults_PbPb_FinalSolution_ModResponse_DPt5_pt_60_80_ptmin10_Dptmin-1_ptmax140_Dptmax28_Iter5.root");

TFile* f_Bkg_over =TFile::Open("../Bkg_sub/UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_dRmax030_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter5.root");

TFile* f_Bkg_under =TFile::Open("../Bkg_sub/UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_dRmax005_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter5.root");

TFile* f_LC =TFile::Open("../LeadTrackCut/UnfoldedResults_PbPb_ConstSub_wFakes_LC10_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter5.root");

SetStyle();

const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7}; // for syst bands
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

//Load distributions

        //R=0.05
TH1D* pro_unf_R005_def;f_def->GetObject("pro_unfolded_data_R005",pro_unf_R005_def);
TH1D* pro_unf_R005_trackeff; f_trackeff->GetObject("pro_unfolded_data_R005",pro_unf_R005_trackeff);
TH1D* pro_unf_R005_trunc ; f_trunc->GetObject("pro_unfolded_data_R005",pro_unf_R005_trunc);
TH1D* pro_unf_R005_niter4; f_niter4->GetObject("pro_unfolded_data_R005",pro_unf_R005_niter4);
TH1D* pro_unf_R005_niter6; f_niter6->GetObject("pro_unfolded_data_R005",pro_unf_R005_niter6);
TH1D* pro_unf_R005_prior1; f_prior->GetObject("pro_unfolded_data_R005_mod1",pro_unf_R005_prior1);
TH1D* pro_unf_R005_prior2; f_prior->GetObject("pro_unfolded_data_R005_mod2",pro_unf_R005_prior2);
TH1D* pro_unf_R005_bkg030; f_Bkg_over->GetObject("pro_unfolded_data_R005",pro_unf_R005_bkg030);
TH1D* pro_unf_R005_bkg005; f_Bkg_under->GetObject("pro_unfolded_data_R005",pro_unf_R005_bkg005);
TH1D* pro_unf_R005_LC ; f_LC->GetObject("pro_unfolded_data_R005",pro_unf_R005_LC);

        //R=0.1
TH1D* pro_unf_R010_def; f_def->GetObject("pro_unfolded_data_R010",pro_unf_R010_def);
TH1D* pro_unf_R010_trackeff; f_trackeff->GetObject("pro_unfolded_data_R010",pro_unf_R010_trackeff);
TH1D* pro_unf_R010_trunc; f_trunc->GetObject("pro_unfolded_data_R010",pro_unf_R010_trunc);
TH1D* pro_unf_R010_niter4; f_niter4->GetObject("pro_unfolded_data_R010",pro_unf_R010_niter4);
TH1D* pro_unf_R010_niter6; f_niter6->GetObject("pro_unfolded_data_R010",pro_unf_R010_niter6);
TH1D* pro_unf_R010_prior1; f_prior->GetObject("pro_unfolded_data_R010_mod1",pro_unf_R010_prior1);
TH1D* pro_unf_R010_prior2; f_prior->GetObject("pro_unfolded_data_R010_mod2",pro_unf_R010_prior2);
TH1D* pro_unf_R010_bkg030; f_Bkg_over->GetObject("pro_unfolded_data_R010",pro_unf_R010_bkg030);
TH1D* pro_unf_R010_bkg005; f_Bkg_under->GetObject("pro_unfolded_data_R010",pro_unf_R010_bkg005);
TH1D* pro_unf_R010_LC ; f_LC->GetObject("pro_unfolded_data_R010",pro_unf_R010_LC);

        //R=0.15
TH1D* pro_unf_R015_def; f_def->GetObject("pro_unfolded_data_R015",pro_unf_R015_def);
TH1D* pro_unf_R015_trackeff; f_trackeff->GetObject("pro_unfolded_data_R015",pro_unf_R015_trackeff);
TH1D* pro_unf_R015_trunc; f_trunc->GetObject("pro_unfolded_data_R015",pro_unf_R015_trunc);
TH1D* pro_unf_R015_niter4; f_niter4->GetObject("pro_unfolded_data_R015",pro_unf_R015_niter4);
TH1D* pro_unf_R015_niter6; f_niter6->GetObject("pro_unfolded_data_R015",pro_unf_R015_niter6);
TH1D* pro_unf_R015_prior1; f_prior->GetObject("pro_unfolded_data_R015_mod1",pro_unf_R015_prior1);
TH1D* pro_unf_R015_prior2; f_prior->GetObject("pro_unfolded_data_R015_mod2",pro_unf_R015_prior2);
TH1D* pro_unf_R015_bkg030;   f_Bkg_over->GetObject("pro_unfolded_data_R015",pro_unf_R015_bkg030);
TH1D* pro_unf_R015_bkg005;  f_Bkg_under->GetObject("pro_unfolded_data_R015",pro_unf_R015_bkg005);
TH1D* pro_unf_R015_LC ; f_LC->GetObject("pro_unfolded_data_R015",pro_unf_R015_LC);

        //R=0.2
TH1D* pro_unf_R020_def; f_def->GetObject("pro_unfolded_data_R020",pro_unf_R020_def);
TH1D* pro_unf_R020_trackeff; f_trackeff->GetObject("pro_unfolded_data_R020",pro_unf_R020_trackeff);
TH1D* pro_unf_R020_trunc; f_trunc->GetObject("pro_unfolded_data_R020",pro_unf_R020_trunc);
TH1D* pro_unf_R020_niter4; f_niter4->GetObject("pro_unfolded_data_R020",pro_unf_R020_niter4);
TH1D* pro_unf_R020_niter6; f_niter6->GetObject("pro_unfolded_data_R020",pro_unf_R020_niter6);
TH1D* pro_unf_R020_prior1; f_prior->GetObject("pro_unfolded_data_R020_mod1",pro_unf_R020_prior1);
TH1D* pro_unf_R020_prior2; f_prior->GetObject("pro_unfolded_data_R020_mod2",pro_unf_R020_prior2);
TH1D* pro_unf_R020_bkg030; f_Bkg_over->GetObject("pro_unfolded_data_R020",pro_unf_R020_bkg030);
TH1D* pro_unf_R020_bkg005; f_Bkg_under->GetObject("pro_unfolded_data_R020",pro_unf_R020_bkg005);
TH1D* pro_unf_R020_LC ; f_LC->GetObject("pro_unfolded_data_R020",pro_unf_R020_LC);


//Mean calculation
double R[4] = {0.05,0.1,0.15,0.2};
double R_err[4] = {0.,0.,0.,0.};
double mean_def[4] ={pro_unf_R005_def->GetMean(),pro_unf_R010_def->GetMean(),pro_unf_R015_def->GetMean(),pro_unf_R020_def->GetMean()};
double mean_err_def[4] = {pro_unf_R005_def->GetMeanError(),pro_unf_R010_def->GetMeanError(),pro_unf_R015_def->GetMeanError(),pro_unf_R020_def->GetMeanError()};

double rms_def[4] ={pro_unf_R005_def->GetRMS(),pro_unf_R010_def->GetRMS(),pro_unf_R015_def->GetRMS(),pro_unf_R020_def->GetRMS()};
double rms_err_def[4] = {pro_unf_R005_def->GetRMSError(),pro_unf_R010_def->GetRMSError(),pro_unf_R015_def->GetRMSError(),pro_unf_R020_def->GetRMSError()};

//Mean systematic calculation

        //TrackEff
double mean_trackeff[4] ={pro_unf_R005_trackeff->GetMean(),pro_unf_R010_trackeff->GetMean(),pro_unf_R015_trackeff->GetMean(),pro_unf_R020_trackeff->GetMean()};
double mean_err_trackeff[4] = {pro_unf_R005_trackeff->GetMeanError(),pro_unf_R010_trackeff->GetMeanError(),pro_unf_R015_trackeff->GetMeanError(),pro_unf_R020_trackeff->GetMeanError()};

double rms_trackeff[4] ={pro_unf_R005_trackeff->GetRMS(),pro_unf_R010_trackeff->GetRMS(),pro_unf_R015_trackeff->GetRMS(),pro_unf_R020_trackeff->GetRMS()};
double rms_err_trackeff[4] = {pro_unf_R005_trackeff->GetRMSError(),pro_unf_R010_trackeff->GetRMSError(),pro_unf_R015_trackeff->GetRMSError(),pro_unf_R020_trackeff->GetRMSError()};

        //Truncation
double mean_trunc[4] ={pro_unf_R005_trunc->GetMean(),pro_unf_R010_trunc->GetMean(),pro_unf_R015_trunc->GetMean(),pro_unf_R020_trunc->GetMean()};
double mean_err_trunc[4] = {pro_unf_R005_trunc->GetMeanError(),pro_unf_R010_trunc->GetMeanError(),pro_unf_R015_trunc->GetMeanError(),pro_unf_R020_trunc->GetMeanError()};

double rms_trunc[4] ={pro_unf_R005_trunc->GetRMS(),pro_unf_R010_trunc->GetRMS(),pro_unf_R015_trunc->GetRMS(),pro_unf_R020_trunc->GetRMS()};
double rms_err_trunc[4] = {pro_unf_R005_trunc->GetRMSError(),pro_unf_R010_trunc->GetRMSError(),pro_unf_R015_trunc->GetRMSError(),pro_unf_R020_trunc->GetRMSError()};

        //LeadCut
double mean_LC[4] ={pro_unf_R005_LC->GetMean(),pro_unf_R010_LC->GetMean(),pro_unf_R015_LC->GetMean(),pro_unf_R020_LC->GetMean()};
double mean_err_LC[4] = {pro_unf_R005_LC->GetMeanError(),pro_unf_R010_LC->GetMeanError(),pro_unf_R015_LC->GetMeanError(),pro_unf_R020_LC->GetMeanError()};

double rms_LC[4] ={pro_unf_R005_LC->GetRMS(),pro_unf_R010_LC->GetRMS(),pro_unf_R015_LC->GetRMS(),pro_unf_R020_LC->GetRMS()};
double rms_err_LC[4] = {pro_unf_R005_LC->GetRMSError(),pro_unf_R010_LC->GetRMSError(),pro_unf_R015_LC->GetRMSError(),pro_unf_R020_LC->GetRMSError()};

        //Prior
double mean_prior1[4] ={pro_unf_R005_prior1->GetMean(),pro_unf_R010_prior1->GetMean(),pro_unf_R015_prior1->GetMean(),pro_unf_R020_prior1->GetMean()};
double mean_err_prior1[4] = {pro_unf_R005_prior1->GetMeanError(),pro_unf_R010_prior1->GetMeanError(),pro_unf_R015_prior1->GetMeanError(),pro_unf_R020_prior1->GetMeanError()};

double rms_prior1[4] ={pro_unf_R005_prior1->GetRMS(),pro_unf_R010_prior1->GetRMS(),pro_unf_R015_prior1->GetRMS(),pro_unf_R020_prior1->GetRMS()};
double rms_err_prior1[4] = {pro_unf_R005_prior1->GetRMSError(),pro_unf_R010_prior1->GetRMSError(),pro_unf_R015_prior1->GetRMSError(),pro_unf_R020_prior1->GetRMSError()};


double mean_prior2[4] ={pro_unf_R005_prior2->GetMean(),pro_unf_R010_prior2->GetMean(),pro_unf_R015_prior2->GetMean(),pro_unf_R020_prior2->GetMean()};
double mean_err_prior2[4] = {pro_unf_R005_prior2->GetMeanError(),pro_unf_R010_prior2->GetMeanError(),pro_unf_R015_prior2->GetMeanError(),pro_unf_R020_prior2->GetMeanError()};

double rms_prior2[4] ={pro_unf_R005_prior2->GetRMS(),pro_unf_R010_prior2->GetRMS(),pro_unf_R015_prior2->GetRMS(),pro_unf_R020_prior2->GetRMS()};
double rms_err_prior2[4] = {pro_unf_R005_prior2->GetRMSError(),pro_unf_R010_prior2->GetRMSError(),pro_unf_R015_prior2->GetRMSError(),pro_unf_R020_prior2->GetRMSError()};

        //Niter
double mean_niter4[4] ={pro_unf_R005_niter4->GetMean(),pro_unf_R010_niter4->GetMean(),pro_unf_R015_niter4->GetMean(),pro_unf_R020_niter4->GetMean()};
double mean_err_niter4[4] = {pro_unf_R005_niter4->GetMeanError(),pro_unf_R010_niter4->GetMeanError(),pro_unf_R015_niter4->GetMeanError(),pro_unf_R020_niter4->GetMeanError()};

double rms_niter4[4] ={pro_unf_R005_niter4->GetRMS(),pro_unf_R010_niter4->GetRMS(),pro_unf_R015_niter4->GetRMS(),pro_unf_R020_niter4->GetRMS()};
double rms_err_niter4[4] = {pro_unf_R005_niter4->GetRMSError(),pro_unf_R010_niter4->GetRMSError(),pro_unf_R015_niter4->GetRMSError(),pro_unf_R020_niter4->GetRMSError()};

double mean_niter6[4] ={pro_unf_R005_niter6->GetMean(),pro_unf_R010_niter6->GetMean(),pro_unf_R015_niter6->GetMean(),pro_unf_R020_niter6->GetMean()};
double mean_err_niter6[4] = {pro_unf_R005_niter6->GetMeanError(),pro_unf_R010_niter6->GetMeanError(),pro_unf_R015_niter6->GetMeanError(),pro_unf_R020_niter6->GetMeanError()};

double rms_niter6[4] ={pro_unf_R005_niter6->GetRMS(),pro_unf_R010_niter6->GetRMS(),pro_unf_R015_niter6->GetRMS(),pro_unf_R020_niter6->GetRMS()};
double rms_err_niter6[4] = {pro_unf_R005_niter6->GetRMSError(),pro_unf_R010_niter6->GetRMSError(),pro_unf_R015_niter6->GetRMSError(),pro_unf_R020_niter6->GetRMSError()};


        //BkgSub
double mean_bkg005[4] ={pro_unf_R005_bkg005->GetMean(),pro_unf_R010_bkg005->GetMean(),pro_unf_R015_bkg005->GetMean(),pro_unf_R020_bkg005->GetMean()};
double mean_err_bkg005[4] = {pro_unf_R005_bkg005->GetMeanError(),pro_unf_R010_bkg005->GetMeanError(),pro_unf_R015_bkg005->GetMeanError(),pro_unf_R020_bkg005->GetMeanError()};

double rms_bkg005[4] ={pro_unf_R005_bkg005->GetRMS(),pro_unf_R010_bkg005->GetRMS(),pro_unf_R015_bkg005->GetRMS(),pro_unf_R020_bkg005->GetRMS()};
double rms_err_bkg005[4] = {pro_unf_R005_bkg005->GetRMSError(),pro_unf_R010_bkg005->GetRMSError(),pro_unf_R015_bkg005->GetRMSError(),pro_unf_R020_bkg005->GetRMSError()};

double mean_bkg030[4] ={pro_unf_R005_bkg030->GetMean(),pro_unf_R010_bkg030->GetMean(),pro_unf_R015_bkg030->GetMean(),pro_unf_R020_bkg030->GetMean()};
double mean_err_bkg030[4] = {pro_unf_R005_bkg030->GetMeanError(),pro_unf_R010_bkg030->GetMeanError(),pro_unf_R015_bkg030->GetMeanError(),pro_unf_R020_bkg030->GetMeanError()};

double rms_bkg030[4] ={pro_unf_R005_bkg030->GetRMS(),pro_unf_R010_bkg030->GetRMS(),pro_unf_R015_bkg030->GetRMS(),pro_unf_R020_bkg030->GetRMS()};
double rms_err_bkg030[4] = {pro_unf_R005_bkg030->GetRMSError(),pro_unf_R010_bkg030->GetRMSError(),pro_unf_R015_bkg030->GetRMSError(),pro_unf_R020_bkg030->GetRMSError()};


Double_t mean_total[4] ={};
double_t rms_total[4] ={};
double track_eff_sys=0;double prior_sys=0; double LC_sys=0; double niter_sys =0; double unf_sys =0; double trunc_sys=0;double bkg_sys=0;
double total =0;

        for (int i=0;i<4;i++){
        track_eff_sys = (mean_trackeff[i]-mean_def[i])/mean_def[i];
        prior_sys = abs((mean_prior1[i]-mean_def[i])/mean_def[i]-(mean_prior2[i]-mean_def[i])/mean_def[i])/2;
        bkg_sys = abs((mean_bkg005[i]-mean_def[i])/mean_def[i]-(mean_bkg030[i]-mean_def[i])/mean_def[i])/2;
        LC_sys = (mean_LC[i]-mean_def[i])/mean_def[i];
        niter_sys =abs((mean_niter6[i]-mean_def[i])/mean_def[i]-(mean_niter4[i]-mean_def[i])/mean_def[i])/2;
        trunc_sys =(mean_trunc[i]-mean_def[i])/mean_def[i];
        unf_sys = TMath::Sqrt((TMath::Power(prior_sys,2)+TMath::Power(niter_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(LC_sys,2)+TMath::Power(unf_sys,2)+TMath::Power(bkg_sys,2));
        mean_total[i]=total*mean_def[i];
        R_err[i]=0.015;
                }
track_eff_sys=0; prior_sys=0; LC_sys=0; niter_sys =0; unf_sys =0; trunc_sys=0;bkg_sys=0;
total=0;

        for (int i=0;i<4;i++){
        track_eff_sys = (rms_trackeff[i]-rms_def[i])/rms_def[i];
        prior_sys = abs((rms_prior1[i]-rms_def[i])/rms_def[i]-(rms_prior2[i]-rms_def[i])/rms_def[i])/2;
        bkg_sys = abs((rms_bkg005[i]-rms_def[i])/rms_def[i]-(rms_bkg030[i]-rms_def[i])/rms_def[i])/2;
        LC_sys = (rms_LC[i]-rms_def[i])/rms_def[i];
        niter_sys =abs((rms_niter6[i]-rms_def[i])/rms_def[i]-(rms_niter4[i]-rms_def[i])/rms_def[i])/2;
        trunc_sys =(rms_trunc[i]-rms_def[i])/rms_def[i];
        unf_sys = TMath::Sqrt((TMath::Power(prior_sys,2)+TMath::Power(niter_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(LC_sys,2)+TMath::Power(unf_sys,2)+TMath::Power(bkg_sys,2));
        rms_total[i]=total*rms_def[i];
                }



//Create mean graph
        auto Mean_gr = new TGraphErrors(4,R,mean_def,R_err,mean_err_def);
        Mean_gr->SetLineColor(1);Mean_gr->SetMarkerColor(1);
        Mean_gr->SetMarkerStyle(33); Mean_gr->SetMarkerSize(3);

        auto Mean_gr_Sys = new TGraphErrors(4,R,mean_def,R_err,mean_total);
        Mean_gr->SetLineWidth(2);
        Mean_gr_Sys->SetMarkerSize(1);Mean_gr_Sys->SetMarkerStyle(1);
        Mean_gr_Sys->SetFillColor(0); Mean_gr_Sys->SetFillStyle(0);

        auto RMS_gr = new TGraphErrors(4,R,rms_def,R_err,rms_err_def);
        RMS_gr->SetLineColor(1);RMS_gr->SetMarkerColor(1);
        RMS_gr->SetLineWidth(2);
        RMS_gr->SetMarkerStyle(33); RMS_gr->SetMarkerSize(3);

        auto RMS_gr_Sys = new TGraphErrors(4,R,rms_def,R_err,rms_total);
        RMS_gr_Sys->SetMarkerSize(1);RMS_gr_Sys->SetMarkerStyle(1);
        RMS_gr_Sys->SetFillColor(0); RMS_gr_Sys->SetFillStyle(0);


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

Mean_gr->Draw("LPE"); Mean_gr_Sys->Draw("same l E2");

auto leg = new TLegend(0.58, 0.38, 0.92, 0.47);
leg->AddEntry(Mean_gr,"ALICE Pb-Pb","P");
leg->AddEntry(Mean_gr_Sys,"System. unc.", "f");
leg->Draw("same");

TLatex lat;lat.SetNDC();lat.SetTextFont(42);
lat.DrawLatex(.38,.82,"This thesis");
lat.DrawLatex(.38,.77,"ALICE Pb-Pb data");
lat.DrawLatex(.68,.77,"#sqrt{#it{s_{NN}}} = 5.02 TeV");
lat.DrawLatex(.38,.72,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}");

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

RMS_gr->Draw("LPE"); RMS_gr_Sys->Draw("same l E2");

leg->Draw("same");
lat.DrawLatex(.38,.82,"This thesis");
lat.DrawLatex(.38,.77,"ALICE Pb-Pb data");
lat.DrawLatex(.68,.77,"#sqrt{#it{s_{NN}}} = 5.02 TeV");
lat.DrawLatex(.38,.72,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}");





ofstream myfile;
myfile.open (Form("Systematics_on_mean_Pb_Pb_%d_%d_rel.txt",ptlow,pthigh));
myfile<<"R = 0.05 0.1  0.15 0.2  \n";
myfile <<"Total systematics\n";
for(int i=0;i<4;i++) myfile<<" "<<mean_total[i]/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Default mean\n";
for(int i=0;i<4;i++) myfile<<" "<<mean_def[i]<< " ";
myfile<<"\n";
myfile <<"TrackEff mean\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_trackeff[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Niter mean 4\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_niter4[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Niter mean 6\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_niter6[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Prior1 mean\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_prior1[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<" Prior2 mean\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_prior2[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<" Trunc mean\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_trunc[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<" LeadCut mean\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_LC[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"bkg005 mean\n";
for(int i=0;i<4;i++) myfile<<" "<<(mean_bkg005[i]-mean_bkg030[i])/mean_bkg030[i]<< " ";
myfile<<"\n";
myfile <<"bkg030 mean \n";
for(int i=0;i<4;i++) myfile<<" "<<mean_bkg030[i]<< " ";
myfile<<"\n";

//Save output file
TFile*Result = TFile::Open("Final_Mean_Result_PbPb.root","UPDATE","Final_Mean_Result_PbPb.root");
Mean_gr_Sys->Write(Form("Mean_Sys_graph_%d_%d",ptlow,pthigh),TObject::kOverwrite);
Mean_gr->Write(Form("Mean_graph_%d_%d",ptlow,pthigh),TObject::kOverwrite);
RMS_gr_Sys->Write(Form("RMS_Sys_graph_%d_%d",ptlow,pthigh),TObject::kOverwrite);
RMS_gr->Write(Form("RMS_graph_%d_%d",ptlow,pthigh),TObject::kOverwrite);
Result->Close();



}
void SetStyle(Bool_t graypalette) {
//  cout << "Setting style!" << endl;

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
  gStyle->SetLabelSize(0.045,"xyz");
  gStyle->SetLabelOffset(0.01,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelColor(kBlack,"xyz");
  gStyle->SetTitleSize(0.05,"xyz");
  gStyle->SetTitleOffset(1.,"y");
  gStyle->SetTitleOffset(1.,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

  gStyle->SetLegendBorderSize(1);
  gStyle->SetLegendFillColor(kWhite);
  //  gStyle->SetFillColor(kWhite);
  gStyle->SetLegendFont(42);


}

