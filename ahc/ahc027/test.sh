#!/bin/bash
ans=0
for num in $(seq -w 0000 1000); do
    ./A_Recurring_Cleaning_Route.bin < ./in/$num.txt > ./output/$num.txt
    line=$(tail -n 1 ./output/$num.txt) > /dev/null
    #line="${line:1}"
    ans=$(($ans+$line))
    echo "$num: $line"
done
echo "Overall Score: $ans"