function solution(scanner) {
    const R = [];
    while (true) {
        const N = scanner.readInt();
        if (N === 0) break;
        const program = [];
        const expressions = [];
        const cmds = [];
        for (let i = 0; i < N; i++) {
            let line = scanner.readLine();
            line = highlightKeyword(line);
            line = line.trim();
            let lineNew = line.replace(/\s\s+/g, ' ');
            while (lineNew != line) {
                line = lineNew;
                lineNew = line.replace(/\s\s+/g, ' ');
            }
            program.push(line);

            const curcmds = line.split(' ');
            if (curcmds[0] === 'end') {
                if (curcmds[1] === 'while') {
                    cmds.push('end while');
                } else {
                    cmds.push('end if');
                }
            } else {
                cmds.push(curcmds[0]);
            }
            if (['print' ,'set', 'while', 'if'].indexOf(curcmds[0]) > -1) {
                const cmdType = curcmds[0];
                curcmds.shift(); // 앞의 cmd를 제거
                let convertedExpression = curcmds.join('');
                // unary 연산 예외처리 (-- -> +)
                let convertedExpressionNew = convertedExpression.replace('--', '+');
                convertedExpressionNew = convertedExpressionNew.replace('++', '+');
                convertedExpressionNew = convertedExpressionNew.replace('+-', '-');
                convertedExpressionNew = convertedExpressionNew.replace('-+', '-');
                while (convertedExpressionNew != convertedExpression) {
                    convertedExpression = convertedExpressionNew;
                    convertedExpressionNew = convertedExpressionNew.replace('--', '+');
                    convertedExpressionNew = convertedExpressionNew.replace('++', '+');
                    convertedExpressionNew = convertedExpressionNew.replace('+-', '-');
                    convertedExpressionNew = convertedExpressionNew.replace('-+', '-');
                }
                if (cmdType === 'set') {
                    convertedExpression = replaceToBigIntExpression(convertedExpression, true);
                } else {
                    convertedExpression = replaceToBigIntExpression(convertedExpression);
                }
                expressions.push(convertedExpression);
            } else {
                expressions.push('');
            }
        }
        console.log(program);
        console.log(cmds);
        console.log(expressions);

        // a ~ z의 값을 초기화
        a = 0n; b = 0n; c = 0n; d = 0n; e = 0n; f = 0n; g = 0n; h = 0n; i = 0n; j = 0n;
        k = 0n; l = 0n; m = 0n; n = 0n; o = 0n; p = 0n; q = 0n; r = 0n; s = 0n; t = 0n;
        u = 0n; v = 0n; w = 0n; x = 0n; y = 0n; z = 0n;

        let pc = 0;
        const pcStack = []; // while 등을 만났을 때 분기할 주소
        while (pc < N) {
            console.log(`----[CMD ${pc}]`, program[pc]);
            switch (cmds[pc]) {
                case 'print': {
                    const result = eval(expressions[pc]);
                    console.log(expressions[pc], result);
                    R.push(result);
                    break;
                }
                case 'set': {
                    const result = eval(expressions[pc]);
                    console.log(expressions[pc], result);
                    break;
                }
                case 'while': {
                    pcStack.push(pc);
                    const result = eval(expressions[pc]);
                    console.log(expressions[pc], result);
                    if (result) {
                        console.log('while expression is true, continue');
                    } else {
                        console.log('while expression is false, jump...');
                        let nextWhile = findCommandLine(program, 'while', pc + 1);
                        let nextEnd = findCommandLine(program, 'end while', pc + 1);
                        // 다음 While이 존재하고, while 뒤에 end가 존재하면, 무시한다. (자식 While 문의 끝임)
                        while (nextWhile !== -1 && nextEnd > nextWhile) {
                            nextWhile = findCommandLine(program, 'while', nextEnd);
                            nextEnd = findCommandLine(program, 'end while', nextWhile);
                        }
                        pc = nextEnd;
                        pcStack.pop(); // while 탈출하면, pcStack을 하나 나간다.
                        console.log('jump to', pc, '...');
                    }
                    break;
                }
                case 'end while': {
                    pc = pcStack[pcStack.length - 1] - 1;
                    pcStack.pop(); // while 탈출하면, pcStack을 하나 나간다.
                    console.log('end while, continue to while caluse...');
                    break;
                }
                case 'else': {
                    console.log('else is found, jump to end if...');
                    const next = findCommandLine(program, 'end if', pc);
                    pc = next;
                    console.log('jump to', pc + 1, '...');
                    break;
                }
                case 'if': {
                    const result = eval(expressions[pc]);
                    console.log(expressions[pc], result);
                    if (result) {
                        console.log('if expression is true, continue');
                    } else {
                        console.log('if expression is false, jump to else...');
                        let nextIf = findCommandLine(program, 'if', pc + 1);
                        let nextElse = findCommandLine(program, 'else', pc + 1);
                        let nextEndIf = findCommandLine(program, 'end if', pc + 1);
                        // 다음 If가 존재하고, If 뒤에 end가 존재하면, 무시한다. (자식 If 문의 끝임)
                        while (nextIf !== -1 && nextEndIf > nextIf) {
                            nextIf = findCommandLine(program, 'if', nextEndIf);
                            nextElse = findCommandLine(program, 'else', nextIf);
                            nextEndIf = findCommandLine(program, 'end if', nextIf);
                        }
                        if (nextElse !== -1 && nextElse < nextEndIf) {
                            // 이 경우에만 유효한 else - endif 문임
                            pc = nextElse;
                            console.log('jump to', pc, '...');
                        } else { // else 문이 없는 end if임.
                            pc = nextEndIf;
                            console.log('jump to', pc, '...');
                        }
                    }
                    break;
                }
            }
            pc++;
        }

    } 
    return R.join('\n');

    function highlightKeyword(line) {
        line = line.replace('while', 'while ');
        line = line.replace('if', 'if ');
        line = line.replace('print', 'print ');
        return line;
    }
    function findCommandLine(program, target, start) {
        const sliced = program.slice(start);
        // console.log('sliced', sliced);
        // console.log('indexOf', target, sliced.indexOf(target));
        if (sliced.indexOf(target) > -1) {
            return sliced.indexOf(target) + start;
        }
        return -1;
    }
    function mapTokenToString(_, idx, arr) {
       // Token을 String으로 변화 시킴.
        if (_.type === 'group') {
            let tokens = parseTokens(_.content.substr(1, _.content.length - 2));
            tokens = tokens.map(mapTokenToString);
            return '(' + tokens.join('') + ')';
        } else if (_.type === 'number' || _.type === 'var') {
            if (idx > 0 && arr[idx - 1].type === 'operator') { // 앞검사
                if (arr[idx - 1].content === '!') {
                    return 'BigInt(!Boolean(' + _.content + '))';
                } else if (['&&', '||'].indexOf(arr[idx - 1].content) > -1) {
                    // 이전 타입이 boolean type이면, boolean으로 변환시킨다.
                    return 'BigInt(Boolean(' + _.content + '))';
                } else {
                    return 'BigInt(' + _.content + ')';
                }
            } else if (idx < (arr.length - 1) && arr[idx + 1].type === 'operator') { // 뒤검사
                if (['&&', '||'].indexOf(arr[idx + 1].content) > -1) {
                    // 뒤 타입이 boolean type이면, boolean으로 변환시킨다.
                    return 'BigInt(Boolean(' + _.content + '))';
                } else {
                    return 'BigInt(' + _.content + ')';
                }
            } else {
                return 'BigInt(' + _.content + ')';
            }
        } else if (_.type === 'operator') {
            if (_.content !== '!') {
                // "!" 의 경우, 뒤쪽에서 자체 처리함.
                return _.content;
            } else {
                return '';
            }
        }
    }
    function replaceToBigIntExpression(line, isSetCmd) {

        // setCmd 예외처리
        let prefix = '';
        if (isSetCmd) {
            prefix = line.substr(0, 2);
            line = line.substr(2);
        }
        let tokens = parseTokens(line);
        tokens = tokens.map(mapTokenToString);
        console.log('result', tokens);

        return prefix + tokens.join('');

        // let r = '';
        // let isNumberStarted = false;
        // line = String(line);
        // for (let i = 0; i < line.length; i++) {
        //     if (line.charCodeAt(i) >= 48 && line.charCodeAt(i) <= 57) {
        //         isNumberStarted = true;
        //     } else {
        //         if (isNumberStarted) {
        //             r += 'n';
        //         }
        //         isNumberStarted = false;
        //     }
        //     r += line[i];
        // }
        // if (isNumberStarted) r += 'n';
        // if (isSetCmd) {
        //     const prefix = r.substr(0, 2);
        //     let tmp = r.substr(2);
        //     tmp = replaceAll(tmp, '-', '+-');
        //     tmp = tmp.split('+').map(_=>_);
        //     r = prefix + 'BigInt(' + tmp.join(')+BigInt(') + ')';
        //     r = replaceAll(r, '+-', '-')
        // } else {
        //     let tmp = replaceAll(r, '-', '+-');
        //     tmp = tmp.split('+').map(_=>_);
        //     r = 'BigInt(' + tmp.join(')+BigInt(') + ')';
        //     r = replaceAll(r, '+-', '-')
        // }
        // return r;
    }
    function replaceAll(str, searchStr, replaceStr) {
        return str.split(searchStr).join(replaceStr);
     }
     function parseTokens(line) {
        // 숫자, 문자와 수식 표현을 분리.
        // !의 경우 바깥으로 묶어서 BigInt 화.
        // Logical 연산의 경우 좌/우 묶어서, true / false 리턴할 수 있어야 함.
        // 0 ---!!!n 같은거... 음...
        // Group을 정의할까? a, b, c / 1234, 5678 / (Expression) .. 으로 그룹을 정의.
        // Group과 Operator를 정의하면 될듯.. 다만 - 와 !는 예외. -> Self 연산자..
        // !와 -의 경우에는, Operator 다음을 봐야 함..
        const tokens = [];
        // token은 type과 content를 담는 녀석의 object의 array.
        // type: group, var, operator, number
        let curToken = '';
        let depth = 0;
        let mode = undefined;
        for (let i = 0; i < line.length; i++) {
            if (!mode) { // 처음 시작되는 경우
                if (line[i] === '(') {
                    depth += 1;
                    curToken += line[i];
                    mode = 'group';
                } else if (line[i] === ')') {
                    depth -= 1;
                    curToken += line[i];
                    if (depth === 0) { // 최상단 토큰이 끝나면..
                        mode = undefined;
                        tokens.push({
                            type: 'group',
                            content: curToken
                        });
                        curToken = '';
                    }
                } else if (line.charCodeAt(i) >= 97 && line.charCodeAt(i) <= 122) { // a ~ z
                    if (depth === 0) {
                        tokens.push({
                            type: 'var',
                            content: line[i]
                        });
                    } else {
                        curToken += line[i];
                    }
                } else if (line.charCodeAt(i) >= 48 && line.charCodeAt(i) <= 57) {
                    curToken += line[i];
                    mode = 'number';
                } else if (['+', '-', '!', '*', '/', '%', '<', '>'].indexOf(line[i]) > -1) {
                    if (depth === 0) {
                        tokens.push({
                            type: 'operator',
                            content: line[i]
                        });
                    } else {
                        curToken += line[i];
                    }
                } else if (['<=', '>=', '==', '!=', '&&', '||'].indexOf(line[i] + line[i+1]) > -1) {
                    if (depth === 0) {
                        tokens.push({
                            type: 'operator',
                            content: line[i] + line[i+1]
                        });
                    } else {
                        curToken += line[i] + line[i+1];
                    }
                    i++;
                }
            } else {
                if (line[i] === '(') {
                    depth += 1;
                    curToken += line[i];
                } else if (line[i] === ')') {
                    depth -= 1;
                    curToken += line[i];
                    if (depth === 0) { // 최상단 토큰이 끝나면..
                        mode = undefined;
                        tokens.push({
                            type: 'group',
                            content: curToken
                        });
                        curToken = '';
                    }
                } else if (['+', '-', '!', '*', '/', '%', '<', '>'].indexOf(line[i]) > -1) {
                    if (mode === 'number') {
                        mode = undefined;
                        tokens.push({
                            type: 'number',
                            content: curToken
                        });
                        curToken = '';
                        tokens.push({
                            type: 'operator',
                            content: line[i]
                        });
                    } else {
                        curToken += line[i];
                    }
                } else if (['<=', '>=', '==', '!=', '&&', '||'].indexOf(line[i] + line[i+1]) > -1) {
                    if (mode === 'number') {
                        mode = undefined;
                        tokens.push({
                            type: 'number',
                            content: curToken
                        });
                        curToken = '';
                        tokens.push({
                            type: 'operator',
                            content: line[i] + line[i+1]
                        });
                    } else {
                        curToken +=  line[i] + line[i+1];
                    }
                    i++;
                } else {
                    curToken += line[i];
                }
            }
        }
        // 남아있는 number 처치
        if (mode === 'number') {
            mode = undefined;
            tokens.push({
                type: 'number',
                content: curToken
            });
            curToken = '';
        }
        console.log(tokens);
        return tokens;
     }
}

