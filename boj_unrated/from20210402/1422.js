function solution(scanner) {
    const K = scanner.readInt();
    const N = scanner.readInt();
    let r = '';
    const db = [];
    const dbStr = [];
    for (let i = 0; i < K; i++) {
        const str = scanner.readString();
        db.push(BigInt(str));
        dbStr.push(str);
    }
    db.sort((a, b) => {
        const r = b - a;
        if (r > 0) return 1;
        else if (r < 0) return -1;
        return 0;
    });
    console.log(db);
    const dup = N - K;
    for (let i = 0; i < dup; i++) {
        dbStr.push(db[0].toString());
    }
    // 문자순 정렬 구현.. "9" > "901", "3" > "2"
    dbStr.sort((a, b) => {
        let isSwapped = false;
        let r = 0;
        if (b.length > a.length) {
            [a, b] = [b, a]; // swap
            // swap 후에는 항상 a가 b보다 길다.
            isSwapped = true;
        }
        for (let i = 0; i < a.length; i++) {
            const aInt = Number(a[i]);
            const bInt = Number(b[i])
            if (Number.isNaN(bInt)) {
                // 비교 중에 앞 자리는 다 같고, 두 수의 길이가 달라지는 case.
                const ab = BigInt(a + b);
                const ba = BigInt(b + a);
                if (ab > ba) r = -1;
                else if (ba > ab) r = 1;
                else r = 0;
                break;
            }
            // 길이가 같은 경우에 대한 판정
            if (aInt > bInt) {
                r = -1;
                break;
            } else if (aInt < bInt) {
                r = 1;
                break;
            } else {
                // 같은 경우에는 배열 순회를 마저 한다.
                continue;
            }
        }
        if (isSwapped) r = r * (-1);
        return r;
    }); 
    console.log(dbStr);
    return dbStr.join('');
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
숫자의 신 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	2180	442	312	20.013%
문제
숫자의 신은 여러명이 있지만, 그 중에 자연수의 신은 오세준이다. 오세준은 자연수의 신으로 오래오래 살다가 어느 날 음수의 신과 전쟁을 하게 되었다. 오세준은 음수의 신 이다솜을 이기기위해서 큰 숫자를 만들기로 했다.

오세준은 지금 K개의 자연수를 가지고 있다. 오세준은 K개의 수 중에 정확하게 N개의 수를 뽑아내서 그 수를 붙여서 만들 수 있는 수중에 가장 큰 수를 만들고자 한다. 같은 수를 여러 번 이용해도 된다. 단, 모든 수는 적어도 한 번은 이용되어야 한다.

오세준이 현재 가지고 있는 K개의 수가 주어졌을 때, 이 수를 적어도 한 번 이상 이용해서 만들 수 있는 수 중에 가장 큰 수를 출력하는 프로그램을 작성하시오.

예를 들어 지금 오세준이 2, 3, 7 이라는 3개의 수를 가지고 있고, 4개의 수를 뽑아야 한다면, 7732를 만들면 가장 큰 수가 된다.

입력
첫째 줄에 K와 N이 공백을 사이에 두고 주어진다. K와 N은 각각 1,000보다 작거나 같은 자연수이고, N은 K보다 크거나 같다. 둘째 줄에는 K개의 수가 한 줄에 하나씩 주어진다. 각 수는 1,000,000,000보다 작거나 같은 자연수이다. 이 수는 중복되어 들어올 수 있다. 만약 중복되어서 들어오는 경우에는 각 수가 적어도 입력으로 주어진 만큼 이용되어야 한다는 소리다.

출력
N개의 수를 뽑아서 연결해서 만들 수 있는 가장 큰 수를 출력한다.

예제 입력 1 
3 3
3
2
7
예제 출력 1 
732
*/
