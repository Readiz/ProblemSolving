const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (inputLine) => {
    const N = parseInt(inputLine.toString(), 10);
    let line = '';
    for (let l = 0; l < N - 1; l++) {
        line = '';
        for (let i = N - l - 2; i >= 0; i--) {
            line += ' ';
        }
        line += '*';
        for (let i = 1; i < l * 2; i++) {
            line += ' ';
        }
        if (N >= 3 && l != 0) line += '*';
        console.log(line);
    }
    line = '';
    for (let i = 0; i < N * 2 - 1; i++) {
        line += '*';
    }
    console.log(line);
});

/*
별 찍기 - 17 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	10545	7094	6517	68.687%
문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

예제 입력 1 
1
예제 출력 1 
*
예제 입력 2 
2
예제 출력 2 
 *
***
예제 입력 3 
3
예제 출력 3 
  *
 * *
*****
예제 입력 4 
4
예제 출력 4 
   *
  * *
 *   *
*******
*/