/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
const scanner = {
    readInt: () => {
        return parseInt(__lineDB[__lineIdx++], 10);
    },
    readLine: () => {
        return __lineDB[__lineIdx++];
    }
};
let __lineDB = [];
let __lineIdx = 0;
const isDebug = process.argv[2] === 'readizDebug';
if (!isDebug) {
    global.console = {
        log: () => {},
        warn: () => {},
        info: () => {},
        debug: () => {},
        error: () => {}
    };
    const rl = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.on('line', (line) => {
        __lineDB.push(line);
    });
    rl.on('close', () => {
        process.stdout.write(solution(scanner) + '\n');
    });
} else {
    __lineDB = require('fs').readFileSync(process.argv[1].replace('.js', '_input.txt')).toString().split('\n');
    process.stdout.write('--------------------------------------------\n');
    process.stdout.write('New Start + Log\n');
    process.stdout.write('--------------------------------------------\n');
    const start = __lineIdx;
    const answer = solution(scanner);
    const end = __lineIdx;
    process.stdout.write('----------------------\n');
    process.stdout.write('Input\n')
    process.stdout.write('----------------------\n');
    process.stdout.write(__lineDB.slice(start, end).join('\n') + '\n');
    process.stdout.write('----------------------\n');
    process.stdout.write('Answer\n')
    process.stdout.write('----------------------\n');
    process.stdout.write(answer + '\n');
}


/*
구현하기..

11
    set n = 22
    set s = 1
    while n > 1
        if n % 2 == 0
            set n = n / 2
        else
            set n = 3 * n + 1
        end if
        set s = s + 1
    end while
    print s
1
    print ((2*4-6/3)*(3*5+8/4))-(2+3)+1/2*0
0
*/
