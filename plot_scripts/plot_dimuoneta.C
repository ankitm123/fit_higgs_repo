#include "TPaveStats.h"

void plot_dimuoneta(){
  //TCanvas *c1 = new TCanvas("c1","c1",59,80,1288,535);
  //c1->Divide(3,1);
  //c1->cd(1);
  h1DiMuonEtaReco->SetLineColor(1);
  
  h1DiMuonEtaReco->SetXTitle("Reco. Muon #eta");
  
  h1DiMuonEtaReco->SetYTitle("Number of Events/GeV");
  
  //h1SumMuonPtReco->GetXaxis()->SetTitleOffset(1.4);
  //h1DiMuonPtReco->GetXaxis()->SetTitleOffset(1.4);

  //h1SumMuonPtReco->Draw();
  //gPad->Update();
  


  /*  TPaveStats *tps1 = (TPaveStats*) h1DiMuonEtaReco->FindObject("stats");
  tps1->SetName("Hist1 Stats");
  double X1 = tps1->GetX1NDC();
  double Y1 = tps1->GetY1NDC();
  double X2 = tps1->GetX2NDC();
  double Y2 = tps1->GetY2NDC();
  */
    
  
  h1DiMuonEtaReco->Draw();
  

  
  //tps1->Draw("same");

  c1->SaveAs("muoneta.png");
  
}
