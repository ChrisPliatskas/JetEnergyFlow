//--------------------------------Script description------------------------------------------------
//Date: 7th Jan 2021 Author: Chris Pliatskas
// This is a script will be used to calculate the energy flow fluctuations among jets of increasing jet radius. This is meant as an MC comparison for the Energy flow analysis task, using JEWEL jets as input. Previous implementations were using trees as a data format and were focusing on only hte leading jet for each Rjet wthout any matching conditions. A major requirement was that events would only be saved if a suitable jet was found for every Rjet ("full chain restriction"). The purpose of this script is to loose the latter restriction and simulate the analysis process of the analysis task as best as possible. For that reason,histograms are chosen as a first and simpler approach with the option to extend to a tree implementation which provides more options.

//Including libraries


#include "HepMC/IO_GenEvent.h"
#include "HepMC/GenEvent.h"

#include "fastjet/Selector.hh" //.......... Background Sutraction event by event
#include "fastjet/tools/GridMedianBackgroundEstimator.hh"//.......... Background Sutraction event by event

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/ClusterSequenceAreaBase.hh"
#include "fastjet/contrib/ConstituentSubtractor.hh"

#include "TPDGCode.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TMath.h"
#include "THn.h"
#include "TSystem.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "TTree.h"
#include "THnSparse.h"
#include "TProfile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TFile.h"
#include "TClonesArray.h"
#include "TFile.h"
#include "TList.h"
#include "TVector3.h"
#include "TMath.h"
#include "THnSparse.h"
#include "TNtuple.h"
#include "TString.h"
#include "TRandom3.h"
#include "TH1D.h"

//Setting flags and using namespaces

using std::cout;
using std::cerr;
using std::endl;
using std::vector;

static const int debug = 0;
static const int do_bkg = 1;//Enable when working with the Recoil sample
static const int charged_jets = 1;

//Secondary function to check if the particle is stable

int is_stable(const HepMC::GenParticle *part) {
// copied from AliStack::IsStable()
int pdg = abs(part->pdg_id());
  if(pdg>1000000000)return kTRUE;

  const Int_t kNstable = 18;
  Int_t i;


  Int_t pdgStable[kNstable] = {
    kGamma,             // Photon
    kElectron,          // Electron
    kMuonPlus,          // Muon 
    kPiPlus,            // Pion
    kKPlus,             // Kaon
    kK0Short,           // K0s
    kK0Long,            // K0l
    kProton,            // Proton 
    kNeutron,           // Neutron
    kLambda0,           // Lambda_0
    kSigmaMinus,        // Sigma Minus
    kSigmaPlus,         // Sigma Plus
    3312,               // Xsi Minus 
    3322,               // Xsi 
    3334,               // Omega
    kNuE,               // Electron Neutrino 
    kNuMu,              // Muon Neutrino
    kNuTau              // Tau Neutrino
  };

  Bool_t isStable = kFALSE;
  for (i = 0; i < kNstable; i++) {
    if (pdg == abs(pdgStable[i])) {
      isStable = kTRUE;
      break;
    }
  }

  return isStable;
}
//Secondary function to check if the particle is stable & charged

int is_stable_charged(const HepMC::GenParticle *part) {
  // copied from AliStack::IsStable() 
 int pdg = abs(part->pdg_id());
  if(pdg>1000000000)return kTRUE;

  const Int_t kNstableCharged = 9;
  Int_t i;


  Int_t pdgStableCharged[kNstableCharged] = {
    kElectron,          // Electron
    kMuonPlus,          // Muon 
    kPiPlus,            // Pion
    kKPlus,             // Kaon
    kProton,            // Proton 
    kSigmaMinus,        // Sigma Minus
    kSigmaPlus,         // Sigma Plus
    3312,               // Xsi Minus 
    3334                // Omega
  };

  Bool_t isStable = kFALSE;
  for (i = 0; i < kNstableCharged; i++) {
    if (pdg == abs(pdgStableCharged[i])) {
      isStable = kTRUE;
      break;
    }
  }
  return isStable;
}

//Secondary function to check if the particle is charged

