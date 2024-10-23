#!/bin/bash

# find whether the no. is prime or not

echo -e -n "Enter the number: "
read num

if [ `expr $num % 2` -eq 0 ]
then 
	echo "$num is not a prime number"
else
	echo "$num is a prime number"
fi	
