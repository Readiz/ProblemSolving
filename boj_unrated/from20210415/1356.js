function solution(scanner) {
    const num = scanner.readLine();
    const len = num.length;
    if (len < 2) return 'NO';
    let isYujin = false;
    for (let i = 1; i < len; i++) {
        console.log(num.substr(0, i), num.substr(i));
        const A = num.substr(0, i);
        const B = num.substr(i);
        let Amul = Number(A[0]);
        for (let j = 1; j < A.length; j++) {
            Amul *= Number(A[j]);
        }
        let Bmul = Number(B[0]);
        for (let j = 1; j < B.length; j++) {
            Bmul *= Number(B[j]);
        }
        console.log(Amul, Bmul);
        if (Amul === Bmul) {
            console.log('Yujin!');
            isYujin = true;
            break;
        }
    }
    if (isYujin) return 'YES';
    else return 'NO';
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
유진수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	3257	1350	1178	42.542%
문제
유진수는 어떤 수를 10진수로 표현한 뒤 그 수를 두 부분으로 나눴을 때, 앞부분 자리수의 곱과 뒷부분 자리수의 곱이 같을 때를 말한다.

예를 들어, 1221은 유진수이다. 12와 21로 나눴을 때, 앞부분 자리수의 곱 1*2는 뒷부분 자리수의 곱 2*1과 같기 때문이다. 1236도 마찬가지로 유진수이다. 하지만, 1234는 아니다. 수를 나눌 때 항상 연속된 자리수를 나눠야하고, 각 부분에 적어도 한자리는 있어야 한다.

예를 들어, 12345는 총 4가지 방법으로 나눌 수 있다. 1-2345, 12-345, 123-45, 1234-5 어떤 수 N이 주어질 때, 이 수가 유진수인지 아닌지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수 N이 주어진다. 이 수는 2,147,483,647보다작거나 같은 자연수이다.

출력
첫째 줄에 N이 유진수이면 YES, 아니면 NO를 출력한다.

예제 입력 1 
1236
예제 출력 1 
YES
*/
