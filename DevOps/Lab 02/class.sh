#!/bin/bash
count=1
if [ ! $# -eq 2 ]; then
	echo "Usage: $0 File User"
	exit 0
fi
if [ ! -e $1 ]; then
	echo "Error: No such file"
	exit 0
fi
for line in `cat $1`; do
	if [ $line = $2 ]; then
		echo "The Username was found at $count"
		exit 0
	else
		testVar=0
	fi
	count=`expr $count + 1`
done
if [ $echoVar=0 ]; then
	echo "$2 was not found in $1"
fi
echo "Do you want to add a username to the list? (Y/N)"
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

