#!/bin/bash

filename=$1

if [ -e "$filename" ]
then
mod_time=$(stat -c%y "$filename")
    echo "Last modification time of '$filename' : $mod_time"
else
	echo "File '$filename' does not exist"
fi	
