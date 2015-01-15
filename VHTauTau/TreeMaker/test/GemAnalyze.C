#define GemAnalyze_cxx
#include "GemAnalyze.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void GemAnalyze::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L GemAnalyze.C
//      Root > GemAnalyze t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   double delRMin=1000.;
   double delR=0.;
   //double GenPtMatch=0.;
   double delphi=0.;
   double deleta=0.;
   double RecoMuonPtMatch=0.;
   double MuonInvariantMass=0.;
   TH1F *h1PtReco = new TH1F("h1PtReco","Reco Muon Pt",100,0,200);
   TH1F *h1PtGen = new TH1F("h1PtGen","Gen Muon Pt",100,0,200);
   TH1F *hMCMatch = new TH1F("hMCMatch","Muon Pt resolution",100,-3,3);
   TH1F *hInvMuon = new TH1F("hInvMuon","Invariant Mass plot",100,0,3);

   Long64_t nentries = fChain->GetEntriesFast();
   cout<<"Number of Entries is: "<<nentries<<endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // cout<<nMuon<<endl;
      /* for (int i=0 ; i<nMuon; i++){
	h1PtReco->Fill(Muon_pt[i]);
      }
      //cout<<GenParticle_pdgId<<endl;
      
	
      for (int i=0; i<nGenParticle; i++){
	if (GenParticle_pdgId[i] == 13){
	  h1PtGen->Fill(GenParticle_pt[i]);
	}
	}*/
      cout<<nGenParticle<<endl;
      //MC Truth Matching
       for (int i=0;i<nGenParticle; i++){
	if (GenParticle_pdgId[i] == 13 && ((fabs(GenParticle_eta[i]) > 1.6) && (fabs(GenParticle_eta[i]) < 2.2))){

	  delRMin=1000;
	  delR=0.;
	  RecoMuonPtMatch=0.;
	  for (int j=0; j<nMuon; j++){
	    if ((fabs(Muon_eta[j]) > 1.6) && (fabs(Muon_eta[j]) < 2.2)){
	      delphi=Muon_phi[j]-GenParticle_phi[i];
	      deleta=Muon_eta[j]-GenParticle_eta[i];
	      delR=sqrt((delphi*delphi)+(deleta*deleta));
	      if (delR<=delRMin){
		delRMin=delR;
		RecoMuonPtMatch=Muon_pt[j];
	      //cout<<GenPtMatch<<endl;
	      }
	    }
	  }
	  
	  hMCMatch->Fill(RecoMuonPtMatch-GenParticle_pt[i]);
	  h1PtGen->Fill(GenParticle_pt[i]);
	  h1PtReco->Fill(RecoMuonPtMatch);
	}
      }    
      /*for (int i=0; i<nGenParticle; i++){
	if (GenParticle_pdgId[i]==15) cout<<nGenParticle<<endl;
	}*/

      /*      
      for (int i=0; i<nGenParticle; i++){
	for (int j=0; j<nGenParticle; j++){
	  if (i != j){
	    if (GenParticle_pdgId[i] == 13 && GenParticle_pdgId[j]==13){
	      //cout<<"hi"<<endl;
	      MuonInvariantMass=sqrt(fabs(((GenParticle_energy[i]+GenParticle_energy[j])*(GenParticle_energy[i]+GenParticle_energy[j]))-((GenParticle_p[i]+GenParticle_p[j])*(GenParticle_p[i]+GenParticle_p[j]))));
	      if (MuonInvariantMass != 0) {hInvMuon->Fill(MuonInvariantMass);}
	    }
	  }
	}
	}*/
   }
}
