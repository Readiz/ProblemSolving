function solution(scanner) {
    const N = scanner.readInt();
    const r = [];
    for (let tc = 0; tc < N; tc++) {
        const line = scanner.readLine();
        const part1 = line.split('-')[0];
        const part2 = line.split('-')[1];
        let score1 = 0;
        score1 += (part1.charCodeAt(0) - 65) * 26 * 26;
        score1 += (part1.charCodeAt(1) - 65) * 26;
        score1 += (part1.charCodeAt(2) - 65);
        let score2 = parseInt(part2, 10);
        console.log('score1: ', score1);
        console.log('score2: ', score2);
        if (Math.abs(score1 - score2) <= 100) {
            r.push('nice');
        } else {
            r.push('not nice');
        }
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
좋은 자동차 번호판 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	2020	1289	1188	65.203%
문제
앨버타의 자동차 번호판은 ABC-0123 (세 글자, 네 숫자)와 같이 두 부분으로 나누어져 있다.

좋은 번호판은 첫 번째 부분의 가치와 두 번째 부분의 가치의 차이가 100을 넘지 않는 번호판이다.

글자로 이루어진 첫 번째 부분의 가치는 글자를 26진법 수처럼 계산한다. (각 자리가 [A..Z]) 예를 들어, "ABC"의 가치는 28 (0*26^2 + 1*26^1 + 2*26^0)이 된다. "ABC-0123"은  |28 - 123| <= 100 이기 때문에, 좋은 번호판이다.

자동차 번호판이 주어졌을 때, 좋은 번호판인지 아닌지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 번호판의 수 N (1 ≤ N ≤ 100)이 주어진다. 다음 N개 줄에는 자동차 번호판이 LLL-DDDD 형식으로 주어진다.

출력
각각의 자동차 번호판에 대해서, 좋은 번호판이면 "nice"를, 아니면 "not nice"를 출력한다.

예제 입력 1 
2
ABC-0123
AAA-9999
예제 출력 1 
nice
not nice
*/
