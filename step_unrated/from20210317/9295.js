const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
let N = 0;
let i = 0;
rl.on('line', (line) => {
    if (N === 0 && isFirst) {
        const num = parseInt(line.toString(), 10);
        N = num;
        isFirst = false;
        return;
    }
    N--;
    const [a, b] = line.toString().split(' ').map(_ => parseInt(_, 10));
    console.log(`Case ${++i}: ${a + b}`);
    if (N === 0) {
        process.exit();
    }
});


/*
주사위 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	2740	2044	1895	76.135%
문제
오늘은 갑자기 주사위를 던지고 싶다.

그런데 코딩도 하고 싶다.

그럼 같이할까?

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 주사위를 두 번 던져 나온 두 수를 입력한다.

출력
각 테스트 케이스마다 "Case x: "를 출력한 다음, 주사위를 두 번 던져 나온 두 수의 합을 출력한다. 테스트 케이스 번호(x)는 1부터 시작한다.

예제 입력 1 
5
1 2
1 3
3 5
2 6
3 4
예제 출력 1 
Case 1: 3
Case 2: 4
Case 3: 8
Case 4: 8
Case 5: 7
*/
