function solution(scanner) {
    const N = scanner.readInt();
    const M = scanner.readInt();
    const db = new Map();
    for (let i = 0; i < N; i++) {
        db.set(scanner.readString(), scanner.readString());
    }
    let r = [];
    for (let i = 0; i < M; i++) {
        r.push(db.get(scanner.readString()));
    }
    return r.join('\n');
}


/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
(function readizInit() {
    const _input = require('fs').readFileSync('/dev/stdin');
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
    if (process.argv[2] !== 'readizDebug') {
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
비밀번호 찾기 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
5 초	256 MB	2505	1686	1328	68.524%
문제
2019 HEPC - MAVEN League의 "비밀번호 만들기"와 같은 방식으로 비밀번호를 만든 경민이는 한 가지 문제점을 발견하였다. 비밀번호가 랜덤으로 만들어져서 기억을 못 한다는 것이었다! 그래서 경민이는 메모장에 사이트의 주소와 비밀번호를 저장해두기로 했다. 하지만 컴맹인 경민이는 메모장에서 찾기 기능을 활용하지 못하고 직접 눈으로 사이트의 주소와 비밀번호를 찾았다. 메모장에 저장된 사이트의 수가 늘어나면서 경민이는 비밀번호를 찾는 일에 시간을 너무 많이 쓰게 되었다. 이를 딱하게 여긴 문석이는 경민이를 위해 메모장에서 비밀번호를 찾는 프로그램을 만들기로 결심하였다! 문석이를 도와 경민이의 메모장에서 비밀번호를 찾아주는 프로그램을 만들어보자.

입력
첫째 줄에 저장된 사이트 주소의 수 N(1 ≤ N ≤ 100,000)과 비밀번호를 찾으려는 사이트 주소의 수 M(1 ≤ M ≤ 100,000)이 주어진다.

두번째 줄부터 N개의 줄에 걸쳐 각 줄에 사이트 주소와 비밀번호가 공백으로 구분되어 주어진다. 사이트 주소는 알파벳 소문자, 알파벳 대문자, 대시('-'), 마침표('.')로 이루어져 있고, 중복되지 않는다. 비밀번호는 알파벳 대문자로만 이루어져 있다. 모두 길이는 최대 20자이다.

N+2번째 줄부터 M개의 줄에 걸쳐 비밀번호를 찾으려는 사이트 주소가 한줄에 하나씩 입력된다. 이때, 반드시 이미 저장된 사이트 주소가 입력된다.

출력
첫 번째 줄부터 M개의 줄에 걸쳐 비밀번호를 찾으려는 사이트 주소의 비밀번호를 차례대로 각 줄에 하나씩 출력한다.

예제 입력 1 
16 4
noj.am IU
acmicpc.net UAENA
startlink.io THEKINGOD
google.com ZEZE
nate.com VOICEMAIL
naver.com REDQUEEN
daum.net MODERNTIMES
utube.com BLACKOUT
zum.com LASTFANTASY
dreamwiz.com RAINDROP
hanyang.ac.kr SOMEDAY
dhlottery.co.kr BOO
duksoo.hs.kr HAVANA
hanyang-u.ms.kr OBLIVIATE
yd.es.kr LOVEATTACK
mcc.hanyang.ac.kr ADREAMER
startlink.io
acmicpc.net
noj.am
mcc.hanyang.ac.kr
예제 출력 1 
THEKINGOD
UAENA
IU
ADREAMER
*/
