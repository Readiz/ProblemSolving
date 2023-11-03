#!/bin/bash
ans=0
for num in $(seq -w 0000 0099); do
    ./A_Balancing_by_Balance < ../input/$num.txt > ../result/$num.txt
    line=$(tail -n 1 ../result/$num.txt) > /dev/null
    line="${line:1}"
    ans=$(($ans+$line))
    echo "$num: $line"
done
echo "Overall Score: $ans"