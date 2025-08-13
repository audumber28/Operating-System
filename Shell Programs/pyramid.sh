#!/bin/bash

read -p "Enter number of rows: " n

for (( i=1; i<=n; i++ ))
do
 
  for (( j=i; j<n; j++ ))
  do
    echo -n " "
  done

  for (( k=1; k<=i; k++ ))
  do
    echo -n "$i "
  done

  echo
done

