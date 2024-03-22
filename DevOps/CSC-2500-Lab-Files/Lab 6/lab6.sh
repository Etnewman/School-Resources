nvim#!/bin/bash
count=1
if [ ! $# -eq 2 ]; then
	echo "Usage: $0 File User"
	exit 0
fi
if [ ! -e $1 ]; then
	echo "Error: No such file exists"
	exit 0
fi
for line in `cat $1`; do
	if [ $line = $2 ]; then 
		echo "The username was found at $count"
		exit 0
	fi
	count=`expr $count + 1`
done
	echo "Do you want a username to the list?(Y/N)"
	read ans
	ans=`echo $ans | tr [a-z] [A-Z]`

if [ $ans = 'Y' ]; then
	echo $2 >> $1
	exit 0
fi
if [ $ans = 'N' ]; then
	echo "No user was added to the file"
	exit 0
fi
