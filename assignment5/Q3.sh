#!/bin/bash

read -p "Enter a name(file or directory): " name

if [ -f "$name" ]
then
	echo "$name is a file"
	echo "File size: $(stat -c%s "name") bytes"
elif [ -d "$name" ]
then
	echo "$name is a directory"
	echo "Contents: "
	ls "$name"
else
	echo "$name is neither a file nor a directory"
fi	
