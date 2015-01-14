void plot_int_3(){
  
  hLeadMuon3->ComputeIntegral();
  Double_t *integral = (hLeadMuon3->GetIntegral());
  hLeadMuon3->SetContent(integral);
  //TH1F *hLeadMuon3=1-(*hLeadMuon3);
  //TH1F *hLeadMuon3i = new TH1F("hLeadMuon3i","histogram with 1 as entries",100,0,60);
  Int_t binsize=hLeadMuon3->GetSize();
  for (int i=1;i<binsize-1;i++){
    Double_t entry=hLeadMuon3->GetBinContent(i);
    hLeadMuon3->SetBinContent(i,1-entry);
  }

  hSubLeadMuon3->ComputeIntegral();
  Double_t *integral = (hSubLeadMuon3->GetIntegral());
  hSubLeadMuon3->SetContent(integral);
  binsize=hSubLeadMuon3->GetSize();
  //hSubLeadMuon3=1-(*hSubLeadMuon3);
  for (int i=1;i<binsize-1;i++){
    entry=hSubLeadMuon3->GetBinContent(i);
    hSubLeadMuon3->SetBinContent(i,1-entry);
  }


  hLeadMuon3->SetLineColor(1);
  hSubLeadMuon3->SetLineColor(4);
  hLeadMuon3->SetXTitle("Reco Muon p_{T} in GeV/c");
  hSubLeadMuon3->SetXTitle("Reco Muon p_{T} in GeV/c");
  hLeadMuon3->SetYTitle("Kinematic Acceptance");
  hSubLeadMuon3->SetYTitle("Kinematic Acceptance");
  
  hSubLeadMuon3->Draw();
  
  hLeadMuon3->Draw("same");          //draw hist_2 first as it has a larger range
  
  
  leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms for case 3");
  leg_hist->AddEntry(hLeadMuon3,"leading muon Pt","l");
  leg_hist->AddEntry(hSubLeadMuon3,"subleading muon pt","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();

  //c1->SaveAs("case1.png");
  
}
