void plot_accept_pt_3d_graph(){
  //h2->SetLineColor(1);
  
  TTree *MyTree = new TTree("MyTree", "MyTree");
  MyTree->ReadFile("acceptance2.file", "lead:sublead:weight");
  //MyTree->SetEstimate(MyTree->GetEntries());
  MyTree->Draw("sublead:lead:weight>>htemp", "", "COLZ");
  //htemp->Rebin(0.5);
  //cout<<htemp->GetAize
  htemp->SetXTitle("Reco leading muon p_{T} in GeV/c");
  htemp->SetYTitle("Reco subleading muon p_{T} in GeV/c");
  htemp->SetTitle("2-D acceptance plot");
  htemp->SetStats(0);
  htemp->Draw("COLZ");
  c1->SaveAs("acceptance_2d_100.png");
  //gROOT->ProcessLine(".q");
}
