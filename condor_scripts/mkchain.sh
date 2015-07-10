#/bin/bash                                                                                                                                                                    
echo "{"
echo "TChain *fchain = new TChain(\"dyttbkg\");"
ls -all $1/histos_mva_dytt_file*.root  |  grep "Jul 10" | awk '{if ($5>1000) print $NF}' | awk '{print "fchain->Add(\""$NF"\");"}'
echo "fchain.Merge(\"$1/$2.root\");"
echo "gROOT->ProcessLine(\".q\");"
echo "}"
exit