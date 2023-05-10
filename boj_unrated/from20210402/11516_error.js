function solution(scanner) {
    const R = [];
    while (true) {
        const N = scanner.readInt();
        if (N === 0) break;
        const program = [];
        for (let i = 0; i < N; i++) {
            let line = scanner.readLine().trim();
            let lineNew = line.replace(/\s\s+/g, ' ');
            while (lineNew != line) {
                line = lineNew;
                lineNew = line.replace(/\s\s+/g, ' ');
            }
            program.push(line);
        }
        console.log(program);

        // a ~ z의 값을 초기화
        a = 0n; b = 0n; c = 0n; d = 0n; e = 0n; f = 0n; g = 0n; h = 0n; i = 0n; j = 0n;
        k = 0n; l = 0n; m = 0n; n = 0n; o = 0n; p = 0n; q = 0n; r = 0n; s = 0n; t = 0n;
        u = 0n; v = 0n; w = 0n; x = 0n; y = 0n; z = 0n;

        let pc = 0;
        const pcStack = []; // while 등을 만났을 때 분기할 주소
        while (pc < N) {
            console.log('cmd:', program[pc]);
            const cmd = program[pc].split(' ')[0];
            if (cmd === 'print') {
                let expression = program[pc].split(' ');
                expression.shift(); // 앞의 print를 제거
                expression = replaceToBigIntExpression(expression.join(''));
                const result = eval(expression);
                console.log(result);
                R.push(result);
            } else if (cmd === 'set') {
                let expression = program[pc].split(' ');
                expression.shift(); // 앞의 print를 제거
                expression = replaceToBigIntExpression(expression.join(''));
                const result = eval(expression);
                console.log(expression, result);
            } else if (cmd === 'while') {
                pcStack.push(pc);
                let expression = program[pc].split(' ');
                expression.shift();
                expression = replaceToBigIntExpression(expression.join(''));
                const result = eval(expression);
                console.log(expression, result);
                if (result) {
                    console.log('while expression is true, continue');
                } else {
                    console.log('while expression is false, jump...');
                    const next = findCommandLine(program, 'end while', pc);
                    pc = next + 1;
                    pcStack.pop(); // while 탈출하면, pcStack을 하나 나간다.
                    console.log('jump to', pc, '...');
                    continue;
                }
            } else if (cmd === 'end') {
                const endWhat = program[pc].split(' ')[1];
                if (endWhat === 'while') {
                    pc = pcStack[pcStack.length - 1];
                    console.log('end while, continue to while caluse...', pc);
                    continue;
                }
            } else if (cmd === 'else') {
                console.log('else is found, jump to end if...');
                const next = findCommandLine(program, 'end if', pc);
                pc = next + 1;
                console.log('jump to', pc, '...');
                continue;
            } else if (cmd === 'if') {
                let expression = program[pc].split(' ');
                expression.shift();
                expression = replaceToBigIntExpression(expression.join(''));
                const result = eval(expression);
                console.log(expression, result);
                if (result) {
                    console.log('if expression is true, continue');
                } else {
                    console.log('if expression is false, jump to else...');
                    const nextElse = findCommandLine(program, 'else', pc);
                    const nextEndIf = findCommandLine(program, 'end if', pc);
                    if (nextElse < nextEndIf) {
                        // 이 경우에만 유효한 else - endif 문임
                        pc = nextElse + 1;
                        console.log('jump to', pc, '...');
                        continue;
                    } else { // else 문이 없는 end if임.
                        pc = nextEndIf + 1;
                        console.log('jump to', pc, '...');
                        continue;
                    }
                }
            }
            pc++;
        }

    } 
    return R.join('\n');

    function findCommandLine(program, target, start) {
        const sliced = program.slice(start);
        if (sliced.indexOf(target) > -1) {
            return sliced.indexOf(target) + start;
        }
        return -1;
    }
    function replaceToBigIntExpression(line) {
        let r = '';
        let isNumberStarted = false;
        line = String(line);
        for (let i = 0; i < line.length; i++) {
            if (line.charCodeAt(i) >= 48 && line.charCodeAt(i) <= 57) {
                isNumberStarted = true;
            } else {
                if (isNumberStarted) {
                    r += 'n';
                }
                isNumberStarted = false;
            }
            r += line[i];
        }
        if (isNumberStarted) r += 'n';
        return r;
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
