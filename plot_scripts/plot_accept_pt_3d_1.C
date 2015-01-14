void plot_accept_pt_3d_1(){
  //hAccept1->SetLineColor(1);
  
     hAccept1->SetXTitle("Reco. leading muon p_{T} in GeV/c");
     hAccept1->SetYTitle("Reco. subleading muon p_{T} in GeV/c");
  //hAccept1->SetZTitle("Kinematic acceptance");
     hAccept1->SetStats(0);
     hAccept1->Draw("cont3 colz");
   //HLT_PATH Mu17_Mu8
   
     Int_t a=hAccept1->GetXaxis()->FindBin(17);
     Int_t b = hAccept1->GetYaxis()->FindBin(8);
     Double_t c = hAccept1->GetBinContent(a,b);
     cout<<"17-18 "<<c<<endl;
     //Double_t a = hAccept1->GetBinContent(hAccept1->GetXaxis()->FindBin(17),hAccept1->GetYaxis()->FindBin(8)));
   //HLT_PATH Mu13_Mu8
   //Double_t f=hAccept1->GetBinContent(
     Int_t d = hAccept1->GetXaxis()->FindBin(13);
     Int_t e = hAccept1->GetYaxis()->FindBin(8);
     Double_t f = hAccept1->GetBinContent(d,e);
     cout<<"13-18 "<<f<<endl;
     //Offline Cuts
  
     Int_t g=hAccept1->GetXaxis()->FindBin(20);
     Int_t h=hAccept1->GetYaxis()->FindBin(10);
     Double_t z=hAccept1->GetBinContent(g,h);
     cout<<"20-10 "<<z<<endl;
  //Double_t i=GetBinContenthAccept1->GetXaxis()->FindBin(20),hAccept1->GetYaxis()->FindBin(10));

  
  
  //Double_t m=hAccept1->GetBinContent(k,l);
  //draw hist_2 first as it has a larger range
  
     TLatex latex;
  //latex.DrawLatex(17,8,TString::Format("#bullet %f ",a));
  //latex.DrawLatex(17,8,TString::Format("#bullet %2f %",c*100));
     latex.DrawLatex(17,8,"#bullet 64%");
     latex.DrawLatex(13,8,"#diamond 72%");
     latex.DrawLatex(20,10,"#color[2]{#bullet} 45%");
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
     
     c1->SaveAs("acceptance_2d_1.png");  
     c1->SaveAs("acceptance_2d_1.eps");  
   

  
  /*leg_hist = new TLegend(0.5,0.6,0.79,0.79);
  leg_hist->SetHeader("Pt histograms for case 1 (both muons in endcap)");
  leg_hist->AddEntry(hAccept1,"leading muon Pt","l");
  leg_hist->AddEntry(hSubLeadMuon1,"subleading muon pt","l");
  leg_hist->Draw();
  */
  
  
}
