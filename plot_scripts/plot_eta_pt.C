void plot_eta_pt(){
  hEtaPt10->SetLineColor(8);
  hEtaPt15->SetLineColor(9);
  hEtaPt20->SetLineColor(6);
  hEtaPt25->SetLineColor(2);
  hEtaPt30->SetLineColor(5);
  hEtaPt35->SetLineColor(30);

  
  hEtaPt10->SetStats(0);
  hEtaPt10->SetTitle("|#eta| as a function of p_{T} threshold");

  hEtaPt10->SetXTitle("|#eta_{#mu}^{Reco}|");
  hEtaPt10->GetYaxis()->SetTitleOffset(1.23);  
  hEtaPt10->SetYTitle("Events/0.1");

  
  
  hEtaPt10->Draw("hist e");
  hEtaPt15->Draw("hist e SAME");
  hEtaPt20->Draw("hist e SAME");
  hEtaPt25->Draw("hist e SAME");
  hEtaPt30->Draw("hist e SAME");
  hEtaPt35->Draw("hist e SAME");

TPaveText *pt = new TPaveText(0.9856374,1222.805,1.427289,1392.754,"br");
   pt->SetBorderSize(2);
   pt->SetFillColor(0);
   TText *text = pt->AddText("0 < |#eta| < 1.5");
   text = pt->AddText("77 %");
   pt->Draw();
   
   pt = new TPaveText(1.627644,1222.805,2.076191,1392.754,"br");
   pt->SetBorderSize(2);
   pt->SetFillColor(0);
   text = pt->AddText("1.5 < |#eta| < 2.2");
   text = pt->AddText("20 %");
   pt->Draw();
   
   pt = new TPaveText(2.278276,822.805,2.7307,992.754,"br");
   pt->SetBorderSize(2);
   pt->SetFillColor(0);
   text = pt->AddText("2.2 < |#eta| < 2.4");
   text = pt->AddText("3 %");
   pt->Draw();



   leg_hist = new TLegend(0.7586207,0.6772152,0.9382184,0.8649789);
  //leg_hist->SetHeader("Pt histograms");
   leg_hist->SetBorderSize(0); 
   leg_hist->SetFillColor(0);
   leg_hist->AddEntry(hEtaPt10,"p_{T} > 10 GeV","f");
   leg_hist->AddEntry(hEtaPt15,"p_{T} > 15 GeV","f");
   leg_hist->AddEntry(hEtaPt20,"p_{T} > 20 GeV","f");
   leg_hist->AddEntry(hEtaPt25,"p_{T} > 25 GeV","f");
   leg_hist->AddEntry(hEtaPt30,"p_{T} > 30 GeV","f");
   leg_hist->AddEntry(hEtaPt35,"p_{T} > 35 GeV","f");
   leg_hist->Draw();

  TLine *line1=new TLine(1.5,0,1.5,1500);
  line1->SetLineStyle(2);
  line1->SetLineColor(9);
  line1->SetLineWidth(3);
  line1->Draw("SAME");
  
  TLine *line2=new TLine(2.2,0,2.2,1500);
  line2->SetLineStyle(2);
  line2->SetLineColor(2);
  line2->SetLineWidth(3);
  line2->Draw("SAME");
  
  TLine *line3=new TLine(2.4,0,2.4,1500);
  line3->SetLineStyle(2);
  line3->SetLineColor(8);
  line3->SetLineWidth(3);
  line3->Draw("SAME");
  
  


  c1->SaveAs("plot_eta_pt.png");

}
