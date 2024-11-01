#!/bin/bash

rows=5
i=1

while [ $i -le $rows ]
do

j=1
while [ $j -le $i ]
do
	echo -n "* "
	j=`expr $j + 1`
done
echo " "
i=`expr $i + 1`
done
