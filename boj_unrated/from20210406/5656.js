function solution(scanner) {
    const r = [];

    let idx = 1;
    while (true) {
        let [a, op, b] = scanner.readLine().split(' ');
        [a, b] = [a, b].map(Number);
        if (op === 'E') break;
        let result = false;
        switch (op) {
            case '>':
            result = a > b;
            break;
            case '>=':
            result = a >= b;
            break;
            case '<':
            result = a < b;
            break;
            case '<=':
            result = a <= b;
            break;
            case '==':
            result = a == b;
            break;
            case '!=':
            result = a != b;
            break;
        }

        r.push(`Case ${idx}: ${result}`);
        idx++;
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
비교 연산자 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	1741	1028	898	60.717%
문제
C언어의 비교 연산자는 아래 표에 나와있다. 

연산자	뜻
>	크다
>=	크거나 같다
<	작다
<=	작거나 같다
==	같다
!=	같지 않다
이 연산자는 두 피연산자를 비교하고, (왼쪽 값과 오른쪽 값) true또는 false (1 또는 0)을 리턴한다. 예를 들어, 2 > 3은 "false"를 리턴하고 (2는 3보다 작기 때문), 3 != 4는 "true", 3 >= 3은 "true"를 리턴한다.

C언어의 비교 연산식이 주어졌을 때, 결과를 구하는 프로그램을 작성하시오.

입력
입력은 최대 12000줄로 이루어져 있다. 각 줄은 두 정수 a, b가 주어지며, 정수 사이에는 연산자 ">", ">=", "<", "<=", "==", "!="중 하나가 주어진다. 연산자와 피연산자 사이에는 공백이 하나 있으며, 연산자로 "E"가 주어진 경우에는 프로그램을 끝낸다. (-10000 ≤ a,b ≤ 10000)

출력
입력의 각 줄 마다 입력으로 주어진 식의 결과가 "true"인지 "false"인지 출력한다.

예제 입력 1 
3 != 3
4 < 4
4 <= 5
3 E 3
예제 출력 1 
Case 1: false
Case 2: false
Case 3: true
*/
