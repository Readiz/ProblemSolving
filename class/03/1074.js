function solution_compare(scanner) {
    function copy(step) {
        // [참고] 원래 데이터 위치를 수식으로 표현하면
        // db[0] ~ db[prevSize - 1] 이 되고, 이를 복사하는 작업을 해야 한다.
        const prevSize = Math.pow(2, step - 1);
        const newSize = prevSize * 2;
        let base = prevSize * prevSize - 1; // 이 값이 계속 증가할 것..
        // 오른쪽 위 복사
        for (let i = 0; i < prevSize; i++) {
            for (let j = prevSize; j < newSize; j++) {
                db[i][j] = ++base;
            }
        }
        // 왼쪽 아래 복사
        for (let i = prevSize; i < newSize; i++) {
            for (let j = 0; j < prevSize; j++) {
                db[i][j] = ++base;
            }
        }
        // 오른쪽 아래 복사
        for (let i = prevSize; i < newSize; i++) {
            for (let j = prevSize; j < newSize; j++) {
                db[i][j] = ++base;
            }
        }
    }
    console.log('----------------------');
    console.log('TC Start!')
    console.log('----------------------');
    const N = scanner.readInt();
    const r = scanner.readInt();
    const c = scanner.readInt();
    const db = new Array(Math.pow(2, N));
    for (let i = 0; i < Math.pow(2, N); i++) {
        db[i] = new Array(Math.pow(2, N));
        for (let j = 0; j < Math.pow(2, N); j++) {
            db[i][j] = 0;
        }
    }
    db[0][0] = 0; db[0][1] = 1; db[1][0] = 2; db[1][1] = 3;
    for (let i = 2 ; i <= N; i++) {
        // 2^N 크기로 늘려나가면서 배열을 채운다..
        // step의 경우 복사하는 칸의 사이즈라고 보면 됨
        copy(i);
    }
    for (let i = 0; i < Math.pow(2, N); i++) {
        let str = '';
        for (let j = 0; j < Math.pow(2, N); j++) {
            str += db[i][j] + ' ';
        }
        console.log(str);
    }
    console.log('----------------------');
    console.log('TC End!')
    console.log('----------------------');
    return db[r][c];
}
function solution(scanner) {
    function getArea(N, r, c) {
        const split = N / 2;
        if (r < split && c < split) return 1;
        if (r < split && c >= split) return 2;
        if (r >= split && c < split) return 3;
        if (r >= split && c >= split) return 4;
    }
    console.log('----------------------');
    console.log('TC Start!')
    console.log('----------------------');
    const _N = scanner.readInt(); // 이 N은 실질적으로 필요가 없다.
    let r = scanner.readInt();
    let c = scanner.readInt();
    let max = Math.max(r, c);
    let n = 0;
    while (max >= Math.pow(2, n)) {
        n++;
    }
    let N = Math.pow(2, n);
    console.log('N', N);
    let base = 0;
    while (N >= 2) {
        const k = getArea(N, r, c);
        N /= 2;
        console.log('N', N);
        console.log('Area', k);
        if (k == 1) { // 1사분면의 경우는 그대로 사이즈 줄이면 된다.
            // do nothing
        } else if (k == 2) {
            base += N * N;
        } else if (k == 3) {
            base += N * N * 2;
        } else if (k == 4) {
            base += N * N * 3;
        }
        console.log('Base', base);
        r %= N;
        c %= N;
    }
    console.log('----------------------');
    console.log('TC End!')
    console.log('----------------------');
    return base;
}


/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
(function readizInit() {
    const _input = require('fs').readFileSync('/dev/stdin');
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
    if (process.argv[2] !== 'readizDebug') {
        global.console = {
            log: () => {},
            warn: () => {},
            info: () => {},
            debug: () => {},
            error: () => {}
        }
    }
    process.stdout.write(solution(scanner) + '\n');
})();
/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util End
/////////////////////////////////////////////////////////////////////////////////

/*
Z 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.5 초 (추가 시간 없음)	512 MB	28005	9072	6722	37.028%
문제
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.



만약, N > 1이 라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

다음 예는 22 × 22 크기의 배열을 방문한 순서이다.



N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음은 N=3일 때의 예이다.



입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
1 ≤ N ≤ 15
0 ≤ r, c < 2N
예제 입력 1 
2 3 1
예제 출력 1 
11
예제 입력 2 
3 7 7
예제 출력 2 
63
*/
