void plot_corr(){
  //h2->SetLineColor(1);
  TCanvas *c1 = new TCanvas("c1","c1",700,400);
  c1->Divide(2,2);
  c1->cd(1);
  h1->SetXTitle("Reco. leading muon p_{T} in GeV/c");
  h1->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  //h2->SetZTitle("Kinematic acceptance");
  //h2->GetZaxis()->SetRangeUser(0,1);
  //h2->SetStats(0);
  h1->Draw("COLZ");          //draw hist_2 first as it has a larger range
  
  c1->cd(2);
  h11->SetXTitle("Reco. leading muon p_{T} in GeV/c");
  h11->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  h11->Draw("COLZ");          //draw hist_2 first as it has a larger range
  c1->cd(3);
  h12->SetXTitle("Reco. leading muon p_{T} in GeV/c");
  h12->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  h12->Draw("COLZ");          //draw hist_2 first as it has a larger range
  c1->cd(4);
  h13->SetXTitle("Reco. leading muon p_{T} in GeV/c");
  h13->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  h13->Draw("COLZ");
            //draw hist_2 first as it has a larger range
  /*leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms for case 1 (both muons in endcap)");
  leg_hist->AddEntry(h2,"leading muon Pt","l");
  leg_hist->AddEntry(hSubLeadMuon1,"subleading muon pt","l");
  leg_hist->Draw();
  */
  
  
}
