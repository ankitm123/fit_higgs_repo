void plot_dimuon_ratio(){
  h1DiMuonEtaReco->SetLineColor(1);
  

  
  h1DiMuonEtaReco->SetStats(0);
  //h1DiMuonEtaReco->SetTitle("#eta as a function of p_{T} threshold");

  h1DiMuonEtaReco->SetXTitle("Ratio of dimuon pT to scalar sum");
  h1DiMuonEtaReco->SetYTitle("Events");
  
  h1DiMuonEtaReco->Draw();
    
  /*leg_hist = new TLegend(0.6724138,0.684322,0.8520115,0.8728814);
  //leg_hist->SetHeader("Pt histograms");
  leg_hist->SetFillColor(0);
  leg_hist->AddEntry(hEtaPt10,"p_{T} > 10 GeV/c","l");
  leg_hist->AddEntry(hEtaPt15,"p_{T} > 15 GeV/c","l");
  leg_hist->AddEntry(hEtaPt20,"p_{T} > 20 GeV/c","l");
  leg_hist->AddEntry(hEtaPt25,"p_{T} > 25 GeV/c","l");
  leg_hist->AddEntry(hEtaPt30,"p_{T} > 30 GeV/c","l");
  leg_hist->AddEntry(hEtaPt35,"p_{T} > 35 GeV/c","l");
  leg_hist->Draw();*/
  c1->SaveAs("plot_pt_ratio.png");
}
