function solution(scanner) {
    const T = scanner.readInt();
    const r = [];
    for (let tc = 0; tc < T; tc++) {
        let Fn = BigInt(scanner.readString());
        if (Fn === 0n) {
            r.push(0);
            continue;
        }
        Fn = Fn % 1000000n;
        let pprev = 0n, prev = 1n, cur = 1n;
        curIdx = 2;
        while (cur != Fn) {
            pprev = prev;
            prev = cur;
            cur = (pprev + prev) % 1000000n;
            curIdx++;
        }
        r.push(curIdx);
    }
    return r.join('\n');
}

/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
(function readizInit() {
    const isDebug = process.argv[2] === 'readizDebug';
    const _input = (!isDebug) ?
        require('fs').readFileSync('/dev/stdin') :
        require('fs').readFileSync(process.argv[1].replace('.js', '_input.txt'));
    let _index = 0;
    const _index_max = _input.length;
    const scanner = {
        readInt: () => {
            let result = 0;
            let isMinus = false;
            while ((!(_input[_index] & 0x10) && _input[_index] !== 45) && _index < _index_max) ++_index;
            if (_input[_index] === 45) { isMinus = true; ++_index; }
            while ((_input[_index] & 0x10) && _index < _index_max) { result = result * 10 + (_input[_index] & 0x0f); ++_index; }
            return isMinus ? -result : result;
        },
        readString: () => {
            while ((_input[_index] === 0x0a || _input[_index] === 0x20) && _index < _index_max) ++_index;
            const startIdx = _index;
            while (!(_input[_index] === 0x0a || _input[_index] === 0x20) && _index < _index_max) ++_index;
            const endIdx = _index;
            return _input.toString('utf-8', startIdx, endIdx);
        },
        readLine: () => {
            while ((_input[_index] === 0x0a) && _index < _index_max) ++_index;
            const startIdx = _index;
            while (!(_input[_index] === 0x0a) && _index < _index_max) ++_index;
            const endIdx = _index;
            return _input.toString('utf-8', startIdx, endIdx);
        }
    }
    if (!isDebug) {
        global.console = {
            log: () => {},
            warn: () => {},
            info: () => {},
            debug: () => {},
            error: () => {}
        }
        const answer = solution(scanner);
        process.stdout.write(answer + '\n');
    } else {
        while (_index !== _index_max) {
            process.stdout.write('--------------------------------------------\n');
            process.stdout.write('New Start + Log\n');
            process.stdout.write('--------------------------------------------\n');
            const start = _index;
            const answer = solution(scanner);
            const end = _index;
            process.stdout.write('----------------------\n');
            process.stdout.write('Input\n')
            process.stdout.write('----------------------\n');
            process.stdout.write(_input.toString('utf-8', start, end).trim() + '\n');
            process.stdout.write('----------------------\n');
            process.stdout.write('Answer\n')
            process.stdout.write('----------------------\n');
            process.stdout.write(answer + '\n');
        }
    }
})();

/*
피보나치 인버스 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	839	202	145	34.772%
문제
 

피보나치 수는 수학에서 위의 점화식으로 정의되는 수열이다. 피보나치 수는 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다. n = 0, 1,...에 해당하는 피보나치 수는 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946… 이다. 

프로그래밍 실습에서 문제 중 n을 입력 받았을 때 Fn의 값을 출력하는 문제가 자주 등장한다. 실습을 하고 있던 희원이는 문득 이 문제가 너무 쉽다고 생각했다. 희원이는 실습 도중 반대로 Fn이 주어졌을 때 n을 출력하는 문제는 어떨지 궁금했다.  피보나치 수 Fn이 주어졌을 때 n을 출력하는 프로그램을 만들어 보자.

입력
첫 번째 줄에 테스트케이스를 나타내는 T(1 ≤ T ≤ 100)가 입력으로 주어진다. 두 번째 줄부터 각 테스트케이스마다 양의 정수 Fn이 입력으로 주어진다. (1 ≤ Fn ≤ 1021000, 1 ≤ N ≤ 100,000)

출력
피보나치 수 Fn이 주어졌을 때 n을 출력한다. 만약 가능한 경우가 여러 개 있는 경우에는 가장 큰 인덱스를 출력하라. 피보나치 수가 아닌 수가 들어오는 경우는 없다.

예제 입력 1 
4
1
5
8
1597
예제 출력 1 
2
5
6
17
*/
