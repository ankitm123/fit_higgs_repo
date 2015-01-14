#include "TPaveStats.h"

void plot_dimuoneta(){
  //TCanvas *c1 = new TCanvas("c1","c1",59,80,1288,535);
  //c1->Divide(3,1);
  //c1->cd(1);
  h1DiMuonPtReco->SetLineColor(1);
  h1SumMuonPtReco->SetLineColor(4);
  h1DiMuonPtReco->SetXTitle("Reco. Muon p_{T} in GeV/c");
  h1SumMuonPtReco->SetXTitle("Reco. Muon p_{T} in GeV/c");
  h1DiMuonPtReco->SetYTitle("Number of Events/GeV");
  h1SumMuonPtReco->SetYTitle("Number of Events/GeV");
  //h1SumMuonPtReco->GetXaxis()->SetTitleOffset(1.4);
  //h1DiMuonPtReco->GetXaxis()->SetTitleOffset(1.4);

  h1SumMuonPtReco->Draw();
  gPad->Update();
  h1DiMuonPtReco->Draw();          //draw hist_2 first as it has a larger range
  gPad->Update();


  TPaveStats *tps1 = (TPaveStats*) h1DiMuonPtReco->FindObject("stats");
  tps1->SetName("Hist1 Stats");
  double X1 = tps1->GetX1NDC();
  double Y1 = tps1->GetY1NDC();
  double X2 = tps1->GetX2NDC();
  double Y2 = tps1->GetY2NDC();

  TPaveStats *tps2 = (TPaveStats*) h1SumMuonPtReco->FindObject("stats");
  tps2->SetTextColor(kRed);
  tps2->SetLineColor(kRed);
  tps2->SetX1NDC(X1);
  tps2->SetX2NDC(X2);
  tps2->SetY1NDC(Y1-(Y2-Y1));
  tps2->SetY2NDC(Y1);

  
  
  h1DiMuonPtReco->Draw();
  h1SumMuonPtReco->Draw("same");          //draw hist_2 first as it has a larger range

  tps2->Draw("same");
  tps1->Draw("same");

  leg_hist = new TLegend(0.4770115,0.6038136,0.7658046,0.7923729);
  leg_hist->SetHeader("p_{T} histograms");
  leg_hist->SetFillColor(0);
  leg_hist->AddEntry(h1DiMuonPtReco,"Di muon p_{T}","l");
  leg_hist->AddEntry(h1SumMuonPtReco,"Sum of the muon p_{T}","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();
  
  c1->SaveAs("muonpt.png");
  
}
