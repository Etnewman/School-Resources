#!/bin/bash
echo "Enter your Name:"
read name
echo "$name" > $$.name
cat $$.name
