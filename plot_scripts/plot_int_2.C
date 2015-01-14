void plot_int_2(){
  
  hLeadMuon2->ComputeIntegral();
  Double_t *integral = (hLeadMuon2->GetIntegral());
  hLeadMuon2->SetContent(integral);
  //TH1F *hLeadMuon2=1-(*hLeadMuon2);
  //TH1F *hLeadMuon2i = new TH1F("hLeadMuon2i","histogram with 1 as entries",100,0,60);
  Int_t binsize=hLeadMuon2->GetSize();
  for (int i=1;i<binsize-1;i++){
    Double_t entry=hLeadMuon2->GetBinContent(i);
    hLeadMuon2->SetBinContent(i,1-entry);
  }

  hSubLeadMuon2->ComputeIntegral();
  Double_t *integral = (hSubLeadMuon2->GetIntegral());
  hSubLeadMuon2->SetContent(integral);
  binsize=hSubLeadMuon2->GetSize();
  //hSubLeadMuon2=1-(*hSubLeadMuon2);
  for (int i=1;i<binsize-1;i++){
    entry=hSubLeadMuon2->GetBinContent(i);
    hSubLeadMuon2->SetBinContent(i,1-entry);
  }


  hLeadMuon2->SetLineColor(1);
  hSubLeadMuon2->SetLineColor(4);
  hLeadMuon2->SetXTitle("Reco Muon p_{T} in GeV/c");
  hSubLeadMuon2->SetXTitle("Reco Muon p_{T} in GeV/c");
  hLeadMuon2->SetYTitle("Kinematic Acceptance");
  hSubLeadMuon2->SetYTitle("Kinematic Acceptance");
  
  hSubLeadMuon2->Draw();
  
  hLeadMuon2->Draw("same");          //draw hist_2 first as it has a larger range
  
  
  leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms for case 2");
  leg_hist->AddEntry(hLeadMuon2,"leading muon Pt","l");
  leg_hist->AddEntry(hSubLeadMuon2,"subleading muon pt","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();

  //c1->SaveAs("case1.png");
  
}
