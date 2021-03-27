function solution(scanner) {
    const T = scanner.readInt();
    const r = [];
    for (let i = 0; i < T; i++) {
        let N = scanner.readInt();
        const db = [];
        for (let i = 0; i < N; i++) {
            db.push(scanner.readInt());
        }
        r.push((Math.max(...db) - Math.min(...db)) * 2);
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
주차의 신 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	1836	1466	1364	81.579%
문제
선영이는 쇼핑하러 긴 도로에 자주 간다. 선영이는 주차를 세상에서 가장 귀찮아 하기 때문에, 아무데나 주차를 한다. 주차를 한 후에는 가려고 했던 상점으로 걸어 간다.

어느 날, 선영이는 다리가 너무 아파서 병원에 갔다. 의사는 선영이에게 되도록 조금 걷거나, 쇼핑을 하지 말라고 했다. 선영이는 쇼핑을 버릴 수 없다. 그녀의 특기를 발휘해서 가장 좋은 주차 자리를 찾으려고 한다.

긴 도로는 일직선이다. 또, 모든 상점의 위치는 정수 좌표를 가지고 있다. 주차장은 모든 정수 좌표마다 하나씩 있으며, 선영이를 위해 항상 비어있다. 선영이는 주차비를 아끼기 위해서 쇼핑을 마치기 전 까지는 주차한 차를 이동시키지 않을 것이다. 선영이는 힘이 매우 세기 때문에, 자신이 쇼핑한 물건을 모두 들지 못하는 경우는 없다. 가려고 계획한 상점은 모두 방문해야 한다.

입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 100) 모든 테스트 케이스는 두 줄로 이루어져 있다. 첫째 줄에는 선영이가 방문할 상점의 수 n이 주어지며 (1 ≤ n ≤ 20), 둘째 줄에는 상점의 위치가 주어진다. (0 ≤ xi ≤ 99)

출력
선영이가 가려고 했던 모든 상점을 방문하고 차로 돌아오기 위해 걸어야 하는 거리의 최솟값을 출력한다. 
*/
