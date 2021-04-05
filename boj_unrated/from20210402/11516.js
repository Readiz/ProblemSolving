function solution(scanner) {
    const R = [];
    while (true) {
        const N = scanner.readInt();
        if (N === 0) break;
        const program = [];
        const expressions = [];
        const cmds = [];
        for (let i = 0; i < N; i++) {
            let line = scanner.readLine().trim();
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
                curcmds.shift(); // 앞의 cmd를 제거
                expressions.push(replaceToBigIntExpression(curcmds.join('')));
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
            console.log('cmd:', program[pc]);
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
                        const next = findCommandLine(program, 'end while', pc);
                        pc = next + 1;
                        pcStack.pop(); // while 탈출하면, pcStack을 하나 나간다.
                        console.log('jump to', pc, '...');
                        continue;
                    }
                    break;
                }
                case 'end while': {
                    pc = pcStack[pcStack.length - 1];
                    pcStack.pop(); // while 탈출하면, pcStack을 하나 나간다.
                    console.log('end while, continue to while caluse...', pc);
                    continue;
                    break;
                }
                case 'else': {
                    console.log('else is found, jump to end if...');
                    const next = findCommandLine(program, 'end if', pc);
                    pc = next + 1;
                    console.log('jump to', pc, '...');
                    continue;
                    break;
                }
                case 'if': {
                    const result = eval(expressions[pc]);
                    console.log(expressions[pc], result);
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
                    break;
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
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

global.console = {
    log: () => {},
    warn: () => {},
    info: () => {},
    debug: () => {},
    error: () => {}
};

const scanner = {
    readInt: () => {
        return parseInt(lineDB[lineIdx++], 10);
    },
    readLine: () => {
        return lineDB[lineIdx++];
    }
};

let N = 0;
const lineDB = [];
let lineIdx = 0;
rl.on('line', (line) => {
    lineDB.push(line);
    if (N === 0) {
        N = parseInt(line, 10);
        if (N === 0) {
            process.stdout.write(solution(scanner) + '\n');
            process.exit();
        }
        return;
    }
    N--;
});


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
