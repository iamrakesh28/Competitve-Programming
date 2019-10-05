#! /bin/bash
while read line
do
	echo $line | cut -d$'\t' -f1-3
	#echo "${line:1:6}"
done
#echo "${a:0:6}" 6 length content from 0th index
# | cut -c2-7
