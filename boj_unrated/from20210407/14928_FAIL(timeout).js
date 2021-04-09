function solution(scanner) {
    return BigInt(scanner.readLine()) % 20000303n;
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
큰 수 (BIG) 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	1865	1152	997	66.246%
문제
제연이는 그의 생일(2000년 3월 3일)을 기념해 자신이 가장 좋아하는 수를 20000303으로 나눈 나머지를 구해 그 수만큼 잠을 자기로 했다. 제연이가 얼마나 잠을 잘 수 있을지 구하자.

입력
첫째 줄에 제연이가 가장 좋아하는 수 N이 주어진다. (N ≤ 101,000,000)

출력
N을 20000303으로 나눈 나머지를 출력한다.

예제 입력 1 
20000303200003032000030320000303200003032000030320000303200003032000030320000303
예제 출력 1 
0
예제 입력 2 
123456789123456789123456789123456789123456789123456789123456789123456789
예제 출력 2 
1313652
*/
