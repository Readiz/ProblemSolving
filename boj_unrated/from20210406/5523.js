function solution(scanner) {
    const N = scanner.readInt();
    let AwinCount = 0;
    let BwinCount = 0;
    for (let i = 0; i < N; i++) {
        const [A, B] = scanner.readLine().split(' ').map(Number);
        if (A > B) AwinCount++;
        else if (A < B) BwinCount++;
    }
    return AwinCount + ' ' + BwinCount;
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
경기 결과 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	2075	1489	1353	73.773%
문제
A와 B가 게임을 한다. 게임은 N번의 라운드로 이루어져 있다. 각 라운드에서는, 더 많은 점수를 얻은 사람이 그 라운드의 승자가 된다. 즉, A의 점수가 B의 점수보다 크면 i번째 라운드는 A의 승리이며, B의 점수가 A의 점수보다 크면 i번째 라운드는 B의 승리이다. 무승부인 경우에는 아무도 승리하지 않는다.

N번의 라운드에서의 A와 B의 점수가 주어졌을 때, A가 이긴 횟수와, B가 이긴 횟수를 출력하는 프로그램을 만들어라.

입력
첫째 줄에는 정수 N(1≤N≤1,000,000)이 주어진다.

둘째 줄부터는 정수 Ai, Bi(0≤Ai,Bi≤100)가 공백을 사이에 두고 차례대로 주어진다.

출력
첫째 줄에 A가 이긴 횟수와 B가 이긴 횟수를 차례대로 출력하라.

예제 입력 1 
4
100 0
5 6
40 50
74 75
예제 출력 1 
1 3
예제 입력 2 
5
20 20
3 95
60 59
40 40
20 19
예제 출력 2 
2 1
*/
