function solution(scanner) {
    let N = scanner.readInt();
    if (N === 1 || N === 2) return 2;
    while(true) {
        let reversedInt = reverse(N);
        // 1. 팰린드롬 판정
        if (reversedInt === N) {
            // 2. 소수 판정
            if (isPrime(N)) {
                return N;
            }
        }
        N++;
    }

    function reverse(n) {
        return Number(n.toString().split('').reverse().join(''));
    }
    function isPrime(n) {
        if (n % 2 === 0) return false;
        for (let i = 3; i * i <= n; i+=2) {
            if (n % i === 0) { // 나누어 떨어지면..
                console.log(n, 'is not prime, because it has:', i);
                return false;
            }
        }
        return true;
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
소수&팰린드롬 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	9167	2601	1891	27.358%
문제
어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 예를 들어 79,197과 324,423 등이 팰린드롬 수이다.

어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다.

출력
첫째 줄에 조건을 만족하는 수를 출력한다.

예제 입력 1 
31
예제 출력 1 
101
*/
