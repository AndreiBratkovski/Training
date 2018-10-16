#!/bin/bash

# Very slow version of primeregbs.c

START=$(date +%s.%N)
count=0

for((number=2;count<${1};number++))
do
    check=1
    sqrt=`bc <<< "sqrt($number)"`
    for((factor=2;factor<=sqrt;factor++))
    do 
        if [ `expr $number % $factor` -eq 0 ]
            then
                check=0
                break
        fi
    done
    
    if [ $check -eq 1 ]
        then
        printf "$number " >&2
        count=$((count+1))
    fi
done
echo ""
DIFF=$(echo "$(date +%s.%N) - $START" | bc)
printf "%8.4lf\n" $DIFF
