
void SetStyle(TH1*h1,int Color);
void SetStyle2(Bool_t graypalette=kFALSE);

void Syst_Comb_PbPb_60(){

//Open input file
TFile*f_in= TFile::Open("UnfoldedResults_PbPb_ConstSub_wFakes_LCJC8_FinalSolution_smallR_Binw3_pt_60_80_ptmin10_140_Dptmin-1_max28_Iter5.root");

//Load unfolded distributions
TH2D* unf_data_R005_def;f_in->GetObject("Unfolded_Dpt_data_R005",unf_data_R005_def);
TH2D* unf_data_R010_def;f_in->GetObject("Unfolded_Dpt_data_R010",unf_data_R010_def);
TH2D* unf_data_R015_def;f_in->GetObject("Unfolded_Dpt_data_R015",unf_data_R015_def);
TH2D* unf_data_R020_def;f_in->GetObject("Unfolded_Dpt_data_R020",unf_data_R020_def);


int ptlow =60;
int pthigh=80;


int Dpt_low_bin = unf_data_R005_def->GetYaxis()->FindBin(0.);
int Dpt_high_bin = unf_data_R005_def->GetYaxis()->FindBin(28.);
int Ptlow_bin =unf_data_R005_def->GetXaxis()->FindBin(ptlow);
int Pthigh_bin = unf_data_R005_def->GetXaxis()->FindBin(pthigh)-1;

unf_data_R005_def->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
unf_data_R010_def->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
unf_data_R015_def->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);
unf_data_R020_def->GetYaxis()->SetRange(Dpt_low_bin,Dpt_high_bin);

TH1D* pro_unf_R005_def = (TH1D*)unf_data_R005_def->ProjectionY("pro_unf_R005_def",Ptlow_bin,Pthigh_bin);
TH1D* pro_unf_R010_def = (TH1D*)unf_data_R010_def->ProjectionY("pro_unf_R010_def",Ptlow_bin,Pthigh_bin);
TH1D* pro_unf_R015_def = (TH1D*)unf_data_R015_def->ProjectionY("pro_unf_R015_def",Ptlow_bin,Pthigh_bin);
TH1D* pro_unf_R020_def = (TH1D*)unf_data_R020_def->ProjectionY("pro_unf_R020_def",Ptlow_bin,Pthigh_bin);

pro_unf_R005_def->Scale(1./pro_unf_R005_def->Integral("width")); pro_unf_R010_def->Scale(1./pro_unf_R010_def->Integral("width"));
pro_unf_R015_def->Scale(1./pro_unf_R015_def->Integral("width")); pro_unf_R020_def->Scale(1./pro_unf_R020_def->Integral("width"));


//Clone syst-error versions 
double track_eff_sys=0;double prior_sys=0;
double LC_sys=0; double niter_sys =0;
double unf_sys =0; double trunc_sys=0;
double bkg_sys =0;
double total =0; int range=0;
double con =0;double cent=0;

double pro_sys_R005[10] ={};double pro_sys_R010[10] ={};
double pro_sys_R015[10] ={};double pro_sys_R020[10] ={};
double dpt_err[10] ={};

double pro_R005[10] ={};double pro_R010[10] ={};
double pro_R015[10] ={};double pro_R020[10] ={};

double total_R005[10] ={};double total_R010[10] ={};
double total_R015[10] ={};double total_R020[10] ={};

double total_R005_err[10] ={};double total_R010_err[10] ={};
double total_R015_err[10] ={};double total_R020_err[10] ={};

//Dpt dependenct systematics
double TrackEff[4][6]= {{.015, .03, .038, .05, .07, .07},               //R =0.05
                        {.027, .06, .08, .09, .09, .09},                //R=0.1
                        {.025, .08, .11, .11, .11, .11},                //R=0.15
                        {.02, .1, .15, .15, .1, .1}};                   //R=0.2

double Trunc[4][6] =    {{.0005, .0005, .001, .0025, .000, .006},       //R =0.05
                         {.002, .003, .0015, .0015, .0025, .0025},      //R=0.1
                         {.0008, .0035, .004, .004, .003, .003},        //R=0.15
                         {.001, .005, .005, .007, .007, .007}};         //R=0.2


