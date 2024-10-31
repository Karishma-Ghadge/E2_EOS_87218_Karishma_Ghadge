#!/bin/bash

echo "Enter a number: "
read number

factorial=1
i=1

while [ $i -le $number ]
do
factorial=`expr $factorial \* $i`
i=`expr $i + 1`
done

echo "Factorial of $number is : $factorial"
