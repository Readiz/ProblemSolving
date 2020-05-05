const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
    const inputNumbers = line.split(' ').map(item => parseInt(item));
    if (inputNumbers.length === 1) return;

    var [x1, y1, r1, x2, y2, r2] = inputNumbers;
    // Make sure r1 is the bigger circle.
    // if r2 is bigger, make it swap.
    if (r2 > r1) [x1, y1, r1, x2, y2, r2] = [x2, y2, r2, x1, y1, r1];

    // console.log("Swap completed.");
    // console.log([x1, y1, r1, x2, y2, r2]);

    const x_d = x2 - x1;
    const y_d = y2 - y1;
    const d = Math.sqrt(x_d * x_d + y_d * y_d);

    // console.log(`Distance: ${d}`);

    // Case 1. If the origin is the same.
    if (x1 == x2 && y1 == y2) {
        // console.log("Case 1!");
        if (r1 == 0 && r2 == 0) {
            console.log(1);
        } else if (r1 == r2) {
            console.log(-1); // Same circle, Infinity
        } else {
            console.log(0);
        }
        return;
    }

    // Case 2. Normal case
    if (r1 <= d) {
        // console.log("Case 2!");
        if (r1 + r2 < d) {
            console.log(0);
        } else if (r1 + r2 == d) {
            console.log(1);
        } else {
            console.log(2);
        }
    // Case 3. Edge Case
    } else {
        // console.log("Case 3!");
        if (r1 - r2 < d) {
            console.log(2);
        } else if (r1 - r2 == d) {
            console.log(1);
        } else {
            console.log(0);
        }
    }
});
/*
문제 
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.

이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
입력 
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.
한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.
출력 
각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.


3
0 0 13 40 0 37             => 2
0 0 3 0 7 4                => 1
1 1 1 1 1 5                => 0

*/
