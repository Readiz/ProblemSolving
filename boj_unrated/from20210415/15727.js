function solution(scanner) {
    const L = scanner.readInt();
    return Math.ceil(L / 5);
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
조별과제를 하려는데 조장이 사라졌다 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	3435	2158	2004	63.659%
문제
3학년 1학기를 재학 중인 성우는 ‘빨간눈 초파리의 뒷다리 털의 개수와 파인애플 껍질의 이해’라는 과목을 수강 중이다. 기말고사를 맞이하여 교수님은 수강생들에게 조별과제를 내주었고, 그 내용은 다음과 같다.

중간고사 이전에 배운 빨간눈 초파리의 뒷다리 털의 개수를 구하는 방법을 이용하여, 파인애플 껍질의 두께를 구하는 공식을 과학적인 근거와 함께 A4용지 10장 이상으로 제출하시오. [30%]

하지만 성우의 조 조장인 민건은 과제 내용을 듣자마자 집으로 도망쳐 버렸고, 성우는 민건이를 찾기 위해 떠난다. 성우는 1분에 1에서 5까지의 거리를 이동할 수 있다. 성우가 있는 곳으로부터 민건이의 집까지 거리가 주어졌을 때, 최대한 빨리 찾을 경우, 정확히 몇 분만에 민건이를 찾을 수 있는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 성우의 현재 위치와 민건이의 집까지의 거리 L(1 ≤ L ≤ 1,000,000)가 주어진다.

출력
성우가 최소 t분만에 민건이를 찾을 수 있을 때, t 이상의 가장 작은 정수를 출력한다.

예제 입력 1 
12
예제 출력 1 
3
*/
