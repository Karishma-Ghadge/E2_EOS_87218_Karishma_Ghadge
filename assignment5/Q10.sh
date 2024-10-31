#!/bin/bash

echo "Enter a number: "
read n

a=0
b=1

echo "Fibonacci series up to $n terms: "
while [ $i -lt $n ]
do
	echo -n "$a "
	fn=`expr $a + $b`
	a=$b
	b=$fn
	i=`expr $i + 1`
done

echo " "
