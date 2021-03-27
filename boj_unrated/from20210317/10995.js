const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
    const num = parseInt(line.toString(), 10);
    for (let i = 0; i < num; i++) {
        let line = (i % 2 == 1) ? ' ' : '';
        for (let j = 0; j < num; j++) {
            line += '* ';
        }
        console.log(line);
    }
    process.exit();
});


/*
별 찍기 - 20 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	4607	3879	3598	85.301%
문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 차례대로 별을 출력한다.

예제 입력 1 
1
예제 출력 1 
*
예제 입력 2 
2
예제 출력 2 
* *
 * *
예제 입력 3 
3
예제 출력 3 
* * *
 * * *
* * *
예제 입력 4 
4
예제 출력 4 
* * * *
 * * * *
* * * *
 * * * *
*/