int is_charged(const HepMC::GenParticle *part) {
  int abs_kf = abs(part->pdg_id());

  if (abs_kf==211 || abs_kf==321 || abs_kf==2212 || abs_kf==11 || abs_kf==13)
    return 1;
  else if (abs_kf != 22 && abs_kf!=111 && abs_kf!=130 && abs_kf!=2112 && abs_kf!=311 && abs_kf!=12 && abs_kf !=14 && abs_kf!=16)
 //   cout << " Unexpected particle: kf=" << abs_kf << endl;
  return 0;
}

//Secondary function to calculate azimuthal angle difference
float dphi(float phi1, float phi2) {
  float dphi=phi1-phi2;
  float pi = 3.14159;
  if (dphi < -pi)
    dphi+=2*pi;
  if (dphi > pi)
    dphi-=2*pi;
  return dphi;
}

void JetMatcher( std::vector <fastjet::PseudoJet> *genJets,const Int_t &kGenJets,
                 std::vector <fastjet::PseudoJet> *recJets,const Int_t &kRecJets,
                TArrayI &iGenIndex,TArrayI &iRecIndex,Int_t iDebug, Float_t maxDist){

 // Get the implementation from the analysis task

   // Size indepnedendentt Implemenation of jet matching
   // Thepassed TArrayI should be static in the user function an only increased if needed
   //
   // Relate the two input jet Arrays
   //
   // The association has to be unique
   // So check in two directions
   // find the closest rec to a gen
   // and check if there is no other rec which is closer
   // Caveat: Close low energy/split jets may disturb this correlation
   //
   // Idea: search in two directions generated e.g (a--e) and rec (1--3)
   // Fill a matrix with Flags (1 for closest rec jet, 2 for closest rec jet
   // in the end we have something like this
   //   1   2   3
   // ------------
   //a| 3   2   0
   //b| 0   1   0
   //c| 0   0   3
   //d| 0   0   1
   //e| 0   0   1
   // Topology
   //  1     2
   //    a         b        
   //
   //  d      c
   //       3     e
   // Only entries with "3" match from both sides

        iGenIndex.Reset(-1);
        iRecIndex.Reset(-1);
	
	Int_t size_gen = genJets->size();
	Int_t size_rec = recJets->size();
        const int kMode = 3;
        const Int_t nGenJets = TMath::Min(size_gen,kGenJets);
        const Int_t nRecJets = TMath::Min(size_rec,kRecJets);
        if(nRecJets==0||nGenJets==0)return;

        static TArrayS iFlag(nGenJets*nRecJets);
        if(iFlag.GetSize()<(nGenJets*nRecJets)){
        iFlag.Set(nGenJets*nRecJets);
        }
        iFlag.Reset(0);

       // find the closest distance to the generated
            for(int ig = 0;ig<nGenJets;++ig){
       fastjet::PseudoJet &genJet = genJets->at(ig);
         // if(!genJet)continue;

      Float_t dist = maxDist;
      if(iDebug>1)Printf("Gen (%d) p_T %3.3f eta %3.3f ph %3.3f ",ig,genJet.pt(),genJet.eta(),genJet.phi());
      for(int ir = 0;ir<nRecJets;++ir){
        fastjet::PseudoJet const &recJet = recJets->at(ir);
   	// if(!recJet)continue;

      if(iDebug>1){
      printf("Rec (%d) ",ir);
      Printf("p_T %3.3f eta %3.3f ph %3.3f ",recJet.pt(),recJet.eta(),recJet.phi());
          }
        Double_t dR = genJet.delta_R(recJet);
        if(iDebug>1)Printf("Distance (%d)--(%d) %g ",ig,ir,dR);

        if(dR<dist){
    iRecIndex[ig] = ir;
    dist = dR;
        }
      }
      if(iRecIndex[ig]>=0)iFlag[ig*nRecJets+iRecIndex[ig]]+=1;
      // Resetting...
	 iRecIndex[ig] = -1;
    }
    // other way around
    for(int ir = 0;ir<nRecJets;++ir){
       fastjet::PseudoJet const &recJet = recJets->at(ir);
     //        if(!recJet)continue;
               Float_t dist = maxDist;
               for(int ig = 0;ig<nGenJets;++ig){
          fastjet::PseudoJet &genJet = genJets->at(ig);
//	  if(!genJet)continue;
     Double_t dR = genJet.delta_R(recJet);
         if(dR<dist){
           iGenIndex[ir] = ig;
           dist = dR;
               }
             }
             if(iGenIndex[ir]>=0)iFlag[iGenIndex[ir]*nRecJets+ir]+=2;
             // Resetting...
            iGenIndex[ir] = -1;
           }

if(iDebug>1)Printf(">>>>>> Matrix Size %d",iFlag.GetSize());

     for(int ig = 0;ig<nGenJets;++ig){
       for(int ir = 0;ir<nRecJets;++ir){
         // Print
         if(iDebug>1)printf("Flag2[%d][%d] %d ",ig,ir,iFlag[ig*nRecJets+ir]);
        	 if(kMode==3){
         // we have a unique correlation
                if(iFlag[ig*nRecJets+ir]==3){
             iGenIndex[ir] = ig;
             iRecIndex[ig] = ir;
         }
         }
         else{
     // we just take the correlation from on side                 
           if((iFlag[ig*nRecJets+ir]&2)==2){
             iGenIndex[ir] = ig;
           }
           if((iFlag[ig*nRecJets+ir]&1)==1){
         iRecIndex[ig] = ir;
     }
               }
             }
             if(iDebug>1)printf("\n");
         }
};

