function solution(scanner) {
    const TC = scanner.readInt();
    const R = [];
    for (let tc = 1; tc <= TC; tc++) {
        const line = scanner.readLine();
        console.log('---------------------------------');
        console.log('curLine: ', line);
        let data = '';
        let anonymousData = '';
        for (let i = 0; i < line.length; i++) {
            let char = line[i];
            if (line.charCodeAt(i) >= 97 && line.charCodeAt(i) <= 122) {
                data += char;
                anonymousData += 'a';
            } else if (['(', ')', '&', '~', '|', '^'].indexOf(char) > -1) {
                if (char === '(') {
                } else if (char === ')') {
                } else if (char === '~') {
                    char = '!';
                } else if (['&', '|', '^'].indexOf(char) > -1) {
                }
                data += char;
                anonymousData += char;
            }
        }
        let splitPtr = -1;
        if (anonymousData.indexOf(')!') > -1) {
            splitPtr = anonymousData.indexOf(')!') + 1;
        } else if (anonymousData.indexOf('a!') > -1) {
            splitPtr = anonymousData.indexOf('a!') + 1;
        } else if (anonymousData.indexOf(')(') > -1) {
            splitPtr = anonymousData.indexOf(')(') + 1;
        } else if (anonymousData.indexOf('aa') > -1) {
            splitPtr = anonymousData.indexOf('aa') + 1;
        } else if (anonymousData.indexOf('a(') > -1) {
            splitPtr = anonymousData.indexOf('a(') + 1;
        } else if (anonymousData.indexOf(')a') > -1) {
            splitPtr = anonymousData.indexOf(')a') + 1;
        } else {
            console.error('Cannot found secondExpression!');
            process.exit(1);
        }
        let firstExpression = data.substr(0, splitPtr);
        let secondExpression = data.substr(splitPtr);
        console.log('First : ', firstExpression);
        console.log('Second: ', secondExpression);
        const variables = new Set();
        for (let i = 0; i < firstExpression.length; i++) {
            const char = firstExpression[i];
            if (firstExpression.charCodeAt(i) >= 97 && firstExpression.charCodeAt(i) <= 122) {
                variables.add(char);
            }
        }
        const compareVariables = new Set();
        for (let i = 0; i < secondExpression.length; i++) {
            const char = secondExpression[i];
            if (secondExpression.charCodeAt(i) >= 97 && secondExpression.charCodeAt(i) <= 122) {
                compareVariables.add(char);
            }
        }
        const vars = [...variables].sort();
        const compare = [...compareVariables].sort();
        console.log('Check variables: ', vars.toString() === compare.toString());
        if (vars.toString() !== compare.toString()) { // 더 볼 필요도 없는 case
            R.push(`Data set ${tc}: Different`);
            continue;
        }
        console.log('Variables: ', compare);
        let resultIsAllTheSame = true;
        DFS(0, 0);
        DFS(0, 1);
        if (resultIsAllTheSame) {
            R.push(`Data set ${tc}: Equivalent`);
        } else {
            R.push(`Data set ${tc}: Different`);
        }

        function DFS(idx, val) {
            if (!resultIsAllTheSame) return;
            eval(vars[idx] + '=' + val); // 값 할당 수행
            if (idx + 1 === vars.length) {
                // 실제 두 식을 비교하는 phases는 여기에 구현
                const first = Boolean(eval(firstExpression));
                const second = Boolean(eval(secondExpression));
                const curVars = [];
                for (let ii = 0; ii < vars.length; ii++) {
                    let res = '';
                    res += vars[ii] + ': ';
                    res += eval(vars[ii]);
                    curVars.push(res);
                }
                console.log('Cur Setting  : ', curVars.join(', '));
                console.log('First Result : ', first);
                console.log('Second Result: ', second);
                if (first !== second) {
                    resultIsAllTheSame = false;
                    console.log('Result is not same!!!');
                } else {
                    console.log('Result is same, continue...');
                }
                return;
            } else {
                // 다음 index 값을 세팅한다.. (총 depths는 최대 10이 될 것..)
                DFS(idx + 1, 0);
                DFS(idx + 1, 1);
            }
        }
    }

    return R.join('\n');
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
    while (__lineIdx < __lineDB.length) {
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
}


/*
논리식 비교 출처다국어
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	48	18	9	34.615%
문제
두 논리식이 주어졌을 때, 두 논리식이 논리적으로 같은지 아닌지를 판별하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 같은지 비교해야 할 두 논리식이 주어진다. 입력으로 주어지는 식은 26개의 변수 a-z, 이항 연산자 |, &, ^,(OR, AND, XOR), 단항 연산자 ~(NOT), 괄호로 이루어져 있다. 

이외의 다른 문자는 무시해야 하고, C언어 연산자 우선순위를 따른다. 두 입력식은 구분되어 있지 않다. 두 논리식을 구분하는 것도 구현해야 한다.

이러한 문제를 풀 때는 보통 각 식을 정규화 한 뒤, 두 정규화 식이 같은지 판별하는 방법을 사용한다. 각각의 논리식은 10개 이하의 변수, 100개 이하의 연산자로 이루어져 있다.

출력
각각의 테스트 케이스에 대해서, 두 논리식이 같다면,

Data set N: Equivalent

다르다면

Data set N: Different

를 출력한다. N은 테스트 케이스 번호이고, 1번부터 시작한다.

예제 입력 1 
3
a ^b&(b|a)~b^ a
a^b&(b|a)(a^(b&(b|a)))
~~~~z~~z
예제 출력 1 
Data set 1: Different
Data set 2: Equivalent
Data set 3: Equivalent
*/
