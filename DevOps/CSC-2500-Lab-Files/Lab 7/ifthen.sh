#!/bin/bash

echo ">>"
read name
if [ ! -z "$name" ]; then
	echo "You entered: $name"
else
	echo "What is your input ?"
fi
