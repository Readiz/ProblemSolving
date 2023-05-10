function solution(scanner) {
    const A = scanner.readInt();
    const B = scanner.readInt();
    const C = scanner.readInt();
    const D = scanner.readInt();
    const P = scanner.readInt();
    
    const valX = A * P;
    let valY;
    
    if (P <= C) valY = B;
    else {
        valY = B + (P - C) * D;
    }

    return Math.min(valX, valY);
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
수도요금 출처다국어
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	5405	4078	3825	76.469%
문제
JOI군이 살고 있는 지역에는 X사와 Y사, 두 개의 수도회사가 있다. 두 회사의 수도요금은 한 달간 수도의 사용량에 따라 다음과 같이 정해진다.

X사 : 1리터당 A엔.
Y사 : 기본요금은 B엔이고, 사용량이 C리터 이하라면 요금은 기본요금만 청구된다. 사용량이 C리터가 넘었을 경우 기본요금 B엔에 더해서 추가요금이 붙는다. 추가요금은 사용량이 C리터를 넘었을 경우 1리터를 넘었을 때마다 D엔이다.
JOI군의 집에서 한 달간 쓰는 수도의 양은 P리터이다.

수도요금이 최대한 싸게 되도록 수도회사를 고를 때, JOI군의 집의 1달간 수도요금을 구하여라.

입력
입력은 5줄이고 한 줄에 하나씩 정수가 입력된다.

첫 번째 줄에는 X사의 1리터당 요금 A가 입력된다.
두 번째 줄에는 Y사의 기본요금 B가 입력된다.
세 번째 줄에는 Y사의 요금이 기본요금이 되는 사용량의 상한 C가 입력된다.
네 번째 줄에는 Y사의 1리터 당 추가요금 D가 입력된다.
다섯 번째 줄에는 JOI군의 집에서 사용하는 한 달간 수도의 양 P가 입력된다.
입력되는 정수 A,B,C,D,P는 전부 1 이상 10000 이하이다.

출력
JOI군의 집에서 지불하는 한 달간 수도요금을 첫째 줄에 출력한다.

예제 입력 1 
9
100
20
3
10
예제 출력 1 
90
예제 입력 2 
8
300
100
10
250
예제 출력 2 
1800
*/
