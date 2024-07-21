# #!/bin/bash

g++ -O2 sol.cpp -o max

ans=0
for num in $(seq -w 0000 0299); do
    ./max < ./in/$num.txt > ./out/$num.txt
    line=$(tail -n 1 ./out/$num.txt) > /dev/null
    line="${line:1}"
    ans=$(($ans+$line))
    echo "$num: $line"
done
echo "Overall Score: $ans"