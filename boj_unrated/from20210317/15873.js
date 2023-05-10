const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
    line = line.toString();
    if (line.length == 2) {
        console.log(parseInt(line[0], 10) + parseInt(line[1], 10));
    } else if (line.length == 3) {
        if (line[1] == '0') {
            console.log(parseInt(line[2], 10) + 10);
        } else {
            console.log(parseInt(line[0], 10) + 10);
        }
    } else {
        console.log(20);
    }
});

/*
공백 없는 A+B 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.5 초	512 MB	2443	1302	1168	55.094%
문제
자연수 A, B가 주어지면 A+B를 구하는 프로그램을 작성하시오.

입력
자연수 A, B (0 < A, B ≤ 10)가 첫 번째 줄에 주어진다. 단, 두 수의 사이에는 공백이 주어지지 않는다. 두 수의 앞에 불필요한 0이 붙는 경우는 없다.

출력
첫 번째 줄에 A+B의 값을 출력한다.

예제 입력 1 
37
예제 출력 1 
10
예제 입력 2 
102
예제 출력 2 
12
*/
