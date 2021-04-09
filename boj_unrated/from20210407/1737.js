function solution(scanner) {
    const MOD = 1000000000000000000n;
    let N = scanner.readInt();
    const db = new Map(); // Memoization
    return phi(N);

    function phi(n) {
        if (n >= 0 && n <= Math.PI) {
            return 1n;
        }
        if (!db.has(n)) {
            // console.log('calculating phi:', n);
            db.set(n, (phi(n - 1) + phi(n - Math.PI)) % MOD);
        }
        return db.get(n);
    }
}


/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
const scanner = {
    readInt: () => {
        return parseInt(__lineDB[__lineIdx++], 10);
    },
    readLine: () => {
        return __lineDB[__lineIdx++];
    }
};
let __lineDB = [];
let __lineIdx = 0;
const isDebug = process.argv[2] === 'readizDebug';
if (!isDebug) {
    global.console = {
        log: () => {},
        warn: () => {},
        info: () => {},
        debug: () => {},
        error: () => {}
    };
    const rl = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.on('line', (line) => {
        __lineDB.push(line);
    });
    rl.on('close', () => {
        process.stdout.write(solution(scanner) + '\n');
    });
} else {
    __lineDB = require('fs').readFileSync(process.argv[1].replace('.js', '_input.txt')).toString().split('\n');
    while (__lineIdx < __lineDB.length) {
        process.stdout.write('--------------------------------------------\n');
        process.stdout.write('New Start + Log\n');
        process.stdout.write('--------------------------------------------\n');
        const start = __lineIdx;
        const answer = solution(scanner);
        const end = __lineIdx;
        process.stdout.write('----------------------\n');
        process.stdout.write('Input\n')
        process.stdout.write('----------------------\n');
        process.stdout.write(__lineDB.slice(start, end).join('\n') + '\n');
        process.stdout.write('----------------------\n');
        process.stdout.write('Answer\n')
        process.stdout.write('----------------------\n');
        process.stdout.write(answer + '\n');
    }
}




/*
Pibonacci 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	600	232	166	40.686%
문제
피보나치(Fibonacci) 수열은 매우 유명한 수열로 그 점화식은 F[i]=F[i-1]+F[i-2]와 같이 표현된다. 우리는 이와 같은 수열을 살짝 변경한 피보나치(Pibonacci) 수열에 대해 살펴보자. 피보나치 수열의 점화식은 아래와 같다.

P[n] = 1 (0 ≤ n ≤ π)
P[n] = P[n-1] + P[n-π] (그 외)
주의할 것은 n이 꼭 정수일 필요는 없다는 것이다. 즉, P[n-π] = P[n-π-1]+P[n-π-π]와 같은 식으로 계산을 해 주어야 한다.

자연수로 n이 주어졌을 때, P[n]을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 n(1 ≤ n ≤ 1,000)이 주어진다.

출력
첫째 줄에 P[n]을 출력한다. 값이 매우 커질 수 있으므로 1,000,000,000,000,000,000으로 나눈 나머지를 출력한다.

예제 입력 1 
10
예제 출력 1 
19

*/
