function solution(scanner) {
    const [N, K] = scanner.readLine().split(' ').map(Number);
    const db = Array(27);
    db[1] = 'a';
    db[2] = 'aabba';
    for (let i = 3; i <= 26; i++) {
        db[i] = '';
        let check = new Set();
        for (let c = 97; c < 97 + i; c++) {
            db[i] += String.fromCharCode(c) + String.fromCharCode(c);
        }
        for (let k = 0; k < db[i].length - 1; k++) {
            check.add(db[i][k] + db[i][k + 1]);
        }
        while (true) {
            let isNoneMatched = true;
            for (let c = 97; c < 97 + i; c++) {
                const toCheck = db[i][db[i].length - 1] + String.fromCharCode(c);
                if (check.has(toCheck)) continue;
                else {
                    isNoneMatched = false;
                    db[i] += String.fromCharCode(c);
                    check.add(toCheck);
                }
            }
            if (isNoneMatched) break;
        }
        // console.log(check);
    }
    // console.log(db);
    const usingDB = db[K];
    const len = usingDB.length;
    let r = '';
    for (let i = 0; i < N; i++) {
        r += usingDB[i % len];
    }
    return r;
}


/////////////////////////////////////////////////////////////////////////////////
// Readiz JS Util Start
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
