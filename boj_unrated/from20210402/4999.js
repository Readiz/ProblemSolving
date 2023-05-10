function solution(scanner) {
    const line = scanner.readLine();
    const line2 = scanner.readLine();
    return line.length >= line2.length ? 'go' : 'no';
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
아! 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	5843	3629	3360	62.874%
문제
재환이는 저스틴 비버 콘서트에서 소리를 너무 많이 질러서 인후염에 걸렸다.

의사는 재환이에게 "aaah"를 말해보라고 시켰다. 안타깝게도 재환이는 의사가 원하는만큼 소리를 길게 낼 수 없는 경우가 있었다.

각각의 의사는 재환이에게 특정한 길이의 "aah"를 말해보라고 요청한다. 어떤 의사는 "aaaaaah"를 요구하기도 하고, "h"만 요구하는 의사도 있다.

모든 의사는 자신이 원하는 길이의 "aah"를 듣지 못하면 진단을 내릴 수 없다.

따라서, 재환이는 집에서 자신이 얼마나 길게 "aah"를 낼 수 있는지 알아냈고, 자기가 소리낼 수 있는 길이의 "aah"를 요구하는 의사를 방문하려고 한다.

재환이가 낼 수 있는 "aah"의 길이와 의사가 요구하는 길이가 주어진다. 이때, 그 병원에 가야하는지 말아야하는지를 알아내는 프로그램을 작성하시오.

입력
입력은 두 줄로 이루어져 있다. 첫째 줄은 재환이가 가장 길게 낼 수 있는 "aaah"이다. 둘째 줄은 의사가 듣기를 원하는 "aah"이다. 두 문자열은 모두 a와 h로만 이루어져 있다. a의 개수는 0보다 크거나 같고, 999보다 작거나 같으며, 항상 h는 마지막에 하나만 주어진다.

출력
재환이가 그 병원에 가야하면 "go"를, 아니면 "no"를 출력한다.

예제 입력 1 
aaah
aaaaah
예제 출력 1 
no
예제 입력 2 
aaah
ah
예제 출력 2 
go
*/
