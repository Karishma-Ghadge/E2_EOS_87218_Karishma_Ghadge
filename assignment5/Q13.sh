#!/bin/bash

found=false

echo "hidden files in the current directory:  "

for file in .[^.]*
do
if [ -e "$file" ]
then
    echo "$file"
    found=true
fi
done

if [ "$found" = false ]
then
	echo "no hidden files found"
fi

