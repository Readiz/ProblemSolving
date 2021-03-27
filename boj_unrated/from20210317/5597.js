const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let count = 0;
let memo = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
rl.on('line', (line) => {
    const num = parseInt(line.toString(), 10);
    memo[num]++;
    count++;
    if (count === 28) {
        for (let i = 1; i <= 30; i++) {
            if (memo[i] === 0) {
                console.log(i);
            }
        }
        process.exit();
    }
});

/*
과제 안 내신 분..? 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	7357	4855	4425	67.423%
문제
X대학 M교수님은 프로그래밍 수업을 맡고 있습니다. 교실엔 학생이 30명이 있는데, 학생 명부엔 각 학생별로 1번부터 30번까지 출석번호가 붙어 있습니다.

교수님이 내준 특별과제를 28명이 제출했는데, 그 중에서 제출 안 한 학생 2명의 출석번호를 구하는 프로그램을 작성하세요.
*/
