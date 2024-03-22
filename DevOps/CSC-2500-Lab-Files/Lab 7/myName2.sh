#!/bin/bash

echo "Enter your Name:"
echo
read name
echo "$name" > $$.name
cat $$.name
