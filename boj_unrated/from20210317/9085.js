const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
let idx = 0;
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        return;
    }
    if (++idx % 2 == 1) return;
    console.log(line.toString().split(' ').map(_ => parseInt(_, 10)).reduce((_, i) => { return _ + i}));
});

/*
더하기 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	5328	4050	3756	77.507%
문제
10보다 작거나 같은 자연수 N개를 주면 합을 구하는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 첫 줄에 자연수의 개수 N(1 ≤ N ≤ 100)이 주어지고, 그 다음 줄에는 N개의 자연수가 주어진다. 각각의 자연수 사이에는 하나씩의 공백이 있다.

출력
각 테스트 케이스에 대해서 주어진 자연수의 합을 한 줄에 하나씩 출력한다.

예제 입력 1 
2
5
1 1 1 1 1
7
1 2 3 4 5 6 7
예제 출력 1 
5
28
*/
