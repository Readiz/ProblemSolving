function solution(scanner) {
    const N = scanner.readInt();
    const M = scanner.readInt();
    if (N < 2 || (N === 2 && M < 18)) return 'Before';
    else if (N === 2 && M === 18) return 'Special';
    else return 'After';
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
특별한 날 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	2867	1928	1828	68.107%
문제
2월 18일은 올해 CCC에 있어서 특별한 날이다.

사용자로부터 정수인 월과 일을 입력받아 날짜가 2월 18일인지 전인지 후인지를 출력하는 프로그램이다.

만약 날짜가 2월 18일 전이면, "Before"을 출력한다. 만약 날짜가 2월 18일 후면, "After"을 출력한다. 만약 2월 18일이라면 "Special" 을 출력한다.

입력
입력은 두 개의 정수가 각 줄에 걸쳐 입력된다. 이 정수들은 2015년의 날짜에 포함된다.

첫 번째 줄은 1에서 12사이의 월을 입력한다.

두 번째 줄은 1에서 31사이의 그 달에 들어있는 날짜를 입력한다 .

출력
마지막 줄에 "Before", "After"나 "Special"을 출력한다.

예제 입력 1 
1
7
예제 출력 1 
Before
예제 입력 2 
8
31
예제 출력 2 
After
예제 입력 3 
2
18
예제 출력 3 
Special
*/
