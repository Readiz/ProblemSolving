function solution(scanner) {
    const N = scanner.readInt();
    if (N < 2) return 1;

    let pprev = 1n, prev = 1n, cur = 3n;
    curIdx = 2;
    while (curIdx < N) {
        pprev = prev;
        prev = cur;
        cur = (pprev + prev + 1n) % 1000000007n;
        curIdx++;
    }
    return cur;
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
피보나치는 지겨웡~ 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	1613	693	639	44.717%
문제
혁진이는 알고리즘 문제를 만들라는 독촉을 받아 스트레스다. 하지만 피보나치 문제는 너무 많이 봐서 지겹기 그지없다. 그러나 문제를 만들 시간이 없는 혁진이는 피보나치 문제를 응용해서 문제를 만들려 한다.

int fibonacci(int n) { // 호출
  if (n < 2) {
    return n;
  }  
  return fibonacci(n-2) + fibonacci(n-1);
}
위와 같이 코딩하였을 때 fibonacci(n)를 입력했을 때에 fibonacci 함수가 호출되는 횟수를 계산해보자.

입력
fibonacci 함수에 인자로 입력할 n이 주어진다. (0 ≤ n ≤ 50)

출력
fibonacci 함수가 호출된 횟수를 출력한다.

출력값이 매우 커질 수 있으므로 정답을 1,000,000,007 로 나눈 나머지를 출력한다.

예제 입력 1 
2
예제 출력 1 
3
예제 입력 2 
3
예제 출력 2 
5
*/
