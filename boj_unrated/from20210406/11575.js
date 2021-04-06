function solution(scanner) {
    const T = scanner.readInt();
    const r = [];
    for (let tc = 0; tc < T; tc++) {
        const [a, b] = scanner.readLine().split(' ').map(Number);
        const line = scanner.readLine();
        let encrypted = '';
        console.log('a', a, 'b', b);
        for (let i = 0; i < line.length; i++) {
            const code = line.charCodeAt(i) - 65;
            encrypted += String.fromCharCode((code * a + b) % 26 + 65);
            console.log('code', code, '->', (code * a + b) % 26);
        }
        r.push(encrypted);
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
Affine Cipher 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
5 초	256 MB	1691	1048	862	66.104%
문제
서쪽나라에서 특수훈련을 받은 정은이는 동쪽나라로 침투를 하게 되었다. 뛰어난 스파이였던 정은이는 동쪽나라의 정보를 입수하게 되었고 정보를 안전하게 서쪽나라로 전달하기 위해 아핀 암호(Affine Cipher)를 이용하기로 하였다.

아핀 암호는 다음과 같은 식을 통해 구할 수 있다.

E(X) = (aX + b) mod 26

A부터 Z까지의 알파벳을 차례대로 0, 1, 2, ... , 25 라고 하자. a = 3이고, b = 1인 경우에 알파벳 A를 아핀 암호식에 대입하면 E(0) = (3 × 0 + 1) mod 26 이 되어 암호화된 결과는 B가 된다.

a와 b, 그리고 알파벳 대문자로만 구성된 평문이 주어졌을 때, 이를 암호문으로 치환하는 프로그램을 작성하라.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 50) 가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 정수 a와 b(0 < a, b ≤ 1,000,000)의 값이 주어진다. a는 26과 서로소이다.

각 테스트케이스의 두 번째 줄에는 평문 s가 주어진다. 평문의 길이 |s|는 0보다 크고 1,000,000보다 작다.

출력
각 테스트 케이스마다 한 줄에 한 개씩 평문 s를 암호문으로 치환한 결과를 출력한다.

예제 입력 1 
2
3 1
IAMSPY
5 3
ABCDEFGHIJKLMNOPQRSTUVWXYZ
예제 출력 1 
ZBLDUV
DINSXCHMRWBGLQVAFKPUZEJOTY
*/
