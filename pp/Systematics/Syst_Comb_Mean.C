void SetStyle(Bool_t graypalette=kFALSE);

void Syst_Comb_Mean(int ptlow, int pthigh){

//Open input files
TFile* f_def = TFile::Open(Form("%d_%d/UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_trackeff =TFile::Open(Form("%d_%d/UnfoldedResults_ppFinalSolution_TrackEff_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_trunc =TFile::Open(Form("%d_%d/UnfoldedResults_ppFinalSolution_Trunc_wFakes_smallR_Binw3_pt_%d_%d_ptmin25_Dptmin-1_max28_Iter4.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_niter3 = TFile::Open(Form("%d_%d/UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter3.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_niter5 = TFile::Open(Form("%d_%d/UnfoldedResults_ppFinalSolution_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter5.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_prior =TFile::Open(Form("%d_%d/UnfoldedResults_ppFinalSolution_ModResponse_DPt5_pt_%d_%d_ptmin20_Dptmin-1_ptmax100_Dptmax28_Iter4.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_model_pythia =TFile::Open(Form("%d_%d/UnfoldedResults_pp_PYTHIAfastSim_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",ptlow,pthigh,ptlow,pthigh));

TFile* f_model_herwig =TFile::Open(Form("%d_%d/UnfoldedResults_pp_HERWIGfastsim_wFakes_smallR_Binw3_pt_%d_%d_ptmin20_Dptmin-1_max28_Iter4.root",ptlow,pthigh,ptlow,pthigh));

SetStyle();

const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7}; // for syst bands
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};

//Load distributions

        //R=0.05
TH1D* pro_unf_R005_def;f_def->GetObject("pro_unfolded_data_R005",pro_unf_R005_def);
TH1D* pro_unf_R005_trackeff; f_trackeff->GetObject("pro_unfolded_data_R005",pro_unf_R005_trackeff);
TH1D* pro_unf_R005_trunc ; f_trunc->GetObject("pro_unfolded_data_R005",pro_unf_R005_trunc);
TH1D* pro_unf_R005_niter3; f_niter3->GetObject("pro_unfolded_data_R005",pro_unf_R005_niter3);
TH1D* pro_unf_R005_niter5; f_niter5->GetObject("pro_unfolded_data_R005",pro_unf_R005_niter5);
TH1D* pro_unf_R005_prior1; f_prior->GetObject("pro_unfolded_data_R005_mod1",pro_unf_R005_prior1);
TH1D* pro_unf_R005_prior2; f_prior->GetObject("pro_unfolded_data_R005_mod2",pro_unf_R005_prior2);
TH1D* pro_unf_R005_fast; f_model_pythia->GetObject("pro_unfolded_data_R005",pro_unf_R005_fast);
TH1D* pro_unf_R005_herwig; f_model_herwig->GetObject("pro_unfolded_data_R005",pro_unf_R005_herwig);
        //R=0.1
TH1D* pro_unf_R010_def; f_def->GetObject("pro_unfolded_data_R010",pro_unf_R010_def);
TH1D* pro_unf_R010_trackeff; f_trackeff->GetObject("pro_unfolded_data_R010",pro_unf_R010_trackeff);
TH1D* pro_unf_R010_trunc; f_trunc->GetObject("pro_unfolded_data_R010",pro_unf_R010_trunc);
TH1D* pro_unf_R010_niter3; f_niter3->GetObject("pro_unfolded_data_R010",pro_unf_R010_niter3);
TH1D* pro_unf_R010_niter5; f_niter5->GetObject("pro_unfolded_data_R010",pro_unf_R010_niter5);
TH1D* pro_unf_R010_prior1; f_prior->GetObject("pro_unfolded_data_R010_mod1",pro_unf_R010_prior1);
TH1D* pro_unf_R010_prior2; f_prior->GetObject("pro_unfolded_data_R010_mod2",pro_unf_R010_prior2);
TH1D* pro_unf_R010_fast; f_model_pythia->GetObject("pro_unfolded_data_R010",pro_unf_R010_fast);
TH1D* pro_unf_R010_herwig; f_model_herwig->GetObject("pro_unfolded_data_R010",pro_unf_R010_herwig);

        //R=0.15
TH1D* pro_unf_R015_def; f_def->GetObject("pro_unfolded_data_R015",pro_unf_R015_def);
TH1D* pro_unf_R015_trackeff; f_trackeff->GetObject("pro_unfolded_data_R015",pro_unf_R015_trackeff);
TH1D* pro_unf_R015_trunc; f_trunc->GetObject("pro_unfolded_data_R015",pro_unf_R015_trunc);
TH1D* pro_unf_R015_niter3; f_niter3->GetObject("pro_unfolded_data_R015",pro_unf_R015_niter3);
TH1D* pro_unf_R015_niter5; f_niter5->GetObject("pro_unfolded_data_R015",pro_unf_R015_niter5);
TH1D* pro_unf_R015_prior1; f_prior->GetObject("pro_unfolded_data_R015_mod1",pro_unf_R015_prior1);
TH1D* pro_unf_R015_prior2; f_prior->GetObject("pro_unfolded_data_R015_mod2",pro_unf_R015_prior2);
TH1D* pro_unf_R015_fast;   f_model_pythia->GetObject("pro_unfolded_data_R015",pro_unf_R015_fast);
TH1D* pro_unf_R015_herwig;  f_model_herwig->GetObject("pro_unfolded_data_R015",pro_unf_R015_herwig);
        //R=0.2
TH1D* pro_unf_R020_def; f_def->GetObject("pro_unfolded_data_R020",pro_unf_R020_def);
TH1D* pro_unf_R020_trackeff; f_trackeff->GetObject("pro_unfolded_data_R020",pro_unf_R020_trackeff);
TH1D* pro_unf_R020_trunc; f_trunc->GetObject("pro_unfolded_data_R020",pro_unf_R020_trunc);
TH1D* pro_unf_R020_niter3; f_niter3->GetObject("pro_unfolded_data_R020",pro_unf_R020_niter3);
TH1D* pro_unf_R020_niter5; f_niter5->GetObject("pro_unfolded_data_R020",pro_unf_R020_niter5);
TH1D* pro_unf_R020_prior1; f_prior->GetObject("pro_unfolded_data_R020_mod1",pro_unf_R020_prior1);
TH1D* pro_unf_R020_prior2; f_prior->GetObject("pro_unfolded_data_R020_mod2",pro_unf_R020_prior2);
TH1D* pro_unf_R020_fast; f_model_pythia->GetObject("pro_unfolded_data_R020",pro_unf_R020_fast);
TH1D* pro_unf_R020_herwig; f_model_herwig->GetObject("pro_unfolded_data_R020",pro_unf_R020_herwig);
        //R=0.25
TH1D* pro_unf_R025_def; f_def->GetObject("pro_unfolded_data_R025",pro_unf_R025_def);
TH1D* pro_unf_R025_trackeff; f_trackeff->GetObject("pro_unfolded_data_R025",pro_unf_R025_trackeff);
TH1D* pro_unf_R025_trunc; f_trunc->GetObject("pro_unfolded_data_R025",pro_unf_R025_trunc);
TH1D* pro_unf_R025_niter3; f_niter3->GetObject("pro_unfolded_data_R025",pro_unf_R025_niter3);
TH1D* pro_unf_R025_niter5; f_niter5->GetObject("pro_unfolded_data_R025",pro_unf_R025_niter5);
TH1D* pro_unf_R025_prior1; f_prior->GetObject("pro_unfolded_data_R025_mod1",pro_unf_R025_prior1);
TH1D* pro_unf_R025_prior2; f_prior->GetObject("pro_unfolded_data_R025_mod2",pro_unf_R025_prior2);
TH1D* pro_unf_R025_fast; f_model_pythia->GetObject("pro_unfolded_data_R025",pro_unf_R025_fast);
TH1D* pro_unf_R025_herwig; f_model_herwig->GetObject("pro_unfolded_data_R025",pro_unf_R025_herwig);
        //R=0.3
TH1D* pro_unf_R030_def; f_def->GetObject("pro_unfolded_data_R030",pro_unf_R030_def);
TH1D* pro_unf_R030_trackeff; f_trackeff->GetObject("pro_unfolded_data_R030",pro_unf_R030_trackeff);
TH1D* pro_unf_R030_trunc; f_trunc->GetObject("pro_unfolded_data_R030",pro_unf_R030_trunc);
TH1D* pro_unf_R030_niter3; f_niter3->GetObject("pro_unfolded_data_R030",pro_unf_R030_niter3);
TH1D* pro_unf_R030_niter5; f_niter5->GetObject("pro_unfolded_data_R030",pro_unf_R030_niter5);
TH1D* pro_unf_R030_prior1; f_prior->GetObject("pro_unfolded_data_R030_mod1",pro_unf_R030_prior1);
TH1D* pro_unf_R030_prior2; f_prior->GetObject("pro_unfolded_data_R030_mod2",pro_unf_R030_prior2);
TH1D* pro_unf_R030_fast; f_model_pythia->GetObject("pro_unfolded_data_R030",pro_unf_R030_fast);
TH1D* pro_unf_R030_herwig; f_model_herwig->GetObject("pro_unfolded_data_R030",pro_unf_R030_herwig);
        //R=0.35
TH1D* pro_unf_R035_def; f_def->GetObject("pro_unfolded_data_R035",pro_unf_R035_def);
TH1D* pro_unf_R035_trackeff; f_trackeff->GetObject("pro_unfolded_data_R035",pro_unf_R035_trackeff);
TH1D* pro_unf_R035_trunc; f_trunc->GetObject("pro_unfolded_data_R035",pro_unf_R035_trunc);
TH1D* pro_unf_R035_niter3; f_niter3->GetObject("pro_unfolded_data_R035",pro_unf_R035_niter3);
TH1D* pro_unf_R035_niter5; f_niter5->GetObject("pro_unfolded_data_R035",pro_unf_R035_niter5);
TH1D* pro_unf_R035_prior1; f_prior->GetObject("pro_unfolded_data_R035_mod1",pro_unf_R035_prior1);
TH1D* pro_unf_R035_prior2; f_prior->GetObject("pro_unfolded_data_R035_mod2",pro_unf_R035_prior2);
TH1D* pro_unf_R035_fast; f_model_pythia->GetObject("pro_unfolded_data_R035",pro_unf_R035_fast);
TH1D* pro_unf_R035_herwig; f_model_herwig->GetObject("pro_unfolded_data_R035",pro_unf_R035_herwig);

//Mean calculation
double R[7] = {0.05,0.1,0.15,0.2,0.25,0.3,0.35};
double R_err[7] = {0.,0.,0.,0.,0.,0.,0.};
double mean_def[7] ={pro_unf_R005_def->GetMean(),pro_unf_R010_def->GetMean(),pro_unf_R015_def->GetMean(),pro_unf_R020_def->GetMean(),pro_unf_R025_def->GetMean(),pro_unf_R030_def->GetMean(),pro_unf_R035_def->GetMean()};
double mean_err_def[7] = {pro_unf_R005_def->GetMeanError(),pro_unf_R010_def->GetMeanError(),pro_unf_R015_def->GetMeanError(),pro_unf_R020_def->GetMeanError(),pro_unf_R025_def->GetMeanError(),pro_unf_R030_def->GetMeanError(),pro_unf_R035_def->GetMeanError()};

double rms_def[7] ={pro_unf_R005_def->GetRMS(),pro_unf_R010_def->GetRMS(),pro_unf_R015_def->GetRMS(),pro_unf_R020_def->GetRMS(),pro_unf_R025_def->GetRMS(),pro_unf_R030_def->GetRMS(),pro_unf_R035_def->GetRMS()};
double rms_err_def[7] = {pro_unf_R005_def->GetRMSError(),pro_unf_R010_def->GetRMSError(),pro_unf_R015_def->GetRMSError(),pro_unf_R020_def->GetRMSError(),pro_unf_R025_def->GetRMSError(),pro_unf_R030_def->GetRMSError(),pro_unf_R035_def->GetRMSError()};

//Mean systematic calculation

        //TrackEff
double mean_trackeff[7] ={pro_unf_R005_trackeff->GetMean(),pro_unf_R010_trackeff->GetMean(),pro_unf_R015_trackeff->GetMean(),pro_unf_R020_trackeff->GetMean(),pro_unf_R025_trackeff->GetMean(),pro_unf_R030_trackeff->GetMean(),pro_unf_R035_trackeff->GetMean()};
double mean_err_trackeff[7] = {pro_unf_R005_trackeff->GetMeanError(),pro_unf_R010_trackeff->GetMeanError(),pro_unf_R015_trackeff->GetMeanError(),pro_unf_R020_trackeff->GetMeanError(),pro_unf_R025_trackeff->GetMeanError(),pro_unf_R030_trackeff->GetMeanError(),pro_unf_R035_trackeff->GetMeanError()};

double rms_trackeff[7] ={pro_unf_R005_trackeff->GetRMS(),pro_unf_R010_trackeff->GetRMS(),pro_unf_R015_trackeff->GetRMS(),pro_unf_R020_trackeff->GetRMS(),pro_unf_R025_trackeff->GetRMS(),pro_unf_R030_trackeff->GetRMS(),pro_unf_R035_trackeff->GetRMS()};
double rms_err_trackeff[7] = {pro_unf_R005_trackeff->GetRMSError(),pro_unf_R010_trackeff->GetRMSError(),pro_unf_R015_trackeff->GetRMSError(),pro_unf_R020_trackeff->GetRMSError(),pro_unf_R025_trackeff->GetRMSError(),pro_unf_R030_trackeff->GetRMSError(),pro_unf_R035_trackeff->GetRMSError()};

        //Truncation
double mean_trunc[7] ={pro_unf_R005_trunc->GetMean(),pro_unf_R010_trunc->GetMean(),pro_unf_R015_trunc->GetMean(),pro_unf_R020_trunc->GetMean(),pro_unf_R025_trunc->GetMean(),pro_unf_R030_trunc->GetMean(),pro_unf_R035_trunc->GetMean()};
double mean_err_trunc[7] = {pro_unf_R005_trunc->GetMeanError(),pro_unf_R010_trunc->GetMeanError(),pro_unf_R015_trunc->GetMeanError(),pro_unf_R020_trunc->GetMeanError(),pro_unf_R025_trunc->GetMeanError(),pro_unf_R030_trunc->GetMeanError(),pro_unf_R035_trunc->GetMeanError()};

double rms_trunc[7] ={pro_unf_R005_trunc->GetRMS(),pro_unf_R010_trunc->GetRMS(),pro_unf_R015_trunc->GetRMS(),pro_unf_R020_trunc->GetRMS(),pro_unf_R025_trunc->GetRMS(),pro_unf_R030_trunc->GetRMS(),pro_unf_R035_trunc->GetRMS()};
double rms_err_trunc[7] = {pro_unf_R005_trunc->GetRMSError(),pro_unf_R010_trunc->GetRMSError(),pro_unf_R015_trunc->GetRMSError(),pro_unf_R020_trunc->GetRMSError(),pro_unf_R025_trunc->GetRMSError(),pro_unf_R030_trunc->GetRMSError(),pro_unf_R035_trunc->GetRMSError()};

        //Prior
double mean_prior1[7] ={pro_unf_R005_prior1->GetMean(),pro_unf_R010_prior1->GetMean(),pro_unf_R015_prior1->GetMean(),pro_unf_R020_prior1->GetMean(),pro_unf_R025_prior1->GetMean(),pro_unf_R030_prior1->GetMean(),pro_unf_R035_prior1->GetMean()};
double mean_err_prior1[7] = {pro_unf_R005_prior1->GetMeanError(),pro_unf_R010_prior1->GetMeanError(),pro_unf_R015_prior1->GetMeanError(),pro_unf_R020_prior1->GetMeanError(),pro_unf_R025_prior1->GetMeanError(),pro_unf_R030_prior1->GetMeanError(),pro_unf_R035_prior1->GetMeanError()};

double rms_prior1[7] ={pro_unf_R005_prior1->GetRMS(),pro_unf_R010_prior1->GetRMS(),pro_unf_R015_prior1->GetRMS(),pro_unf_R020_prior1->GetRMS(),pro_unf_R025_prior1->GetRMS(),pro_unf_R030_prior1->GetRMS(),pro_unf_R035_prior1->GetRMS()};
double rms_err_prior1[7] = {pro_unf_R005_prior1->GetRMSError(),pro_unf_R010_prior1->GetRMSError(),pro_unf_R015_prior1->GetRMSError(),pro_unf_R020_prior1->GetRMSError(),pro_unf_R025_prior1->GetRMSError(),pro_unf_R030_prior1->GetRMSError(),pro_unf_R035_prior1->GetRMSError()};

double mean_prior2[7] ={pro_unf_R005_prior2->GetMean(),pro_unf_R010_prior2->GetMean(),pro_unf_R015_prior2->GetMean(),pro_unf_R020_prior2->GetMean(),pro_unf_R025_prior2->GetMean(),pro_unf_R030_prior2->GetMean(),pro_unf_R035_prior2->GetMean()};
double mean_err_prior2[7] = {pro_unf_R005_prior2->GetMeanError(),pro_unf_R010_prior2->GetMeanError(),pro_unf_R015_prior2->GetMeanError(),pro_unf_R020_prior2->GetMeanError(),pro_unf_R025_prior2->GetMeanError(),pro_unf_R030_prior2->GetMeanError(),pro_unf_R035_prior2->GetMeanError()};

double rms_prior2[7] ={pro_unf_R005_prior2->GetRMS(),pro_unf_R010_prior2->GetRMS(),pro_unf_R015_prior2->GetRMS(),pro_unf_R020_prior2->GetRMS(),pro_unf_R025_prior2->GetRMS(),pro_unf_R030_prior2->GetRMS(),pro_unf_R035_prior2->GetRMS()};
double rms_err_prior2[7] = {pro_unf_R005_prior2->GetRMSError(),pro_unf_R010_prior2->GetRMSError(),pro_unf_R015_prior2->GetRMSError(),pro_unf_R020_prior2->GetRMSError(),pro_unf_R025_prior2->GetRMSError(),pro_unf_R030_prior2->GetRMSError(),pro_unf_R035_prior2->GetRMSError()};

        //Niter
double mean_niter3[7] ={pro_unf_R005_niter3->GetMean(),pro_unf_R010_niter3->GetMean(),pro_unf_R015_niter3->GetMean(),pro_unf_R020_niter3->GetMean(),pro_unf_R025_niter3->GetMean(),pro_unf_R030_niter3->GetMean(),pro_unf_R035_niter3->GetMean()};
double mean_err_niter3[7] = {pro_unf_R005_niter3->GetMeanError(),pro_unf_R010_niter3->GetMeanError(),pro_unf_R015_niter3->GetMeanError(),pro_unf_R020_niter3->GetMeanError(),pro_unf_R025_niter3->GetMeanError(),pro_unf_R030_niter3->GetMeanError(),pro_unf_R035_niter3->GetMeanError()};

double rms_niter3[7] ={pro_unf_R005_niter3->GetRMS(),pro_unf_R010_niter3->GetRMS(),pro_unf_R015_niter3->GetRMS(),pro_unf_R020_niter3->GetRMS(),pro_unf_R025_niter3->GetRMS(),pro_unf_R030_niter3->GetRMS(),pro_unf_R035_niter3->GetRMS()};
double rms_err_niter3[7] = {pro_unf_R005_niter3->GetRMSError(),pro_unf_R010_niter3->GetRMSError(),pro_unf_R015_niter3->GetRMSError(),pro_unf_R020_niter3->GetRMSError(),pro_unf_R025_niter3->GetRMSError(),pro_unf_R030_niter3->GetRMSError(),pro_unf_R035_niter3->GetRMSError()};

double mean_niter5[7] ={pro_unf_R005_niter5->GetMean(),pro_unf_R010_niter5->GetMean(),pro_unf_R015_niter5->GetMean(),pro_unf_R020_niter5->GetMean(),pro_unf_R025_niter5->GetMean(),pro_unf_R030_niter5->GetMean(),pro_unf_R035_niter5->GetMean()};
double mean_err_niter5[7] = {pro_unf_R005_niter5->GetMeanError(),pro_unf_R010_niter5->GetMeanError(),pro_unf_R015_niter5->GetMeanError(),pro_unf_R020_niter5->GetMeanError(),pro_unf_R025_niter5->GetMeanError(),pro_unf_R030_niter5->GetMeanError(),pro_unf_R035_niter5->GetMeanError()};

double rms_niter5[7] ={pro_unf_R005_niter5->GetRMS(),pro_unf_R010_niter5->GetRMS(),pro_unf_R015_niter5->GetRMS(),pro_unf_R020_niter5->GetRMS(),pro_unf_R025_niter5->GetRMS(),pro_unf_R030_niter5->GetRMS(),pro_unf_R035_niter5->GetRMS()};
double rms_err_niter5[7] = {pro_unf_R005_niter5->GetRMSError(),pro_unf_R010_niter5->GetRMSError(),pro_unf_R015_niter5->GetRMSError(),pro_unf_R020_niter5->GetRMSError(),pro_unf_R025_niter5->GetRMSError(),pro_unf_R030_niter5->GetRMSError(),pro_unf_R035_niter5->GetRMSError()};

        //Model
double mean_fast[7] ={pro_unf_R005_fast->GetMean(),pro_unf_R010_fast->GetMean(),pro_unf_R015_fast->GetMean(),pro_unf_R020_fast->GetMean(),pro_unf_R025_fast->GetMean(),pro_unf_R030_fast->GetMean(),pro_unf_R035_fast->GetMean()};
double mean_err_fast[7] = {pro_unf_R005_fast->GetMeanError(),pro_unf_R010_fast->GetMeanError(),pro_unf_R015_fast->GetMeanError(),pro_unf_R020_fast->GetMeanError(),pro_unf_R025_fast->GetMeanError(),pro_unf_R030_fast->GetMeanError(),pro_unf_R035_fast->GetMeanError()};

double rms_fast[7] ={pro_unf_R005_fast->GetRMS(),pro_unf_R010_fast->GetRMS(),pro_unf_R015_fast->GetRMS(),pro_unf_R020_fast->GetRMS(),pro_unf_R025_fast->GetRMS(),pro_unf_R030_fast->GetRMS(),pro_unf_R035_fast->GetRMS()};
double rms_err_fast[7] = {pro_unf_R005_fast->GetRMSError(),pro_unf_R010_fast->GetRMSError(),pro_unf_R015_fast->GetRMSError(),pro_unf_R020_fast->GetRMSError(),pro_unf_R025_fast->GetRMSError(),pro_unf_R030_fast->GetRMSError(),pro_unf_R035_fast->GetRMSError()};

double mean_herwig[7] ={pro_unf_R005_herwig->GetMean(),pro_unf_R010_herwig->GetMean(),pro_unf_R015_herwig->GetMean(),pro_unf_R020_herwig->GetMean(),pro_unf_R025_herwig->GetMean(),pro_unf_R030_herwig->GetMean(),pro_unf_R035_herwig->GetMean()};
double mean_err_herwig[7] = {pro_unf_R005_herwig->GetMeanError(),pro_unf_R010_herwig->GetMeanError(),pro_unf_R015_herwig->GetMeanError(),pro_unf_R020_herwig->GetMeanError(),pro_unf_R025_herwig->GetMeanError(),pro_unf_R030_herwig->GetMeanError(),pro_unf_R035_herwig->GetMeanError()};

double rms_herwig[7] ={pro_unf_R005_herwig->GetRMS(),pro_unf_R010_herwig->GetRMS(),pro_unf_R015_herwig->GetRMS(),pro_unf_R020_herwig->GetRMS(),pro_unf_R025_herwig->GetRMS(),pro_unf_R030_herwig->GetRMS(),pro_unf_R035_herwig->GetRMS()};
double rms_err_herwig[7] = {pro_unf_R005_herwig->GetRMSError(),pro_unf_R010_herwig->GetRMSError(),pro_unf_R015_herwig->GetRMSError(),pro_unf_R020_herwig->GetRMSError(),pro_unf_R025_herwig->GetRMSError(),pro_unf_R030_herwig->GetRMSError(),pro_unf_R035_herwig->GetRMSError()};

Double_t mean_total[7] ={};
double_t rms_total[7] ={};
double track_eff_sys=0;double prior_sys=0; double model_sys=0; double niter_sys =0; double unf_sys =0; double trunc_sys=0;
double total =0;

        for (int i=0;i<7;i++){
        track_eff_sys = (mean_trackeff[i]-mean_def[i])/mean_def[i];
        prior_sys = abs((mean_prior1[i]-mean_def[i])/mean_def[i]-(mean_prior2[i]-mean_def[i])/mean_def[i])/2;
        model_sys = (mean_herwig[i]-mean_fast[i])/mean_fast[i];
        niter_sys =abs((mean_niter5[i]-mean_def[i])/mean_def[i]-(mean_niter3[i]-mean_def[i])/mean_def[i])/2;
        trunc_sys =(mean_trunc[i]-mean_def[i])/mean_def[i];
        unf_sys = TMath::Sqrt((TMath::Power(prior_sys,2)+TMath::Power(niter_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(model_sys,2)+TMath::Power(unf_sys,2));
        mean_total[i]=total*mean_def[i];
        R_err[i]=0.015;
                }
track_eff_sys=0; prior_sys=0; model_sys=0; niter_sys =0; unf_sys =0; trunc_sys=0;
total=0;

        for (int i=0;i<7;i++){
        track_eff_sys = (rms_trackeff[i]-rms_def[i])/rms_def[i];
        prior_sys = abs((rms_prior1[i]-rms_def[i])/rms_def[i]-(rms_prior2[i]-rms_def[i])/rms_def[i])/2;
        model_sys = (rms_herwig[i]-rms_fast[i])/rms_fast[i];
        niter_sys =abs((rms_niter5[i]-rms_def[i])/rms_def[i]-(rms_niter3[i]-rms_def[i])/rms_def[i])/2;
        trunc_sys =(rms_trunc[i]-rms_def[i])/rms_def[i];
        unf_sys = TMath::Sqrt((TMath::Power(prior_sys,2)+TMath::Power(niter_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(model_sys,2)+TMath::Power(unf_sys,2));
        rms_total[i]=total*rms_def[i];
                }
//Create mean graph
        auto Mean_gr = new TGraphErrors(7,R,mean_def,R_err,mean_err_def);
        Mean_gr->SetLineColor(1);Mean_gr->SetMarkerColor(1);
        Mean_gr->SetMarkerStyle(33); Mean_gr->SetMarkerSize(3);

        auto Mean_gr_Sys = new TGraphErrors(7,R,mean_def,R_err,mean_total);
        Mean_gr->SetLineWidth(2);
        Mean_gr_Sys->SetMarkerSize(1);Mean_gr_Sys->SetMarkerStyle(1);
        Mean_gr_Sys->SetFillColor(0); Mean_gr_Sys->SetFillStyle(0);

        auto RMS_gr = new TGraphErrors(7,R,rms_def,R_err,rms_err_def);
        RMS_gr->SetLineColor(1);RMS_gr->SetMarkerColor(1);
        RMS_gr->SetLineWidth(2);
        RMS_gr->SetMarkerStyle(33); RMS_gr->SetMarkerSize(3);

        auto RMS_gr_Sys = new TGraphErrors(7,R,rms_def,R_err,rms_total);
        RMS_gr_Sys->SetMarkerSize(1);RMS_gr_Sys->SetMarkerStyle(1);
        RMS_gr_Sys->SetFillColor(0); RMS_gr_Sys->SetFillStyle(0);
ofstream myfile;
myfile.open (Form("Systematics_on_mean_%d_%d_rel.txt",ptlow,pthigh));
myfile<<"R = 0.05 0.1  0.15 0.2  0.25  0.3 0.35  \n";
myfile <<"Total systematics\n";
for(int i=0;i<7;i++) myfile<<" "<<mean_total[i]/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Default mean\n";
for(int i=0;i<7;i++) myfile<<" "<<mean_def[i]<< " ";
myfile<<"\n";
myfile <<"TrackEff mean\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_trackeff[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Niter mean 3\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_niter3[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Niter mean 5\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_niter5[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Prior1 mean\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_prior1[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<" Prior2 mean\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_prior2[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<" Trunc mean\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_trunc[i]-mean_def[i])/mean_def[i]<< " ";
myfile<<"\n";
myfile <<"Herwig mean\n";
for(int i=0;i<7;i++) myfile<<" "<<(mean_herwig[i]-mean_fast[i])/mean_fast[i]<< " ";
myfile<<"\n";
myfile <<"Pythia mean \n";
for(int i=0;i<7;i++) myfile<<" "<<mean_fast[i]<< " ";
myfile<<"\n";

//Save output file
TFile*Result = TFile::Open("Final_Mean_Result_pp.root","UPDATE","Final_Mean_Result_pp.root");
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

