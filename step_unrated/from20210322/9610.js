const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;
let N = 0;
rl.on('line', (line) => {
    if (N === 0) {
        N = parseInt(line.toString(), 10);
        return;
    }
    N--;
    const [a, b] = line.toString().split(' ').map(_=>parseInt(_,10));
    if (a === 0 || b === 0) {
        axis++;
    }
    if (a > 0 && b > 0) {
        q1++;
    }
    if (a < 0 && b > 0) {
        q2++;
    }
    if (a < 0 && b < 0) {
        q3++;
    }
    if (a > 0 && b < 0) {
        q4++;
    }
    if (N === 0) {
        console.log(`Q1: ${q1}`);
        console.log(`Q2: ${q2}`);
        console.log(`Q3: ${q3}`);
        console.log(`Q4: ${q4}`);
        console.log(`AXIS: ${axis}`);
        process.exit();
    }
});


/*
사분면 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	3049	2109	1937	72.330%
문제
2차원 좌표 상의 여러 점의 좌표 (x,y)가 주어졌을 때, 각 사분면과 축에 점이 몇 개 있는지 구하는 프로그램을 작성하시오.



입력
첫째 줄에 점의 개수 n (1 ≤ n ≤ 1000)이 주어진다. 다음 n개 줄에는 점의 좌표 (xi, yi)가 주어진다. (-106 ≤ xi, yi ≤ 106)

출력
각 사분면과 축에 점이 몇 개 있는지를 예제 출력과 같은 형식으로 출력한다.

예제 입력 1 
5
0 0
0 1
1 1
3 -3
2 2
예제 출력 1 
Q1: 2
Q2: 0
Q3: 0
Q4: 1
AXIS: 2
*/
