function solution(scanner) {
    let N = BigInt(scanner.readInt());
    let r = 1n;
    while (N > 1) {
        r *= N;
        while (r % 10n === 0n) { // 10으로 나누어 떨어지지 않을 때까지 반복
            r /= 10n; // 끝자리 0을 없앤다..
        }
        r %= 100000000000000000000n; // 스무 자리만 남기면서 반복한다.
        N--;
    }
    r %= 100000n; // 다섯 자리만 남긴다.
    let rStr = r.toString();
    while (rStr.length < 5) {
        rStr = '0' + rStr;
    }
    return rStr;
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
팩토리얼5 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	3810	487	353	17.901%
문제
팩토리얼5란, N!의 0이 아닌 뒤 5자리를 말한다.

N이 주어졌을 때, 팩토리얼5를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N이 주어진다. N은 1,000,000보다 작거나 같다. 또, 9보다 크거나 같다.

출력
첫째 줄에 N의 팩토리얼5를 계산한다.

예제 입력 1 
20
예제 출력 1 
17664
예제 입력 2 
18
예제 출력 2 
05728
*/
