function solution(scanner) {
    const A = scanner.readLine();
    const B = scanner.readLine();
    let A10 = 0n; let B10 = 0n;
    let posA = 1n; let posB = 1n;
    for (let i = A.length - 1; i >= 0; i--) {
        A10 += BigInt(parseInt(A[i], 32)) * posA;
        posA *= 32n;
    }
    for (let i = B.length - 1; i >= 0; i--) {
        B10 += BigInt(parseInt(B[i], 32)) * posB;
        posB *= 32n;
    }
    let r = 0n;
    if (A10 - B10 > 0) {
        r = (A10 + B10) * (A10 - B10);
    } else {
        r = (A10 + B10) * (B10 - A10);
    }
    let strResult = '';
    if (r === 0n) strResult = '0';
    else {
        while (r > 0) {
            const v = r % 32n;
            strResult += String(v.toString(32)).toUpperCase();
            r /= 32n;
        }
    }
    return strResult.split('').reverse().join('');
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
(A+B)|A-B|
*/