int main(int argc, char **argv) {
//~~~~~~~~~~~~~~~~~~~~~Analysis Level (0th Level)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 if (argc < 2) {
        cerr << "Need two arguments: infile outfile" << endl << "infile is HEPMC ascii format; outfile will be root format" << endl;
        return 1;
  }

// Input and Output name manipulation
char *inname = argv[1];
  // specify an input file
HepMC::IO_GenEvent ascii_in(inname,std::ios::in);

//Specify the name of the output file
 char *outbase = argv[2];
  TString outlabel;
  if (charged_jets == 1) {outlabel += "_charged";}
  if (do_bkg == 1) {outlabel += "_bkgsub";}
TString outname(Form("%s%s.root",outbase,outlabel.Data()));
  cout << "Input: " << inname << ", output " << outname << endl;

TFile fout(outname,"RECREATE");
  static const int nR = 8; // radii 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4
  static float Rstep = 0.05;


  TH1F *hJetPt[nR] = {0};
  TH1F *hJetEta[nR] = {0};
  TH1F *hJetPtMatched[nR] = {0};
  TH1F *hJetEtaMatched[nR] = {0};
  TH2F *hPtJetDeltaPt[nR] = {0};
  TH2F *hPtJetDeltaR[nR] = {0};
  TH3F *hPtJetDeltaRDeltaPt[nR] = {0};
  TH3F *hJetPtDeltaRMF[nR] = {0};
  TH1F *hMatchingEff[nR] = {0};
 // TH2F *hPtJetDeltaPtoverPt_low[nR] = {0};
 // TH2F *hPtJetDeltaPtoverPt_high[nR] = {0};
//  TH2F *hEtaJetDeltaR[nR] = {0};  
//  TH3F *hDptPtDEta[nR] = {0};
//  TH3F *hDptPtEta_low[nR] = {0};
//  TH3F *hDptPtEta_high[nR] = {0};  
  TH3F* hDptPtMultiplicity[nR] = {0};
 // TH2F* hJetPtConstZ[nR] = {0};
 // TH3F* hJetPtConstPtConstR[nR] = {0};
 // TH2F* hJetPtAngularity[nR] = {0};  

//Binning choices;
 const int NPtBins = 40;
 const int PtBin_min = 0;
 const int PtBin_max = 200;
 const int NEtaBins =20;
 const float EtaBin_max = 1.0;
 const float maxEtapart = 2;
 const int NDptBins = 100;
 const int DPtBin_min = -20.5;
 const int DPtBin_max = 79.5;
 const int NDRBins = 120;
 const float DRBin_min = 0.0;
 const float DRBin_max = 0.3;

//General histograms
  TH1F *hNEvent = new TH1F("hNEvent","number of events; N",1,0,1);
  hNEvent->Sumw2();
  TH2D *hPtPartEta = new TH2D("hPtPartEta","Particle p_{t} and #eta distribution ;p_{t};#eta",100,0,100,NEtaBins,-maxEtapart,maxEtapart);
  hPtPartEta->Sumw2();
 
  TString histname;
  TString htitle;
