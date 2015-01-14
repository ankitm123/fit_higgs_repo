void plot_int_2d_1(){
  TH3F *h2 = new TH3F("h2","acceptance plot",100,0,60,100,0,60,100,0,1);  
  Double_t weight=0.;
  hLeadMuon1->ComputeIntegral();
  Double_t *integral = (hLeadMuon1->GetIntegral());
  hLeadMuon1->SetContent(integral);
  Int_t binsize=hLeadMuon1->GetSize();
  for (int i=1;i<binsize-1;i++){
    Double_t entry=hLeadMuon1->GetBinContent(i);
    hLeadMuon1->SetBinContent(i,1-entry);
  }

  hSubLeadMuon1->ComputeIntegral();
  Double_t *integral = (hSubLeadMuon1->GetIntegral());
  hSubLeadMuon1->SetContent(integral);
  binsize=hSubLeadMuon1->GetSize();
  
  for (int i=1;i<binsize-1;i++){
    entry=hSubLeadMuon1->GetBinContent(i);
    hSubLeadMuon1->SetBinContent(i,1-entry);
  }
  
  for (int i=1;i<leadmuonpt.size();i++){
    for (int j=1;j<subleadmuonpt.size();j++){
      weight=0;
      int k=hleadMuon1->GetXaxis()->FindBin(leadmuonpt[i]);
      int m=hSubLeadMuon1->GetXaxis()->FindBin(subleadmuonpt[j]);
      if (hLeadMuon1->GetBinContent(k) < hSubLeadMuon1->GetBinContent(m))
	weight=hLeadMuon1->GetBinContent(k);
      else if (hLeadMuon1->GetBinContent(k) > hSubLeadMuon1->GetBinContent(m))
	weight=hSubLeadMuon1->GetBinContent(m);
      else
	weight=hSubLeadMuon1->GetBinContent(m);
      h2->Fill(leadmuonpt[i],subleadmuonpt[j],weight);
    }
  }
}
