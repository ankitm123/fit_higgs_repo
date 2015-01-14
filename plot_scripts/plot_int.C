void plot_int(){
  
  h1->ComputeIntegral();
  Double_t *integral = (h1->GetIntegral());
  h1->SetContent(integral);
  //TH1F *h1=1-(*h1);
  //TH1F *h1i = new TH1F("h1i","histogram with 1 as entries",100,0,60);
  //Int_t binsize=h1->GetSize();
  //for (int i=1;i<binsize-1;i++){
    //    std::cout<<i<<"\t"<<(*integral)<<endl;
    //Double_t entry=h1->GetBinContent(i);
    //h1->SetBinContent(i,1-entry);
  //}

    //c1->SaveAs("case1.png");
  
}
