#!/bin/sh
source ~/.bashrc
source /cmssoft/cms/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc472
cd /home/amohapatra/samples_gem_studies/Backgrounds/CMSSW_6_2_0_SLHC23_patch1/src/
cmsenv
sed -e 's|file.txt|'$1'|' -e 's/dytaumu_14TeV_pu0.root/dytaumu_14TeV_pu0_'$1'.root/' test_skimmer_condor.py >> test_skimmer_condor_$1.py
cmsRun test_skimmer_condor_$1.py
