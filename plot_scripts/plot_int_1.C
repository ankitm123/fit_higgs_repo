void plot_int_1(){
  
  hLeadMuon1->ComputeIntegral();
  Double_t *integral = (hLeadMuon1->GetIntegral());
  hLeadMuon1->SetContent(integral);
  //TH1F *hLeadMuon1=1-(*hLeadMuon1);
  //TH1F *hLeadMuon1i = new TH1F("hLeadMuon1i","histogram with 1 as entries",100,0,60);
  Int_t binsize=hLeadMuon1->GetSize();
  for (int i=1;i<binsize-1;i++){
    //    std::cout<<i<<"\t"<<(*integral)<<endl;
    Double_t entry=hLeadMuon1->GetBinContent(i);
    hLeadMuon1->SetBinContent(i,1-entry);
  }

  hSubLeadMuon1->ComputeIntegral();
  Double_t *integral = (hSubLeadMuon1->GetIntegral());
  hSubLeadMuon1->SetContent(integral);
  binsize=hSubLeadMuon1->GetSize();
  //hSubLeadMuon1=1-(*hSubLeadMuon1);
  for (int i=1;i<binsize-1;i++){
    entry=hSubLeadMuon1->GetBinContent(i);
    hSubLeadMuon1->SetBinContent(i,1-entry);
  }


  hLeadMuon1->SetLineColor(1);
  hSubLeadMuon1->SetLineColor(4);
  hLeadMuon1->SetXTitle("Reco Muon p_{T} in GeV/c");
  hSubLeadMuon1->SetXTitle("Reco Muon p_{T} in GeV/c");
  hLeadMuon1->SetYTitle("kinematic acceptance");
  hSubLeadMuon1->SetYTitle("kinematic acceptance");
  
  hSubLeadMuon1->Draw();
  
  hLeadMuon1->Draw("same");          //draw hist_2 first as it has a larger range
  
  
  leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms for case 1");
  leg_hist->AddEntry(hLeadMuon1,"leading muon p_{T}","l");
  leg_hist->AddEntry(hSubLeadMuon1,"subleading muon p_{T}","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();

  //c1->SaveAs("case1.png");
  
}
