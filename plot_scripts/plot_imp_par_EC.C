void plot_imp_par_EC(){
  hImPEC->SetLineColor(1);
  //h1PtReco->SetLineColor(4);
  //h1PtReco->SetXTitle("GeV/c");
  hImPEC->SetXTitle("d_{xy} in cm");
  hImPEC->GetYaxis()->SetTitleOffset(1.3);
  hImPEC->SetYTitle("Events");
  hImPEC->Draw();          //draw hist_2 first as it has a larger range
  hImPEC->Draw("c hist same");          //draw hist_2 first as it has a larger range
  c1->SaveAs("plot_imp_1.eps");
  c1->SaveAs("plot_imp_1.png");
  //h1PtReco->Draw("same");
  
  /*leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms");
  leg_hist->AddEntry(hImPEC,"Gen Pt","l");
  leg_hist->AddEntry(h1PtReco,"Reco Pt","l");
  leg_hist->Draw();*/
}
