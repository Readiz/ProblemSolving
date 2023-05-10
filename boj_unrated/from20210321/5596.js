const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let max = -1;
rl.on('line', (line) => {
    N++;
    const sum = line.toString().split(' ').map(_ => parseInt(_, 10)).reduce((_, i) => _ + i);
    if (sum > max) max = sum;
    if (N === 2) {
        console.log(max);
        process.exit();
    }
});


/*
시험 점수 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	4233	3470	3265	83.482%
문제
대한고등학교에 재학 중인 민국이와 만세는 4과목(정보, 수학, 과학, 영어)에 대한 시험을 봤습니다. 민국이와 만세가 본 4과목의 점수를 입력하면, 민국이의 총점 S와 만세의 총점 T 중에서 큰 점수를 출력하는 프로그램을 작성하세요. 다만, 서로 동점일 때는 민국이의 총점 S를 출력하세요.

입력
입력은 2줄로 이루어져 있습니다.

1번째 줄에는 순서대로 민국이의 정보, 수학, 과학, 영어 점수(정수형)를 입력하는데, 이때 공백을 끊어서 구분합니다.

2번째 줄에는 마찬가지로 순서대로 만세의 정보, 수학, 과학, 영어 점수(정수형)를 입력하고 위와 같이 공백을 끊어서 구분합니다.

출력
출력은 문제에서 제시했던 방법대로 구하면 됩니다.

예제 입력 1 
100 80 70 60
80 70 80 90
예제 출력 1 
320
*/
