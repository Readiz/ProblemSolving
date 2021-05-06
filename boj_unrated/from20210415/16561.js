function solution(scanner) {
    const N = scanner.readInt();
    const count3 = N / 3;
    // 3의 개수에서 1을 뺀 것이 가능한 칸막이의 수, 여기서 2개를 선택하는 것이 정답임 (nC2)
    const splitter = count3 - 1;
    return splitter * (splitter - 1) / 2;
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
3의 배수 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.1 초	128 MB	1739	1082	953	65.952%
문제
윤영이는 3의 배수 마니아이다. 그는 모든 자연수를 3개의 3의 배수의 자연수로 분해하는 것을 취미로 가지고 있다. 문득 그는 자신에게 주어진 수를 3개의 3의 배수로 분리하는 경우의 수가 몇 개인지 궁금해졌다. 하지만 윤영이는 마지막 학기이기 때문에 이런 계산을 하기에는 너무 게을러졌다. 그래서 당신에게 이 계산을 부탁했다.

즉, 임의의 3의 배수 자연수 n이 주어졌을 때, 해당 수를 3의 배수의 자연수 3개로 분리하는 방법의 개수를 출력해라. 단 분해한 수의 순서가 다르면 다른 방법으로 간주한다. 예를 들어 12 = 3 + 6 + 3 과 12 = 3 + 3 + 6 은 다른 방법이다.

입력
임의의 3의 배수 자연수 n이 주어진다. (3 ≤ n ≤ 3000)

출력
자연수 n을 분해하는 방법의 개수를 출력하라.

예제 입력 1 
9
예제 출력 1 
1
예제 입력 2 
12
예제 출력 2 
3
*/
