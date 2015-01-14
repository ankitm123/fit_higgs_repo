#include "TPaveStats.h"

void plot1(){
  //TCanvas *c1 = new TCanvas("c1","c1",59,80,1288,535);
  //c1->Divide(3,1);
  //c1->cd(1);
  hLeadMuon1->SetLineColor(1);
  hSubLeadMuon1->SetLineColor(4);
  hLeadMuon1->SetXTitle("Reco. Muon p_{T} in GeV/c");
  hSubLeadMuon1->SetXTitle("Reco. Muon p_{T} in GeV/c");
  hLeadMuon1->SetYTitle("Number of Events/GeV");
  hSubLeadMuon1->SetYTitle("Number of Events/GeV");
  //hSubLeadMuon1->GetXaxis()->SetTitleOffset(1.4);
  //hLeadMuon1->GetXaxis()->SetTitleOffset(1.4);

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

  leg_hist = new TLegend(0.4770115,0.6038136,0.7658046,0.7923729);
  leg_hist->SetHeader("P_{T} histograms for case 1");
  leg_hist->SetFillColor(0);
  leg_hist->AddEntry(hLeadMuon1,"leading muon p_{T}","l");
  leg_hist->AddEntry(hSubLeadMuon1,"subleading muon p_{T}","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();
  
  c1->SaveAs("case1.png");
  
}
