void plot_accept_pt_3d(){
  //hAcceptAll->SetLineColor(1);
  
  hAcceptAll->GetXaxis()->SetRangeUser(5, 30);
  hAcceptAll->GetYaxis()->SetRangeUser(5, 30);

  hAcceptAll->SetXTitle("Reco. leading muon p_{T} in GeV/c");
  hAcceptAll->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  //hAcceptAll->SetZTitle("Kinematic acceptance");
  hAcceptAll->SetStats(0);
  hAcceptAll->Draw("cont3 colz");
  //HLT_PATH Mu17_Mu8
  //gStyle->SetPalette(0,100);
  Int_t a=hAcceptAll->GetXaxis()->FindBin(17);
  Int_t b = hAcceptAll->GetYaxis()->FindBin(8);
  Double_t c = hAcceptAll->GetBinContent(a,b);
  //Double_t a = hAcceptAll->GetBinContent(hAcceptAll->GetXaxis()->FindBin(17),hAcceptAll->GetYaxis()->FindBin(8)));
  //HLT_PATH Mu13_Mu8
  //Double_t f=hAcceptAll->GetBinContent(

  //TPaletteAxis *pal = hAcceptAll->GetListOfFunctions()->FindObject("palette");
  //pal->GetAxis()->SetName("A_kin");
  
  cout<<"17-18 "<<c<<endl;

  Int_t d = hAcceptAll->GetXaxis()->FindBin(13);
  Int_t e = hAcceptAll->GetYaxis()->FindBin(8);
  Double_t f = hAcceptAll->GetBinContent(d,e);
  
  cout<<"13-18 "<<f<<endl;

  //Offline Cuts
  
  Int_t g=hAcceptAll->GetXaxis()->FindBin(20);
  Int_t h=hAcceptAll->GetYaxis()->FindBin(10);
  Double_t z=hAcceptAll->GetBinContent(g,h);
  //Double_t i=GetBinContenthAcceptAll->GetXaxis()->FindBin(20),hAcceptAll->GetYaxis()->FindBin(10));
  
  cout<<"20-10 "<<z<<endl;
  
  //Double_t m=hAcceptAll->GetBinContent(k,l);
  //draw hist_2 first as it has a larger range
  
  TLatex latex;
  //latex.DrawLatex(17,8,TString::Format("#bullet %f ",a));
  //latex.DrawLatex(17,8,TString::Format("#bullet %2f %",c*100));
  latex.DrawLatex(17,8,"#bullet 62%");
  latex.DrawLatex(13,8,"#diamond 71%");
  latex.DrawLatex(20,10,"#color[2]{#bullet} 42%");
  //latex.DrawLatex(17,8,TString::Format("%f",c));
  //latex.DrawLatex(17,8,TString::Format("%f",c));
  //latex.DrawLatex(13,8,TString::Format("#diamond %f ",f));
  
  //latex.DrawLatex(20,10,TString::Format("#circ %f ",i));
  
  latex.DrawLatex(3,22,"#bullet");
  latex.DrawLatex(2.83,25,"#diamond");
  
  
  
  latex.DrawLatex(4,28,"#scale[0.8]{HLT Paths(Run-1)}");
  latex.DrawLatex(4,22,"#scale[0.8]{Mu17_Mu8 (Luminosity 19.1 fb^{-1})}");
  latex.DrawLatex(4,25,"#scale[0.8]{Mu13_Mu8 (Luminosity 3.7 fb^{-1})}");
  
  latex.DrawLatex(4,19,"#scale[0.8]{Offline selection}");
  latex.DrawLatex(3,16,"#color[2]{#bullet}");
  latex.DrawLatex(4,16,"#scale[0.8]{Mu20_Mu10}");
  
  


  
  c1->SaveAs("acceptance_2d_all_cont3.png");
  c1->SaveAs("acceptance_2d_all_cont3.eps");
  
  /*leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms for case 1 (both muons in endcap)");
  leg_hist->AddEntry(hAcceptAll,"leading muon Pt","l");
  leg_hist->AddEntry(hSubLeadMuon1,"subleading muon pt","l");
  leg_hist->Draw();
  */
  
  
}
