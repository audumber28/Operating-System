#!/bin/bash

echo "Simple Interest Calculator"

read -p "Enter principal amount: " principal
read -p "Enter rate of interest (in %): " rate
read -p "Enter time (in years): " time

simple_interest=$(( principal * rate * time / 100 ))

echo "Simple Interest = $simple_interest"

