#!/bin/bash

found=false

echo "Executable files in the current directory: "

for file in *
do
	if [ -x"$file" ]
	then
		echo "$file"
		found=true
	fi
done

if [ "$found" = false ]
then
	echo "No executable files found in the current working directory"
fi	
