function solution(scanner) {
    const N = scanner.readInt();

    // 3 -> 0  (직선 0개)
    // 4 -> 1  (직선 2  (1 * 2)개, 교차점 1개)  -> 1개까진 그냥 긋고, 나머지가 1개를 그음 -> 1개
    // 5 -> 5  (직선 5  (2 * 5)개, 교차점 5개)  -> 2개까진 그냥 긋고, 나머지가 2개씩 그임
    // 6 -> 15 (직선 9 (3 * 6)개, 교차점 15개)  -> 15 + 6 = 21

    // 1 교차점 = 직선 2개
    // 직선 2개는 꼭지점 4개
    // n각형 일때, 4개의 꼭지점 뽑기. nC4

    return Math.floor(N * (N - 1) * (N - 2) * (N - 3) / (4 * 3 * 2));
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
다각형의 대각선 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	1937	1409	1282	76.173%
문제
세 대각선이 한 점에서 만나지 않는 볼록 N각형이 주어졌을 때, 대각선의 교차점의 개수를 세는 프로그램을 작성하시오.

아래 그림은 위의 조건을 만족하는 한 육각형의 교차점 그림이다.



모든 내부각이 180도보다 작은 다각형을 볼록 다각형이라고 한다.

입력
첫째 줄에 N이 주어진다. (3 ≤ N ≤ 100)

출력
첫째 줄에 교차점의 개수를 출력한다.

예제 입력 1 
3
예제 출력 1 
0
예제 입력 2 
4
예제 출력 2 
1
예제 입력 3 
6
예제 출력 3 
15
*/