double Niter[4][6]=     {{.008, .008, .008, .015, .02, .02},            //R =0.05
                         {.02, .03, .02, .02, .025, .025},              //R=0.1
                         {.025, .075, .075, .05, .05, .06},             //R=0.15
                         {.025, .11, .16, .18, .18, .18}};              //R=0.2


double Prior[4][6]=     {{.002, .0015, .002, .0025, .007, .007},        //R =0.05
                         {.0006, .004, .002, .0015, .002, .02},         //R=0.1
                         {.001, .025, .025, .035, .05, .05},            //R=0.15
                         {.02, .07, .12, .18, .22, .22}};               //R=0.2

double LC[4][6]=        {{.002, .006, .006, .006, .015, .015},          //R =0.05
                         {.002, .005, .005, .015, .015, .015},          //R=0.1
                         {.002, .015, .028, .04, .04, .04},             //R=0.15
                         {.003, .02, .04, .04, .04, .04}};              //R=0.2

double BkgSub[4][6]=     {{.03, .03, .02, .015, .015, .015},            //R =0.05
                          {.035, .05, .04, .017, .01, .01},             //R=0.1
                          {.03, .1, .06, .02, .02, .02},                //R=0.15
                          {.025, .12, .14, .12, .2, .2}};               //R=0.2



