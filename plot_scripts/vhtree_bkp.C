#define vhtree_cxx
#include "vhtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <fstream>
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
   double RecoMuonPt=0.;
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
   double phi_2=0;
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

   ofstream myfile("acceptance.file",ios::app);
   ofstream myfile2("acceptance2.file",ios::app);
   
   TH1F *h1PtReco = new TH1F("h1PtReco","Reco Muon Pt",100,0,300);
   TH1F *h1PtGen = new TH1F("h1PtGen","Gen Muon Pt",100,0,300);

   TH1F *h1DiMuonPtReco = new TH1F("h1DiMuonPtReco","Reco DiMuon Pt",100,0,300);
   
   TH1F *h1SumMuonPtReco = new TH1F("h1SumMuonPtReco","Reco Sum Muon Pt",100,0,300);
   
   
   
   TH1F *h1PtLeading = new TH1F("h1PtLeading","Leading Muon Pt",100,0,100);
   TH1F *h1PtSubLeading = new TH1F("h1PtSubLeading","SubLeading Muon Pt",100,0,100);
   
   TH1F *h1PtLeadingi = new TH1F("h1PtLeadingi","Integrated Leading Muon Pt",100,0,100);
   TH1F *h1PtSubLeadingi = new TH1F("h1PtSubLeadingi","Integrated SubLeading Muon Pt",100,0,100);
   


   TH1F *h1EtaReco = new TH1F("h1EtaReco","Reco Muon Eta",100,-5,+5);
   //TH1F *h1EtaGen = new TH1F("h1EtaGen","Gen Muon Eta",100,-5,+5);
   TH1F *h1DiMuonEtaReco = new TH1F("h1DiMuonEtaReco","Reco DiMuon Eta",100,-10,+10);
   
   TH1F *hPhiReco = new TH1F("hPhiReco","Difference in Phi between the two muons in multiples of #pi",100,-2,2);

   
   
   TH1F *hMCMatchEC = new TH1F("hMCMatchEC","Muon Pt resolution in End cap region",200,-0.5,0.5);
   TH1F *hMCMatchBa = new TH1F("hMCMatchBa","Muon Pt resolution in barrel region",200,-0.5,0.5);
   
   TH1F *hLeadMuon1 = new TH1F("hLeadMuon1","Leading Muon and Subleading Muon in EndCap",100,0,100);
   TH1F *hLeadMuon2 = new TH1F("hLeadMuon2","Leading Muon in Endcap, subleading muon in barrel",100,0,100);
   TH1F *hLeadMuon3 = new TH1F("hLeadMuon3","Leading Muon in Barrel, subleading muon in endcap",100,0,100);
   //TH1F *hLeadMuonAll = new TH1F("hLeadMuonAll","Overall Leading muon distribution",100,0,100);
   
   

   TH1F *hSubLeadMuon1 = new TH1F("hSubLeadMuon1","Leading Muon and Subleading Muon in EndCap",100,0,100);
   TH1F *hSubLeadMuon2 = new TH1F("hSubLeadMuon2","Leading Muon in Endcap, subleading muon in barrel",100,0,100);
   TH1F *hSubLeadMuon3 = new TH1F("hSubLeadMuon3","Leading Muon in Barrel, subleading muon in endcap",100,0,100);
   //TH1F *hSubLeadMuonAll = new TH1F("hSubLeadMuonAll","Overall Subleading muon distribution",100,0,100);


   TH2F *h1 = new TH2F("h1","Correlation plot between Subleading and leading muon Pt(Overall)",30,0,30,30,0,30);
   TH2F *h11 = new TH2F("h11","Correlation plot between Subleading and leading muon Pt(EC(Lead), EC(sublead))",30,0,30,30,0,30);
   TH2F *h12 = new TH2F("h12","Correlation plot between Subleading and leading muon Pt(EC(Lead),Barrel(Sublead))",30,0,30,30,0,30);
   TH2F *h13 = new TH2F("h13","Correlation plot between Subleading and leading muon Pt(EC(sublead),Barrel(Lead))",30,0,30,30,0,30);
   //TH3F *h2 = new TH3F("h2","acceptance plot",300,0,300,100,0,150,100,0,1);
   TH2F *hAcceptAll = new TH2F("hAcceptAll","Overall acceptance plot",120,0,30,120,0,30);
   TH2F *hAccept1 = new TH2F("hAccept1","Leading Muon and Subleading Muon in EndCap",120,0,30,120,0,30);
   TH2F *hAccept2 = new TH2F("hAccept2","Leading Muon in Endcap, subleading muon in barrel",120,0,30,120,0,30);
   TH2F *hAccept3 = new TH2F("hAccept3","Leading Muon in Barrel, subleading muon in endcap",120,0,30,120,0,30);
   
   //TProfile2D *h2 = new TProfile2D("h2","acceptance plot",100,0,300,100,0,300,0,1);  
   //TGraph2D *t2 = new TGraph2D();
   TH1F *hInvTau = new TH1F("hInvTau","Invariant Mass plot for Taus",100,0,300);
   TH1F *hInvMuon = new TH1F("hInvMuon","Invariant Mass plot for Muons(visible)",100,0,300);

   
   
   TH1F *hImPEC = new TH1F("hImPEC","Impact parameter plot End cap",100,-0.3,0.3);
   TH1F *hImPBa = new TH1F("hImPBa","Impact parameter plot barrel",100,-0.3,0.3);
   
   TH1F *hDZEC = new TH1F("hDZEC","Muon DZ plot End cap",100,-10,10);
   TH1F *hDZBa = new TH1F("hDZBa","Muon DZ plot barrel",100,-10,10);

   TH1F *hChiEC = new TH1F("hChiEC","Muon Chi plot End cap",100,0,16);
   TH1F *hChiBa = new TH1F("hChiBa","Muon Chi plot barrel",100,0,16);

   TH1F *hImPECEr = new TH1F("hImPECEr","Error in Impact parameter plot End cap",100,0,16);
   TH1F *hImPBaEr = new TH1F("hImPBaEr","Error in Impact parameter plot barrel",100,0,16);

   //Muon eta plots for pT threshold !

   TH1F *hEtaPt10 = new TH1F("hEtaPt10","Reco Muon Eta 10",100,-3,3);
   TH1F *hEtaPt15 = new TH1F("hEtaPt15","Reco Muon Eta 15",100,-3,3);
   TH1F *hEtaPt20 = new TH1F("hEtaPt20","Reco Muon Eta 20",100,-3,3);
   TH1F *hEtaPt25 = new TH1F("hEtaPt25","Reco Muon Eta 25",100,-3,3);
   TH1F *hEtaPt30 = new TH1F("hEtaPt30","Reco Muon Eta 30",100,-3,3);
   TH1F *hEtaPt35 = new TH1F("hEtaPt35","Reco Muon Eta 35",100,-3,3);

   //2-D histograms

   TH2F *hEtaResEC = new TH2F("hEtaResEC","Eta vs MuonPt resolution in Endcap",100,-3,3,100,-5,5);
   TH2F *hEtaResBa = new TH2F("hEtaResBa","Eta vs MuonPt resolution in barrel",100,-3,3,100,-5,5);
   TH2F *hEtaResAll = new TH2F("hEtaResAll","Eta vs MuonPt resolution Overall",100,-3,3,100,-5,5);
   
   TH2F *hEtaPtEC = new TH2F("hEtaPtEC","Eta vs MuonPt in Endcap",100,-3,3,100,0,200);
   TH2F *hEtaPtBa = new TH2F("hEtaPtBa","Eta vs MuonPt in barrel",100,-3,3,100,0,200);
   TH2F *hEtaPtAll = new TH2F("hEtaPtAll","Eta vs MuonPt Overall",100,-3,3,100,0,200);
   


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

   //TFile *f1 = new TFile("histos_signal.root","RECREATE");
   //f1->cd();
   //TTree *tree = new TTree("gemtree","variables");
   //tree->Branch("dimuoneta",&dimuoneta,"dimuoneta/D");
   //tree->Branch("dimuonratiopt",&dimuonratiopt,"dimuonratiopt/D");
   
   
   Long64_t nentries = fChain->GetEntriesFast();
   cout<<"Number of events "<<nentries<<endl;
   //int dimuon=0;
   Long64_t nbytes = 0, nb = 0;
   //for (Long64_t jentry=0;jentry<nentries;jentry++) {
   for (Long64_t jentry=0;jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     //if (nMuon!=2) continue;
     //if (abs(Muon_phi[0]-Muon_phi[1] < 2.0))continue;
     //++dimuon;
     
     
     for (int i=0;i<nMuon; i++){
       if (Muon_pt[i]<0.3) cout<<"found it"<<endl;
       RecoMuonPt=Muon_pt[i];
       RecoMuonEta=Muon_eta[i];
       GenMuonPt=Muon_ptgen[i];
       ImpParam=Muon_trkD0[i];
       MuonDZ=Muon_trkDz[i];
       MuonChi2=Muon_globalChi2[i];
     
       h1PtGen->Fill(GenMuonPt);
       h1PtReco->Fill(RecoMuonPt);
       h1EtaReco->Fill(RecoMuonEta);
       hEtaPtAll->Fill(RecoMuonEta,RecoMuonPt);
       
     }
     //f1->cd();
     //tree->Write();
     //f1->Close();
   }
   
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

