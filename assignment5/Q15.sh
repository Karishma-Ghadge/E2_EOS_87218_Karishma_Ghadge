#!/bin/bash

echo " Enter the first filename: "
read file1

echo " Enter the 2nd filename: "
read file2

if [ ! -f "$file1" ]
then
	echo "File '$file1' does not exist"
	exit 1
fi

while IFS= read -r line
do
	echo "$line" | tr '[:lower:][:upper:]' '[:upper:][:lower:]' >> "$file2"
	done <"$file1"
	echo "Contents of '$file' in reverse case have been appended to '$file2'"

