ls -ltr $1/| grep root | awk '{print ""$NF""}' > file
sed 's/^/file:/' file > newfile ; mv newfile file
sed -e "s|file:|file:$1|g" file > file1; mv file1 file
#sed -e "s/\(.*\)/'\1'/" file > file1; mv file1 file
#sed 's/$/,/' file > file1; mv file1 file
#xargs <file1 | sed -e "s|file:|file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/|g" > file