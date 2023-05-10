function solution(scanner) {
    function makeLargeClosest(N, btns) {
        // 버튼이 1개만 있는 case에 대한 예외처리
        if (btns.length <= 1) {
            if (btns.length === 1 && btns[0] === 0) return Infinity;
            if (btns.length === 0) return Infinity;
        }
        const strN = String(N);
        const minButton = btns[0];
        const minButtonExcept0 = (minButton === 0) ? btns[1] : btns[0];
        const maxButton = btns[btns.length - 1];
        let r = '';
        let lastSamePos = -1;
        let isDefinatelyLarge = false;
        for (let i = 0; i < strN.length; i++) {
            // i 번째 자리에 대해서 더 큰 녀석을 찾아보도록 함..
            let closestMax = maxButton;
            if (!isDefinatelyLarge) {
                for (let j = btns.length - 1; j >= 0; j--) {
                    if (btns[j] > Number(strN[i])) {
                        closestMax = btns[j]; // 업데이트
                    } else if (btns[j] === Number(strN[i])) {
                        closestMax = btns[j]; // 업데이트
                        lastSamePos = i;
                    } else {
                        if (maxButton < Number(strN[i]) && lastSamePos !== -1) {
                            if (btns.findIndex(_ => _ === Number(r[lastSamePos])) > 0) {
                                i = lastSamePos;
                                closestMax = btns[btns.findIndex(_ => _ === Number(r[lastSamePos])) + 1];
                                r = r.substr(0, lastSamePos);
                                lastSamePos = -1;
                                isDefinatelyLarge = true;
                            }
                        } // 만약에 그런거 없으면 걍 break..
                        break;
                    }
                }
            } else { // 이미 최대자리수가 증가한 상태이므로, 나머지 자리는 최소 버튼으로 채움.
                closestMax = minButton;
            }
            if (closestMax > Number(strN[i])) {
                isDefinatelyLarge = true;
            }
            r += closestMax; 
            console.log(r);
        }
        if (Number(r) >= N) return Number(r);
        else {
            // 같은자릿수의 크면서 최대한 가까운 놈을 만들 수 없으면, 아래 예외 로직을 작동 시킨다.
            r = '';
            r += minButtonExcept0; // 맨 앞에 최소 크기 더해주고.. (0은 맨앞에 못오니 제외)
            for (let i = 0; i < strN.length; i++) {
                r += minButton; // 역시 가장 최소가 되게 붙여준다.
            }
            return Number(r);
        }
    }
    function makeSmallClosest(N, btns) {
        // 버튼이 1개만 있는 case에 대한 예외처리
        if (btns.length <= 1) {
            if (btns.length === 1 && btns[0] === 0) return Infinity;
            if (btns.length === 0) return Infinity;
        }
        const strN = String(N);
        const minButton = btns[0];
        const minButtonExcept0 = (minButton === 0) ? btns[1] : btns[0];
        const maxButton = btns[btns.length - 1];
        let r = '';
        let lastSamePos = -1;
        let isDefinatelySmall = false;
        for (let i = 0; i < strN.length; i++) {
            // i 번째 자리에 대해서 더 작은 녀석을 찾아보도록 함..
            const logicalMin = (i === 0) ? minButtonExcept0: minButton;
            let closestMin = (i === 0) ? minButtonExcept0: minButton;
            if (!isDefinatelySmall) {
                for (let j = 0; j < btns.length; j++) {
                    if (btns[j] < Number(strN[i])) {
                        closestMin = btns[j]; // 업데이트
                    } else if (btns[j] === Number(strN[i])) {
                        closestMin = btns[j]; // 업데이트
                        lastSamePos = i;
                    } else { // 더 작은 놈이 없는 때가 오면, 아까 체크한을 더 작게 만듬.
                        if (logicalMin > Number(strN[i]) && lastSamePos !== -1) {
                            if (btns.findIndex(_ => _ === Number(r[lastSamePos])) > 0) {
                                i = lastSamePos;
                                closestMin = btns[btns.findIndex(_ => _ === Number(r[lastSamePos])) - 1];
                                r = r.substr(0, lastSamePos);
                                lastSamePos = -1;
                                isDefinatelySmall = true;
                            }
                        } // 만약에 그런거 없으면 걍 break..
                        break;
                    }
                }
            } else {
                closestMin = maxButton;
            }
            if (closestMin < Number(strN[i])) {
                isDefinatelySmall = true;
            }
            r += closestMin;
            console.log(r);
        }
        if (Number(r) <= N) return Number(r);
        else {
            // 같은자릿수의 작으면서 가급적 큰 놈을 만들 수 없으면, 아래 예외 로직을 작동 시킨다.
            r = '';
            for (let i = 0; i < strN.length - 1; i++) { // 한자리 작은 놈으로 만들어서
                r += maxButton; // 가장 크게 한다.
            }
            if (r === '') return Infinity;
            return Number(r);
        }
    }
    const N = scanner.readInt();
    const M = scanner.readInt();
    console.log('TargetChannel:', N);
    const availableButtons = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    for (let i = 0; i < M; i++) {
        const val = scanner.readInt();
        const idx = availableButtons.findIndex(_ => _ === val);
        availableButtons.splice(idx, 1);
    }
    console.log(availableButtons);
    console.log(availableButtons.length);

    // 현재 보고 있는 100번에서의 거리
    const possibleMin1 = Math.abs(100 - N);
    console.log('fromInitChannelBtnCount:', possibleMin1);
    // 가고자 하는 채널보다 좀 더 크게 세팅
    const largeClosest = makeLargeClosest(N, availableButtons);
    const possibleMin2 = String(largeClosest).length + Math.abs(largeClosest - N);
    console.log('largeClosest:', largeClosest);
    console.log('btnInputCount:', possibleMin2);

    // 가고자 하는 채널보다 좀 더 작게 세팅
    const smallClosest = makeSmallClosest(N, availableButtons);
    const possibleMin3 = String(smallClosest).length + Math.abs(N - smallClosest);
    console.log('smallClosest:', smallClosest);
    console.log('btnInputCount:', possibleMin3);

    // 0번 예외처리: 0 이 있으면 0 누르고 이동가능한 case들
    let possibleMin4 = Infinity;
    if (availableButtons[0] === 0) {
        possibleMin4 = 1 + N; // 1: 0을 누르는 행위, 그리고 N 번 채널까지 채널업 버튼 눌러서 이동함.
    }
    console.log('from0ChannelBtnCount:', possibleMin4);
    return Math.min(possibleMin1, possibleMin2, possibleMin3, possibleMin4);
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
리모컨 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	42624	9896	6762	22.363%
문제
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 

수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

출력
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

예제 입력 1 
5457
3
6 7 8
예제 출력 1 
6
예제 입력 2 
100
5
0 1 2 3 4
예제 출력 2 
0
예제 입력 3 
500000
8
0 2 3 4 6 7 8 9
예제 출력 3 
11117
*/
