function solution(scanner) {
    const r = [];
    const lines = scanner.readAll().split('\n');
    for (let line of lines) {
        console.log('-------------------------------------');
        console.log('Current Line:', line);
        console.log('-------------------------------------');

        const stack = [];
        // 1. Context Tag Stack 구성
        let pos = 0;
        let validStack = true;
        while (line.indexOf('<', pos) > -1) {
            const curTagStartPos = line.indexOf('<', pos);
            const curTagEndPos = line.indexOf('>', curTagStartPos);
            const tagName = line.substr(curTagStartPos + 1, curTagEndPos - curTagStartPos - 1);
            console.log(curTagEndPos, tagName);
            if (curTagStartPos !== -1 && curTagEndPos !== -1) {
                // 유효 TagName 검사
                // 빈거 검사..
                if (tagName === '' || tagName === '/') {
                    console.log('tagName is empty! invalid!');
                    validStack = false;
                    break;
                }
                // / 를 제외하고 검사..
                let tagNameforValidation = tagName;
                if (tagName.startsWith('/')) {
                    tagNameforValidation = tagNameforValidation.substr(1);
                } else if (tagName.endsWith('/')) {
                    tagNameforValidation = tagNameforValidation.substr(0, tagNameforValidation.length - 1);
                }
                const checkInvalidChar = tagNameforValidation.split('').filter(_ => !['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                                                                      'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                                                                                      'q', 'r', 's', 't', 'u', 'v', 'w', 'x' ,'y', 'z',
                                                                                      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'].includes(_));
                if (checkInvalidChar.length > 0) {
                    console.log('tagName:', tagName, 'is invalid! (reason: invalid tag char detected)', checkInvalidChar);
                    validStack = false;
                    break;
                }

                // 여는 태그 / 닫는 태그
                if (tagName.startsWith('/')) {
                    const stackTop = stack.pop();
                    if (tagName.substr(1) === stackTop) {
                        // 이 경우 올바른 경우임
                        console.log(stackTop, tagName, 'matched!');
                    } else {
                        // 올바르지 않은 스택 구성, false 세팅.
                        console.log(stackTop, tagName, 'unmatched stack! invalid.');
                        validStack = false;
                        break;
                    }
                } else if (tagName.endsWith('/')) {
                    // 이 경우 Push 되지 않음
                    console.log(tagName, 'not added.');
                } else {
                    console.log(tagName, 'added.');
                    stack.push(tagName);
                }
                let newLine = line.split('');
                newLine.splice(curTagStartPos, curTagEndPos - curTagStartPos + 1);
                line = newLine.join('')
                console.log('NewLine:', line);
                pos = 0;
            } else {
                validStack = false;
                break;
            }
        }
        if (validStack === false) {
            r.push('invalid');
            continue;
        }
        // 2. Context Tag Stack Validation
        if (stack.length !== 0) {
            console.log('invalid stack remained:', stack);
            r.push('invalid');
            continue;
        }
        // 3. &xHEX; 검사
        pos = 0;
        let validAmp = true;
        while (line.indexOf('&', pos) > -1) {
            let ampStartPos = line.indexOf('&', pos);
            let ampEndPos = line.indexOf(';', ampStartPos);
            const ampName = line.substr(ampStartPos + 1, ampEndPos - ampStartPos - 1);
            if (ampStartPos !== -1 && ampEndPos !== -1) {
                if (['gt', 'lt', 'amp'].indexOf(ampName) > -1) {
                    console.log('ampName:', ampName, 'is valid.');
                } else if(ampName.startsWith('x')) {
                    const HEX = ampName.substr(1);
                    // 길이 짝수인지 검사
                    if (HEX.length % 2 === 0 && HEX.length > 0) {
                        // 문자열 구성 검사
                        const checkInvalidChar = HEX.split('').filter(_ => !['A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'].includes(_));
                        if (checkInvalidChar.length > 0) {
                            console.log('ampName:', ampName, 'is invalid! (reason: invalid HEX char)');
                            validAmp = false;
                            break;
                        } else {
                            console.log('ampName:', ampName, 'is valid.');
                        }
                    } else {
                        console.log('ampName:', ampName, 'is invalid! (reason: HEX length is not even)');
                        validAmp = false;
                        break;
                    }
                } else {
                    console.log('ampName:', ampName, 'is invalid! (reason: Not available char with &)');
                    validAmp = false;
                    break;
                }
                let newLine = line.split('');
                newLine.splice(ampStartPos, ampEndPos - ampStartPos + 1);
                line = newLine.join('')
                console.log('NewLine:', line);
                pos = 0;
            } else {
                validAmp = false;
                break;
            }
        }
        if (validAmp === false) {
            r.push('invalid');
            continue;
        }

        // 4. 와서는 안되는 문자열이 있는지 확인
        // &, <, > 등
        const checkInvalidChar = line.split('').filter(_ => ['&', '<', '>'].includes(_));
        if (checkInvalidChar.length > 0) {
            console.log('line is invalid! invalid char is remained:', line);
            r.push('invalid');
            continue;
        }
        // 다 통과했으면, valid를 부여
        console.log('line is valid. final:', line);
        r.push('valid');
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
        },
        readAll: () => {
            _index = _index_max;
            return _input.toString('utf-8', 0, _index_max);
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
XML 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	541	71	30	15.228%
문제
인터넷프로그래밍 교수 이다솜은 XML이야말로 세상을 바꿀 혁신적인 언어라고 믿으며, 항상 학생들에게 XML의 장점을 어필한다.
그러나 잘못 사용되었다가는 지구를 파괴할 수도 있는 무시무시한 부작용도 존재하기에, 문법이 맞게 되었는지를 판정하는 파서가 필요하게 되었다. 그러나 이다솜은 XML을 할 줄 모르기에 여러분이 판독기를 구현해야 한다.

우리가 XML 문서의 형식이 유효한지 판별하는 기준은 다음과 같다.

평문---32~127 사이에 있는(32, 127도 포함) ASCII코드값으로 이루어지며, 다음 문자는 포함되면 안 된다: <, >, &
다음과 같은 문자열:
&lt;
&gt;
&amp;
이것들은 각각 <, >, &를 인코딩한다.
&xHEX; HEX는 양의 짝수 자릿수의 16진수여야 하며, 0~9 또는 알파벳 A~F 대소문자로 이루어진다.
<tag> 여는 태그이다. 태그는 숫자 또는 알파벳 소문자로 이루어진 문자열이어야 한다. 이 태그는 context 스택에 push된다.
<tag/> 이 태그는 context 스택에 push되지 않는다.
</tag> 닫는 태그이다. context 스택의 맨 위에 있는 태그를 pop하게 된다. 단, 이때 맨 위에 있는 태그와 이 태그의 문자열이 일치해야 한다.
문서 전체가 파싱된 후에는 context 스택은 비어 있어야 한다. 또한, 빈 문자열 역시 유효하다고 판정한다.

입력
여러 줄의 입력이 주어진다. 각 줄에 대해 유효한 XML 문법인지를 판별한다. 각 줄은 ASCII 코드 값이 32~127인 문자로만 이루어져 있으며, 비어 있는 줄이 들어올 수도 있다. 입력은 파일 끝에서 종료된다.

출력
각 줄에 대하여, 해당 줄이 유효한 XML 문법을 가지고 있다면 valid를, 그렇지 않다면 invalid를 출력한다.

예제 입력 1 
the quick brown fox.
the <i><b>quick</b> brown</i> fox.
<doc>fox &amp; socks.</doc>
3x+5&gt;7
Null: &x00;
<doc>the quick brown fox.
the <i>quick <b>brown</i></b> fox
fox & socks.
3x+5>7
Null: &x0;
예제 출력 1 
valid
valid
valid
valid
valid
invalid
invalid
invalid
invalid
invalid
*/
