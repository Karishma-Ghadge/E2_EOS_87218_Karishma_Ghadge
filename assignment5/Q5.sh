#!/bin/bash

# find the greater of 3 numbers

echo -e -n "Enter the first number: "
read n1

echo -e -n "Enter the 2nd number: "
read n2

echo -e -n "Enter the third number: "
read n3

if [ $n1 -gt $n2 ]
then 
	if [ $n1 -gt $n3 ]
	then 
		echo -e -n "num1 =  $n1"
	else
		echo -e -n "num3 = $n3"
	fi	
else
	if [ $n2 -gt $n3 ]
	then
		echo -e -n "num2 = $n2"
	else
		echo -e -n " num3 = $n3"
	fi	
fi

