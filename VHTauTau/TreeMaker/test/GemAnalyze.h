//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Mar 30 20:52:22 2014 by ROOT version 5.34/07
// from TTree vhtree/VH Analysis Tree
// found on file: test_53x.root
//////////////////////////////////////////////////////////

#ifndef GemAnalyze_h
#define GemAnalyze_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxVertex = 4;
const Int_t kMaxGenParticle = 1586;
const Int_t kMaxMuon = 2;
const Int_t kMaxTau = 38;

class GemAnalyze {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           Vertex_;
   UInt_t          Vertex_fUniqueID[kMaxVertex];   //[Vertex_]
   UInt_t          Vertex_fBits[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_x[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_y[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_z[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_xErr[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_yErr[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_zErr[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_rho[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_chi2[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_ndf[kMaxVertex];   //[Vertex_]
   Int_t           Vertex_ntracks[kMaxVertex];   //[Vertex_]
   Int_t           Vertex_ntracksw05[kMaxVertex];   //[Vertex_]
   Bool_t          Vertex_isfake[kMaxVertex];   //[Vertex_]
   Bool_t          Vertex_isvalid[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_sumPt[kMaxVertex];   //[Vertex_]
   Int_t           Vertex_selbit[kMaxVertex];   //[Vertex_]
   Int_t           nVertex;
   Int_t           GenParticle_;
   UInt_t          GenParticle_fUniqueID[kMaxGenParticle];   //[GenParticle_]
   UInt_t          GenParticle_fBits[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_eta[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_phi[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_p[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_px[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_py[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_pz[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_pt[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_energy[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_pdgId[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_vx[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_vy[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_vz[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_status[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_charge[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_numDaught[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_numMother[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_motherIndex[kMaxGenParticle];   //[GenParticle_]
   vector<int>     GenParticle_motherIndices[kMaxGenParticle];
   vector<int>     GenParticle_daughtIndices[kMaxGenParticle];
   Int_t           nGenParticle;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Bool_t          Muon_isTrackerMuon[kMaxMuon];   //[Muon_]
   Bool_t          Muon_isPFMuon[kMaxMuon];   //[Muon_]
   Double_t        Muon_eta[kMaxMuon];   //[Muon_]
   Double_t        Muon_phi[kMaxMuon];   //[Muon_]
   Double_t        Muon_pt[kMaxMuon];   //[Muon_]
   Double_t        Muon_ptError[kMaxMuon];   //[Muon_]
   Double_t        Muon_p[kMaxMuon];   //[Muon_]
   Double_t        Muon_energy[kMaxMuon];   //[Muon_]
   Int_t           Muon_charge[kMaxMuon];   //[Muon_]
   Double_t        Muon_trkD0[kMaxMuon];   //[Muon_]
   Double_t        Muon_trkD0Error[kMaxMuon];   //[Muon_]
   Double_t        Muon_trkDz[kMaxMuon];   //[Muon_]
   Double_t        Muon_trkDzError[kMaxMuon];   //[Muon_]
   Double_t        Muon_globalChi2[kMaxMuon];   //[Muon_]
   Double_t        Muon_trkIso[kMaxMuon];   //[Muon_]
   Double_t        Muon_ecalIso[kMaxMuon];   //[Muon_]
   Double_t        Muon_hcalIso[kMaxMuon];   //[Muon_]
   Double_t        Muon_hoIso[kMaxMuon];   //[Muon_]
   Double_t        Muon_relIso[kMaxMuon];   //[Muon_]
   Int_t           Muon_passID[kMaxMuon];   //[Muon_]
   Double_t        Muon_vtxDist3D[kMaxMuon];   //[Muon_]
   Int_t           Muon_vtxIndex[kMaxMuon];   //[Muon_]
   Double_t        Muon_vtxDistZ[kMaxMuon];   //[Muon_]
   Int_t           Muon_pixHits[kMaxMuon];   //[Muon_]
   Int_t           Muon_trkHits[kMaxMuon];   //[Muon_]
   Int_t           Muon_muoHits[kMaxMuon];   //[Muon_]
   Int_t           Muon_matches[kMaxMuon];   //[Muon_]
   Int_t           Muon_trackerLayersWithMeasurement[kMaxMuon];   //[Muon_]
   Double_t        Muon_pfRelIso[kMaxMuon];   //[Muon_]
   Double_t        Muon_vx[kMaxMuon];   //[Muon_]
   Double_t        Muon_vy[kMaxMuon];   //[Muon_]
   Double_t        Muon_vz[kMaxMuon];   //[Muon_]
   Double_t        Muon_dB[kMaxMuon];   //[Muon_]
   Double_t        Muon_edB[kMaxMuon];   //[Muon_]
   Double_t        Muon_dB3d[kMaxMuon];   //[Muon_]
   Double_t        Muon_edB3d[kMaxMuon];   //[Muon_]
   Bool_t          Muon_isGlobalMuonPromptTight[kMaxMuon];   //[Muon_]
   Bool_t          Muon_isAllArbitrated[kMaxMuon];   //[Muon_]
   Int_t           Muon_nChambers[kMaxMuon];   //[Muon_]
   Int_t           Muon_nMatches[kMaxMuon];   //[Muon_]
   Int_t           Muon_nMatchedStations[kMaxMuon];   //[Muon_]
   UInt_t          Muon_stationMask[kMaxMuon];   //[Muon_]
   UInt_t          Muon_stationGapMaskDistance[kMaxMuon];   //[Muon_]
   UInt_t          Muon_stationGapMaskPull[kMaxMuon];   //[Muon_]
   Int_t           Muon_muonID[kMaxMuon];   //[Muon_]
   Float_t         Muon_idMVA[kMaxMuon];   //[Muon_]
   Float_t         Muon_isoRingsMVA[kMaxMuon];   //[Muon_]
   Float_t         Muon_isoRingsRadMVA[kMaxMuon];   //[Muon_]
   Float_t         Muon_idIsoCombMVA[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIso03v1[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIso03v2[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIsoDB03v1[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIsoDB03v2[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIso04v1[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIso04v2[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIsoDB04v1[kMaxMuon];   //[Muon_]
   Float_t         Muon_pfRelIsoDB04v2[kMaxMuon];   //[Muon_]
   Int_t           Muon_selbit[kMaxMuon];   //[Muon_]
   Int_t           nMuon;
   Int_t           Tau_;
   UInt_t          Tau_fUniqueID[kMaxTau];   //[Tau_]
   UInt_t          Tau_fBits[kMaxTau];   //[Tau_]
   Double_t        Tau_eta[kMaxTau];   //[Tau_]
   Double_t        Tau_phi[kMaxTau];   //[Tau_]
   Double_t        Tau_pt[kMaxTau];   //[Tau_]
   Double_t        Tau_energy[kMaxTau];   //[Tau_]
   Int_t           Tau_charge[kMaxTau];   //[Tau_]
   Double_t        Tau_mass[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkPt[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkPtError[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkEta[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkPhi[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkCharge[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkD0[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkD0Error[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkDz[kMaxTau];   //[Tau_]
   Double_t        Tau_leadTrkDzError[kMaxTau];   //[Tau_]
   Int_t           Tau_vtxIndex[kMaxTau];   //[Tau_]
   Double_t        Tau_vtxDxy[kMaxTau];   //[Tau_]
   Double_t        Tau_vtxDz[kMaxTau];   //[Tau_]
   Double_t        Tau_leadChargedParticlePt[kMaxTau];   //[Tau_]
   Double_t        Tau_leadNeutralParticlePt[kMaxTau];   //[Tau_]
   Double_t        Tau_leadParticlePt[kMaxTau];   //[Tau_]
   Int_t           Tau_numChargedHadronsSignalCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numNeutralHadronsSignalCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numPhotonsSignalCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numParticlesSignalCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numChargedHadronsIsoCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numNeutralHadronsIsoCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numPhotonsIsoCone[kMaxTau];   //[Tau_]
   Int_t           Tau_numParticlesIsoCone[kMaxTau];   //[Tau_]
   Double_t        Tau_ptSumPFChargedHadronsIsoCone[kMaxTau];   //[Tau_]
   Double_t        Tau_ptSumPFNeutralHadronsIsoCone[kMaxTau];   //[Tau_]
   Double_t        Tau_ptSumPhotonsIsoCone[kMaxTau];   //[Tau_]
   Double_t        Tau_sigChHadCandPt[kMaxTau][40];   //[Tau_]
   Double_t        Tau_sigChHadCandEta[kMaxTau][40];   //[Tau_]
   Double_t        Tau_sigChHadCandPhi[kMaxTau][40];   //[Tau_]
   Double_t        Tau_sigNeHadCandPt[kMaxTau][20];   //[Tau_]
   Double_t        Tau_sigNeHadCandEta[kMaxTau][20];   //[Tau_]
   Double_t        Tau_sigNeHadCandPhi[kMaxTau][20];   //[Tau_]
   Double_t        Tau_sigGammaCandPt[kMaxTau][20];   //[Tau_]
   Double_t        Tau_sigGammaCandEta[kMaxTau][20];   //[Tau_]
   Double_t        Tau_sigGammaCandPhi[kMaxTau][20];   //[Tau_]
   Double_t        Tau_isoChHadCandPt[kMaxTau][40];   //[Tau_]
   Double_t        Tau_isoChHadCandEta[kMaxTau][40];   //[Tau_]
   Double_t        Tau_isoChHadCandPhi[kMaxTau][40];   //[Tau_]
   Double_t        Tau_isoNeHadCandPt[kMaxTau][20];   //[Tau_]
   Double_t        Tau_isoNeHadCandEta[kMaxTau][20];   //[Tau_]
   Double_t        Tau_isoNeHadCandPhi[kMaxTau][20];   //[Tau_]
   Double_t        Tau_isoGammaCandPt[kMaxTau][20];   //[Tau_]
   Double_t        Tau_isoGammaCandEta[kMaxTau][20];   //[Tau_]
   Double_t        Tau_isoGammaCandPhi[kMaxTau][20];   //[Tau_]
   Float_t         Tau_decayModeFinding[kMaxTau];   //[Tau_]
   Float_t         Tau_decayModeFindingNewDMs[kMaxTau];   //[Tau_]
   Float_t         Tau_decayModeFindingOldDMs[kMaxTau];   //[Tau_]
   Float_t         Tau_chargedIsoPtSum[kMaxTau];   //[Tau_]
   Float_t         Tau_neutralIsoPtSum[kMaxTau];   //[Tau_]
   Float_t         Tau_puCorrPtSum[kMaxTau];   //[Tau_]
   Float_t         Tau_CombinedIsolationDeltaBetaCorrRaw3Hits[kMaxTau];   //[Tau_]
   Float_t         Tau_CombinedIsolationDeltaBetaCorrRaw[kMaxTau];   //[Tau_]
   Float_t         Tau_byIsolationMVA3newDMwLTraw[kMaxTau];   //[Tau_]
   Float_t         Tau_byIsolationMVA3newDMwoLTraw[kMaxTau];   //[Tau_]
   Float_t         Tau_byIsolationMVA3oldDMwLTraw[kMaxTau];   //[Tau_]
   Float_t         Tau_byIsolationMVA3oldDMwoLTraw[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseCombinedIsolationDeltaBetaCorr[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseCombinedIsolationDeltaBetaCorr3Hits[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumCombinedIsolationDeltaBetaCorr[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumCombinedIsolationDeltaBetaCorr3Hits[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightCombinedIsolationDeltaBetaCorr[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightCombinedIsolationDeltaBetaCorr3Hits[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseIsolationMVA3newDMwLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseIsolationMVA3newDMwoLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseIsolationMva3oldDMwLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseIsolationMVA3oldDMwoLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumIsolationMVA3newDMwLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumIsolationMVA3newDMwoLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumIsolationMva3oldDMwLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumIsolationMVA3oldDMwoLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightIsolationMVA3newDMwLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightIsolationMVA3newDMwoLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightIsolationMva3oldDMwLT[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightIsolationMVA3oldDMwoLT[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonLoose[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonLoose2[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonLoose3[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonLooseMVA[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonTight[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonTight2[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonTight3[kMaxTau];   //[Tau_]
   Float_t         Tau_againstMuonTightMVA[kMaxTau];   //[Tau_]
   Float_t         Tau_againstElectronLoose[kMaxTau];   //[Tau_]
   Float_t         Tau_againstElectronMedium[kMaxTau];   //[Tau_]
   Float_t         Tau_againstElectronTight[kMaxTau];   //[Tau_]
   Float_t         Tau_pfElectronMVA[kMaxTau];   //[Tau_]
   Float_t         Tau_againstElectronMVALooseMVA5[kMaxTau];   //[Tau_]
   Float_t         Tau_againstElectronMVAMediumMVA5[kMaxTau];   //[Tau_]
   Float_t         Tau_againstElectronMVATightMVA5[kMaxTau];   //[Tau_]
   Float_t         Tau_byVLooseCombinedIsolationDeltaBetaCorr[kMaxTau];   //[Tau_]
   Float_t         Tau_byLooseIsolationMVA[kMaxTau];   //[Tau_]
   Float_t         Tau_byMediumIsolationMVA[kMaxTau];   //[Tau_]
   Float_t         Tau_byTightIsolationMVA[kMaxTau];   //[Tau_]
   Double_t        Tau_jetPt[kMaxTau];   //[Tau_]
   Double_t        Tau_jetEta[kMaxTau];   //[Tau_]
   Double_t        Tau_jetPhi[kMaxTau];   //[Tau_]
   Float_t         Tau_emFraction[kMaxTau];   //[Tau_]
   Float_t         Tau_maximumHCALPFClusterEt[kMaxTau];   //[Tau_]
   Float_t         Tau_ecalStripSumEOverPLead[kMaxTau];   //[Tau_]
   Float_t         Tau_bremsRecoveryEOverPLead[kMaxTau];   //[Tau_]
   Float_t         Tau_hcalTotOverPLead[kMaxTau];   //[Tau_]
   Float_t         Tau_hcalMaxOverPLead[kMaxTau];   //[Tau_]
   Float_t         Tau_hcal3x3OverPLead[kMaxTau];   //[Tau_]
   Float_t         Tau_etaetaMoment[kMaxTau];   //[Tau_]
   Float_t         Tau_phiphiMoment[kMaxTau];   //[Tau_]
   Float_t         Tau_etaphiMoment[kMaxTau];   //[Tau_]
   Double_t        Tau_vx[kMaxTau];   //[Tau_]
   Double_t        Tau_vy[kMaxTau];   //[Tau_]
   Double_t        Tau_vz[kMaxTau];   //[Tau_]
   Double_t        Tau_zvertex[kMaxTau];   //[Tau_]
   Double_t        Tau_ltsipt[kMaxTau];   //[Tau_]
   Int_t           Tau_selbit[kMaxTau];   //[Tau_]
   Int_t           nTau;

   // List of branches
   TBranch        *b_Vertex_;   //!
   TBranch        *b_Vertex_fUniqueID;   //!
   TBranch        *b_Vertex_fBits;   //!
   TBranch        *b_Vertex_x;   //!
   TBranch        *b_Vertex_y;   //!
   TBranch        *b_Vertex_z;   //!
   TBranch        *b_Vertex_xErr;   //!
   TBranch        *b_Vertex_yErr;   //!
   TBranch        *b_Vertex_zErr;   //!
   TBranch        *b_Vertex_rho;   //!
   TBranch        *b_Vertex_chi2;   //!
   TBranch        *b_Vertex_ndf;   //!
   TBranch        *b_Vertex_ntracks;   //!
   TBranch        *b_Vertex_ntracksw05;   //!
   TBranch        *b_Vertex_isfake;   //!
   TBranch        *b_Vertex_isvalid;   //!
   TBranch        *b_Vertex_sumPt;   //!
   TBranch        *b_Vertex_selbit;   //!
   TBranch        *b_fnVertex;   //!
   TBranch        *b_GenParticle_;   //!
   TBranch        *b_GenParticle_fUniqueID;   //!
   TBranch        *b_GenParticle_fBits;   //!
   TBranch        *b_GenParticle_eta;   //!
   TBranch        *b_GenParticle_phi;   //!
   TBranch        *b_GenParticle_p;   //!
   TBranch        *b_GenParticle_px;   //!
   TBranch        *b_GenParticle_py;   //!
   TBranch        *b_GenParticle_pz;   //!
   TBranch        *b_GenParticle_pt;   //!
   TBranch        *b_GenParticle_energy;   //!
   TBranch        *b_GenParticle_pdgId;   //!
   TBranch        *b_GenParticle_vx;   //!
   TBranch        *b_GenParticle_vy;   //!
   TBranch        *b_GenParticle_vz;   //!
   TBranch        *b_GenParticle_status;   //!
   TBranch        *b_GenParticle_charge;   //!
   TBranch        *b_GenParticle_numDaught;   //!
   TBranch        *b_GenParticle_numMother;   //!
   TBranch        *b_GenParticle_motherIndex;   //!
   TBranch        *b_GenParticle_motherIndices;   //!
   TBranch        *b_GenParticle_daughtIndices;   //!
   TBranch        *b_fnGenParticle;   //!
   TBranch        *b_Muon_;   //!
   TBranch        *b_Muon_fUniqueID;   //!
   TBranch        *b_Muon_fBits;   //!
   TBranch        *b_Muon_isTrackerMuon;   //!
   TBranch        *b_Muon_isPFMuon;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptError;   //!
   TBranch        *b_Muon_p;   //!
   TBranch        *b_Muon_energy;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_trkD0;   //!
   TBranch        *b_Muon_trkD0Error;   //!
   TBranch        *b_Muon_trkDz;   //!
   TBranch        *b_Muon_trkDzError;   //!
   TBranch        *b_Muon_globalChi2;   //!
   TBranch        *b_Muon_trkIso;   //!
   TBranch        *b_Muon_ecalIso;   //!
   TBranch        *b_Muon_hcalIso;   //!
   TBranch        *b_Muon_hoIso;   //!
   TBranch        *b_Muon_relIso;   //!
   TBranch        *b_Muon_passID;   //!
   TBranch        *b_Muon_vtxDist3D;   //!
   TBranch        *b_Muon_vtxIndex;   //!
   TBranch        *b_Muon_vtxDistZ;   //!
   TBranch        *b_Muon_pixHits;   //!
   TBranch        *b_Muon_trkHits;   //!
   TBranch        *b_Muon_muoHits;   //!
   TBranch        *b_Muon_matches;   //!
   TBranch        *b_Muon_trackerLayersWithMeasurement;   //!
   TBranch        *b_Muon_pfRelIso;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_dB;   //!
   TBranch        *b_Muon_edB;   //!
   TBranch        *b_Muon_dB3d;   //!
   TBranch        *b_Muon_edB3d;   //!
   TBranch        *b_Muon_isGlobalMuonPromptTight;   //!
   TBranch        *b_Muon_isAllArbitrated;   //!
   TBranch        *b_Muon_nChambers;   //!
   TBranch        *b_Muon_nMatches;   //!
   TBranch        *b_Muon_nMatchedStations;   //!
   TBranch        *b_Muon_stationMask;   //!
   TBranch        *b_Muon_stationGapMaskDistance;   //!
   TBranch        *b_Muon_stationGapMaskPull;   //!
   TBranch        *b_Muon_muonID;   //!
   TBranch        *b_Muon_idMVA;   //!
   TBranch        *b_Muon_isoRingsMVA;   //!
   TBranch        *b_Muon_isoRingsRadMVA;   //!
   TBranch        *b_Muon_idIsoCombMVA;   //!
   TBranch        *b_Muon_pfRelIso03v1;   //!
   TBranch        *b_Muon_pfRelIso03v2;   //!
   TBranch        *b_Muon_pfRelIsoDB03v1;   //!
   TBranch        *b_Muon_pfRelIsoDB03v2;   //!
   TBranch        *b_Muon_pfRelIso04v1;   //!
   TBranch        *b_Muon_pfRelIso04v2;   //!
   TBranch        *b_Muon_pfRelIsoDB04v1;   //!
   TBranch        *b_Muon_pfRelIsoDB04v2;   //!
   TBranch        *b_Muon_selbit;   //!
   TBranch        *b_fnMuon;   //!
   TBranch        *b_Tau_;   //!
   TBranch        *b_Tau_fUniqueID;   //!
   TBranch        *b_Tau_fBits;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_energy;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_mass;   //!
   TBranch        *b_Tau_leadTrkPt;   //!
   TBranch        *b_Tau_leadTrkPtError;   //!
   TBranch        *b_Tau_leadTrkEta;   //!
   TBranch        *b_Tau_leadTrkPhi;   //!
   TBranch        *b_Tau_leadTrkCharge;   //!
   TBranch        *b_Tau_leadTrkD0;   //!
   TBranch        *b_Tau_leadTrkD0Error;   //!
   TBranch        *b_Tau_leadTrkDz;   //!
   TBranch        *b_Tau_leadTrkDzError;   //!
   TBranch        *b_Tau_vtxIndex;   //!
   TBranch        *b_Tau_vtxDxy;   //!
   TBranch        *b_Tau_vtxDz;   //!
   TBranch        *b_Tau_leadChargedParticlePt;   //!
   TBranch        *b_Tau_leadNeutralParticlePt;   //!
   TBranch        *b_Tau_leadParticlePt;   //!
   TBranch        *b_Tau_numChargedHadronsSignalCone;   //!
   TBranch        *b_Tau_numNeutralHadronsSignalCone;   //!
   TBranch        *b_Tau_numPhotonsSignalCone;   //!
   TBranch        *b_Tau_numParticlesSignalCone;   //!
   TBranch        *b_Tau_numChargedHadronsIsoCone;   //!
   TBranch        *b_Tau_numNeutralHadronsIsoCone;   //!
   TBranch        *b_Tau_numPhotonsIsoCone;   //!
   TBranch        *b_Tau_numParticlesIsoCone;   //!
   TBranch        *b_Tau_ptSumPFChargedHadronsIsoCone;   //!
   TBranch        *b_Tau_ptSumPFNeutralHadronsIsoCone;   //!
   TBranch        *b_Tau_ptSumPhotonsIsoCone;   //!
   TBranch        *b_Tau_sigChHadCandPt;   //!
   TBranch        *b_Tau_sigChHadCandEta;   //!
   TBranch        *b_Tau_sigChHadCandPhi;   //!
   TBranch        *b_Tau_sigNeHadCandPt;   //!
   TBranch        *b_Tau_sigNeHadCandEta;   //!
   TBranch        *b_Tau_sigNeHadCandPhi;   //!
   TBranch        *b_Tau_sigGammaCandPt;   //!
   TBranch        *b_Tau_sigGammaCandEta;   //!
   TBranch        *b_Tau_sigGammaCandPhi;   //!
   TBranch        *b_Tau_isoChHadCandPt;   //!
   TBranch        *b_Tau_isoChHadCandEta;   //!
   TBranch        *b_Tau_isoChHadCandPhi;   //!
   TBranch        *b_Tau_isoNeHadCandPt;   //!
   TBranch        *b_Tau_isoNeHadCandEta;   //!
   TBranch        *b_Tau_isoNeHadCandPhi;   //!
   TBranch        *b_Tau_isoGammaCandPt;   //!
   TBranch        *b_Tau_isoGammaCandEta;   //!
   TBranch        *b_Tau_isoGammaCandPhi;   //!
   TBranch        *b_Tau_decayModeFinding;   //!
   TBranch        *b_Tau_decayModeFindingNewDMs;   //!
   TBranch        *b_Tau_decayModeFindingOldDMs;   //!
   TBranch        *b_Tau_chargedIsoPtSum;   //!
   TBranch        *b_Tau_neutralIsoPtSum;   //!
   TBranch        *b_Tau_puCorrPtSum;   //!
   TBranch        *b_Tau_CombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_Tau_CombinedIsolationDeltaBetaCorrRaw;   //!
   TBranch        *b_Tau_byIsolationMVA3newDMwLTraw;   //!
   TBranch        *b_Tau_byIsolationMVA3newDMwoLTraw;   //!
   TBranch        *b_Tau_byIsolationMVA3oldDMwLTraw;   //!
   TBranch        *b_Tau_byIsolationMVA3oldDMwoLTraw;   //!
   TBranch        *b_Tau_byLooseCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_Tau_byLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_Tau_byMediumCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_Tau_byMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_Tau_byTightCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_Tau_byTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_Tau_byLooseIsolationMVA3newDMwLT;   //!
   TBranch        *b_Tau_byLooseIsolationMVA3newDMwoLT;   //!
   TBranch        *b_Tau_byLooseIsolationMva3oldDMwLT;   //!
   TBranch        *b_Tau_byLooseIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_Tau_byMediumIsolationMVA3newDMwLT;   //!
   TBranch        *b_Tau_byMediumIsolationMVA3newDMwoLT;   //!
   TBranch        *b_Tau_byMediumIsolationMva3oldDMwLT;   //!
   TBranch        *b_Tau_byMediumIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_Tau_byTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_Tau_byTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_Tau_byTightIsolationMva3oldDMwLT;   //!
   TBranch        *b_Tau_byTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_Tau_againstMuonLoose;   //!
   TBranch        *b_Tau_againstMuonLoose2;   //!
   TBranch        *b_Tau_againstMuonLoose3;   //!
   TBranch        *b_Tau_againstMuonLooseMVA;   //!
   TBranch        *b_Tau_againstMuonTight;   //!
   TBranch        *b_Tau_againstMuonTight2;   //!
   TBranch        *b_Tau_againstMuonTight3;   //!
   TBranch        *b_Tau_againstMuonTightMVA;   //!
   TBranch        *b_Tau_againstElectronLoose;   //!
   TBranch        *b_Tau_againstElectronMedium;   //!
   TBranch        *b_Tau_againstElectronTight;   //!
   TBranch        *b_Tau_pfElectronMVA;   //!
   TBranch        *b_Tau_againstElectronMVALooseMVA5;   //!
   TBranch        *b_Tau_againstElectronMVAMediumMVA5;   //!
   TBranch        *b_Tau_againstElectronMVATightMVA5;   //!
   TBranch        *b_Tau_byVLooseCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_Tau_byLooseIsolationMVA;   //!
   TBranch        *b_Tau_byMediumIsolationMVA;   //!
   TBranch        *b_Tau_byTightIsolationMVA;   //!
   TBranch        *b_Tau_jetPt;   //!
   TBranch        *b_Tau_jetEta;   //!
   TBranch        *b_Tau_jetPhi;   //!
   TBranch        *b_Tau_emFraction;   //!
   TBranch        *b_Tau_maximumHCALPFClusterEt;   //!
   TBranch        *b_Tau_ecalStripSumEOverPLead;   //!
   TBranch        *b_Tau_bremsRecoveryEOverPLead;   //!
   TBranch        *b_Tau_hcalTotOverPLead;   //!
   TBranch        *b_Tau_hcalMaxOverPLead;   //!
   TBranch        *b_Tau_hcal3x3OverPLead;   //!
   TBranch        *b_Tau_etaetaMoment;   //!
   TBranch        *b_Tau_phiphiMoment;   //!
   TBranch        *b_Tau_etaphiMoment;   //!
   TBranch        *b_Tau_vx;   //!
   TBranch        *b_Tau_vy;   //!
   TBranch        *b_Tau_vz;   //!
   TBranch        *b_Tau_zvertex;   //!
   TBranch        *b_Tau_ltsipt;   //!
   TBranch        *b_Tau_selbit;   //!
   TBranch        *b_fnTau;   //!

   GemAnalyze(TTree *tree=0);
   virtual ~GemAnalyze();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef GemAnalyze_cxx
GemAnalyze::GemAnalyze(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test_53x.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test_53x.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("test_53x.root:/treeCreator");
      dir->GetObject("vhtree",tree);

   }
   Init(tree);
}

GemAnalyze::~GemAnalyze()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t GemAnalyze::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t GemAnalyze::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void GemAnalyze::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Vertex", &Vertex_, &b_Vertex_);
   fChain->SetBranchAddress("Vertex.fUniqueID", Vertex_fUniqueID, &b_Vertex_fUniqueID);
   fChain->SetBranchAddress("Vertex.fBits", Vertex_fBits, &b_Vertex_fBits);
   fChain->SetBranchAddress("Vertex.x", Vertex_x, &b_Vertex_x);
   fChain->SetBranchAddress("Vertex.y", Vertex_y, &b_Vertex_y);
   fChain->SetBranchAddress("Vertex.z", Vertex_z, &b_Vertex_z);
   fChain->SetBranchAddress("Vertex.xErr", Vertex_xErr, &b_Vertex_xErr);
   fChain->SetBranchAddress("Vertex.yErr", Vertex_yErr, &b_Vertex_yErr);
   fChain->SetBranchAddress("Vertex.zErr", Vertex_zErr, &b_Vertex_zErr);
   fChain->SetBranchAddress("Vertex.rho", Vertex_rho, &b_Vertex_rho);
   fChain->SetBranchAddress("Vertex.chi2", Vertex_chi2, &b_Vertex_chi2);
   fChain->SetBranchAddress("Vertex.ndf", Vertex_ndf, &b_Vertex_ndf);
   fChain->SetBranchAddress("Vertex.ntracks", Vertex_ntracks, &b_Vertex_ntracks);
   fChain->SetBranchAddress("Vertex.ntracksw05", Vertex_ntracksw05, &b_Vertex_ntracksw05);
   fChain->SetBranchAddress("Vertex.isfake", Vertex_isfake, &b_Vertex_isfake);
   fChain->SetBranchAddress("Vertex.isvalid", Vertex_isvalid, &b_Vertex_isvalid);
   fChain->SetBranchAddress("Vertex.sumPt", Vertex_sumPt, &b_Vertex_sumPt);
   fChain->SetBranchAddress("Vertex.selbit", Vertex_selbit, &b_Vertex_selbit);
   fChain->SetBranchAddress("nVertex", &nVertex, &b_fnVertex);
   fChain->SetBranchAddress("GenParticle", &GenParticle_, &b_GenParticle_);
   fChain->SetBranchAddress("GenParticle.fUniqueID", GenParticle_fUniqueID, &b_GenParticle_fUniqueID);
   fChain->SetBranchAddress("GenParticle.fBits", GenParticle_fBits, &b_GenParticle_fBits);
   fChain->SetBranchAddress("GenParticle.eta", GenParticle_eta, &b_GenParticle_eta);
   fChain->SetBranchAddress("GenParticle.phi", GenParticle_phi, &b_GenParticle_phi);
   fChain->SetBranchAddress("GenParticle.p", GenParticle_p, &b_GenParticle_p);
   fChain->SetBranchAddress("GenParticle.px", GenParticle_px, &b_GenParticle_px);
   fChain->SetBranchAddress("GenParticle.py", GenParticle_py, &b_GenParticle_py);
   fChain->SetBranchAddress("GenParticle.pz", GenParticle_pz, &b_GenParticle_pz);
   fChain->SetBranchAddress("GenParticle.pt", GenParticle_pt, &b_GenParticle_pt);
   fChain->SetBranchAddress("GenParticle.energy", GenParticle_energy, &b_GenParticle_energy);
   fChain->SetBranchAddress("GenParticle.pdgId", GenParticle_pdgId, &b_GenParticle_pdgId);
   fChain->SetBranchAddress("GenParticle.vx", GenParticle_vx, &b_GenParticle_vx);
   fChain->SetBranchAddress("GenParticle.vy", GenParticle_vy, &b_GenParticle_vy);
   fChain->SetBranchAddress("GenParticle.vz", GenParticle_vz, &b_GenParticle_vz);
   fChain->SetBranchAddress("GenParticle.status", GenParticle_status, &b_GenParticle_status);
   fChain->SetBranchAddress("GenParticle.charge", GenParticle_charge, &b_GenParticle_charge);
   fChain->SetBranchAddress("GenParticle.numDaught", GenParticle_numDaught, &b_GenParticle_numDaught);
   fChain->SetBranchAddress("GenParticle.numMother", GenParticle_numMother, &b_GenParticle_numMother);
   fChain->SetBranchAddress("GenParticle.motherIndex", GenParticle_motherIndex, &b_GenParticle_motherIndex);
   fChain->SetBranchAddress("GenParticle.motherIndices", GenParticle_motherIndices, &b_GenParticle_motherIndices);
   fChain->SetBranchAddress("GenParticle.daughtIndices", GenParticle_daughtIndices, &b_GenParticle_daughtIndices);
   fChain->SetBranchAddress("nGenParticle", &nGenParticle, &b_fnGenParticle);
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.isTrackerMuon", Muon_isTrackerMuon, &b_Muon_isTrackerMuon);
   fChain->SetBranchAddress("Muon.isPFMuon", Muon_isPFMuon, &b_Muon_isPFMuon);
   fChain->SetBranchAddress("Muon.eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon.phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon.pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon.ptError", Muon_ptError, &b_Muon_ptError);
   fChain->SetBranchAddress("Muon.p", Muon_p, &b_Muon_p);
   fChain->SetBranchAddress("Muon.energy", Muon_energy, &b_Muon_energy);
   fChain->SetBranchAddress("Muon.charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon.trkD0", Muon_trkD0, &b_Muon_trkD0);
   fChain->SetBranchAddress("Muon.trkD0Error", Muon_trkD0Error, &b_Muon_trkD0Error);
   fChain->SetBranchAddress("Muon.trkDz", Muon_trkDz, &b_Muon_trkDz);
   fChain->SetBranchAddress("Muon.trkDzError", Muon_trkDzError, &b_Muon_trkDzError);
   fChain->SetBranchAddress("Muon.globalChi2", Muon_globalChi2, &b_Muon_globalChi2);
   fChain->SetBranchAddress("Muon.trkIso", Muon_trkIso, &b_Muon_trkIso);
   fChain->SetBranchAddress("Muon.ecalIso", Muon_ecalIso, &b_Muon_ecalIso);
   fChain->SetBranchAddress("Muon.hcalIso", Muon_hcalIso, &b_Muon_hcalIso);
   fChain->SetBranchAddress("Muon.hoIso", Muon_hoIso, &b_Muon_hoIso);
   fChain->SetBranchAddress("Muon.relIso", Muon_relIso, &b_Muon_relIso);
   fChain->SetBranchAddress("Muon.passID", Muon_passID, &b_Muon_passID);
   fChain->SetBranchAddress("Muon.vtxDist3D", Muon_vtxDist3D, &b_Muon_vtxDist3D);
   fChain->SetBranchAddress("Muon.vtxIndex", Muon_vtxIndex, &b_Muon_vtxIndex);
   fChain->SetBranchAddress("Muon.vtxDistZ", Muon_vtxDistZ, &b_Muon_vtxDistZ);
   fChain->SetBranchAddress("Muon.pixHits", Muon_pixHits, &b_Muon_pixHits);
   fChain->SetBranchAddress("Muon.trkHits", Muon_trkHits, &b_Muon_trkHits);
   fChain->SetBranchAddress("Muon.muoHits", Muon_muoHits, &b_Muon_muoHits);
   fChain->SetBranchAddress("Muon.matches", Muon_matches, &b_Muon_matches);
   fChain->SetBranchAddress("Muon.trackerLayersWithMeasurement", Muon_trackerLayersWithMeasurement, &b_Muon_trackerLayersWithMeasurement);
   fChain->SetBranchAddress("Muon.pfRelIso", Muon_pfRelIso, &b_Muon_pfRelIso);
   fChain->SetBranchAddress("Muon.vx", Muon_vx, &b_Muon_vx);
   fChain->SetBranchAddress("Muon.vy", Muon_vy, &b_Muon_vy);
   fChain->SetBranchAddress("Muon.vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("Muon.dB", Muon_dB, &b_Muon_dB);
   fChain->SetBranchAddress("Muon.edB", Muon_edB, &b_Muon_edB);
   fChain->SetBranchAddress("Muon.dB3d", Muon_dB3d, &b_Muon_dB3d);
   fChain->SetBranchAddress("Muon.edB3d", Muon_edB3d, &b_Muon_edB3d);
   fChain->SetBranchAddress("Muon.isGlobalMuonPromptTight", Muon_isGlobalMuonPromptTight, &b_Muon_isGlobalMuonPromptTight);
   fChain->SetBranchAddress("Muon.isAllArbitrated", Muon_isAllArbitrated, &b_Muon_isAllArbitrated);
   fChain->SetBranchAddress("Muon.nChambers", Muon_nChambers, &b_Muon_nChambers);
   fChain->SetBranchAddress("Muon.nMatches", Muon_nMatches, &b_Muon_nMatches);
   fChain->SetBranchAddress("Muon.nMatchedStations", Muon_nMatchedStations, &b_Muon_nMatchedStations);
   fChain->SetBranchAddress("Muon.stationMask", Muon_stationMask, &b_Muon_stationMask);
   fChain->SetBranchAddress("Muon.stationGapMaskDistance", Muon_stationGapMaskDistance, &b_Muon_stationGapMaskDistance);
   fChain->SetBranchAddress("Muon.stationGapMaskPull", Muon_stationGapMaskPull, &b_Muon_stationGapMaskPull);
   fChain->SetBranchAddress("Muon.muonID", Muon_muonID, &b_Muon_muonID);
   fChain->SetBranchAddress("Muon.idMVA", Muon_idMVA, &b_Muon_idMVA);
   fChain->SetBranchAddress("Muon.isoRingsMVA", Muon_isoRingsMVA, &b_Muon_isoRingsMVA);
   fChain->SetBranchAddress("Muon.isoRingsRadMVA", Muon_isoRingsRadMVA, &b_Muon_isoRingsRadMVA);
   fChain->SetBranchAddress("Muon.idIsoCombMVA", Muon_idIsoCombMVA, &b_Muon_idIsoCombMVA);
   fChain->SetBranchAddress("Muon.pfRelIso03v1", Muon_pfRelIso03v1, &b_Muon_pfRelIso03v1);
   fChain->SetBranchAddress("Muon.pfRelIso03v2", Muon_pfRelIso03v2, &b_Muon_pfRelIso03v2);
   fChain->SetBranchAddress("Muon.pfRelIsoDB03v1", Muon_pfRelIsoDB03v1, &b_Muon_pfRelIsoDB03v1);
   fChain->SetBranchAddress("Muon.pfRelIsoDB03v2", Muon_pfRelIsoDB03v2, &b_Muon_pfRelIsoDB03v2);
   fChain->SetBranchAddress("Muon.pfRelIso04v1", Muon_pfRelIso04v1, &b_Muon_pfRelIso04v1);
   fChain->SetBranchAddress("Muon.pfRelIso04v2", Muon_pfRelIso04v2, &b_Muon_pfRelIso04v2);
   fChain->SetBranchAddress("Muon.pfRelIsoDB04v1", Muon_pfRelIsoDB04v1, &b_Muon_pfRelIsoDB04v1);
   fChain->SetBranchAddress("Muon.pfRelIsoDB04v2", Muon_pfRelIsoDB04v2, &b_Muon_pfRelIsoDB04v2);
   fChain->SetBranchAddress("Muon.selbit", Muon_selbit, &b_Muon_selbit);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_fnMuon);
   fChain->SetBranchAddress("Tau", &Tau_, &b_Tau_);
   fChain->SetBranchAddress("Tau.fUniqueID", Tau_fUniqueID, &b_Tau_fUniqueID);
   fChain->SetBranchAddress("Tau.fBits", Tau_fBits, &b_Tau_fBits);
   fChain->SetBranchAddress("Tau.eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau.phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau.pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau.energy", Tau_energy, &b_Tau_energy);
   fChain->SetBranchAddress("Tau.charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("Tau.mass", Tau_mass, &b_Tau_mass);
   fChain->SetBranchAddress("Tau.leadTrkPt", Tau_leadTrkPt, &b_Tau_leadTrkPt);
   fChain->SetBranchAddress("Tau.leadTrkPtError", Tau_leadTrkPtError, &b_Tau_leadTrkPtError);
   fChain->SetBranchAddress("Tau.leadTrkEta", Tau_leadTrkEta, &b_Tau_leadTrkEta);
   fChain->SetBranchAddress("Tau.leadTrkPhi", Tau_leadTrkPhi, &b_Tau_leadTrkPhi);
   fChain->SetBranchAddress("Tau.leadTrkCharge", Tau_leadTrkCharge, &b_Tau_leadTrkCharge);
   fChain->SetBranchAddress("Tau.leadTrkD0", Tau_leadTrkD0, &b_Tau_leadTrkD0);
   fChain->SetBranchAddress("Tau.leadTrkD0Error", Tau_leadTrkD0Error, &b_Tau_leadTrkD0Error);
   fChain->SetBranchAddress("Tau.leadTrkDz", Tau_leadTrkDz, &b_Tau_leadTrkDz);
   fChain->SetBranchAddress("Tau.leadTrkDzError", Tau_leadTrkDzError, &b_Tau_leadTrkDzError);
   fChain->SetBranchAddress("Tau.vtxIndex", Tau_vtxIndex, &b_Tau_vtxIndex);
   fChain->SetBranchAddress("Tau.vtxDxy", Tau_vtxDxy, &b_Tau_vtxDxy);
   fChain->SetBranchAddress("Tau.vtxDz", Tau_vtxDz, &b_Tau_vtxDz);
   fChain->SetBranchAddress("Tau.leadChargedParticlePt", Tau_leadChargedParticlePt, &b_Tau_leadChargedParticlePt);
   fChain->SetBranchAddress("Tau.leadNeutralParticlePt", Tau_leadNeutralParticlePt, &b_Tau_leadNeutralParticlePt);
   fChain->SetBranchAddress("Tau.leadParticlePt", Tau_leadParticlePt, &b_Tau_leadParticlePt);
   fChain->SetBranchAddress("Tau.numChargedHadronsSignalCone", Tau_numChargedHadronsSignalCone, &b_Tau_numChargedHadronsSignalCone);
   fChain->SetBranchAddress("Tau.numNeutralHadronsSignalCone", Tau_numNeutralHadronsSignalCone, &b_Tau_numNeutralHadronsSignalCone);
   fChain->SetBranchAddress("Tau.numPhotonsSignalCone", Tau_numPhotonsSignalCone, &b_Tau_numPhotonsSignalCone);
   fChain->SetBranchAddress("Tau.numParticlesSignalCone", Tau_numParticlesSignalCone, &b_Tau_numParticlesSignalCone);
   fChain->SetBranchAddress("Tau.numChargedHadronsIsoCone", Tau_numChargedHadronsIsoCone, &b_Tau_numChargedHadronsIsoCone);
   fChain->SetBranchAddress("Tau.numNeutralHadronsIsoCone", Tau_numNeutralHadronsIsoCone, &b_Tau_numNeutralHadronsIsoCone);
   fChain->SetBranchAddress("Tau.numPhotonsIsoCone", Tau_numPhotonsIsoCone, &b_Tau_numPhotonsIsoCone);
   fChain->SetBranchAddress("Tau.numParticlesIsoCone", Tau_numParticlesIsoCone, &b_Tau_numParticlesIsoCone);
   fChain->SetBranchAddress("Tau.ptSumPFChargedHadronsIsoCone", Tau_ptSumPFChargedHadronsIsoCone, &b_Tau_ptSumPFChargedHadronsIsoCone);
   fChain->SetBranchAddress("Tau.ptSumPFNeutralHadronsIsoCone", Tau_ptSumPFNeutralHadronsIsoCone, &b_Tau_ptSumPFNeutralHadronsIsoCone);
   fChain->SetBranchAddress("Tau.ptSumPhotonsIsoCone", Tau_ptSumPhotonsIsoCone, &b_Tau_ptSumPhotonsIsoCone);
   fChain->SetBranchAddress("Tau.sigChHadCandPt[40]", Tau_sigChHadCandPt, &b_Tau_sigChHadCandPt);
   fChain->SetBranchAddress("Tau.sigChHadCandEta[40]", Tau_sigChHadCandEta, &b_Tau_sigChHadCandEta);
   fChain->SetBranchAddress("Tau.sigChHadCandPhi[40]", Tau_sigChHadCandPhi, &b_Tau_sigChHadCandPhi);
   fChain->SetBranchAddress("Tau.sigNeHadCandPt[20]", Tau_sigNeHadCandPt, &b_Tau_sigNeHadCandPt);
   fChain->SetBranchAddress("Tau.sigNeHadCandEta[20]", Tau_sigNeHadCandEta, &b_Tau_sigNeHadCandEta);
   fChain->SetBranchAddress("Tau.sigNeHadCandPhi[20]", Tau_sigNeHadCandPhi, &b_Tau_sigNeHadCandPhi);
   fChain->SetBranchAddress("Tau.sigGammaCandPt[20]", Tau_sigGammaCandPt, &b_Tau_sigGammaCandPt);
   fChain->SetBranchAddress("Tau.sigGammaCandEta[20]", Tau_sigGammaCandEta, &b_Tau_sigGammaCandEta);
   fChain->SetBranchAddress("Tau.sigGammaCandPhi[20]", Tau_sigGammaCandPhi, &b_Tau_sigGammaCandPhi);
   fChain->SetBranchAddress("Tau.isoChHadCandPt[40]", Tau_isoChHadCandPt, &b_Tau_isoChHadCandPt);
   fChain->SetBranchAddress("Tau.isoChHadCandEta[40]", Tau_isoChHadCandEta, &b_Tau_isoChHadCandEta);
   fChain->SetBranchAddress("Tau.isoChHadCandPhi[40]", Tau_isoChHadCandPhi, &b_Tau_isoChHadCandPhi);
   fChain->SetBranchAddress("Tau.isoNeHadCandPt[20]", Tau_isoNeHadCandPt, &b_Tau_isoNeHadCandPt);
   fChain->SetBranchAddress("Tau.isoNeHadCandEta[20]", Tau_isoNeHadCandEta, &b_Tau_isoNeHadCandEta);
   fChain->SetBranchAddress("Tau.isoNeHadCandPhi[20]", Tau_isoNeHadCandPhi, &b_Tau_isoNeHadCandPhi);
   fChain->SetBranchAddress("Tau.isoGammaCandPt[20]", Tau_isoGammaCandPt, &b_Tau_isoGammaCandPt);
   fChain->SetBranchAddress("Tau.isoGammaCandEta[20]", Tau_isoGammaCandEta, &b_Tau_isoGammaCandEta);
   fChain->SetBranchAddress("Tau.isoGammaCandPhi[20]", Tau_isoGammaCandPhi, &b_Tau_isoGammaCandPhi);
   fChain->SetBranchAddress("Tau.decayModeFinding", Tau_decayModeFinding, &b_Tau_decayModeFinding);
   fChain->SetBranchAddress("Tau.decayModeFindingNewDMs", Tau_decayModeFindingNewDMs, &b_Tau_decayModeFindingNewDMs);
   fChain->SetBranchAddress("Tau.decayModeFindingOldDMs", Tau_decayModeFindingOldDMs, &b_Tau_decayModeFindingOldDMs);
   fChain->SetBranchAddress("Tau.chargedIsoPtSum", Tau_chargedIsoPtSum, &b_Tau_chargedIsoPtSum);
   fChain->SetBranchAddress("Tau.neutralIsoPtSum", Tau_neutralIsoPtSum, &b_Tau_neutralIsoPtSum);
   fChain->SetBranchAddress("Tau.puCorrPtSum", Tau_puCorrPtSum, &b_Tau_puCorrPtSum);
   fChain->SetBranchAddress("Tau.CombinedIsolationDeltaBetaCorrRaw3Hits", Tau_CombinedIsolationDeltaBetaCorrRaw3Hits, &b_Tau_CombinedIsolationDeltaBetaCorrRaw3Hits);
   fChain->SetBranchAddress("Tau.CombinedIsolationDeltaBetaCorrRaw", Tau_CombinedIsolationDeltaBetaCorrRaw, &b_Tau_CombinedIsolationDeltaBetaCorrRaw);
   fChain->SetBranchAddress("Tau.byIsolationMVA3newDMwLTraw", Tau_byIsolationMVA3newDMwLTraw, &b_Tau_byIsolationMVA3newDMwLTraw);
   fChain->SetBranchAddress("Tau.byIsolationMVA3newDMwoLTraw", Tau_byIsolationMVA3newDMwoLTraw, &b_Tau_byIsolationMVA3newDMwoLTraw);
   fChain->SetBranchAddress("Tau.byIsolationMVA3oldDMwLTraw", Tau_byIsolationMVA3oldDMwLTraw, &b_Tau_byIsolationMVA3oldDMwLTraw);
   fChain->SetBranchAddress("Tau.byIsolationMVA3oldDMwoLTraw", Tau_byIsolationMVA3oldDMwoLTraw, &b_Tau_byIsolationMVA3oldDMwoLTraw);
   fChain->SetBranchAddress("Tau.byLooseCombinedIsolationDeltaBetaCorr", Tau_byLooseCombinedIsolationDeltaBetaCorr, &b_Tau_byLooseCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("Tau.byLooseCombinedIsolationDeltaBetaCorr3Hits", Tau_byLooseCombinedIsolationDeltaBetaCorr3Hits, &b_Tau_byLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("Tau.byMediumCombinedIsolationDeltaBetaCorr", Tau_byMediumCombinedIsolationDeltaBetaCorr, &b_Tau_byMediumCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("Tau.byMediumCombinedIsolationDeltaBetaCorr3Hits", Tau_byMediumCombinedIsolationDeltaBetaCorr3Hits, &b_Tau_byMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("Tau.byTightCombinedIsolationDeltaBetaCorr", Tau_byTightCombinedIsolationDeltaBetaCorr, &b_Tau_byTightCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("Tau.byTightCombinedIsolationDeltaBetaCorr3Hits", Tau_byTightCombinedIsolationDeltaBetaCorr3Hits, &b_Tau_byTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("Tau.byLooseIsolationMVA3newDMwLT", Tau_byLooseIsolationMVA3newDMwLT, &b_Tau_byLooseIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("Tau.byLooseIsolationMVA3newDMwoLT", Tau_byLooseIsolationMVA3newDMwoLT, &b_Tau_byLooseIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("Tau.byLooseIsolationMva3oldDMwLT", Tau_byLooseIsolationMva3oldDMwLT, &b_Tau_byLooseIsolationMva3oldDMwLT);
   fChain->SetBranchAddress("Tau.byLooseIsolationMVA3oldDMwoLT", Tau_byLooseIsolationMVA3oldDMwoLT, &b_Tau_byLooseIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("Tau.byMediumIsolationMVA3newDMwLT", Tau_byMediumIsolationMVA3newDMwLT, &b_Tau_byMediumIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("Tau.byMediumIsolationMVA3newDMwoLT", Tau_byMediumIsolationMVA3newDMwoLT, &b_Tau_byMediumIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("Tau.byMediumIsolationMva3oldDMwLT", Tau_byMediumIsolationMva3oldDMwLT, &b_Tau_byMediumIsolationMva3oldDMwLT);
   fChain->SetBranchAddress("Tau.byMediumIsolationMVA3oldDMwoLT", Tau_byMediumIsolationMVA3oldDMwoLT, &b_Tau_byMediumIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("Tau.byTightIsolationMVA3newDMwLT", Tau_byTightIsolationMVA3newDMwLT, &b_Tau_byTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("Tau.byTightIsolationMVA3newDMwoLT", Tau_byTightIsolationMVA3newDMwoLT, &b_Tau_byTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("Tau.byTightIsolationMva3oldDMwLT", Tau_byTightIsolationMva3oldDMwLT, &b_Tau_byTightIsolationMva3oldDMwLT);
   fChain->SetBranchAddress("Tau.byTightIsolationMVA3oldDMwoLT", Tau_byTightIsolationMVA3oldDMwoLT, &b_Tau_byTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("Tau.againstMuonLoose", Tau_againstMuonLoose, &b_Tau_againstMuonLoose);
   fChain->SetBranchAddress("Tau.againstMuonLoose2", Tau_againstMuonLoose2, &b_Tau_againstMuonLoose2);
   fChain->SetBranchAddress("Tau.againstMuonLoose3", Tau_againstMuonLoose3, &b_Tau_againstMuonLoose3);
   fChain->SetBranchAddress("Tau.againstMuonLooseMVA", Tau_againstMuonLooseMVA, &b_Tau_againstMuonLooseMVA);
   fChain->SetBranchAddress("Tau.againstMuonTight", Tau_againstMuonTight, &b_Tau_againstMuonTight);
   fChain->SetBranchAddress("Tau.againstMuonTight2", Tau_againstMuonTight2, &b_Tau_againstMuonTight2);
   fChain->SetBranchAddress("Tau.againstMuonTight3", Tau_againstMuonTight3, &b_Tau_againstMuonTight3);
   fChain->SetBranchAddress("Tau.againstMuonTightMVA", Tau_againstMuonTightMVA, &b_Tau_againstMuonTightMVA);
   fChain->SetBranchAddress("Tau.againstElectronLoose", Tau_againstElectronLoose, &b_Tau_againstElectronLoose);
   fChain->SetBranchAddress("Tau.againstElectronMedium", Tau_againstElectronMedium, &b_Tau_againstElectronMedium);
   fChain->SetBranchAddress("Tau.againstElectronTight", Tau_againstElectronTight, &b_Tau_againstElectronTight);
   fChain->SetBranchAddress("Tau.pfElectronMVA", Tau_pfElectronMVA, &b_Tau_pfElectronMVA);
   fChain->SetBranchAddress("Tau.againstElectronMVALooseMVA5", Tau_againstElectronMVALooseMVA5, &b_Tau_againstElectronMVALooseMVA5);
   fChain->SetBranchAddress("Tau.againstElectronMVAMediumMVA5", Tau_againstElectronMVAMediumMVA5, &b_Tau_againstElectronMVAMediumMVA5);
   fChain->SetBranchAddress("Tau.againstElectronMVATightMVA5", Tau_againstElectronMVATightMVA5, &b_Tau_againstElectronMVATightMVA5);
   fChain->SetBranchAddress("Tau.byVLooseCombinedIsolationDeltaBetaCorr", Tau_byVLooseCombinedIsolationDeltaBetaCorr, &b_Tau_byVLooseCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("Tau.byLooseIsolationMVA", Tau_byLooseIsolationMVA, &b_Tau_byLooseIsolationMVA);
   fChain->SetBranchAddress("Tau.byMediumIsolationMVA", Tau_byMediumIsolationMVA, &b_Tau_byMediumIsolationMVA);
   fChain->SetBranchAddress("Tau.byTightIsolationMVA", Tau_byTightIsolationMVA, &b_Tau_byTightIsolationMVA);
   fChain->SetBranchAddress("Tau.jetPt", Tau_jetPt, &b_Tau_jetPt);
   fChain->SetBranchAddress("Tau.jetEta", Tau_jetEta, &b_Tau_jetEta);
   fChain->SetBranchAddress("Tau.jetPhi", Tau_jetPhi, &b_Tau_jetPhi);
   fChain->SetBranchAddress("Tau.emFraction", Tau_emFraction, &b_Tau_emFraction);
   fChain->SetBranchAddress("Tau.maximumHCALPFClusterEt", Tau_maximumHCALPFClusterEt, &b_Tau_maximumHCALPFClusterEt);
   fChain->SetBranchAddress("Tau.ecalStripSumEOverPLead", Tau_ecalStripSumEOverPLead, &b_Tau_ecalStripSumEOverPLead);
   fChain->SetBranchAddress("Tau.bremsRecoveryEOverPLead", Tau_bremsRecoveryEOverPLead, &b_Tau_bremsRecoveryEOverPLead);
   fChain->SetBranchAddress("Tau.hcalTotOverPLead", Tau_hcalTotOverPLead, &b_Tau_hcalTotOverPLead);
   fChain->SetBranchAddress("Tau.hcalMaxOverPLead", Tau_hcalMaxOverPLead, &b_Tau_hcalMaxOverPLead);
   fChain->SetBranchAddress("Tau.hcal3x3OverPLead", Tau_hcal3x3OverPLead, &b_Tau_hcal3x3OverPLead);
   fChain->SetBranchAddress("Tau.etaetaMoment", Tau_etaetaMoment, &b_Tau_etaetaMoment);
   fChain->SetBranchAddress("Tau.phiphiMoment", Tau_phiphiMoment, &b_Tau_phiphiMoment);
   fChain->SetBranchAddress("Tau.etaphiMoment", Tau_etaphiMoment, &b_Tau_etaphiMoment);
   fChain->SetBranchAddress("Tau.vx", Tau_vx, &b_Tau_vx);
   fChain->SetBranchAddress("Tau.vy", Tau_vy, &b_Tau_vy);
   fChain->SetBranchAddress("Tau.vz", Tau_vz, &b_Tau_vz);
   fChain->SetBranchAddress("Tau.zvertex", Tau_zvertex, &b_Tau_zvertex);
   fChain->SetBranchAddress("Tau.ltsipt", Tau_ltsipt, &b_Tau_ltsipt);
   fChain->SetBranchAddress("Tau.selbit", Tau_selbit, &b_Tau_selbit);
   fChain->SetBranchAddress("nTau", &nTau, &b_fnTau);
   Notify();
}

Bool_t GemAnalyze::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void GemAnalyze::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t GemAnalyze::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef GemAnalyze_cxx
