function solution(scanner) {
    db = [];
    r = [];
    for (let i = 0; i < 9; i++) {
        db.push(scanner.readInt());
    }
    for (let i = 0; i < 9; i++) {
        sum = db[i];
        const result = DFS(1, i);
        if (result) {
            r.push(db[i]);
            break;
        }
    }
    return r.reverse().join('\n');
}

let db;
let r;
let sum;
function DFS(depth, from) {
    if (depth === 7 && sum !== 100) {
        return false;
    } else if (depth === 7 && sum === 100) {
        return true;
    }

    for (let i = from + 1; i < 9; i++) {
        sum += db[i];
        const result = DFS(depth + 1, i);
        if (result) {
            r.push(db[i]);
            return true;
        }
        sum -= db[i];
    }
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
백설 공주와 일곱 난쟁이 스페셜 저지출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	5786	3963	3450	71.414%
문제
매일 매일 일곱 난쟁이는 광산으로 일을 하러 간다. 난쟁이가 일을 하는 동안 백설공주는 그들을 위해 저녁 식사를 준비한다. 백설공주는 의자 일곱개, 접시 일곱개, 나이프 일곱개를 준비한다.

어느 날 광산에서 아홉 난쟁이가 돌아왔다. (왜 그리고 어떻게 아홉 난쟁이가 돌아왔는지는 아무도 모른다) 아홉 난쟁이는 각각 자신이 백설공주의 일곱 난쟁이라고 우기고 있다.

백설공주는 이런 일이 생길 것을 대비해서, 난쟁이가 쓰고 다니는 모자에 100보다 작은 양의 정수를 적어 놓았다. 사실 백설 공주는 공주가 되기 전에 매우 유명한 수학자였다. 따라서, 일곱 난쟁이의 모자에 쓰여 있는 숫자의 합이 100이 되도록 적어 놓았다.

아홉 난쟁이의 모자에 쓰여 있는 수가 주어졌을 때, 일곱 난쟁이를 찾는 프로그램을 작성하시오. (아홉 개의 수 중 합이 100이 되는 일곱 개의 수를 찾으시오)

입력
총 아홉개 줄에 1보다 크거나 같고 99보다 작거나 같은 자연수가 주어진다. 모든 숫자는 서로 다르다. 또, 항상 답이 유일한 경우만 입력으로 주어진다.

출력
일곱 난쟁이가 쓴 모자에 쓰여 있는 수를 한 줄에 하나씩 출력한다.
*/
