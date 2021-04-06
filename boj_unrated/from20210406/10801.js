function solution(scanner) {
    const A = scanner.readLine().split(' ').map(Number);
    const B = scanner.readLine().split(' ').map(Number);
    let AwinCount = 0;
    let BwinCount = 0;
    for (let i = 0; i < 10; i++) {
        if (A[i] > B[i]) AwinCount++;
        else if (A[i] < B[i]) BwinCount++;
    }

    if (AwinCount > BwinCount) return 'A';
    if (AwinCount < BwinCount) return 'B';
    return 'D';
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
카드게임 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	4000	2823	2517	72.830%
문제
두 사람 A와 B는 1부터 10까지의 숫자가 하나씩 적힌 열 장의 카드로 ‘게임’을 한다. 게임은 총 열 번의 ‘라운드’로 구성되고, 각 라운드 마다 자신이 가지고 있는 카드 중 하나를 제시하고, 한 번 제시한 카드는 버린다. 게임 승패는 다음과 같이 결정된다. 

각 라운드는 더 높은 숫자를 제시한 사람이 승리하고, 제시한 숫자가 같은 경우는 비긴다. 
열 번의 라운드에서 더 많은 라운드를 승리한 사람이 게임을 승리하고, 승리한 라운드 횟수가 동일한 경우 비긴다. 
다음은 게임의 한 예로, 각 라운드마다 A와 B가 제시한 카드의 숫자와 각 라운드의 승자를 보여준다. (비긴 라운드는 D로 표시함)

라운드	1	2	3	4	5	6	7	8	9	10
A의 카드	6	7	5	1	4	10	2	3	8	9
B의 카드	1	10	2	9	4	8	3	7	5	6
라운드 승자	A	B	A	B	D	A	B	B	A	A
A는 5번의 라운드에서 승리하고 B는 4번의 라운드에서 승리하였으므로, 이 게임은 A가 승리한다. 

라운드 순서대로 A와 B가 제시한 카드의 숫자가 주어졌을 때, 게임의 승자를 판단하는 프로그램을 작성하시오. 

입력
첫 번째 줄에는 A가 제시한 카드의 숫자 10개가 라운드 순서대로 주어지고, 두 번째 줄에는 B가 제시한 카드의 숫자 10개가 라운드 순서대로 주어진다.

출력
게임의 승패가 결정되는 경우 승리한 사람을 출력하고, 비기는 경우에는 D를 출력한다. 

예제 입력 1 
6 7 5 1 4 10 2 3 8 9
1 10 2 9 4 8 3 7 5 6
예제 출력 1 
A
예제 입력 2 
1 2 3 4 5 6 7 8 9 10
5 4 3 2 1 10 9 8 7 6
예제 출력 2 
D
*/
