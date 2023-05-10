function solution(scanner) {
    const T = scanner.readInt();
    const r = [];
    for (let i = 0; i < T; i++) {
        const N = BigInt(scanner.readLine());
        if (N % 2n == 0n) {
            r.push('even');
        } else {
            r.push('odd');
        }
    }
    return r.join('\n');
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
홀수일까 짝수일까 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	8009	3188	2893	42.987%
문제
짝이 없는 경재는 매일 홀로 있다보니 홀수를 판별할 수 있는 능력이 생겼다. 창식이는 경재의 말이 사실인지 그 능력을 시험해보려 한다. 창식이의 의심이 끝이 없을 것 같아 N개만 확인하기로 정했다.

N개의 정수가 주어지면 홀수인지 짝수인지를 출력하는 프로그램을 만들어 경재의 능력을 검증할 수 있게 도와주자.

입력
첫 번째 줄에 숫자의 개수 N(1 <= N <= 100)이 주어진다.

두 번째 줄부터 N+1번째 줄에 걸쳐 홀수인지 짝수인지 확인할 정수 K (1 <= K <= 10^60)가 주어진다.

출력
N개의 줄에 걸쳐 한 줄씩 정수 K가 홀수라면 'odd'를, 짝수라면 'even'을 출력한다.

예제 입력 1 
2
1024
5931
예제 출력 1 
even
odd
*/
