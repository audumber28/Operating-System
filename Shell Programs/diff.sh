echo "Enter a number"
read num
max=0
min=9
temp=$num

while [ $temp -gt 0 ]
do
    digit=$((temp % 10))
    if [ $digit -gt $max ]; then
        max=$digit
    fi
    if [ $digit -lt $min ]; then
        min=$digit
    fi
    temp=$((temp / 10))
done
echo "max: $max"
echo "min: $min"


diff=$((max - min))
echo "Difference between largest and smallest digit is: $diff"