/* Bkg subtracted histograms applicable to Non-pp case- Not implemented for now
   TH2F *hbkgdensity = new TH2F("hbkgdensity","main jet rho,matched jet rho;main;matched",100,0,30, 100,0,30);
  hbkgdensity->Sumw2();
*/
	//Leading subjet
//	TH2F* hJetPtSubjetZr01= new TH2F("hJetPtSubjetZr01","Leading subjet Z_{r} fraction for R=0.4 and r=0.1; p_{t} (GeV/c);Z_{r=0.1}",NPtBins,PtBin_min,PtBin_max,100,0,1);
//	TH2F* hJetPtSubjetZr02= new TH2F("hJetPtSubjetZr02","Leading subjet Z_{r} fraction for R=0.4 and r=0.2; p_{t} (GeV/c);Z_{r=0.2}",NPtBins,PtBin_min,PtBin_max,100,0,1);

//	TH3F* hJetPtDptSubjetZr01= new TH3F("hJetPtDptSubjetZr01","Leading subjet Z_{r} fraction for R=0.4 and r=0.1 vs #Deltap_{t}; p_{t} (GeV/c);#Deltap_{t}(GeV/c);Z_{r=0.1}",NPtBins,PtBin_min,PtBin_max,NDptBins,DPtBin_min,DPtBin_max,10,0,1);
//	TH3F* hJetPtDptSubjetZr02= new TH3F("hJetPtDptSubjetZr02","Leading subjet Z_{r} fraction for R=0.4 and r=0.2 vs #Deltap_{t}; p_{t} (GeV/c);#Deltap_{t}(GeV/c);Z_{r=0.2}",NPtBins,PtBin_min,PtBin_max,NDptBins,DPtBin_min,DPtBin_max,10,0,1); 

	//Inlusive subjet
//	TH2F* hJetPtSubjetZr01_inc= new TH2F("hJetPtSubjetZr01_inc","Inclusive subjet Z_{r} fraction for R=0.4 and r=0.1; p_{t} (GeV/c);Z_{r=0.1}",NPtBins,PtBin_min,PtBin_max,100,0,1);
//        TH2F* hJetPtSubjetZr02_inc= new TH2F("hJetPtSubjetZr02_inc","Inclusive subjet Z_{r} fraction for R=0.4 and r=0.2; p_{t} (GeV/c);Z_{r=0.2}",NPtBins,PtBin_min,PtBin_max,100,0,1);

  //      TH3F* hJetPtDptSubjetZr01_inc= new TH3F("hJetPtDptSubjetZr01_inc","Inclusive subjet Z_{r} fraction for R=0.4 and r=0.1 vs #Deltap_{t}; p_{t} (GeV/c);#Deltap_{t}(GeV/c);Z_{r=0.1}",NPtBins,PtBin_min,PtBin_max,NDptBins,DPtBin_min,DPtBin_max,100,0,1);
   //     TH3F* hJetPtDptSubjetZr02_inc= new TH3F("hJetPtDptSubjetZr02_inc","Inclusive subjet Z_{r} fraction for R=0.4 and r=0.2 vs #Deltap_{t}; p_{t} (GeV/c);#Deltap_{t}(GeV/c);Z_{r=0.2}",NPtBins,PtBin_min,PtBin_max,NDptBins,DPtBin_min,DPtBin_max,100,0,1);

