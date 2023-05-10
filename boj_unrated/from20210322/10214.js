const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let sumA = 0, sumB = 0;
rl.on('line', (line) => {
    if (N === 0) {
        N = parseInt(line.toString(), 10);
        N *= 9;
        return;
    }
    N--;
    const [a, b] = line.toString().split(' ').map(_=>parseInt(_,10));
    sumA += a;
    sumB += b;
    if (N % 9 === 0) {
        if (sumA > sumB) {
            console.log('Yonsei');
        } else if (sumA < sumB) {
            console.log('Korea');
        } else {
            console.log('Draw');
        }
        sumA = 0;
        sumB = 0;
    }
    if (N === 0) {
        process.exit();
    }
});

/*
Baseball 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	4632	2739	2568	61.686%
문제
경근이는 수업 과제의 일환으로 연세대학교의 역사를 조사하고 있었다. 케케묵은 도서관 구석에서 경근이가 발견한 것은 역대 연고전의 야구경기 실황 기록문서였다.
하지만 문서를 가지고 있음에도 불구하고 한 눈에 당시의 경기 승패를 파악하기에는 어려움이 많았는데, 문서에는 회차별 양 팀 획득 점수만이 적혀져 있기 때문이었다.

경근이는 주어진 방대한 자료를 해석하는것이 귀찮았기 때문에 절친한 프로그래머 친구인 당신에게 도움을 요청했다.

주어진 실황 기록문서에서 어떤 팀이 이겼는지를 알아내 경근이를 도와주자!

입력
입력 파일의 첫 번째 줄에 테스트 케이스의 수를 의미하는 자연수 T가 주어진다. 그 다음에는 T개의 테스트 케이스가 주어진다.

각 테스트 케이스는 9줄에 걸쳐서 입력되며, 매 줄마다 해당 회의 연세대 득점 Y와 고려대 득점 K가 공백으로 구분되어 주어진다. 이 두 수는 0이상 9이하이다.

출력
각각의 케이스마다 한 줄에 연세대가 이겼을 경우 "Yonsei", 고려대가 이겼을 경우 "Korea", 비겼을 경우 "Draw"를 출력한다.

예제 입력 1 
1
1 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
예제 출력 1 
Yonsei
*/
