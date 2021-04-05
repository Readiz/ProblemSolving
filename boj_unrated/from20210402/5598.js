function solution(scanner) {
    const line = scanner.readLine();
    let r = '';
    for (let i = 0; i < line.length; i++) {
        if (line[i] === 'A') {
            r += 'X';
        } else if (line[i] === 'B') {
            r += 'Y';
        } else if (line[i] === 'C') {
            r += 'Z';
        } else {
            r += String.fromCharCode(line.charCodeAt(i) - 3);
        }
    }
    return r;
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
카이사르 암호 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	6306	3621	3268	59.592%
문제
가이우스 율리우스 카이사르(Gaius Julius Caesar)는 고대 로마 군인이자 정치가였습니다. 카이사르는 비밀스럽게 편지를 쓸 때, 'A'를 'D로', 'B'를 'E'로, 'C'를 'F'로... 이런 식으로 알파벳 문자를 3개씩 건너뛰어 적었다고 합니다.

26개의 대문자 알파벳으로 이루어진 단어를 카이사르 암호 형식으로 3문자를 옮겨 겹치지 않게 나열하여 얻은 카이사르 단어가 있습니다. 이 카이사르 단어를 원래 단어로 돌려놓는 프로그램을 작성하세요.

각 문자별로 변환 전과 변환 후를 나타낸 건 아래와 같습니다.

      변환전    A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
      변환후    D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
예를 들어서, 이 방법대로 단어 'JOI'를 카이사르 단어 형식으로 변환한다면 'MRL'을 얻을 수 있고, 앞의 예와 같은 방법으로 얻은 카이사르 단어 'FURDWLD'를 원래 단어로 고치면 'CROATIA'가 됩니다.

입력
입력은 한 줄로 이루어져 있으며, 그 한 줄엔 대문자 알파벳으로 구성된 단어가 1개 있습니다.

입력받는 단어는 최대 1000자 이하입니다.

출력
출력은 입력받은 카이사르 단어를 원래 단어로 고친 걸 출력하시면 됩니다.

예제 입력 1 
MRL
예제 출력 1 
JOI
*/