// Creation of R-dependent histograms
for (Int_t iR=0; iR<nR; iR++){
	Float_t Rjet = (iR+1)*Rstep;

	histname = TString::Format("hJetPt_R%03d",int(Rjet*100));
	htitle = TString::Format("Jet p_{t} spectrum for R=%.2f;p_{t} (GeV/c)",Rjet);
	hJetPt[iR] = new TH1F(histname,htitle,NPtBins,PtBin_min,PtBin_max);

        histname = TString::Format("hJetEta_R%03d",int(Rjet*100));
        htitle = TString::Format("Jet #eta distribution for R=%.2f;#eta",Rjet);
        hJetEta[iR] = new TH1F(histname,htitle,NEtaBins,-EtaBin_max,EtaBin_max);

        histname = TString::Format("hJetPtMatched_R%03d",int(Rjet*100));
        htitle = TString::Format("Matched jet p_{t} spectrum for R=%.2f;p_{t} (GeV/c)",Rjet);
        hJetPtMatched[iR] = new TH1F(histname,htitle,NPtBins,PtBin_min,PtBin_max);

        histname = TString::Format("hJetEtaMatched_R%03d",int(Rjet*100));
        htitle = TString::Format("Matched jet #eta distribution for R=%.2f;#eta",Rjet);
        hJetEtaMatched[iR] = new TH1F(histname,htitle,NEtaBins,-EtaBin_max,EtaBin_max);

	if(iR<nR-1){
	histname = TString::Format("hJetPtDeltaRMF_R%03d",int(Rjet*100));
        htitle = TString::Format("#DeltaR between R=%.2f and R=%.2f vs matching p_{t} fraction;p_{t} (GeV/c);#DeltaR;Matching fraction;",Rjet,Rjet+Rstep);
	hJetPtDeltaRMF[iR] = new TH3F(histname,htitle,NPtBins,PtBin_min,PtBin_max,NDRBins,DRBin_min,DRBin_max,20,0,1);

	histname = TString::Format("hMatchingEff_R%03d",int(Rjet*100));
	htitle = TString::Format("Matching efficiency for R=%.2f;Matching efficiency;",Rjet);
	hMatchingEff[iR] = new TH1F(histname,htitle,20,0,1);

	histname = TString::Format("hPtJetDeltaPt_R%03d",int(Rjet*100));
        htitle = TString::Format("#Deltap_{t} between R=%.2f and R=%.2f;p_{t,R=%.2f} (GeV/c);#Delta P_{t} (GeV/c)",Rjet,Rjet+Rstep,Rjet);
        hPtJetDeltaPt[iR] = new TH2F(histname,htitle,NPtBins,PtBin_min,PtBin_max,NDptBins,DPtBin_min,DPtBin_max);

        histname = TString::Format("hPtJetDeltaRDeltaPt_R%03d",int(Rjet*100));
        htitle = TString::Format("#Deltap_{t} vs #DeltaR between R=%.2f and R=%.2f;p_{t,R=%.2f} (GeV/c);#DeltaR;#Deltap_{t} (GeV/c)",Rjet,Rjet+Rstep,Rjet);
        hPtJetDeltaRDeltaPt[iR] = new TH3F(histname,htitle,NPtBins,PtBin_min,PtBin_max,NDRBins,DRBin_min,DRBin_max,NDptBins,DPtBin_min,DPtBin_max);

        histname = TString::Format("hPtJetDeltaR_R%03d",int(Rjet*100));
        htitle = TString::Format("#DeltaR between R=%.2f and R=%.2f;p_{t,R=%.2f} (GeV/c);#DeltaR",Rjet,Rjet+Rstep,Rjet);
        hPtJetDeltaR[iR] = new TH2F(histname,htitle,NPtBins,PtBin_min,PtBin_max,NDRBins,DRBin_min,DRBin_max);
	
	histname = TString::Format("hDptPtMultiplicity_R%03d",int(Rjet*100));
	htitle = TString::Format("#DeltaP_{t} between R=%.2f and R=%.2f vs P_{t} vs multiplicity;#Deltap_{t,R=%.2f} (GeV/c);p_{t,R=%.2f} (GeV/c); Multiplicity",Rjet,Rjet+Rstep,Rjet,Rjet+Rstep);
	hDptPtMultiplicity[iR]= new TH3F(histname,htitle,NDptBins,DPtBin_min,DPtBin_max,NPtBins,PtBin_min,PtBin_max,40,0,40);
	}
}

HepMC::GenEvent* evt = ascii_in.read_next_event();
  if (!evt) cerr << "Input file not found " << inname << endl;

