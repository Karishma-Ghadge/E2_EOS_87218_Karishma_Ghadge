#!/bin/bash

echo "Enter number: "
read number
i=1

echo "Table for $number: "
while [ $i -le 10 ]
do
	result=`expr $number \* $i`
	echo "$number x $i = $result"
	i=`expr $i + 1`
done

