void plot2(){
  hMC
  h1PtGen->SetLineColor(1);
  h1PtReco->SetLineColor(4);
  h1PtReco->SetXTitle("GeV/c");
  h1PtGen->SetXTitle("GeV/c");
  h1PtGen->Draw();          //draw hist_2 first as it has a larger range
  h1PtReco->Draw("same");
  
  leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms");
  leg_hist->AddEntry(h1PtGen,"Gen Pt","l");
  leg_hist->AddEntry(h1PtReco,"Reco Pt","l");
  leg_hist->Draw();
}
