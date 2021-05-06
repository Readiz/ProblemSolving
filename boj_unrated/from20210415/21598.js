function solution(scanner) {
    let N = BigInt(scanner.readLine());
    const r = [];
    while (N > 0n) {
        r.push('SciComLove');
        N -= 1n;
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
SciComLove 서브태스크출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	117	101	79	92.941%
문제
당신은 싸이컴을 향해 절을 하려고 합니다. 하지만, 당신이 싸이컴에 들어오고 싶어서 절을 한 번 할 수도 있고, 싸이컴을 매우 싫어해 절을 두 번 할 수도 있습니다.

당신이 절을 할 횟수가 주어질 때, 그 횟수만큼 절하는 프로그램을 작성하세요. 실제로 프로그램을 이용해 절을 할 수는 없기 때문에, 대신 “SciComLove”를 출력하도록 합니다.

입력
첫 줄에 정수 이 주어집니다.

출력
"SciComLove"를 예제와 같이 번 출력합니다. 단, 따옴표는 출력하지 않습니다.

제한
서브태스크
번호	배점	제한
1	40	

2	40	

3	20	
추가 제한 조건이 없습니다.

예제 입력 1 
1
예제 출력 1 
SciComLove
예제 입력 2 
2
예제 출력 2 
SciComLove
SciComLove
*/
