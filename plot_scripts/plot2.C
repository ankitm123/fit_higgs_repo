void plot2(){
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

  leg_hist = new TLegend(0.4770115,0.6038136,0.7658046,0.7923729);
  leg_hist->SetHeader("Pt histograms for case 2");
  leg_hist->SetFillColor(0);
  leg_hist->AddEntry(hLeadMuon2,"leading muon Pt","l");
  leg_hist->AddEntry(hSubLeadMuon2,"subleading muon pt","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();

  c1->SaveAs("case2.png");
  

}
