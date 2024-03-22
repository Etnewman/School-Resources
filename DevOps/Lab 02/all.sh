#!/bin/bash
echo "Calling Program: $0"
echo "Number of Positional Parameter: $#"
for i in $@; do
	echo $i
done
