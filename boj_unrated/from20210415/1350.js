function solution(scanner) {
    let N = scanner.readInt();
    const data = scanner.readLine().split(' ').map(Number);
    const clusterSize = scanner.readInt();
    let ans = 0;
    for (let i = 0; i < data.length; i++) {
        ans += Math.ceil(data[i] / clusterSize) * clusterSize;
    }
    return ans;
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
진짜 공간 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	5484	1707	1505	31.892%
문제
어떤 파일 시스템에는 디스크 공간이 파일의 사이즈와 항상 같지는 않다. 이것은 디스크가 일정한 크기의 클러스터로 나누어져 있고, 한 클러스터는 오직 한 파일만 이용할 수 있기 때문이다.

예를 들어, 클러스터의 크기가 512바이트이고, 600바이트 파일을 저장하려고 한다면, 두 개의 클러스터에 저장하게 된다. 두 클러스터는 다른 파일과 공유할 수 없기 때문에, 디스크 사용 공간은 1024바이트가 된다.

파일의 사이즈와 클러스터의 크기가 주어질 때, 사용한 디스크 공간을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 파일의 개수 N이 주어진다. N은 1,000보다 작거나 같은 자연수이다. 둘째 줄에는 파일의 크기가 공백을 사이에 두고 하나씩 주어진다. 파일의 크기는 1,000,000,000보다 작거나 같은 음이 아닌 정수이다. 마지막 줄에는 클러스터의 크기가 주어진다. 이 값은 1,048,576보다 작거나 같은 자연수이다.

출력
첫째 줄에 사용한 디스크 공간을 출력한다.

예제 입력 1 
1
600
512
예제 출력 1 
1024
예제 입력 2 
5
16 32 128 128 0
32768
예제 출력 2 
131072
*/
