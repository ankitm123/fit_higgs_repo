void ratio(){
  TFile* f1= new TFile("histos_signal.root");
  TH1F *h1=(TH1F*)f1->Get("h1DiMuonEtaReco");
  
  TFile* f2=new TFile("/home/amohapatra/work/CMSSW_6_2_0_SLHC12/src/bkg_dymu_pu_50/histos_bkg.root");
  TH1F *h2=(TH1F*)f2->Get("h1DiMuonEtaReco");
  //h2->Draw("COLZ");
  //TH2F *h3 = new TH2F("h3","S/B acceptance plot ",120,0,30,102,0,30);
    
  h1->SetLineColor(1);
  h2->SetLineColor(4);


  h1->SetStats(0);  
  h2->SetStats(0);  
  h1->SetTitle("Dimuon Eta");
  h1->SetXTitle("Dimuon Eta for reco muons");
  //h1->GetXaxis()->SetTitleOffset(1.44);
  h1->SetYTitle("Events");
  //h1->GetYaxis()->SetTitleOffset(1.44);
  //h1->SetZTitle("Ratio");
  
  h1->Draw();
  h2->Draw("SAME");
  
  leg_hist = new TLegend(0.4770115,0.6038136,0.7658046,0.7923729);
  leg_hist->SetFillColor(0);
  leg_hist->AddEntry(h1,"Signal","l");
  leg_hist->AddEntry(h2,"Background","l");
  leg_hist->SetTextSize(0.03);
  leg_hist->Draw();


  c1->SaveAs("dimuon_eta.png");
  //h2->Draw("SAME");
}
  
  
  
