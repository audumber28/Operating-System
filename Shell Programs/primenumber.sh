#!/bin/bash

read -p "Enter a number (n): " n

echo "Prime numbers up to $n are:"

for (( num=2; num<=n; num++ ))
do
  is_prime=1 

  for (( i=2; i*i<=num; i++ ))
  do
    if (( num % i == 0 )); then
      is_prime=0 
      break
    fi
  done

  if (( is_prime == 1 )); then
    echo "$num"
  fi
done

