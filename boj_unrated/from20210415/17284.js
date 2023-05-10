function solution(scanner) {
    const btns = scanner.readLine().split(' ');
    let remain = 5000;

    while (btns.length > 0) {
        if (btns[0] == '1') {
            remain -= 500;
        } else if (btns[0] == '2') {
            remain -= 800;
        } else {
            remain -= 1000;
        }
        btns.shift();
    }

    return remain;
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
Vending Machine 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	645	453	409	72.776%
문제
정웅이는 어머니께 5000원이라는 큰 용돈을 받아 자판기에 갔다.

자판기에는 세 개의 버튼이 있다.

1을 누르면 500원짜리 레쓰비를 먹을 수 있다.
2를 누르면 800원짜리 게토레이를 먹을 수 있다.
3을 누르면 1000원짜리 코카콜라를 먹을 수 있다.
누른 버튼값이 순서대로 주어질 때, 거스름돈이 얼마인지 구하시오. 단, 주어진 돈을 초과하도록 버튼을 누르는 일은 없다.

입력
첫째 줄에 정웅이가 누른 버튼의 번호가 공백으로 사이에 두고 주어진다. 정웅이는 버튼을 한 번 이상 눌렀다.

출력
첫째 줄에 자판기에서 나올 거스름돈을 출력한다.

예제 입력 1 
1 2 3
예제 출력 1 
2700
*/
