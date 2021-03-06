#define vhtree_cxx
#include "vhtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <fstream>
#include <TMath.h>
void vhtree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L vhtree.C
//      Root > vhtree t
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
   double delRMin=0.03;
   double delR=0.;
   double GenMuonPt=0.;                                                                                                            
   double delphi=0.;
   double deleta=0.;
   Double_t RecoMuonPt=0.;
   double RecoMuonEta=0.;
   double inv_mass=0.;
   double ImpParam=0.;
   double MuonDZ=0.;
   double MuonChi2=0.;
   double SumMuonChi2=0.;
   double e1=0.;
   double e2=0.;
   double p1x=0.;
   double p2x=0.;
   double p1y=0.;
   double p2y=0.;
   double p1z=0.;
   double p2z=0.;
   double phi_1=0.;
   double phi_tau_1=0.;
   double phi_2=0.;
   double phi_tau_2=0.;
   double theta_1=0;
   double theta_2=0;
   double metx=0.;
   double mety=0.;
   double p_1=0.;
   double p_2=0.;
   double x_1=0;
   double x_2=0;
   double pvis_1=0;
   double pvis_2=0;
   double inv_mass_vis=0;
   Double_t total_events=0;
   Double_t events=0;
   Double_t mag=0;
   Double_t dimuoneta=0;
   Double_t dimuonratiopt=0;
   Int_t counter=0;
   Double_t GenMuonCharge=0;
   Double_t RecoMuonCharge=0;
   Double_t numerator=0;
   Double_t denominator=0;
   Int_t counter_ba=0;
   Int_t counter_ec=0;
   Int_t counter_out=0;
   Double_t cost=0.;
   double dimuonpt=0;
   double summuonpt=0;
   double count=0;
   double dcasig[2]={0};
   double phi_pmuon_met = 0;
   ofstream myfile("acceptance.file",ios::app);
   ofstream myfile2("acceptance2.file",ios::app);
   
   //TH1F::SetDefaultSumw2();
   
   TH1F *h1PtReco = new TH1F("h1PtReco","Reco Muon Pt",300,0,300);
   TH1F *h1PtGen = new TH1F("h1PtGen","Gen Muon Pt",300,0,300);

   TH1F *h1DiMuonPtReco = new TH1F("h1DiMuonPtReco","Reco DiMuon Pt",300,0,300);
   
   TH1F *h1SumMuonPtReco = new TH1F("h1SumMuonPtReco","Reco Sum Muon Pt",300,0,300);
   
   TH1F *h1DiMuonSumPtRatio = new TH1F("h1DiMuonSumPtRatio","Ratio of dimuon pT to the muon sum pT",200,0,2);

   TH1F *h1MuonImpParSig = new TH1F("h1MuonImpParSig","DCA Significance of muons",100,-5,5);
   
   TH1F *h1PhiPMuonMet = new TH1F("h1PhiPMuonMet","Azimuthal Angle between the positive muon and MET ",10,0,3);

   TH1F *h1DecayAngleDiMuonRest = new TH1F("h1DecayAngleDiMuonRest","Decay Angle of the positive muon in the dimuon rest frame",10,-1,1);

   TH2F *hSumMuonDiMuon=new TH2F("hSumMuonDiMuon","Corr",300,0,300,300,0,300);

   
   TH1F *h1PtLeading = new TH1F("h1PtLeading","Leading Muon Pt",100,0,100);
   TH1F *h1PtSubLeading = new TH1F("h1PtSubLeading","SubLeading Muon Pt",100,0,100);
   
   TH1F *h1PtLeadingi = new TH1F("h1PtLeadingi","Integrated Leading Muon Pt",100,0,100);
   TH1F *h1PtSubLeadingi = new TH1F("h1PtSubLeadingi","Integrated SubLeading Muon Pt",100,0,100);
   


   TH1F *h1EtaReco = new TH1F("h1EtaReco","Reco Muon Eta",100,-7,+7);
   //TH1F *h1EtaGen = new TH1F("h1EtaGen","Gen Muon Eta",100,-5,+5);
   TH1F *h1DiMuonEtaReco = new TH1F("h1DiMuonEtaReco","Dimuon Eta (with GEMs)",100,-5,5);
   
   TH1F *hPhiReco = new TH1F("hPhiReco","Difference in Phi between the two muons in multiples of #pi",100,-2,2);

   
   
   TH1F *hMCMatchEC = new TH1F("hMCMatchEC","Muon pT resolution in 1.5<|#eta|<2.2",200,-0.1,0.1);
   TH1F *hMCMatchBa = new TH1F("hMCMatchBa","Muon pT resolution in |#eta|<1.5",200,-0.1,0.1);
   
   TH1F *hLeadMuon1 = new TH1F("hLeadMuon1","Leading Muon and Subleading Muon in 1.5<|#eta|<2.2",100,0,100);
   TH1F *hLeadMuon2 = new TH1F("hLeadMuon2","Leading Muon in 1.5<|#eta|<2.2, subleading muon in |#eta|<1.5 ",100,0,100);
   TH1F *hLeadMuon3 = new TH1F("hLeadMuon3","Leading Muon in |#eta|<1.5, subleading muon in 1.5<|#eta|<2.2",100,0,100);
   //TH1F *hLeadMuonAll = new TH1F("hLeadMuonAll","Overall Leading muon distribution",100,0,100);
   
   

   TH1F *hSubLeadMuon1 = new TH1F("hSubLeadMuon1","Leading Muon and Subleading Muon in 1.5<|#eta|<2.2",100,0,100);
   TH1F *hSubLeadMuon2 = new TH1F("hSubLeadMuon2","Leading Muon in 1.5<|#eta|<2.2, subleading muon in |#eta|<1.5",100,0,100);
   TH1F *hSubLeadMuon3 = new TH1F("hSubLeadMuon3","Leading Muon in |#eta|<1.5, subleading muon in 1.5<|#eta|<2.2",100,0,100);
   //TH1F *hSubLeadMuonAll = new TH1F("hSubLeadMuonAll","Overall Subleading muon distribution",100,0,100);


   TH2F *h1 = new TH2F("h1","Correlation plot between Subleading and leading muon Pt(Overall)",30,0,30,30,0,30);
   TH2F *h11 = new TH2F("h11","Correlation plot between Subleading and leading muon Pt(EC(Lead), EC(sublead))",30,0,30,30,0,30);
   TH2F *h12 = new TH2F("h12","Correlation plot between Subleading and leading muon Pt(EC(Lead),Barrel(Sublead))",30,0,30,30,0,30);
   TH2F *h13 = new TH2F("h13","Correlation plot between Subleading and leading muon Pt(EC(sublead),Barrel(Lead))",30,0,30,30,0,30);
   //TH3F *h2 = new TH3F("h2","acceptance plot",300,0,300,100,0,150,100,0,1);
   TH2F *hAcceptAll = new TH2F("hAcceptAll","Overall acceptance plot",120,0,30,120,0,30);
   TH2F *hAccept1 = new TH2F("hAccept1","Leading Muon and Subleading Muon in 1.5<|#eta|<2.2      ",120,0,30,120,0,30);
   TH2F *hAccept2 = new TH2F("hAccept2","Leading Muon in 1.5<|#eta|<2.2, subleading muon in |#eta|<1.5",120,0,30,120,0,30);
   TH2F *hAccept3 = new TH2F("hAccept3","Leading Muon in |#eta|<1.5, subleading muon in 1.5<|#eta|<2.2      ",120,0,30,120,0,30);
   
   //TProfile2D *h2 = new TProfile2D("h2","acceptance plot",100,0,300,100,0,300,0,1);  
   //TGraph2D *t2 = new TGraph2D();
   TH1F *hInvTau = new TH1F("hInvTau","Invariant Mass plot for Taus",100,0,300);
   TH1F *hInvMuon = new TH1F("hInvMuon","Invariant Mass plot for Muons(visible)",100,0,300);

   
   
   TH1F *hImPEC = new TH1F("hImPEC","Impact parameter plot in 1.5<|#eta|<2.2",100,-0.06,0.06);
   TH1F *hImPBa = new TH1F("hImPBa","Impact parameter plot in |#eta|<1.5",100,-0.06,0.06);
   
   TH1F *hDZEC = new TH1F("hDZEC","Muon DZ plot End cap",100,-10,10);
   TH1F *hDZBa = new TH1F("hDZBa","Muon DZ plot barrel",100,-10,10);

   TH1F *hChiEC = new TH1F("hChiEC","Muon Chi plot End cap",100,0,16);
   TH1F *hChiBa = new TH1F("hChiBa","Muon Chi plot barrel",100,0,16);

   TH1F *hImPECEr = new TH1F("hImPECEr","Error in Impact parameter plot End cap",100,0,16);
   TH1F *hImPBaEr = new TH1F("hImPBaEr","Error in Impact parameter plot barrel",100,0,16);

   //Muon eta plots for pT threshold !

   TH1F *hEtaPt10 = new TH1F("hEtaPt10","Reco Muon Eta 10",30,0,3);
   TH1F *hEtaPt15 = new TH1F("hEtaPt15","Reco Muon Eta 15",30,0,3);
   TH1F *hEtaPt20 = new TH1F("hEtaPt20","Reco Muon Eta 20",30,0,3);
   TH1F *hEtaPt25 = new TH1F("hEtaPt25","Reco Muon Eta 25",30,0,3);
   TH1F *hEtaPt30 = new TH1F("hEtaPt30","Reco Muon Eta 30",30,0,3);
   TH1F *hEtaPt35 = new TH1F("hEtaPt35","Reco Muon Eta 35",30,0,3);

   //2-D histograms

   TH2F *hEtaResEC = new TH2F("hEtaResEC","Eta vs MuonPt resolution in Endcap",100,-3,3,100,-5,5);
   TH2F *hEtaResBa = new TH2F("hEtaResBa","Eta vs MuonPt resolution in barrel",100,-3,3,100,-5,5);
   TH2F *hEtaResAll = new TH2F("hEtaResAll","Eta vs MuonPt resolution Overall",100,-3,3,100,-5,5);
   
   TH2F *hEtaPtEC = new TH2F("hEtaPtEC","Eta vs MuonPt in Endcap",100,-3,3,100,0,200);
   TH2F *hEtaPtBa = new TH2F("hEtaPtBa","Eta vs MuonPt in barrel",100,-3,3,100,0,200);
   TH2F *hEtaPtAll = new TH2F("hEtaPtAll","Reco Muon |#eta| vs p_{T}",100,0,3,100,0,200);
   


   //std::vector<double> leadmuonpt;
   //std::vector<double> subleadmuonpt;
   Double_t pt_cut=30.;
   Double_t bin_width=0.25;
   const int bin_size_sl=pt_cut/bin_width;
   const int bin_size_l=pt_cut/bin_width;
   
   Double_t leadmuonpt[bin_size_l]={0}; //100 is the number of bins
   Double_t subleadmuonpt[bin_size_sl]={0};
   
   Double_t leadmuonpt1[bin_size_l]={0}; //100 is the number of bins
   Double_t subleadmuonpt1[bin_size_sl]={0};
   
   Double_t leadmuonpt2[bin_size_l]={0}; //100 is the number of bins
   Double_t subleadmuonpt2[bin_size_sl]={0};
   
   Double_t leadmuonpt3[bin_size_l]={0}; //100 is the number of bins
   Double_t subleadmuonpt3[bin_size_sl]={0};

   //TFile f("~/histos_mva_dytt.root","recreate");
   

   TFile *f = new TFile("~/histos_mva_dytt.root","recreate");
   //cout<<"New file created"<<endl;
   TTree *tree = new TTree("gluHsignal","variables");
   //cout<<"New tree created"<<endl;
   tree->Branch("dimuoneta",&dimuoneta,"dimuoneta/D");
   //tree->Branch("h1DiMuonEtaReco","TH1F",&h1DiMuonEtaReco,32000,0);
   tree->Branch("dimuonratiopt",&dimuonratiopt,"dimuonratiopt/D");
   //tree->Branch("coll_approx",&dimuonratiopt,"coll_approx/D");
   tree->Branch("dcasig",&dcasig,"dcasig[2]/D");
   tree->Branch("phi_pmuon_met",&phi_pmuon_met,"phi_pmuon_met/D");
   tree->Branch("cost",&dcasig,"cost/D");
   
   Long64_t nentries = fChain->GetEntriesFast();
   cout<<"Number of events "<<nentries<<endl;
   int dimuon=0;
   Long64_t nbytes = 0, nb = 0;
   //for (Long64_t jentry=0;jentry<nentries;jentry++) {
   for (Long64_t jentry=0;jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     if (nMuon<2) continue;
     if ((fabs(Muon_eta[0]) >= 2.1))continue;
     if ((fabs(Muon_eta[1]) >= 2.1))continue;
     if ((fabs(Muon_pt[0]) <= 20))continue;
     if ((fabs(Muon_pt[1]) <= 10))continue;
     if ((Muon_nMatchedStations[0])<1)continue; 
     if ((Muon_nMatchedStations[1])<1)continue; 
     if ((Muon_trackerLayersWithMeasurement[0])<=5)continue; 
     if ((Muon_trackerLayersWithMeasurement[1])<=5)continue; 
     if ((Muon_pixHits[0])<1)continue; 
     if ((Muon_pixHits[1])<1)continue; 
     
     if ((Muon_globalChi2[0])>=10)continue; 
     if ((Muon_globalChi2[1])>=10)continue; 
     if (fabs(Muon_trkD0[0])>=0.04)continue; 
     if (fabs(Muon_trkD0[1])>=0.04)continue; 
     //if (fabs(Muon_trkDz[0])>=1)continue; 
     //if (fabs(Muon_trkDz[1])>=1)continue; 
     if (fabs(Muon_vtxDistZ[0])>=0.1)continue; 
     if (fabs(Muon_vtxDistZ[1])>=0.1)continue; 
     if ((Muon_ptError[0]/Muon_pt[0])*100>=10) continue;
     if ((Muon_ptError[1]/Muon_pt[1])*100>=10) continue;
     if (fabs((Muon_phi[0]-Muon_phi[1])) <= 2) continue;
     //if ((fabs(Muon_pt[0]) < 5))continue;
     //if ((fabs(Muon_pt[1]) < 5))continue;
     //if (abs(Muon_phi[0]-Muon_phi[1] < 2.0))continue;
     
     e1=Muon_energy[0];
     e2=Muon_energy[1];
     p1x=Muon_px[0];
     p2x=Muon_px[1];
     p1y=Muon_py[0];
     p2y=Muon_py[1];
     p1z=Muon_pz[0];
     p2z=Muon_pz[1];
     inv_mass_vis=sqrt((e1+e2)*(e1+e2)-((p1x+p2x)*(p1x+p2x)+(p1y+p2y)*(p1y+p2y)+(p1z+p2z)*(p1z+p2z)));
     if (inv_mass_vis<=35) continue;
     
     /*count=0;
     for (int i=0;i<nJet;i++){
       if (Jet_pt[i]<30) ++count;
     }
     if (count<1) continue;
     */
     ++dimuon;

     phi_1=Muon_phi[0];
     phi_2=Muon_phi[1];
     phi_tau_1=Tau_phi[0];
     phi_tau_2=Tau_phi[1];
     //cout<<phi_tau_1<<endl;
     hInvTau->Fill(phi_tau_1-phi_tau_2);
     //phi_tau_2=Tau_phi[1];
     theta_1=2*atan(exp(-1*Muon_eta[0]));
     theta_2=2*atan(exp(-1*Muon_eta[1]));
     metx=MET_metx[0];
     mety=MET_mety[0];
     //cout<<metx<<" "<<mety<<endl;
     p_1=(metx*sin(phi_2)-mety*cos(phi_2))/(sin(theta_1)*(cos(phi_1)-sin(phi_1)));
     p_2=(metx*sin(phi_1)-mety*cos(phi_1))/(sin(theta_2)*(cos(phi_2)-sin(phi_2)));
     pvis_1=sqrt(Muon_px[0]*Muon_px[0]+Muon_py[0]*Muon_py[0]+Muon_pz[0]*Muon_pz[0]);
     pvis_2=sqrt(Muon_px[1]*Muon_px[1]+Muon_py[1]*Muon_py[1]+Muon_pz[1]*Muon_pz[1]);
     //cout<<p_1<<endl;
     x_1=pvis_1/(pvis_1+p_1);
     x_2=pvis_2/(pvis_2+p_2);
     
     /*e1=Muon_energy[0];
     e2=Muon_energy[1];
     p1x=Muon_px[0];
     p2x=Muon_px[1];
     p1y=Muon_py[0];
     p2y=Muon_py[1];
     p1z=Muon_pz[0];
     p2z=Muon_pz[1];
     inv_mass_vis=sqrt((e1+e2)*(e1+e2)-((p1x+p2x)*(p1x+p2x)+(p1y+p2y)*(p1y+p2y)+(p1z+p2z)*(p1z+p2z)));*/
     inv_mass=inv_mass_vis/sqrt(fabs(x_1*x_2));
     hPhiReco->Fill(((Muon_phi[0]-Muon_phi[1])/(22.0/7.0)));
     //if ((fabs((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))) >= 1.1 || (fabs((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))) <= 0.9) cout<<(Muon_phi[0]-Muon_phi[1])/(22.0/7.0)<<" Pi"<<endl;
     if (inv_mass>0) {
       /*if ((fabs((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))) >= 1.3 || (fabs((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))) <= 0.7)hInvTau->Fill(inv_mass);*/
       hInvMuon->Fill(inv_mass_vis);
     }
     if (inv_mass<0) {
       /*if ((fabs((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))) >= 1.3 || (fabs((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))) <= 0.7)hInvTau->Fill(inv_mass);*/
       cout<<"less than zero"<<endl;
     }
     
     
     h1DiMuonPtReco->Fill(sqrt(((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1]))));
     h1SumMuonPtReco->Fill(Muon_pt[0]+Muon_pt[1]);
     if ((Muon_pt[0]+Muon_pt[1])!=0) dimuonratiopt=(sqrt(((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1])))/(Muon_pt[0]+Muon_pt[1]));
     //dimuonratiopt=(dimuonpt/SumMuonPt);
     h1DiMuonSumPtRatio->Fill(dimuonratiopt);
     summuonpt=Muon_pt[0]+Muon_pt[1];
     dimuonpt=sqrt(((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1])));
     hSumMuonDiMuon->Fill(summuonpt,dimuonpt);
     //cout<<(Muon_pt[0]+Muon_pt[1])<<endl;
     //cout<<dimuonratiopt<<endl;
     //cout<<"DiMuon pT"<<sqrt(((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1])))<<"Sum of pT "<<Muon_pt[0]+Muon_pt[1]<<endl;

     mag=sqrt(((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1]))+((Muon_pz[0]+Muon_pz[1])*(Muon_pz[0]+Muon_pz[1])));
     /*if ((mag-Muon_pz[0]+Muon_pz[1])!=0)*/dimuoneta=0.5*log((mag+Muon_pz[0]+Muon_pz[1])/(mag-(Muon_pz[0]+Muon_pz[1])));
     h1DiMuonEtaReco->Fill(dimuoneta);
     
     //h1MuonImpParSig->Fill(log10(Muon_trkD0[0]/Muon_trkD0Error[0]));
     //h1MuonImpParSig->Fill(log10(Muon_trkD0[1]/Muon_trkD0Error[1]));
     dcasig[0]=log10(Muon_trkD0[0]/Muon_trkD0Error[0]);
     dcasig[1]=log10(Muon_trkD0[1]/Muon_trkD0Error[1]);

     if (Muon_charge[0]>0)h1PhiPMuonMet->Fill(Muon_phi[0]-MET_metphi[0]);
     if (Muon_charge[1]>0)h1PhiPMuonMet->Fill(Muon_phi[1]-MET_metphi[1]);

     phi_pmuon_met=Muon_phi[0]-MET_metphi[0];

     //if (((Muon_phi[0]-Muon_phi[1])/(22.0/7.0))==1) cout<<"meow"<<endl;

       //Routine to calculate dimuon rest frame

     // --- Get the muons parameters in the CM frame
     //
     TLorentzVector pMu1CM(p1x,p1y,p1z,e1);
     TLorentzVector pMu2CM(p2x,p2y,p2z,e2);
     //
     // --- Obtain the dimuon parameters in the CM frame
     //
     TLorentzVector pDimuCM=pMu1CM+pMu2CM;
     //
     // --- Translate the dimuon parameters in the dimuon rest frame
     //
     TVector3 beta=(-1./pDimuCM.E())*pDimuCM.Vect();
     TLorentzVector pMu1Dimu=pMu1CM;
     TLorentzVector pMu2Dimu=pMu2CM;
     pMu1Dimu.Boost(beta);
     pMu2Dimu.Boost(beta);
     //
     // --- Determine the z axis for the calculation of the polarization angle
     // (i.e. the direction of the dimuon in the CM system)
     //
     TVector3 zaxis;
     zaxis=(pDimuCM.Vect()).Unit();

     if (Muon_charge[0]>0)cost = zaxis.Dot((pMu1Dimu.Vect()).Unit());
     if (Muon_charge[1]>0)cost = zaxis.Dot((pMu2Dimu.Vect()).Unit());
     
     //h1DecayAngleDiMuonRest->Fill(cost);
     //cout<<cost<<endl;
     
     //cout<<dimuoneta<<endl;
     //if ((((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1]))+((Muon_pz[0]+Muon_pz[1])*(Muon_pz[0]+Muon_pz[1])))<0.)
     //cout<<(((Muon_px[0]+Muon_px[1])*(Muon_px[0]+Muon_px[1]))+((Muon_py[0]+Muon_py[1])*(Muon_py[0]+Muon_py[1]))+((Muon_pz[0]+Muon_pz[1])*(Muon_pz[0]+Muon_pz[1])))<<endl;
     //tree->Fill();
     //if (((mag+Muon_pz[0]+Muon_pz[1])/(mag-Muon_pz[0]+Muon_pz[1]))<0)cout<<"neg"<<endl;
     
     /*
     if (Muon_pt[0]>=Muon_pt[1]){
       h1PtLeading->Fill(Muon_pt[0]);
       h1PtSubLeading->Fill(Muon_pt[1]);
     }
     
     else if (Muon_pt[0]<Muon_pt[1]){
       h1->Fill(Muon_pt[1],Muon_pt[0]);
       //cout<<Muon_pt[1]<<" "<<Muon_pt[0]<<endl;
     }
     
     

     //Different cases
     if (Muon_pt[0]>Muon_pt[1]){
       if (((fabs(Muon_eta[0]) > 1.5) && (fabs(Muon_eta[0]) < 2.2)) && ((fabs(Muon_eta[1]) > 1.5) && (fabs(Muon_eta[1]) < 2.2))){
	   hLeadMuon1->Fill(Muon_pt[0]);
	   hSubLeadMuon1->Fill(Muon_pt[1]);
	   h1->Fill(Muon_pt[0],Muon_pt[1]);
	   h11->Fill(Muon_pt[0],Muon_pt[1]);
	   if (Muon_pt[0]<pt_cut){
	     for (int i=0;i<bin_size_l;i++){
	       if (Muon_pt[0]>=i*bin_width && Muon_pt[0]<(i+1)*bin_width){
		 leadmuonpt[i]+=1;
		 leadmuonpt1[i]+=1;
	       }
	     }
	   }
       
	   if (Muon_pt[1]<pt_cut){
	     for (int i=0;i<bin_size_sl;i++){
	       if (Muon_pt[1]>i*bin_width && Muon_pt[1]<=(i+1)*bin_width){
		 subleadmuonpt[i]+=1;
		 subleadmuonpt1[i]+=1;
	       }
	     }
	   }
	 }
	 if (((fabs(Muon_eta[0]) > 1.5) && (fabs(Muon_eta[0]) < 2.2)) && (fabs(Muon_eta[1]) < 1.5)){
	   h1->Fill(Muon_pt[0],Muon_pt[1]);
	   h12->Fill(Muon_pt[0],Muon_pt[1]);
	   hLeadMuon2->Fill(Muon_pt[0]);
	   hSubLeadMuon2->Fill(Muon_pt[1]);
	   if (Muon_pt[0]<pt_cut){
	     for (int i=0;i<bin_size_l;i++){
	       if (Muon_pt[0]>=i*bin_width && Muon_pt[0]<(i+1)*bin_width){
		 leadmuonpt[i]+=1;
		 leadmuonpt2[i]+=1;
	       }
	     }
	   }
       
	   if (Muon_pt[1]<pt_cut){
	     for (int i=0;i<bin_size_sl;i++){
	       if (Muon_pt[1]>i*bin_width && Muon_pt[1]<=(i+1)*bin_width){
		 subleadmuonpt[i]+=1;
		 subleadmuonpt2[i]+=1;
	       }
	     }
	   }
	 }
	 if ((fabs(Muon_eta[0]) < 1.5) && ((fabs(Muon_eta[1]) > 1.5) && (fabs(Muon_eta[1]) < 2.2))){
	   h1->Fill(Muon_pt[0],Muon_pt[1]);
	   h13->Fill(Muon_pt[0],Muon_pt[1]);
	   hLeadMuon3->Fill(Muon_pt[0]);
           hSubLeadMuon3->Fill(Muon_pt[1]);
	   if (Muon_pt[0]<pt_cut){
	     for (int i=0;i<bin_size_l;i++){
	       if (Muon_pt[0]>=i*bin_width && Muon_pt[0]<(i+1)*bin_width){
		 leadmuonpt[i]+=1;
		 leadmuonpt3[i]+=1;
	       }
	     }
	   }
       
	   if (Muon_pt[1]<pt_cut){
	     for (int i=0;i<bin_size_sl;i++){
	       if (Muon_pt[1]>i*bin_width && Muon_pt[1]<=(i+1)*bin_width){
		 subleadmuonpt[i]+=1;
		 subleadmuonpt3[i]+=1;
	       }
	     }
	   }
	 }
     } 
       else{
	 if (((fabs(Muon_eta[1]) > 1.5) && (fabs(Muon_eta[1]) < 2.2)) && ((fabs(Muon_eta[0]) > 1.5) && (fabs(Muon_eta[0]) < 2.2))){
	   hLeadMuon1->Fill(Muon_pt[1]);
	   hSubLeadMuon1->Fill(Muon_pt[0]);
	 }
	 if (((fabs(Muon_eta[1]) > 1.5) && (fabs(Muon_eta[1]) < 2.2)) && (fabs(Muon_eta[0]) < 1.5)){
	   hLeadMuon2->Fill(Muon_pt[1]);
	   hSubLeadMuon2->Fill(Muon_pt[0]);
	 }
	 if ((fabs(Muon_eta[1]) < 1.5) && ((fabs(Muon_eta[0]) > 1.5) && (fabs(Muon_eta[0]) < 2.2))){
	   hLeadMuon3->Fill(Muon_pt[1]);
           hSubLeadMuon3->Fill(Muon_pt[0]);
	 }
      
       }
     /*for (int j=0;j<nGenParticle;j++){
       delRMin=0.03;
       for (int i=0;i<nMuon; i++){
	 
	 //counter=0;
	 RecoMuonEta=Muon_eta[i];
       
	 
	 delphi=Muon_phi[i]-GenParticle_phi[j];
	 deleta=Muon_eta[i]-GenParticle_eta[j];
	 delR=sqrt(delphi*delphi+deleta*deleta);
	 if (delR < delRMin){
	   delRMin=delR;
	   if ((fabs(RecoMuonEta) > 1.5) && (fabs(RecoMuonEta) < 2.2)){
	     //cout<<"haha"<<endl;
	     denominator++;
	     //cout<<"Reco Muon Charge "<<Muon_charge[i]<<"Gen Muon Charge "<<GenParticle_charge[j]<<endl;
	     GenMuonCharge=GenParticle_charge[j];
	     RecoMuonCharge=Muon_charge[i];
	     if (GenMuonCharge-RecoMuonCharge != 0) cout<<"MISMATCH"<<endl;//numerator++;
	   }
	 }
	 //cout<<delR<<endl;
       }
       }
     //if (denominator!=0)cout<<"MIS ID "<<numerator/denominator<<endl;
     for (int i=0;i<nMuon; i++){
       RecoMuonEta=Muon_eta[i];
       if (fabs(RecoMuonEta)>2.4) cout<<"one"<<endl;
       GenMuonPt=Muon_ptgen[i];
       ImpParam=Muon_trkD0[i];
       MuonDZ=Muon_trkDz[i];
       MuonChi2=Muon_globalChi2[i];
       RecoMuonPt=Muon_pt[i];
     
       if ((fabs(RecoMuonEta) > 1.5) && (fabs(RecoMuonEta) < 2.2)){
	 hMCMatchEC->Fill((GenMuonPt-RecoMuonPt)/GenMuonPt);
	 hImPEC->Fill(ImpParam);
	 hDZEC->Fill(MuonDZ);
	 hChiEC->Fill(MuonChi2);
	 hEtaPtEC->Fill(RecoMuonEta,RecoMuonPt);
	 //if(Muon_charge[i]-Muon_chargegen[i]!=0) cout<<"MISMATCH"<<endl;
	 //hEtaResEC->Fill(RecoMuonPt-GenMuonPt,RecoMuonEta);
       }
       if ((fabs(Muon_eta[i]) < 1.5)){
	 hMCMatchBa->Fill((GenMuonPt-RecoMuonPt)/GenMuonPt);
	 hImPBa->Fill(ImpParam);
	 hDZBa->Fill(MuonDZ);
	 hChiBa->Fill(MuonChi2);
	 hEtaPtBa->Fill(RecoMuonEta,RecoMuonPt);
       }
       h1PtGen->Fill(GenMuonPt);
       h1PtReco->Fill(RecoMuonPt);
       h1EtaReco->Fill(RecoMuonEta);
       hEtaPtAll->Fill(fabs(RecoMuonEta),RecoMuonPt);
       if (RecoMuonPt>10.){
	 hEtaPt10->Fill(fabs(RecoMuonEta));
	 //if(fabs(RecoMuonEta) < 1.5)counter_barrel++;
       }
       if (RecoMuonPt>15.){
	 hEtaPt15->Fill(fabs(RecoMuonEta));
       }
       if (RecoMuonPt>20.){hEtaPt20->Fill(fabs(RecoMuonEta));}
       if (RecoMuonPt>25.){hEtaPt25->Fill(fabs(RecoMuonEta));}
       if (RecoMuonPt>30.){hEtaPt30->Fill(fabs(RecoMuonEta));}
       if (RecoMuonPt>35.){hEtaPt35->Fill(fabs(RecoMuonEta));}
       
       if(fabs(RecoMuonEta) < 1.5)counter_ba++;
       if((fabs(RecoMuonEta) > 1.5) && (fabs(RecoMuonEta) < 2.2))counter_ec++;
       if((fabs(RecoMuonEta) > 2.2) && (fabs(RecoMuonEta) < 2.4))counter_out++;
       
       
       //if ()
       }*/
     tree->Fill();
     //f->cd();
     //f1->Write();
     //f->Close();
     }
   //   
   
   //h1DiMuonSumPtRatio->Write();
   //h1MuonImpParSig->Write();   
   //h1DiMuonEtaReco->Write();
   //h1PhiPMuonMet->Write();   
   //hSumMuonDiMuon->Write();
   //f->Close();
     cout<<"Number of dimuon events "<<dimuon<<" BR of di tau to dimuon "<<((float)dimuon/(float)nentries)*100<<endl;
   cout<<"Number of muons in barrel "<<(float)counter_ba/(float)(dimuon*2)<<" Number of muons in endcap "<<(float)counter_ec/(float)(dimuon*2)<<" Number of muons outside "<<(float)counter_out/(float)(dimuon*2)<<endl; 
   f->cd();
   tree->Write();
   f->Close();
   

  //Overall
   /*       
   total_events=0;
   events=0;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       if(leadmuonpt[i]!=0 && subleadmuonpt[j]!=0)total_events+=leadmuonpt[i]*subleadmuonpt[j];
     }
   }
   cout<<total_events<<endl;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       events=0;
       for (int k=i;k<bin_size_l;k++){
	 for (int l=j;l<k;l++){
	   if(leadmuonpt[k]!=0 && subleadmuonpt[l]!=0)events+=leadmuonpt[k]*subleadmuonpt[l];
	 }
       }
       hAcceptAll->Fill(i*bin_width,j*bin_width,((Double_t)events/(Double_t)total_events)*100);
     }
   }
   

   //Case-1
   
   total_events=0;
   events=0;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       if(leadmuonpt1[i]!=0 && subleadmuonpt1[j]!=0)total_events+=leadmuonpt1[i]*subleadmuonpt1[j];
     }
   }
   cout<<total_events<<endl;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       events=0;
       for (int k=i;k<bin_size_l;k++){
	 for (int l=j;l<k;l++){
	   if(leadmuonpt1[k]!=0 && subleadmuonpt1[l]!=0)events+=leadmuonpt1[k]*subleadmuonpt1[l];
	 }
       }
       hAccept1->Fill(i*bin_width,j*bin_width,((Double_t)events/(Double_t)total_events)*100);
     }
   }
   
   //Case-2
   total_events=0;
   events=0;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       if(leadmuonpt2[i]!=0 && subleadmuonpt2[j]!=0)total_events+=leadmuonpt2[i]*subleadmuonpt2[j];
     }
   }
   cout<<total_events<<endl;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       events=0;
       for (int k=i;k<bin_size_l;k++){
	 for (int l=j;l<k;l++){
	   if(leadmuonpt2[k]!=0 && subleadmuonpt2[l]!=0)events+=leadmuonpt2[k]*subleadmuonpt2[l];
	 }
       }
       hAccept2->Fill(i*bin_width,j*bin_width,((Double_t)events/(Double_t)total_events)*100);
     }
   }

   //Case-3

   total_events=0;
   events=0;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       if(leadmuonpt3[i]!=0 && subleadmuonpt3[j]!=0)total_events+=leadmuonpt3[i]*subleadmuonpt3[j];
     }
   }
   cout<<total_events<<endl;
   for (int i=0;i<bin_size_l;i++){
     for (int j=0;j<i;j++){
       events=0;
       for (int k=i;k<bin_size_l;k++){
	 for (int l=j;l<k;l++){
	   if(leadmuonpt3[k]!=0 && subleadmuonpt3[l]!=0)events+=leadmuonpt3[k]*subleadmuonpt3[l];
	 }
       }
       //myfile2<<i<<" "<<j<<" "<<" "<<events<<" "<<total_events<<" "<<(Double_t)events/(Double_t)total_events<<endl;
       //myfile2<<i*bin_width<<" "<<j*bin_width<<" "<<(Double_t)events/(Double_t)total_events<<endl;
       hAccept3->Fill(i*bin_width,j*bin_width,((Double_t)events/(Double_t)total_events)*100);
       //hAccept1->Fill(i*bin_width,j*bin_width);
     }
   }
   */
}

   //hAcceptAll->Write();
   /*
   //Time to beautify most of the plots
   hLeadMuon1->SetLineColor(1);
   hSubLeadMuon1->SetLineColor(4);
   hLeadMuon1->SetXTitle("Reco. Muon p_{T} in GeV/c");
   hSubLeadMuon1->SetXTitle("Reco. Muon p_{T} in GeV/c");
   hLeadMuon1->SetYTitle("Number of Events/GeV");
   hSubLeadMuon1->SetYTitle("Number of Events/GeV");
   hSubLeadMuon1->Draw();
   gPad->Update();
   hLeadMuon1->Draw();          //draw hist_2 first as it has a larger range
   gPad->Update();


   TPaveStats *tps1 = (TPaveStats*) hLeadMuon1->FindObject("stats");
   tps1->SetName("Hist1 Stats");
   double X1 = tps1->GetX1NDC();
   double Y1 = tps1->GetY1NDC();
   double X2 = tps1->GetX2NDC();
   double Y2 = tps1->GetY2NDC();
  
   TPaveStats *tps2 = (TPaveStats*) hSubLeadMuon1->FindObject("stats");
   tps2->SetTextColor(kRed);
   tps2->SetLineColor(kRed);
   tps2->SetX1NDC(X1);
   tps2->SetX2NDC(X2);
   tps2->SetY1NDC(Y1-(Y2-Y1));
   tps2->SetY2NDC(Y1);
   
  
  
   hSubLeadMuon1->Draw();
   hLeadMuon1->Draw("same");          //draw hist_2 first as it has a larger range
   tps2->Draw("same");
   tps1->Draw("same");
   
   leg_hist = new TLegend(0.4712644,0.5886076,0.7600575,0.778481,NULL,"brNDC");
   leg_hist->SetHeader("p_{T} histograms for case 1");
   leg_hist->SetFillColor(0);
   leg_hist->AddEntry(hLeadMuon1,"leading muon p_{T}","l");
   leg_hist->AddEntry(hSubLeadMuon1,"subleading muon p_{T}","l");
   leg_hist->SetTextSize(0.03);
   leg_hist->Draw();
  
   c1->SaveAs("case1.pdf");
   c1->Clear();
   

   hLeadMuon2->SetLineColor(1);
   hSubLeadMuon2->SetLineColor(4);
   hLeadMuon2->SetXTitle("Reco Muon p_{T} in GeV/c");
   hSubLeadMuon2->SetXTitle("Reco Muon p_{T} in GeV/c");
   hLeadMuon2->SetYTitle("Number of Events/GeV");
   hSubLeadMuon2->SetYTitle("Number of Events/GeV");
   hSubLeadMuon2->Draw();
   gPad->Update();
   hLeadMuon2->Draw();
   gPad->Update();
   //draw hist_2 first as it has a larger range
   TPaveStats *tps1 = (TPaveStats*) hLeadMuon2->FindObject("stats");
   tps1->SetName("Hist1 Stats");
   double X1 = tps1->GetX1NDC();
   double Y1 = tps1->GetY1NDC();
   double X2 = tps1->GetX2NDC();
   double Y2 = tps1->GetY2NDC();
   
   TPaveStats *tps2 = (TPaveStats*) hSubLeadMuon2->FindObject("stats");
   tps2->SetTextColor(kRed);
   tps2->SetLineColor(kRed);
   tps2->SetX1NDC(X1);
   tps2->SetX2NDC(X2);
   tps2->SetY1NDC(Y1-(Y2-Y1));
   tps2->SetY2NDC(Y1);
   
  
  
   hSubLeadMuon2->Draw();
   hLeadMuon2->Draw("same");          //draw hist_2 first as it has a larger range
   tps2->Draw("same");
   tps1->Draw("same");
   
   leg_hist = new TLegend(0.4712644,0.5886076,0.7600575,0.778481,NULL,"brNDC");
   leg_hist->SetHeader("p_{T} histograms for case 2");
   leg_hist->SetFillColor(0);
   leg_hist->AddEntry(hLeadMuon2,"leading muon p_{T}","l");
   leg_hist->AddEntry(hSubLeadMuon2,"subleading muon p_{T}","l");
   leg_hist->SetTextSize(0.03);
   leg_hist->Draw();
   
   c1->SaveAs("case2.pdf");
  
   
   hLeadMuon3->SetLineColor(1);
   hSubLeadMuon3->SetLineColor(4);
   hLeadMuon3->SetXTitle("Reco Muon p_{T} in GeV/c");
   hSubLeadMuon3->SetXTitle("Reco Muon p_{T} in GeV/c");
   hLeadMuon3->SetYTitle("Number of Events/GeV");
   hSubLeadMuon3->SetYTitle("Number of Events/GeV");
   hSubLeadMuon3->Draw();
   gPad->Update();
   hLeadMuon3->Draw();          //draw hist_2 first as it has a larger range
   gPad->Update();
   
   TPaveStats *tps1 = (TPaveStats*) hLeadMuon3->FindObject("stats");
   tps1->SetName("Hist1 Stats");
   double X1 = tps1->GetX1NDC();
   double Y1 = tps1->GetY1NDC();
   double X2 = tps1->GetX2NDC();
   double Y2 = tps1->GetY2NDC();
   
   TPaveStats *tps2 = (TPaveStats*) hSubLeadMuon3->FindObject("stats");
   tps2->SetTextColor(kRed);
   tps2->SetLineColor(kRed);
   tps2->SetX1NDC(X1);
   tps2->SetX2NDC(X2);
   tps2->SetY1NDC(Y1-(Y2-Y1));
   tps2->SetY2NDC(Y1);
   
   
   
   hSubLeadMuon3->Draw();
   hLeadMuon3->Draw("same");          //draw hist_2 first as it has a larger range
   tps2->Draw("same");
   tps1->Draw("same");
   
   
   leg_hist = new TLegend(0.4712644,0.5886076,0.7600575,0.778481,NULL,"brNDC");
   leg_hist->SetHeader("p_{T} histograms for case 3");
   leg_hist->SetFillColor(0);
   leg_hist->AddEntry(hLeadMuon3,"leading muon p_{T}","l");
   leg_hist->AddEntry(hSubLeadMuon3,"subleading muon p_{T}","l");
   leg_hist->SetTextSize(0.03);
   leg_hist->Draw();
   
   c1->SaveAs("case3.pdf");
   c1->Clear();
   
   //pT resolution plots

   hMCMatchEC->SetLineColor(1);
   
   hMCMatchEC->SetXTitle("p_{T}^{gen}-p_{T}^{reco}/p_{T}^{gen}");
   hMCMatchEC->Draw();          //draw hist_2 first as it has a larger range
   hMCMatchEC->Draw("esame");          //draw hist_2 first as it has a larger range
   c1->SaveAs("plot_res_1.pdf");
   c1->Clear();

   hMCMatchBa->SetLineColor(1);
   
   hMCMatchBa->SetXTitle("p_{T}^{gen}-p_{T}^{reco}/p_{T}^{gen}");
   hMCMatchBa->Draw();          //draw hist_2 first as it has a larger range
   hMCMatchBa->Draw("esame");          //draw hist_2 first as it has a larger range
   c1->SaveAs("plot_res_2.pdf");
   c1->Clear();

   //Acceptance plots
   
   //Overall Acceptance
   
   hAcceptAll->SetXTitle("Reco. leading muon p_{T} in GeV/c");
   hAcceptAll->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  //hAcceptAll->SetZTitle("Kinematic acceptance");
   hAcceptAll->SetStats(0);
   hAcceptAll->Draw("cont3 colz");
   //HLT_PATH Mu17_Mu8
   
   Int_t a=hAcceptAll->GetXaxis()->FindBin(17);
   Int_t b = hAcceptAll->GetYaxis()->FindBin(8);
   Double_t c = hAcceptAll->GetBinContent(a,b);
   //Double_t a = hAcceptAll->GetBinContent(hAcceptAll->GetXaxis()->FindBin(17),hAcceptAll->GetYaxis()->FindBin(8)));
   //HLT_PATH Mu13_Mu8
   //Double_t f=hAcceptAll->GetBinContent(
   Int_t d = hAcceptAll->GetXaxis()->FindBin(13);
   Int_t e = hAcceptAll->GetYaxis()->FindBin(8);
   Double_t f = hAcceptAll->GetBinContent(d,e);
  //Offline Cuts
  
   Int_t g=hAcceptAll->GetXaxis()->FindBin(20);
   Int_t h=hAcceptAll->GetYaxis()->FindBin(10);
   Double_t z=hAcceptAll->GetBinContent(g,h);
  //Double_t i=GetBinContenthAcceptAll->GetXaxis()->FindBin(20),hAcceptAll->GetYaxis()->FindBin(10));

   cout<<c<<" "<<f<<" "<<z<<endl;
  
  //Double_t m=hAcceptAll->GetBinContent(k,l);
  //draw hist_2 first as it has a larger range
  
   TLatex latex;
  //latex.DrawLatex(17,8,TString::Format("#bullet %f ",a));
  //latex.DrawLatex(17,8,TString::Format("#bullet %2f %",c*100));
   latex.DrawLatex(17,8,"#bullet 64%");
   latex.DrawLatex(13,8,"#diamond 72%");
   latex.DrawLatex(20,10,"#color[2]{#bullet} 43%");
  //latex.DrawLatex(17,8,TString::Format("%f",c));
  //latex.DrawLatex(17,8,TString::Format("%f",c));
  //latex.DrawLatex(13,8,TString::Format("#diamond %f ",f));
  
  //latex.DrawLatex(20,10,TString::Format("#circ %f ",i));
  
   latex.DrawLatex(3,22,"#bullet");
   latex.DrawLatex(2.83,25,"#diamond");
  
  
  
   latex.DrawLatex(4,28,"#scale[0.8]{HLT Paths(Run-1)}");
   latex.DrawLatex(4,22,"#scale[0.8]{Mu17_Mu8 (Luminosity 19.1 fb^{-1})}");
   latex.DrawLatex(4,25,"#scale[0.8]{Mu13_Mu8 (Luminosity 3.7 fb^{-1})}");
  
   latex.DrawLatex(4,19,"#scale[0.8]{Offline selection}");
   latex.DrawLatex(3,16,"#color[2]{#bullet}");
   latex.DrawLatex(4,16,"#scale[0.8]{Mu20_Mu10}");
   c1->SaveAs("acceptance_2d_all_cont3.pdf");
  
   //Case-1
   */

