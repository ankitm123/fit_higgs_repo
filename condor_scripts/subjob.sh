#!/bin/bash
echo -n "Enter the name of the file which you got after running the trick.sh file (exact path name)"
read text
echo "You entered: $text"
lines=$(cat $text | wc -l)
echo "Number of input files: $lines"
echo "How do you want to divide them? (if they have 200 lines/files, enter 50 to have 4 files with 50 files in them)"
read number
awk '{filename = "file"  int((NR-1)/'$number'); print >> filename}' $text
loop_index=$((lines/number))
echo $loop_index
for((i=0;i<=loop_index;i++))
do
    sed -e 's/file/file'$i'/' submit_skimmer >> submit_skimmer-$i.jdl
    condor_submit submit_skimmer-$i.jdl
done
