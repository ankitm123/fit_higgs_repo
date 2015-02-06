./copyfile.sh > copy.sh
sed -e "s|Pythia6_Tauola_GluGluH_tautau_mumu_14TeV_RECOSIM_2019_private_standardpat//cms/data/store/user/amohapat/||" copy.sh >> copy_1.sh ; mv copy_1.sh copy.sh
chmod +x copy.sh
source copy.sh
