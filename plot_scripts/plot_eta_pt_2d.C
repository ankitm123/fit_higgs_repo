void plot_eta_pt_2d(){
  hEtaPtAll->SetXTitle("|#eta_{#mu}^{Reco}|");
  hEtaPtAll->SetYTitle("Reco Muon p_{T} in GeV/c");
  hEtaPtAll->SetStats(0);
  hEtaPtAll->Draw("COLZ");
  c1->SaveAs("plot_eta_pt_2d.png");
}
