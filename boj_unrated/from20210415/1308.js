function solution(scanner) {
    const [a1, a2, a3] = scanner.readLine().split(' ').map(Number);
    const [b1, b2, b3] = scanner.readLine().split(' ').map(Number);
    if ((b1 === a1 + 1000 && b2 === a2 && b3 >= a3) || 
        (b1 === a1 + 1000 && b2 > a2) ||
        b1 > a1 + 1000) {
        return 'gg';
    } else {
        const a = new Date(a1 + '-' + a2 + '-' + a3);
        const b = new Date(b1 + '-' + b2 + '-' + b3);
        return 'D-' + Math.floor((b - a) / (1000 * 60 * 60 * 24) + 1);
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
D-Day 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	870	161	132	22.997%
문제
캠프에 오게 된 송유진은 캠프가 너무 지루해서 오늘로부터 캠프가 끝날 때 까지 며칠이나 남았는지 알아보고 싶었다. 그런데 캠프는 비상식적으로 길지도 몰라서 (윤년을 포함할지도 모른다) 손으로 하나하나 세기에는 힘들어 보였다.

더욱 정확한 계산을 위해, 유진이는 윤년이 정해지는 기준을 찾아보았고, 그것은 다음과 같았다.

서력기원 연수가 4로 나누어떨어지는 해는 우선 윤년으로 한다. (2004년, 2008년, …)
100으로 나누어떨어지는 해는 평년으로 한다. (2100년, 2200년, …)
400으로 나누어떨어지는 해는 다시 윤년으로 한다. (1600년, 2000년, …)
그런데 캠프가 너무 길 경우, 사춘기인 유진이는 캠프에 무단으로 빠질지도 모른다.

입력
첫째 줄에 오늘의 날짜가 주어지고, 두 번째 줄에 D-Day인 날의 날짜가 주어진다. 날짜는 연도, 월, 일순으로 주어지며, 공백으로 구분한다. 입력 범위는 1년 1월 1일부터 9999년 12월 31일 까지 이다. 오늘의 날짜는 항상 D-Day보다 앞에 있다.

출력
오늘부터 D-Day까지 x일이 남았다면, "D-"를 출력하고 그 뒤에 공백 없이 x를 출력한다. 만약 캠프가 천년 이상 지속된다면 (오늘이 y년 m월 d일이고, D-Day가 y+1000년 m월 d일과 같거나 늦다면) 대신 "gg"를 출력한다. 오늘이 2월 29일인 경우는 주어지지 않는다.

예제 입력 1 
2008 12 27
2009 1 22
예제 출력 1 
D-26
*/