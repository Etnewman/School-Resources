#!/bin/bash

echo "Example 1:"
sed -E 's/(.*)/\U\1/' names.txt
echo ""
echo "Example 2:"
sed -E 's/(.*) (.*)/\u\1 \u\2/' names.txt
echo ""
echo "Example 3:"
echo "100000000" | sed -E 's/([0-9]{3})/,\1/2g'
echo ""
echo "Example 4:"
echo "" | awk 'BEGIN {print("Start...")}; END {print("Done")}'
echo ""
echo "Example 5:"
awk '/^ed|^mary/ {print $0}' names.txt
echo "" 
echo "Example 6:"
awk '
	BEGIN {
		count=0
	};
	{
		count++;

		print(count ". " toupper(substr($2,1,1)) substr($2,2) "," toupper(substr($1,1,1)) substr($1,2))
	}
	' names.txt
echo ""
echo "Example 7:"
awk '
	BEGIN {
		FS=":";
		printf("%-20s %-5s	%-5s\n", "Login name", "User id", "Group")
	};
	{
		printf("%-20s %5d	%5d\n", $1, $3, $4)
	}
	' /etc/passwd
echo ""
echo "Example 8:"
awk 'BEGIN{printf "%'"'"'d\n", 1e8}'