//Calculate total systematic
int R=0;
        //---------R=0.05------------//
        R=0;
        for(int ibin=1;ibin<=pro_unf_R005_def->GetNbinsX();ibin++){
        con = pro_unf_R005_def->GetBinContent(ibin);
        cent =pro_unf_R005_def->GetBinCenter(ibin);
        range = int(cent/5);
        track_eff_sys =TrackEff[R][range]*con;
        LC_sys =LC[R][range]*con;
        bkg_sys = BkgSub[R][range]*con;
        prior_sys =Prior[R][range]*con;
        trunc_sys =Trunc[R][range]*con;
        niter_sys =Niter[R][range]*con;
        unf_sys = TMath::Sqrt((TMath::Power(niter_sys,2)+TMath::Power(prior_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(LC_sys,2)+TMath::Power(unf_sys,2)+TMath::Power(bkg_sys,2));
        total_R005[ibin-1]=total;total_R005_err[ibin-1]=total/con;
        pro_sys_R005[ibin-1]=cent;
        pro_R005[ibin-1]=con;dpt_err[ibin-1]=1.5;
                }
        //---------R=0.1------------//
        R=1;
        for(int ibin=1;ibin<=pro_unf_R010_def->GetNbinsX();ibin++){
        con = pro_unf_R010_def->GetBinContent(ibin);
        cent =pro_unf_R010_def->GetBinCenter(ibin);
        range = int(cent/5);
        track_eff_sys =TrackEff[R][range]*con;
        LC_sys =LC[R][range]*con;
        bkg_sys = BkgSub[R][range]*con;
        prior_sys =Prior[R][range]*con;
        trunc_sys =Trunc[R][range]*con;
        niter_sys =Niter[R][range]*con;
        unf_sys = TMath::Sqrt((TMath::Power(niter_sys,2)+TMath::Power(prior_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(LC_sys,2)+TMath::Power(unf_sys,2)+TMath::Power(bkg_sys,2));
        total_R010[ibin-1]=total;total_R010_err[ibin-1]=total/con;
        pro_sys_R010[ibin-1]=cent;
        pro_R010[ibin-1]=con;
                }

        //---------R=0.15------------//
        R=2;             
        for(int ibin=1;ibin<=pro_unf_R015_def->GetNbinsX();ibin++){
        con = pro_unf_R015_def->GetBinContent(ibin);
        cent =pro_unf_R015_def->GetBinCenter(ibin);
        range = int(cent/5);
        track_eff_sys =TrackEff[R][range]*con;
        LC_sys =LC[R][range]*con;
        bkg_sys = BkgSub[R][range]*con;
        prior_sys =Prior[R][range]*con;
        trunc_sys =Trunc[R][range]*con;
        niter_sys =Niter[R][range]*con;
        unf_sys = TMath::Sqrt((TMath::Power(niter_sys,2)+TMath::Power(prior_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(LC_sys,2)+TMath::Power(unf_sys,2)+TMath::Power(bkg_sys,2));
        total_R015[ibin-1]=total;total_R015_err[ibin-1]=total/con;
        pro_sys_R015[ibin-1]=cent;
        pro_R015[ibin-1]=con;
                }

        //---------R=0.2------------//
        R=3;
        for(int ibin=1;ibin<=pro_unf_R020_def->GetNbinsX();ibin++){
        con = pro_unf_R020_def->GetBinContent(ibin);
        cent =pro_unf_R020_def->GetBinCenter(ibin);
        range = int(cent/5);
        track_eff_sys =TrackEff[R][range]*con;
        LC_sys =LC[R][range]*con;
        bkg_sys = BkgSub[R][range]*con;
        prior_sys =Prior[R][range]*con;
        trunc_sys =Trunc[R][range]*con;
        niter_sys =Niter[R][range]*con;
        unf_sys = TMath::Sqrt((TMath::Power(niter_sys,2)+TMath::Power(prior_sys,2)+TMath::Power(trunc_sys,2))/3);
        total = TMath::Sqrt(TMath::Power(track_eff_sys,2)+TMath::Power(LC_sys,2)+TMath::Power(unf_sys,2)+TMath::Power(bkg_sys,2));
        total_R020[ibin-1]=total;total_R020_err[ibin-1]=total/con;
        pro_sys_R020[ibin-1]=cent;
        pro_R020[ibin-1]=con;
                }

//Graph Creation
auto pro_R005_gr = new TGraphErrors(10,pro_sys_R005,pro_R005,dpt_err,total_R005);
pro_R005_gr->SetMarkerStyle(1);pro_R005_gr->SetFillStyle(0);pro_R005_gr->SetFillColor(0);

auto pro_R010_gr = new TGraphErrors(10,pro_sys_R010,pro_R010,dpt_err,total_R010);
pro_R010_gr->SetMarkerStyle(1);pro_R010_gr->SetFillStyle(0);pro_R010_gr->SetFillColor(0);

auto pro_R015_gr = new TGraphErrors(10,pro_sys_R015,pro_R015,dpt_err,total_R015);
pro_R015_gr->SetMarkerStyle(1);pro_R015_gr->SetFillStyle(0);pro_R015_gr->SetFillColor(0);

auto pro_R020_gr = new TGraphErrors(10,pro_sys_R020,pro_R020,dpt_err,total_R020);
pro_R020_gr->SetMarkerStyle(1);pro_R020_gr->SetFillStyle(0);pro_R020_gr->SetFillColor(0);


//Histogram beautification
SetStyle2();

const Int_t fillColors[] = {kGray+1,  kRed-10, kBlue-9, kGreen-8, kMagenta-9, kOrange-9,kCyan-8,kYellow-7};
const Int_t colors[]     = {kBlack, kRed+1 , kBlue+1, kGreen+3, kMagenta+1, kOrange-1,kCyan+2,kYellow+2};
const Int_t markers[]    = {kFullCircle, kFullSquare,kOpenCircle,kOpenSquare,kOpenDiamond,kOpenCross,kFullCross,kFullDiamond,kFullStar,kOpenStar};


        SetStyle(pro_unf_R005_def,colors[0]); SetStyle(pro_unf_R010_def,colors[1]);
        SetStyle(pro_unf_R015_def,colors[2]); SetStyle(pro_unf_R020_def,colors[3]);


        pro_R005_gr->SetLineColor(colors[0]);pro_R010_gr->SetLineColor(colors[1]);
        pro_R015_gr->SetLineColor(colors[2]);pro_R020_gr->SetLineColor(colors[3]);

//Plot final dist
TCanvas*c1 = new TCanvas("c1","c1",1000,1000);
TPad *pad1=new TPad("pad1","pad1",0.,0.,1.,1.);
pad1->SetLeftMargin(0.15);pad1->SetBottomMargin(0.15);
pad1->SetTopMargin(0.1);pad1->SetRightMargin(0.05);
pad1->SetTicky(1);pad1->Draw();
pad1->cd();
pad1->DrawFrame(-1.5,1e-5,28.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{#sigma}_{jet}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}"));
pad1->SetLogy(1);

auto leg2 = new TLegend(.18,.22,.46,.37); //leg2->SetNColumns(2);
leg2->AddEntry(pro_unf_R005_def,"#it{R}=0.05 to 0.1","p");leg2->AddEntry(pro_unf_R010_def,"#it{R}=0.1 to 0.15","p");
leg2->AddEntry(pro_R005_gr," System. unc.","f");

pro_unf_R005_def->Draw("same E1");pro_R005_gr->Draw("same 2");
pro_unf_R010_def->Draw("same E1");pro_R010_gr->Draw("same 2");

TLatex lat1;lat1.SetNDC();lat1.SetTextFont(42);
lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE Pb-Pb data");
lat1.DrawLatex(.62,.84,"#sqrt{#it{s}_{NN}} =5.02 TeV");
lat1.DrawLatex(.42,.74,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}");

leg2->Draw("same");

//Plot final selection
TCanvas*c4_sel = new TCanvas("c4_sel","c4_sel",1000,1000);
TPad *pad4_sel=new TPad("pad4_sel","pad4_sel",0.,0.,1.,1.);
pad4_sel->SetLeftMargin(0.15);pad4_sel->SetBottomMargin(0.15);
pad4_sel->SetTopMargin(0.1);pad4_sel->SetRightMargin(0.05);
pad4_sel->SetTicky(1);pad4_sel->Draw();
pad4_sel->cd();
pad4_sel->DrawFrame(-1.5,1e-5,28.5,1,Form(";#it{#Deltap}_{T} (GeV/#it{c}); #frac{1}{#it{#sigma}_{jet}} #frac{d#it{#sigma}}{d#it{#Deltap}_{T}}"));
pad4_sel->SetLogy(1);

pro_unf_R015_def->Draw("same E1");pro_R015_gr->Draw("same 2");
pro_unf_R020_def->Draw("same E1");pro_R020_gr->Draw("same 2");

auto leg2_sel = new TLegend(.18,.22,.46,.37);
leg2_sel->AddEntry(pro_unf_R015_def,"#it{R}=0.15 to 0.2","p");
leg2_sel->AddEntry(pro_unf_R020_def,"#it{R}=0.2 to 0.25","p");
leg2_sel->AddEntry(pro_R005_gr," System. unc.","f");


lat1.DrawLatex(.42,.84,"This thesis");
lat1.DrawLatex(.42,.79,"ALICE Pbb-Pb data");
lat1.DrawLatex(.62,.84,"#sqrt{#it{s}_{NN}} =13 TeV");
lat1.DrawLatex(.42,.74,"60 < #it{p}_{T,ch jet} < 80 GeV/#it{c}");
leg2_sel->Draw("same");


//Save output in new file
ofstream myfile;
myfile.open (Form("Systematics_on_dpt_PbPb_%d_%d_rel.txt",ptlow,pthigh));
myfile <<"Total systematics\n";
myfile <<"R=0.05 \n";
for(int i=0;i<10;i++) myfile<<" "<<total_R005_err[i]<< " ";
myfile<<"\n";
myfile <<"R=0.1 \n";
for(int i=0;i<10;i++) myfile<<" "<<total_R010_err[i]<< " ";
myfile<<"\n";
myfile <<"R=0.15 \n";
for(int i=0;i<10;i++) myfile<<" "<<total_R015_err[i]<< " ";
myfile<<"\n";
myfile <<"R=0.2 \n";
for(int i=0;i<10;i++) myfile<<" "<<total_R020_err[i]<< " ";
myfile<<"\n";

TFile*Result = TFile::Open("Final_Result_dpt_PbPb_60_80.root","RECREATE","Final_Result_dpt_PbPb_60_80.root");
pro_unf_R005_def->Write(Form("pro_unfolded_R005_%d_%d",ptlow,pthigh));
pro_R005_gr->Write(Form("pro_unfolded_Sys_R005_%d_%d",ptlow,pthigh));
pro_unf_R010_def->Write(Form("pro_unfolded_R010_%d_%d",ptlow,pthigh));
pro_R010_gr->Write(Form("pro_unfolded_Sys_R010_%d_%d",ptlow,pthigh));
pro_unf_R015_def->Write(Form("pro_unfolded_R015_%d_%d",ptlow,pthigh));
pro_R015_gr->Write(Form("pro_unfolded_Sys_R015_%d_%d",ptlow,pthigh));
pro_unf_R020_def->Write(Form("pro_unfolded_R020_%d_%d",ptlow,pthigh));
pro_R020_gr->Write(Form("pro_unfolded_Sys_R020_%d_%d",ptlow,pthigh));
Result->Close();

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

