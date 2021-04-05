function solution(scanner) {
    const N = scanner.readInt();
    const before = scanner.readLine();
    const after = scanner.readLine();
    if (N % 2 === 0) {
        if (before === after) {
            return 'Deletion succeeded';
        } else {
            return 'Deletion failed';
        }
    } else {
        let converted = '';
        for (let i = 0; i < after.length; i++) {
            if (after[i] === '0') {
                converted += '1';
            } else {
                converted += '0';
            }
        }
        if (before === converted) {
            return 'Deletion succeeded';
        } else {
            return 'Deletion failed';
        }
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
파일 완전 삭제 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	1773	1104	983	66.285%
문제
어느 날, 상근이의 여자친구는 상근이에게 매우 긴급한 목소리로 전화했다.

"상근아, 나 급하게 지워야 될 파일이 있어! 이 파일은 절대 복구되면 안돼."

파일을 완전 삭제하려면 하드드라이브에서 그 구간을 새로운 데이터로 반복해서 덮어써야 한다.

상근이는 여자친구를 위해 파일 완전 삭제 프로그램을 만들려고 한다. 파일 완전 삭제 프로그램은 매우 간단하다. 사용자는 삭제할 파일을 하나 고르고, 몇 번 덮어씌울지 n을 입력한다. n은 1부터 20까지 숫자 중 하나를 골라야 한다. 상근이의 프로그램은 파일을 비트단위로 덮어씌운다. 한 번 덮어씌울 때, 0인 비트는 1로, 1인 비트는 0으로 덮어씌운다.

상근이는 프로그램을 완성했고 테스트해보려고 한다. 파일을 삭제하기 전에 파일이 있었던 곳의 비트와 파일을 삭제한 후에 파일이 있었던 곳의 비트가 주어졌을 때, 프로그램을 올바르게 작성했는지 출력한다.

이 문제에서 파일이 실제로 삭제되었는지는 중요한 것은 아니다. 따라서, 문제에서 설명한대로 상근이가 프로그램을 작성했으면 삭제가 성공한 것으로, 그 외의 경우는 모두 실패한 것이다.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 20) 둘째 줄에는 파일을 삭제하기 전에 파일이 있었던 곳의 비트가 주어지고, 셋째 줄에는 삭제한 후에 비트가 주어진다. 비트는 0과 1로만 이루어져 있고, 두 문자열의 길이는 같다. 비트는 최대 1000개의 문자로 이루어져 있다. 

출력
첫째 줄에 삭제가 성공했으면 "Deletion succeeded"을, 실패했으면 "Deletion failed"을 출력한다.

예제 입력 1 
1
10001110101000001111010100001110
01110001010111110000101011110001
예제 출력 1 
Deletion succeeded
예제 입력 2 
20
0001100011001010
0001000011000100
예제 출력 2 
Deletion failed
*/
