function solution(scanner) {
    const [min, max] = scanner.readLine().split(' ').map(BigInt);
    const db = [];
    let N = 2n;
    while (N * N <= max) {
        db.push(N * N);
        N++;
    }
    // console.log(db);
    const squarennNumber = new Set();
    for (let i = min; i <= max; i++) {
        squarennNumber.add(i);
    }
    db.map(_ => {
        for (let i = min / _; i * _ <= max; i++) {
            if (i * _ < min) continue;
            squarennNumber.delete(i * _);
        }
    });
    // console.log([...squarennNumber]);
    return squarennNumber.size;
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
제곱 ㄴㄴ 수 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	32870	5552	3723	19.871%
문제
어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

입력
첫째 줄에 두 정수 min과 max가 주어진다.

출력
첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다.

제한
1 ≤ min ≤ 1,000,000,000,000
min ≤ max ≤ min + 1,000,000
*/
