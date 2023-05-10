function solution(scanner) {
    const r = [];
    while(true) {
        const line = scanner.readLine();
        if (line === 'EOI') break;
        if (line.toLowerCase().indexOf('nemo') > -1) r.push('Found');
        else r.push('Missing');
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
니모를 찾아서 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	2073	981	880	52.195%
문제
니모에 대한 이미지 검색결과

영어 문장속 숨어있는 니모(Nemo)를 찾아보자. 니모를 찾는데 있어서 대소문자는 중요하지 않다.

입력
여러 문장이 각 줄로 입력되며, 입력의 마지막에는 "EOI" 입력된다. 한 줄은 최대 80개의 글자로 이루어져 있다.

출력
숨겨진 니모를 찾으면 “Found”, 못찾으면 “Missing”를 각 줄에 맞게 출력하면 된다.

예제 입력 1 
Marlin names this last egg Nemo, a name that Coral liked.
While attempting to save nemo, Marlin meets Dory,
a good-hearted and optimistic regal blue tang with short-term memory loss. 
Upon leaving the East Australian Current,(888*%$^&%0928375)Marlin and Dory
NEMO leaves for school and Marlin watches NeMo swim away.
EOI
예제 출력 1 
Found
Found
Missing
Missing
Found
*/
