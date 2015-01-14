void plotres1(){
  hMCMatchEC->SetLineColor(1);
  //h1PtReco->SetLineColor(4);
  //h1PtReco->SetXTitle("GeV/c");
  hMCMatchEC->GetYaxis()->SetTitleOffset(1.3);
  hMCMatchEC->SetYTitle("Events");
  hMCMatchEC->SetXTitle("p_{T}^{gen}-p_{T}^{reco}/p_{T}^{gen}");
  hMCMatchEC->GetXaxis()->SetTitleOffset(1.1);  
  hMCMatchEC->Draw();          //draw hist_2 first as it has a larger range
  hMCMatchEC->Draw("c hist same");          //draw hist_2 first as it has a larger range
  c1->SaveAs("plot_res_1.eps");
  c1->SaveAs("plot_res_1.png");
  //h1PtReco->Draw("same");
  
  /*leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms");
  leg_hist->AddEntry(hMCMatchEC,"Gen Pt","l");
  leg_hist->AddEntry(h1PtReco,"Reco Pt","l");
  leg_hist->Draw();*/
}
