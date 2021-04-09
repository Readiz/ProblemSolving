function solution(scanner) {
    const N = scanner.readInt();
    const dbStr = scanner.readLine().split(' ');
    // 문자순 정렬 구현.. "9" > "901", "3" > "2"
    dbStr.sort((a, b) => {
        let isSwapped = false;
        let r = 0;
        if (b.length > a.length) {
            [a, b] = [b, a]; // swap
            // swap 후에는 항상 a가 b보다 길다.
            isSwapped = true;
        }
        for (let i = 0; i < a.length; i++) {
            // 한자리 수씩 비교함..
            const aInt = Number(a[i]);
            const bInt = Number(b[i]);
            if (Number.isNaN(bInt)) {
                // 비교 중에 앞 자리는 다 같고, 두 수의 길이가 달라지는 case.
                const ab = BigInt(a + b);
                const ba = BigInt(b + a);
                if (ab > ba) r = -1;
                else if (ba > ab) r = 1;
                else r = 0;
                break;
            }
            // 길이가 같은 경우에 대한 판정
            if (aInt > bInt) {
                r = -1;
                break;
            } else if (aInt < bInt) {
                r = 1;
                break;
            } else {
                // 같은 경우에는 배열 순회를 마저 한다.
                continue;
            }
        }
        if (isSwapped) r = r * (-1);
        return r;
    }); 
    console.log(dbStr);
    return BigInt(dbStr.join('')); // 앞의 0 제거
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

// 1422 문제와 유사함.

/*
큰 수 만들기 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	1054	349	274	33.785%
문제
음이 아닌 정수가 N개 들어있는 리스트가 주어졌을 때, 리스트에 포함된 수를 나열하여 만들 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 리스트에 포함된 수가 주어진다. 수는 공백으로 구분되어져 있고, 1,000,000,000보다 작거나 같은 음이 아닌 정수 이다. 0을 제외한 나머지 수는 0으로 시작하지 않으며, 0이 주어지는 경우 0 하나가 주어진다.

출력
리스트에 포함된 수를 나열하여 만들 수 있는 가장 큰 수를 출력한다. 수는 0으로 시작하면 안되며, 0이 정답인 경우 0 하나를 출력해야 한다.
*/
