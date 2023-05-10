const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function cmp(a, b) {
    if (a > b) return -1;
    if (a === b) return 0;
    return 1;
}

rl.on('line', (line) => {
    const A = line.toString().split('').map(_=>parseInt(_,10)).sort(cmp);
    const checkResult = A.reduce((_, i) => (_ + i));
    if (checkResult % 3 === 0 && A[A.length - 1] === 0) {
        console.log(A.join(''));
    } else {
        console.log(-1);
    }
    process.exit();
});

/*
30으로 나누어 떨어진다 = 3으로도 나누어 떨어지고 10으로도 나누어 떨어진다.
끝자리가 0인지 / 각 자리수 합이 3의 배수인지 확인.

문제
어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

입력
N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.

예제 입력 1 
30
예제 출력 1 
30
예제 입력 2 
102
예제 출력 2 
210
예제 입력 3 
2931
예제 출력 3 
-1
예제 입력 4 
80875542
예제 출력 4 
88755420
*/
