#!/bin/bash

echo -e "Enter your choice: "
echo  "1.Date"
echo  "2.Cal"
echo  "3.Ls"
echo  "4.pwd"
echo "5.Exit"

read -p "Please enter your choice: " choice

case $choice in
1) date
	;;
2) cal
	;;
3) ls
	;;
4)	pwd
	;;
5)	echo "Exit.."
    break
	;;
*)  echo "Invalid choice"
	;;
esac
echo " "



