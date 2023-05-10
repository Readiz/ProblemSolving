function solution(scanner) {
    const N = scanner.readInt();
    return N * (N - 1);
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
Vera and Outfits 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	1568	1397	1334	89.410%
문제
Vera owns N tops and N pants. The i-th top and i-th pants have colour i, for 1 ≤ i ≤ N, where all N colours are different from each other.

An outfit consists of one top and one pants. Vera likes outfits where the top and pants are not the same colour.

How many different outfits does she like?

입력
The input will be in the format:

N
Constraints:

1 ≤ N ≤ 2017
N is integer
출력
Output one line with the number of different outfits Vera likes.

예제 입력 1 
1
예제 출력 1 
0
예제 입력 2 
2
예제 출력 2 
2
예제 입력 3 
5
예제 출력 3 
20
*/
