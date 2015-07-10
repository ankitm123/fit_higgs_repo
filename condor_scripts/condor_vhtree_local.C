void condor_vhtree_local(){
  gROOT->ProcessLine(".L vhtree_local.C");
  gROOT->ProcessLine("vhtree_local gem");
  gROOT->ProcessLine("gem.Loop()");
  gROOT->ProcessLine(".q");
}
