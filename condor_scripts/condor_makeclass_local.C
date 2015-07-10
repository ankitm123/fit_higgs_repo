void condor_makeclass_local(){
  gROOT->ProcessLine("TFile f(\"/home/amohapatra/ankit_storage/gem_physics/DYTauMu_PU0/dytaumu_14TeV_pu0_local.root\")");
  gROOT->ProcessLine("treeCreator->cd()");
  gROOT->ProcessLine("vhtree->MakeClass(\"vhtree_local\")");
  gROOT->ProcessLine(".! cp vhtree.C vhtree_local.C");
  gROOT->ProcessLine(".! sed -i 's|histos_mva_dytt.root|histos_mva_dytt_local.root|g' vhtree_local.C");
  gROOT->ProcessLine(".! sed -i 's|vhtree|vhtree_local|g' vhtree_local.C");
  gROOT->ProcessLine(".q");
}
