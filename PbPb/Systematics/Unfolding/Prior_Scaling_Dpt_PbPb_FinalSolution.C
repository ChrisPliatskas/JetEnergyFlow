void Prior_Scaling_Dpt_PbPb_FinalSolution(const char* fname,double Rjet,Double_t PT_MIN = 0.0, Double_t DPT_MIN = -20.0,Double_t PT_MAX=100.0,Double_t DPT_MAX=30.0, double BinWidth = 3.,double perc = 0.05){
TFile*f = TFile::Open(fname);
AliEmcalList* ali;
f->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_PicoTracks_caloClusters_emcalCells_Embed_ConstSub_SmallR_histos",ali);

//f->GetObject("AliAnalysisTaskEmcalJetEnergyFlow_PicoTracks_caloClusters_emcalCells_Embed_ConstSub_SmallR_histos",ali);

int R = int(100*Rjet);

THnSparseD* RM =(THnSparseD*)(ali->FindObject(Form("ResponseMatrix_R%03d_0",R)));

THnSparseD* RM_mod1 =(THnSparseD*)RM->Clone(Form("RM_mod1_R%03d",R));//RM_mod1->Reset();
THnSparseD* RM_mod2 =(THnSparseD*)RM->Clone(Form("RM_mod2_R%03d",R));//RM_mod2->Reset();
//THnD* RM_mod1 =(THnD*)RM->Clone(Form("RM_mod1_R%03d",R));//RM_mod1->Reset();
//THnD* RM_mod2 =(THnD*)RM->Clone(Form("RM_mod2_R%03d",R));//RM_mod2->Reset();


TH2D *Dpt_pt_true = dynamic_cast<TH2D*>(RM->Projection(2,0,"E"));
Dpt_pt_true->SetName(Form("DeltaPt_Pt_gen_R%03d",R));
TH2D *Dpt_pt_meas = dynamic_cast<TH2D*>(RM->Projection(3,1,"E"));
Dpt_pt_meas->SetName(Form("DeltaPt_Pt_det_R%03d",R));

Double_t pt_min = PT_MIN; // Lower Pt limit for detector level, Perhaps we can change this to evaluate systematics
Double_t pt_max = PT_MAX;//100.0;//40.0;  //Upper Pt limit for detector level (Gen level is higher by 10 GeV (feed-in effect)).
Double_t pt_min_gen = PT_MIN;//0.;//PT_MIN;// Lower Pt limit for generator level
Double_t Dpt_min = DPT_MIN; //Lower Dpt limit for detector level
Double_t Dpt_max = DPT_MAX; //Upper Dpt limit for detector level(Gen level is higher by 5 GeV (feed-in effect))
Double_t Dpt_max_gen = DPT_MAX+BinWidth;//31.5; //Upper Dpt limit for truth level(Gen level is higher by 5 GeV (feed-in effect))

      //Detector, Particle level
Int_t nPtBinWidth[2] = {5,10};
Double_t ptmin[2] = {pt_min,pt_min_gen};
Double_t ptmax[2] = {pt_max,pt_max+10.};// 200};
Int_t nBinPt[2] = {int(ptmax[0]-ptmin[0])/nPtBinWidth[0],int(ptmax[1]-ptmin[1])/nPtBinWidth[1]};

     //Detector, Particle level
Int_t nDptBinWidth[2] = {int(BinWidth),int(BinWidth)};
Double_t Dptmin[2] = {Dpt_min ,Dpt_min};//-BinWidth};
Double_t Dptmax[2] = {Dpt_max,Dpt_max_gen};
Int_t nBinDpt[2] = {int(Dptmax[0]-Dptmin[0])/nDptBinWidth[0],int(Dptmax[1]-Dptmin[1])/nDptBinWidth[1]};

//Rebining the Detector level axes
TH2D *h2Dpt_Rebined_Meas = new TH2D(Form("h2Dpt_Rebined_Meas_R%03d",R),Form("#DeltaP_{t} distribution R =%.2f (Detector level -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);
//Rebining the Particle level axes
TH2D *h2Dpt_Rebined_True = new TH2D(Form("h2Dpt_Rebined_True_R%03d",R),Form("#DeltaP_{t} distribution R =%.2f (Generator level -Rebinned);P_{t} (GeV/c);#DeltaP_{t} (GeV/c)",Rjet),nBinPt[1],ptmin[1],ptmax[1],nBinDpt[1],Dptmin[1],Dptmax[1]);
//Feed-out Response
TH2D *h2Dpt_miss_mod1 = new TH2D(Form("h2Dpt_miss_R%03d_mod1",R),Form("h2Dpt_miss_R =%.2f",Rjet),nBinPt[1],ptmin[1],ptmax[1],nBinDpt[1],Dptmin[1],Dptmax[1]);
TH2D *h2Dpt_miss_mod2 = new TH2D(Form("h2Dpt_miss_R%03d_mod2",R),Form("h2Dpt_miss_R =%.2f",Rjet),nBinPt[1],ptmin[1],ptmax[1],nBinDpt[1],Dptmin[1],Dptmax[1]);
TH2D *hFake_mod1 = new TH2D(Form("hFake_R%03d_mod1",int(Rjet*100)),Form("hFake_R =%.2f",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);
TH2D *hFake_mod2 = new TH2D(Form("hFake_R%03d_mod2",int(Rjet*100)),Form("hFake_R =%.2f",Rjet),nBinPt[0],ptmin[0],ptmax[0],nBinDpt[0],Dptmin[0],Dptmax[0]);

for(Int_t ix=1;ix<=h2Dpt_Rebined_Meas->GetNbinsX();ix++){

      Double_t xlow = h2Dpt_Rebined_Meas->GetXaxis()->GetBinLowEdge(ix);
      Double_t xup = h2Dpt_Rebined_Meas->GetXaxis()->GetBinUpEdge(ix);
      Int_t jxlow = Dpt_pt_meas->GetXaxis()->FindBin(xlow+0.000001);
      Int_t jxup = Dpt_pt_meas->GetXaxis()->FindBin(xup-0.000001);
      for(Int_t iy = 1; iy<=h2Dpt_Rebined_Meas->GetNbinsY(); iy++) {
        Double_t ylow = h2Dpt_Rebined_Meas->GetYaxis()->GetBinLowEdge(iy);
        Double_t yup =h2Dpt_Rebined_Meas->GetYaxis()->GetBinUpEdge(iy);
        Int_t jylow = Dpt_pt_meas->GetYaxis()->FindBin(ylow+0.000001);
        Int_t jyup = Dpt_pt_meas->GetYaxis()->FindBin(yup-0.000001);

        Double_t err = 0.;
        Double_t con = Dpt_pt_meas->IntegralAndError(jxlow,jxup,jylow,jyup,err);
        h2Dpt_Rebined_Meas->SetBinContent(ix,iy,con);
        h2Dpt_Rebined_Meas->SetBinError(ix,iy,err);
         } //End of ybin loop
         } //End of xbin loop


// Repeating the process for the particle level
  for(Int_t ix = 1; ix<=h2Dpt_Rebined_True->GetNbinsX(); ix++) {
      Double_t xlow = h2Dpt_Rebined_True->GetXaxis()->GetBinLowEdge(ix);
      Double_t xup = h2Dpt_Rebined_True->GetXaxis()->GetBinUpEdge(ix);
      Int_t jxlow = Dpt_pt_true->GetXaxis()->FindBin(xlow+0.000001);
      Int_t jxup = Dpt_pt_true->GetXaxis()->FindBin(xup-0.000001);
      for(Int_t iy = 1; iy<=h2Dpt_Rebined_True->GetNbinsY(); iy++) {
        Double_t ylow = h2Dpt_Rebined_True->GetYaxis()->GetBinLowEdge(iy);
        Double_t yup = h2Dpt_Rebined_True->GetYaxis()->GetBinUpEdge(iy);
        Int_t jylow = Dpt_pt_true->GetYaxis()->FindBin(ylow+0.000001);
        Int_t jyup = Dpt_pt_true->GetYaxis()->FindBin(yup-0.000001);

        Double_t err = 0.;
        Double_t con = Dpt_pt_true->IntegralAndError(jxlow,jxup,jylow,jyup,err);
        h2Dpt_Rebined_True->SetBinContent(ix,iy,con);
        h2Dpt_Rebined_True->SetBinError(ix,iy,err);
      }
    }

TH2D *Dpt_pt_true_mod1 = (TH2D*)h2Dpt_Rebined_True->Clone(Form("DeltaPt_Pt_gen_R%03d_mod1",R));
Dpt_pt_true_mod1->Reset(); 
TH2D *Dpt_pt_meas_mod1 = (TH2D*)h2Dpt_Rebined_Meas->Clone(Form("DeltaPt_Pt_det_R%03d_mod1",R));
Dpt_pt_meas_mod1->Reset(); 

TH2D *Dpt_pt_true_mod2 = (TH2D*)h2Dpt_Rebined_True->Clone(Form("DeltaPt_Pt_gen_R%03d_mod2",R));
Dpt_pt_true_mod2->Reset(); 
TH2D *Dpt_pt_meas_mod2 = (TH2D*)h2Dpt_Rebined_Meas->Clone(Form("DeltaPt_Pt_det_R%03d_mod2",R));
Dpt_pt_meas_mod2->Reset(); 


int Nbins0= h2Dpt_Rebined_True->GetNbinsX();
int Nbins1= h2Dpt_Rebined_Meas->GetNbinsX();
int Nbins2= h2Dpt_Rebined_True->GetNbinsY(); 
int Nbins3= h2Dpt_Rebined_Meas->GetNbinsY();

                //Fitting section and function modification 
TH2D *Dpt_RM = dynamic_cast<TH2D*>(RM->Projection(2,3,"E"));
Dpt_RM->SetName("Dpt_RM");
TH1D*pro_Dpt =Dpt_RM->ProjectionY("pro_Dpt",0,-1,"e");
TFitResultPtr r =pro_Dpt->Fit("expo","S","same",1,27.5);
double p1 = r->Parameter(0);
double p2 = r->Parameter(1);

double weight =0.;
double cont=0.;
double mod =0.;
double con =0.;
double dpt_tr=0.;
TF1* func = pro_Dpt->GetFunction("expo");
TF1* mod_func1 = (TF1*)func->Clone();
mod_func1->SetParameter(1,(1.+perc)*p2);
TF1* mod_func2 = (TF1*)func->Clone();
mod_func2->SetParameter(1,(1.-perc)*p2);

                //Modification 1
//Filling the modified truth level projections
for (int ibin2 =1;ibin2<Nbins2;ibin2++){
        dpt_tr=h2Dpt_Rebined_True->GetYaxis()->GetBinCenter(ibin2);
        mod = mod_func1->Eval(dpt_tr)/func->Eval(dpt_tr);
  //      cont = pro_Dpt->GetBinContent(ibin0);
  //      weight = mod/cont;
        for (int ibin0=1;ibin0<Nbins0;ibin0++){
        con = h2Dpt_Rebined_True->GetBinContent(ibin0,ibin2);
        Dpt_pt_true_mod1->SetBinContent(ibin0,ibin2,mod*con);        
        }       
        }

//Filling the modified detector level projections
for (int ibin3 =1;ibin3<Nbins3;ibin3++){
        dpt_tr=h2Dpt_Rebined_True->GetYaxis()->GetBinCenter(ibin3);
        mod = mod_func1->Eval(dpt_tr)/func->Eval(dpt_tr);
        for (int ibin1=1;ibin1<Nbins1;ibin1++){
        con = h2Dpt_Rebined_Meas->GetBinContent(ibin1,ibin3);
        Dpt_pt_meas_mod1->SetBinContent(ibin1,ibin3,mod*con);
        }
        }

RooUnfoldResponse *fResponse1 = new RooUnfoldResponse(Form("Response_R%03d_mod1",R),"RM_mod1");
fResponse1->Setup(Dpt_pt_meas_mod1,Dpt_pt_true_mod1);
double pt_meas=0.;double pt_true=0.;double Dpt_meas=0.;double Dpt_true=0.;
//double cont[4]= {};

   //Fill RooUnfoldResponse object
     Int_t* coord1 = new Int_t[4]; //Carries the bin coordinates
     Int_t nbin = RM->GetNbins();
     Bool_t TruthFlag = kFALSE; Bool_t DetectorFlag = kFALSE;
        for(Int_t bin=0; bin<nbin; bin++) {
      Double_t w = RM->GetBinContent(bin,coord1);
      TruthFlag = kFALSE; DetectorFlag = kFALSE;
      Double_t Dpt_meas = RM->GetAxis(3)->GetBinCenter(coord1[3]);
      Double_t Dpt_true = RM->GetAxis(2)->GetBinCenter(coord1[2]);
      Double_t pt_meas = RM->GetAxis(1)->GetBinCenter(coord1[1]);
      Double_t pt_true = RM->GetAxis(0)->GetBinCenter(coord1[0]);
        mod = mod_func1->Eval(Dpt_true)/func->Eval(Dpt_true);
      //  cont[0] =pt_true; cont[1]=pt_meas; cont[2]=Dpt_true; cont[3]=Dpt_meas;
         RM_mod1->SetBinContent(bin,mod*w);
        //weight = mod/w;
        if((Dpt_meas>=Dptmin[0] && Dpt_meas<Dptmax[0]) && (pt_meas>=ptmin[0] && pt_meas<ptmax[0]))DetectorFlag=kTRUE;
        if((Dpt_true>=Dptmin[1] && Dpt_true<Dptmax[1]) && (pt_true>=ptmin[1] && pt_true<ptmax[1]))TruthFlag = kTRUE;
        if(TruthFlag && DetectorFlag)
        fResponse1->Fill(pt_meas,Dpt_meas,pt_true,Dpt_true,mod*w);
      else if (!DetectorFlag)   //(TruthFlag && (!DetectorFlag))
        {
        fResponse1->Miss(pt_true,Dpt_true,mod*w);
        h2Dpt_miss_mod1->Fill(pt_true,Dpt_true,mod*w);
        }
        else if(DetectorFlag && (!TruthFlag)){
        fResponse1->Miss(pt_true,Dpt_true,mod*w);
//        fResponse1->Fake(pt_meas,Dpt_meas,mod*w);
        hFake_mod1->Fill(pt_meas,Dpt_meas,mod*w);
        }
        }

        //Modification 2
for (int ibin2 =1;ibin2<Nbins2;ibin2++){
        dpt_tr=h2Dpt_Rebined_True->GetYaxis()->GetBinCenter(ibin2);
        mod = mod_func2->Eval(dpt_tr)/func->Eval(dpt_tr);
  //      cont = pro_Dpt->GetBinContent(ibin0);
  //      weight = mod/cont;
        for (int ibin0=1;ibin0<Nbins0;ibin0++){
        con = h2Dpt_Rebined_True->GetBinContent(ibin0,ibin2);
        Dpt_pt_true_mod2->SetBinContent(ibin0,ibin2,mod*con);
        }
        }

//Filling the modified detector level projections
for (int ibin3 =1;ibin3<Nbins3;ibin3++){
        dpt_tr=h2Dpt_Rebined_True->GetYaxis()->GetBinCenter(ibin3);
        mod = mod_func2->Eval(dpt_tr)/func->Eval(dpt_tr);
        for (int ibin1=1;ibin1<Nbins1;ibin1++){
        con = h2Dpt_Rebined_Meas->GetBinContent(ibin1,ibin3);
        Dpt_pt_meas_mod2->SetBinContent(ibin1,ibin3,mod*con);
        }
        }

RooUnfoldResponse *fResponse2 = new RooUnfoldResponse(Form("Response_R%03d_mod2",R),"RM_mod2");
fResponse2->Setup(Dpt_pt_meas_mod2,Dpt_pt_true_mod2);

   //Fill RooUnfoldResponse object
     Int_t* coord2 = new Int_t[4]; //Carries the bin coordinates
//     Int_t nbin = RM_thn->GetNbins();
        TruthFlag = kFALSE;DetectorFlag = kFALSE;
        for(Int_t bin=0; bin<nbin; bin++) {
      Double_t w = RM->GetBinContent(bin,coord2);
      TruthFlag = kFALSE; DetectorFlag = kFALSE;
      Double_t Dpt_meas = RM->GetAxis(3)->GetBinCenter(coord2[3]);
      Double_t Dpt_true = RM->GetAxis(2)->GetBinCenter(coord2[2]);
      Double_t pt_meas = RM->GetAxis(1)->GetBinCenter(coord2[1]);
      Double_t pt_true = RM->GetAxis(0)->GetBinCenter(coord2[0]);
        mod = mod_func2->Eval(Dpt_true)/func->Eval(Dpt_true);
//        cont[0] =pt_true; cont[1]=pt_meas; cont[2]=Dpt_true; cont[3]=Dpt_meas;
        RM_mod2->SetBinContent(bin,mod*w);
//        weight = mod/w;
        if((Dpt_meas>=Dptmin[0] && Dpt_meas<Dptmax[0]) && (pt_meas>=ptmin[0] && pt_meas<ptmax[0]))DetectorFlag=kTRUE;
        if((Dpt_true>=Dptmin[1] && Dpt_true<Dptmax[1]) && (pt_true>=ptmin[1] && pt_true<ptmax[1]))TruthFlag = kTRUE;
        if(TruthFlag && DetectorFlag)
        fResponse2->Fill(pt_meas,Dpt_meas,pt_true,Dpt_true,mod*w);
      else if (!DetectorFlag)     //(TruthFlag && (!DetectorFlag))
        {
        fResponse2->Miss(pt_true,Dpt_true,mod*w);
        h2Dpt_miss_mod2->Fill(pt_true,Dpt_true,mod*w);
        }
        else if(DetectorFlag && (!TruthFlag)){
        fResponse2->Miss(pt_true,Dpt_true,mod*w);
//        fResponse2->Fake(pt_meas,Dpt_meas,mod*w);
        hFake_mod2->Fill(pt_meas,Dpt_meas,mod*w);
        }
        }

/*
   //Fill RooUnfoldResponse object
      Int_t* coord1 = new Int_t[4]; //Carries the bin coordinates
        for (int j=1;j<Nbins0;j++){
                mod = mod_func1->Eval(pro_pt->GetBinCenter(j));
                cont = pro_pt->GetBinContent(j);
                weight = mod/cont;
                for (int k=1;k<Nbins1;k++){
                        for (int l=1;l<Nbins2;l++){
                                for (int m=1;m<Nbins3;m++){                  
                                        coord1[0]=j;
                                        coord1[1]=k;
                                        coord1[2]=l;
                                        coord1[3]=m;
                                        int bin =RM->GetBin(coord1);
                                        con = RM->GetBinContent(bin);
                                        Dpt_meas= RM->GetAxis(3)->GetBinCenter(coord1[3]);
                                        Dpt_true = RM->GetAxis(2)->GetBinCenter(coord1[2]);
                                        pt_meas = RM->GetAxis(1)->GetBinCenter(coord1[1]);
                                        pt_true = RM->GetAxis(0)->GetBinCenter(coord1[0]);
                                        if(Dpt_meas>=Dptmin[0] && Dpt_meas<Dptmax[0]
                                        && Dpt_true>=Dptmin[1] && Dpt_true<Dptmax[1]
                                        && pt_meas>=ptmin[0] && pt_meas<ptmax[0]
                                        && pt_true>=ptmin[1] && pt_true<ptmax[1]
                                        ) 
                        fResponse1->Fill(pt_meas,Dpt_meas,pt_true,Dpt_true,weight*con);
                        else fResponse->Miss(pt_true,Dpt_true,weight*con);
                                                           }        
                                                  }
                                        }

                                }*/

        delete [] coord1; delete [] coord2;

TFile*fout = new TFile(Form("Modified_Response_PbPb_FinalSolution_BinW%d_Dpt%d_ptmin%d_%d_DptMin%02d_DptMax%02d.root",int(BinWidth),int(perc*100),int(PT_MIN),int(PT_MAX),int(Dpt_min),int(Dpt_max)),"UPDATE");
        h2Dpt_Rebined_Meas->Write();
        h2Dpt_Rebined_True->Write();
        Dpt_pt_true_mod1->Write();Dpt_pt_meas_mod1->Write();
        Dpt_pt_true_mod2->Write();Dpt_pt_meas_mod2->Write();
        h2Dpt_miss_mod1->Write();
        h2Dpt_miss_mod2->Write();
        pro_Dpt->Write(Form("pro_dpt_R%03d",R));
        RM->Write(Form("RM_R%03d",R));
        RM_mod1->Write(Form("RM_R%03d_mod1",R));
        RM_mod2->Write(Form("RM_R%03d_mod2",R));      
        fResponse1->Write();
        fResponse2->Write();
        func->Write(Form("Fit_func_R%03d",R));
        mod_func2->Write(Form("Mod_func2_R%03d",R));
        mod_func1->Write(Form("Mod_func1_R%03d",R));
        hFake_mod1->Write();
        hFake_mod2->Write();
        func->Write();
        fout->Write();
        fout->Close();

}
