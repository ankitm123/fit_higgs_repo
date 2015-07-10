rm -f submit_skimmer-*.jdl
rm -f test_skimmer_condor_file*.py
cp file test/
rm -f file*
cp test/file .
cp condor_vhtree_local.C condor_makeclass_local.C test/
rm condor_vhtree*.C condor_makeclass_*.C
cp test/condor_vhtree_local.C test/condor_makeclass_local.C .
rm -f vhtree_file*
rm -f *~