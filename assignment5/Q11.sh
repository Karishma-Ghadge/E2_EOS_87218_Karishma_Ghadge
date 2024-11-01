#!/bin/bash

echo "Enter the basic salary: "
read basic_salary

DA=$(echo "$basic_salary * 0.40" | bc)
echo "DA : $DA"
HRA=$(echo "$basic_salary * 0.20" | bc)
echo "HRA : $HRA"

gross_salary=$(echo "$basic_salary + $DA + $HRA" | bc)

echo "Gross salary: $gross_salary"
