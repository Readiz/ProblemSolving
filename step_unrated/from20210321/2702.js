const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function gcd(a, b) {
    while (b !== 0) {
        let r = a % b;
        a = b;
        b = r;
    }
    return a;
}
function lcm(a, b) {
    return a * b / gcd(a, b);
}

let isFirst = true;
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        return;
    }
    const [a, b] = line.toString().split(' ').map(_ => parseInt(_, 10));
    console.log(`${lcm(a, b)} ${gcd(a, b)}`);
});


/*
초6 수학 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	2370	1857	1742	80.055%
문제
두 정수 a와 b 최소공배수는 두 수의 공통된 배수 중 가장 작은 수이고, 최대공약수는 두 수의 공통된 약수중 가장 큰 수이다.

a와 b가 주어졌을 때, 최소공배수와 최대공약수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1<=T<=1,000)가 주어진다. 각 테스트 케이스는 두 정수 a와 b로 이루어져 있고, 공백으로 구분되어 있다. (1 <= a,b <= 1,000)

출력
각 테스트 케이스에 대해 최소공배수와 최대공약수를 차례대로 출력한다.

예제 입력 1 
3
5 10
7 23
42 56
예제 출력 1 
10 5
161 1
168 14
*/
