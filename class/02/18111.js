function solution(scanner) {
    function getCost(targetLevel) {
        let cost = 0;
        db.forEach(_ => {
            if (_ < targetLevel) { // 채워야 하는 case
                cost += targetLevel - _;
            } else if (_ > targetLevel) { // 깎아야 하는 case
                cost += (_ - targetLevel) * 2;
            }
        });
        return cost;
    }
    function getBlock(targetLevel) {
        let block = 0;
        db.forEach(_ => {
            if (_ < targetLevel) { // 채워야 하는 case
                block -= targetLevel - _;
            } else if (_ > targetLevel) { // 깎아야 하는 case
                block += _ - targetLevel;
            }
        });
        return block;
    }
    
    console.log('----------------------');
    console.log('TC Start!')
    console.log('----------------------');
    const N = scanner.readInt();
    const M = scanner.readInt();
    let B = scanner.readInt();
    const db = [];
    for (let i = 0; i < N * M; i++) {
        db.push(scanner.readInt());
    }
    console.log(db);
    let curLevel = Math.floor(db.reduce((_, i) => _ + i) / (M * N));
    console.log('initLevel', curLevel); // 거의 대부분, 평균 값으로부터 시작하는게 제일 정답에 근접할 것이라 가정..
    let minCost = getCost(curLevel); // 최소 걸리는 시간 계산 시작..
    B += getBlock(curLevel);
    console.log('curBlock', B);
    let minLevel = curLevel;
    
    // 여기서 이제 1 Level씩 올라가자.
    // 기본적으로 더 내려가는 것은 의미가 없고 (cost만 단순 증가니..)
    // 남은 Block이 있는 한에서 올라가되, 오히려 cost가 증가하기 시작하면 중단.
    while (B >= N * M) {
        B -= N * M;
        curLevel++;
        const newCost = getCost(curLevel);
        console.log('----------------------');
        console.log('remain Block', B);
        console.log('curLevel', curLevel);
        console.log('cost', newCost);
        if (newCost <= minCost) { // 등호가 있는 이유는 문제 조건에서 가급적 높은 땅을 선택하라 했기 때문..
            minCost = newCost;
            minLevel = curLevel;
        } else {
            // cost가 증가하기 시작하면, 더이상 계산하지 않는다.
            break;
        }
    }
    console.log('----------------------');
    console.log('TC End!')
    console.log('----------------------');
    return minCost + ' ' + minLevel;
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
마인크래프트 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (추가 시간 없음)	1024 MB	6268	1947	1515	29.452%
문제
팀 레드시프트는 대회 준비를 하다가 지루해져서 샌드박스 게임인 ‘마인크래프트’를 켰다. 마인크래프트는 1 × 1 × 1(세로, 가로, 높이) 크기의 블록들로 이루어진 3차원 세계에서 자유롭게 땅을 파거나 집을 지을 수 있는 게임이다.

목재를 충분히 모은 lvalue는 집을 짓기로 하였다. 하지만 고르지 않은 땅에는 집을 지을 수 없기 때문에 땅의 높이를 모두 동일하게 만드는 ‘땅 고르기’ 작업을 해야 한다.

lvalue는 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 우리의 목적은 이 집터 내의 땅의 높이를 일정하게 바꾸는 것이다. 우리는 다음과 같은 두 종류의 작업을 할 수 있다.

좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다. ‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.

단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 또한, 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다. 땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.

입력
첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)

둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다. (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다. 땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오. 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.
*/