//Event loop
int Event_count=0;
 while(evt)
{
if (debug)cout << "Event: " <<Event_count<<endl;
	Event_count+=1;
  hNEvent->Fill(0.5,evt->weights()[0]); // count events
    double N_matches= 0.;
    float max_eta_track = 2; //2.8;
    float min_pt =10.;
    float max_eta_jet = 0.9-Rstep*nR;
    int index = 0;
    std::vector <fastjet::PseudoJet> Tracks_in;
    for ( HepMC::GenEvent::particle_iterator pit = evt->particles_begin();
          pit != evt->particles_end(); ++pit )
      {
        const HepMC::GenParticle *p = *pit;
        if ((!p->end_vertex() && p->status()==1 && (!charged_jets || is_charged(p)))&& fabs(p->momentum().eta()) < max_eta_track){ hPtPartEta->Fill(p->momentum().perp(), p->momentum().eta(),evt->weights()[0]);
        	if(p->momentum().perp()< 0.15) continue;
                double mom = sqrt(p->momentum().x()*p->momentum().x() +
                                  p->momentum().y()*p->momentum().y() +
                                  p->momentum().z()*p->momentum().z());
                fastjet::PseudoJet jInp(p->momentum().x(),p->momentum().y(),p->momentum().z(),mom);
                jInp.set_user_index(index);
                Tracks_in.push_back(jInp);
                index++;
       }}
      //  cout<<"Number of accepted hard event tracks: "<<Tracks_in.size()<<endl;
        int hard_event_tracks = Tracks_in.size();

//Jet Finding
std::vector <fastjet::PseudoJet> Corrected_tracks;
        if (do_bkg){
        fastjet::GridMedianBackgroundEstimator bge(max_eta_track,0.25);
        fastjet::contrib::ConstituentSubtractor subtractor(&bge);
        subtractor.set_distance_type(fastjet::contrib::ConstituentSubtractor::deltaR);
        subtractor.set_max_distance(0.15);
        subtractor.set_alpha(1);
        subtractor.set_ghost_area(0.005);
        subtractor.set_max_eta(max_eta_track);
        subtractor.set_background_estimator(&bge);
        subtractor.initialize();
        bge.set_particles(Tracks_in);
        Corrected_tracks = subtractor.subtract_event(Tracks_in);
                }
        else Corrected_tracks = Tracks_in;
//	 cout<<"Number of corrected event tracks: "<<Corrected_tracks.size()<<endl;

	fastjet::GhostedAreaSpec ghostSpec(max_eta_track,1,0.005);
	fastjet::Strategy               strategy = fastjet::Best;
	fastjet::RecombinationScheme    recombScheme = fastjet::E_scheme;
	fastjet::AreaType areaType =   fastjet::active_area;
	fastjet::AreaDefinition areaDef = fastjet::AreaDefinition(areaType,ghostSpec);

	fastjet::ClusterSequenceArea* clustSeqCh01=0; fastjet::ClusterSequenceArea* clustSeqCh02=0;
	vector <fastjet::PseudoJet> jets[nR];
	vector <fastjet::PseudoJet> AcceptedJets[nR];
	fastjet::ClusterSequenceArea *clustSeqCh[nR]={0};
	double sum_pt=0;
	float jetR=0.;
	for (int iR =0; iR < nR; iR++) {
      	jetR = Rstep+Rstep*iR;
      	fastjet::JetDefinition jetDefCh(fastjet::antikt_algorithm, jetR,recombScheme, strategy);
      	clustSeqCh[iR]=new fastjet::ClusterSequenceArea(Corrected_tracks, jetDefCh,areaDef);
      	jets[iR] = clustSeqCh[iR]->inclusive_jets();
	// Collection of jets before acceptance cut
	for (auto j:jets[iR]) if((fabs(j.eta()) < max_eta_jet)&&(j.pt()>10.))AcceptedJets[iR].push_back(j);
	// Collection of jets after acceptance cut
	for (auto k:AcceptedJets[iR]){
		hJetPt[iR]->Fill(k.pt(),evt->weights()[0]);
		hJetEta[iR]->Fill(k.eta(),evt->weights()[0]);		
				     }  }
//Jet matching
	Double_t DeltaPt = 0.0;
	Double_t DeltaR = 0.0 ;
	Double_t DeltaEta = 0.0;
	Double_t Pt_low = 0.0;
	Double_t Pt_high = 0.0;
	Int_t Multiplicity = 0;
	Int_t Njets = 200;      //Just a high number so that the matching matrix created by the matcher task will always have the size of the input jet lists
	Int_t &kLowRJets = Njets;
	Int_t &kHighRJets = Njets;

//This array points to the low R jet that matches to each high R jet
	TArrayI iLowRIndex;

// This array points to the high R jet that matches to each low R jet
	TArrayI iHighRIndex;

	for (int iR =0; iR < nR-1; iR++) {
	
	Double_t Maxdist = 0.2;
	
        iLowRIndex.Set(AcceptedJets[iR+1].size());
        iHighRIndex.Set(AcceptedJets[iR].size());

        if(AcceptedJets[iR].size()==0||AcceptedJets[iR+1].size()==0) continue;
	
        JetMatcher(&AcceptedJets[iR],kLowRJets,&AcceptedJets[iR+1],kHighRJets, iLowRIndex,iHighRIndex,0,Maxdist);

	//Fill histograms
	for (Int_t j=0; j<iHighRIndex.GetSize();j++)
                {
        if(iHighRIndex[j]>=0){
		Int_t match_index = iHighRIndex[j];
  //If a match exists then calculate the DeltaPt and DeltaEta quantities before filling the histograms
        if (iLowRIndex[match_index]==j){
		N_matches++;
		Pt_low = AcceptedJets[iR].at(j).pt();
		Pt_high =AcceptedJets[iR+1].at(match_index).pt();
		DeltaPt = Pt_high - Pt_low; 	
//Multiplicity calculation
		Multiplicity =AcceptedJets[iR].at(j).constituents().size();

	if (AcceptedJets[iR].at(j).eta()*AcceptedJets[iR+1].at(match_index).eta()>=0)
		DeltaEta = fabs(AcceptedJets[iR+1].at(match_index).eta()-AcceptedJets[iR].at(j).eta());
	else{if(AcceptedJets[iR].at(j).eta()>0)
		DeltaEta = AcceptedJets[iR].at(j).eta() - AcceptedJets[iR+1].at(match_index).eta();
	     else DeltaEta =AcceptedJets[iR+1].at(match_index).eta() -AcceptedJets[iR].at(j).eta();
	    }
	sum_pt = 0;	
		for(auto cont_lowR:AcceptedJets[iR].at(j).constituents()){
			for(auto cont_highR:AcceptedJets[iR+1].at(match_index).constituents()){		
			if(cont_lowR.user_index()==cont_highR.user_index()){	 
				//	cout<<"MF calculation works!Index is:"<<cont_lowR.user_index()<<endl;
					sum_pt += cont_lowR.pt();}}}
		
		hDptPtMultiplicity[iR]->Fill(DeltaPt,AcceptedJets[iR].at(j).pt(),Multiplicity,evt->weights()[0]);
                DeltaR = AcceptedJets[iR+1].at(match_index).delta_R(AcceptedJets[iR].at(j));
		hJetPtDeltaRMF[iR]->Fill(Pt_low,DeltaR,sum_pt/Pt_high,evt->weights()[0]);
		hJetPtMatched[iR]->Fill(AcceptedJets[iR].at(j).pt(),evt->weights()[0]);
		hJetEtaMatched[iR]->Fill(AcceptedJets[iR].at(j).eta(),evt->weights()[0]);
		jetR = Rstep+Rstep*iR;
		if(iR==nR-2){
			hJetPtMatched[iR+1]->Fill(AcceptedJets[iR+1].at(match_index).pt(),evt->weights()[0]);
			hJetEtaMatched[iR+1]->Fill(AcceptedJets[iR+1].at(match_index).eta(),evt->weights()[0]);	
				
			//Calculation of z_r leading subjet ratios
/*		
			std::vector <fastjet::PseudoJet> Subjet_tracks;
			for(auto cont_sub:AcceptedJets[iR+1].at(match_index).constituents()) Subjet_tracks.push_back(cont_sub);
			vector <fastjet::PseudoJet> Subjets01;
			vector <fastjet::PseudoJet> Subjets02;
			fastjet::JetDefinition SubjetDef01(fastjet::antikt_algorithm, 0.1,recombScheme, strategy);
			fastjet::JetDefinition SubjetDef02(fastjet::antikt_algorithm, 0.2,recombScheme, strategy);
 			clustSeqCh01 = new fastjet::ClusterSequenceArea(Subjet_tracks, SubjetDef01,areaDef);
			clustSeqCh02 = new fastjet::ClusterSequenceArea(Subjet_tracks, SubjetDef02,areaDef);

			Subjets01 = sorted_by_pt(clustSeqCh01->inclusive_jets());
			Subjets02 = sorted_by_pt(clustSeqCh02->inclusive_jets());
			if(debug)cout<<"Z_r filling histograms: "<<(Subjets01[0].pt()/AcceptedJets[iR+1].at(match_index).pt())<<" and "<<(Subjets02[0].pt()/AcceptedJets[iR+1].at(match_index).pt())<<endl;
			hJetPtSubjetZr01->Fill(AcceptedJets[iR+1].at(match_index).pt(),(Subjets01[0].pt()/AcceptedJets[iR+1].at(match_index).pt()),evt->weights()[0]);
			hJetPtSubjetZr02->Fill(AcceptedJets[iR+1].at(match_index).pt(),(Subjets02[0].pt()/AcceptedJets[iR+1].at(match_index).pt()),evt->weights()[0]);			
		//	hJetPtDptSubjetZr01->Fill(AcceptedJets[iR].at(j).pt(),DeltaPt,(Subjets01[0].pt()/AcceptedJets[iR].at(j).pt()),evt->weights()[0]);
		//	hJetPtDptSubjetZr02->Fill(AcceptedJets[iR].at(j).pt(),DeltaPt,(Subjets02[0].pt()/AcceptedJets[iR].at(j).pt()),evt->weights()[0]);
			//Calculation of the inclusive subjet ratios
			for (auto sj01:Subjets01){
				hJetPtSubjetZr01_inc->Fill(AcceptedJets[iR+1].at(match_index).pt(),(sj01.pt()/AcceptedJets[iR+1].at(match_index).pt()),evt->weights()[0]);
		//		hJetPtDptSubjetZr01_inc->Fill(AcceptedJets[iR].at(j).pt(),DeltaPt,(sj01.pt()/AcceptedJets[iR].at(j).pt()),evt->weights()[0]);
				}
			for (auto sj02:Subjets02){
                                hJetPtSubjetZr02_inc->Fill(AcceptedJets[iR+1].at(match_index).pt(),(sj02.pt()/AcceptedJets[iR+1].at(match_index).pt()),evt->weights()[0]);
                  //              hJetPtDptSubjetZr02_inc->Fill(AcceptedJets[iR].at(j).pt(),DeltaPt,(sj02.pt()/AcceptedJets[iR].at(j).pt()),evt->weights()[0]);
                                }		
			delete clustSeqCh01; delete clustSeqCh02; clustSeqCh01=0; clustSeqCh02=0;	*/	
			}
	
		hPtJetDeltaPt[iR]->Fill(AcceptedJets[iR].at(j).pt(),DeltaPt,evt->weights()[0]);
	//	hEtaJetDeltaR[iR]->Fill(AcceptedJets[iR].at(j).eta(),DeltaR,evt->weights()[0]);
		hPtJetDeltaRDeltaPt[iR]->Fill(AcceptedJets[iR].at(j).pt(),DeltaR,DeltaPt,evt->weights()[0]);
		hPtJetDeltaR[iR]->Fill(AcceptedJets[iR].at(j).pt(),DeltaR,evt->weights()[0]);
						}//End of condition for bijective matching
					}//End of condition for existing match for the low R jet
		}// End of loop over the lowR jets
		hMatchingEff[iR]->Fill(N_matches/AcceptedJets[iR].size(),evt->weights()[0]);			
	//	cout<<"Matching efficiency: "<<N_matches/AcceptedJets[iR].size()<<endl;		
		N_matches=0;
		}// End of loop over the jet pairs

	//Clean up
	for (int iR =0; iR < nR; iR++) {
      	delete clustSeqCh[iR];
      	clustSeqCh[iR]=0;
   	 }
 // delete the created event from memory
     delete evt;
// read the next event
     ascii_in >> evt;
} //End of event loop

//----------------------------------------------------------
//cout<<"Writing file"<<endl;
  fout.Write();
//cout<<"Closing file"<<endl;
  fout.Close();

  return 0;
}
