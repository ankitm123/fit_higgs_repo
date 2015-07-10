#/bin/bash                                                                                                                                                                    
echo "{"
echo "TChain *fchain = new TChain(\"dyttbkg\");"

#for ((c=1; c<=40; c++))                   
                                                                                                                                     
#do                                                                                                                                                                            
 
#echo "fchain->Add(\""$1"/sgem_"$c"-"$2".root\");"                                                                                                                             
 
#done                                                                                                                                                                          
 
#ls -all $1/*gem*$2*.root | awk '{if ($5>1000) print $NF}' | awk '{print "fchain->Add(\""$NF"\");"}'                                                                           
 
#ls -all $1/*gem_xray*.root | awk '{if ($5>1000) print $NF}' | awk '{print "fchain->Add(\""$NF"\");"}'                                                                         
 
ls -all $1/histos_mva_dytt_file*.root  |  grep "Jul 10" | awk '{if ($5>1000) print $NF}' | awk '{print "fchain->Add(\""$NF"\");"}'
echo "fchain.Merge(\"$1/$2.root\");"
echo "gROOT->ProcessLine(\".q\");"
echo "}"
exit