void plot_imp_par_Ba(){
  hImPEC->SetLineColor(1);
  //h1PtReco->SetLineColor(4);
  //h1PtReco->SetXTitle("GeV/c");
  hImPBa->SetYTitle("Events");
  hImPBa->GetYaxis()->SetTitleOffset(1.35);
  hImPBa->SetXTitle("d_{xy} in cm");
  hImPBa->Draw();          //draw hist_2 first as it has a larger range
  hImPBa->Draw("c hist same");          //draw hist_2 first as it has a larger range
  c1->SaveAs("plot_imp_2.eps");
  c1->SaveAs("plot_imp_2.png");
  //h1PtReco->Draw("same");
  
  /*leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms");
  leg_hist->AddEntry(hImPEC,"Gen Pt","l");
  leg_hist->AddEntry(h1PtReco,"Reco Pt","l");
  leg_hist->Draw();*/
}
