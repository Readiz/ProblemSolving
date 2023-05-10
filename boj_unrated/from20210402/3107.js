function solution(scanner) {
    let shortIP = String(scanner.readString());
    // 1. :: 위치 찾기
    const idx = shortIP.indexOf('::');
    if (idx !== -1) {
        let leftCnt = 0, rightCnt = 0;
        for (let i = 0; i < idx; i++) {
            if (shortIP[i] === ':') leftCnt++;
        }
        for (let i = idx + 2; i < shortIP.length; i++) {
            if (shortIP[i] === ':') rightCnt++;
        }
        // 원래 :이 7개가 나와야 하는데, 안나온 만큼 복원한다.
        let recovered = '';
        for (let i = 0; i < 7 - (leftCnt + rightCnt); i++) {
            recovered += ':';
        }
        shortIP = shortIP.replace('::', recovered);
    }
    const separated = shortIP.split(':').map(_ => {
        if (_.length === 0) return '0000';
        if (_.length === 1) return '000' + _;
        if (_.length === 2) return '00' + _;
        if (_.length === 3) return '0' + _;
        return _;
    });
    console.log(separated);
    return separated.join(':');
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
IPv6 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	928	245	224	30.812%
문제
IPv6은 길이가 128비트인 차세대 인터넷 프로토콜이다.

IPv6의 주소는 32자리의 16진수를 4자리씩 끊어 나타낸다. 이때, 각 그룹은 콜론 (:)으로 구분해서 나타낸다.

예를 들면, 다음과 같다.

2001:0db8:85a3:0000:0000:8a2e:0370:7334
32자리의 16진수는 사람이 읽고 쓰기에 불편하고, 대부분의 자리가 0이기 때문에 아래와 같이 축약할 수 있다.

각 그룹의 앞자리의 0의 전체 또는 일부를 생략 할 수 있다. 위의 IPv6을 축약하면, 다음과 같다
2001:db8:85a3:0:00:8a2e:370:7334
만약 0으로만 이루어져 있는 그룹이 있을 경우 그 중 한 개 이상 연속된 그룹을 하나 골라 콜론 2개(::)로 바꿀 수 있다.
2001:db8:85a3::8a2e:370:7334
2번째 규칙은 모호함을 방지하기 위해서 오직 한 번만 사용할 수 있다.

올바른 축약형 IPv6주소가 주어졌을 때, 이를 원래 IPv6 (32자리의 16진수)로 복원하는 프로그램을 작성하시오.

입력
첫째 줄에 올바른 IPv6 주소가 주어진다. 이 주소는 최대 39글자이다. 또한, 주소는 숫자 0-9, 알파벳 소문자 a-f, 콜론 :으로만 이루어져 있다.

출력
첫째 줄에, 입력으로 주어진 IPv6의 축약되지 않은 형태를 출력한다.
*/
