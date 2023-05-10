function solution(scanner) {
    let N = scanner.readInt();
    N -= 1;
    const K = N % 14;
    const extraRU = Math.floor(N / 14);
    switch (K) {
        case 0:
        case 12:
            return 'baby';
        case 1:
        case 13:
            return 'sukhwan';
        case 2:
        case 6:
        case 10:
            return calcTuru(2 + extraRU);
        case 3:
        case 7:
        case 11:
            return calcTuru(1 + extraRU);
        case 4:
            return 'very';
        case 5:
            return 'cute';
        case 8:
            return 'in';
        case 9:
            return 'bed';
    }
    function calcTuru(i) {
        switch (i) {
            case 1:
                return 'turu';
            case 2:
                return 'tururu';
            case 3:
                return 'turururu';
            case 4:
                return 'tururururu';
        }
        return 'tu+ru*' + i;
    }
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
아기 석환 뚜루루 뚜루 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (추가 시간 없음)	512 MB	1834	920	807	50.438%
문제
석환이는 오늘 낮에 커피를 마셔서 잠에 들지 못하고 있다. 이불 속에서 너무 심심한 나머지 “아기 석환” 노래를 잠에 들 때까지 부르려고 한다. 석환이는 UCPC 2018 출제진 중의 한 명인 석환(seokhwan)이랑은 달리, 자신의 이름을 sukhwan이라고 쓴다. 노래가 끝나면 다시 처음부터 부른다. 아기 석환 노래는 아래와 같다.

baby sukhwan tururu turu
very cute tururu turu
in bed tururu turu
baby sukhwan

하지만 석환이는 계속 노래를 똑같이 부르기는 심심해서, 노래가 한 번 끝날 때마다 “tururu”와 “turu”에 “ru”를 한 번씩 더 추가해서 다음과 같이 부르려고 한다.

baby sukhwan tururu turu
very cute tururu turu
in bed tururu turu
baby sukhwan

baby sukhwan turururu tururu
very cute turururu tururu
in bed turururu tururu
baby sukhwan

baby sukhwan tururururu turururu
very cute tururururu turururu
in bed tururururu turururu
baby sukhwan

…

이 때, 석환이가 부르는 노래의 N번째 단어는 무엇일까?

입력
첫 번째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

출력
첫 번째 줄에 석환이가 N번째로 부를 단어를 출력한다. 여기서 단어란 가사 중 공백으로 구분되는 연속된 알파벳 소문자열을 뜻한다. 단, 출력할 단어가 “tururu...ru”일 때, “ru”가 k(k ≥ 5)번 반복되면 “tu+ru*k”와 같이 출력한다.

예제 입력 1 
1
예제 출력 1 
baby
예제 입력 2 
17
예제 출력 2 
turururu
예제 입력 3 
45
예제 출력 3 
tu+ru*5
*/
