const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let TC = 0;
let N = 0;
let db = [];
rl.on('line', (line) => {
    if (TC === 0) {
        TC = parseInt(line.toString(), 10);
        return;
    }
    if (N === 0) {
        N = parseInt(line.toString(), 10);
        db.splice(0, db.length);
        return;
    }
    N--;
    const pair = line.toString().split(' ').map(_ => parseInt(_, 10));
    db.push(pair);

    if (N === 0 && TC > 0) {
        TC--;
        db.sort((a, b) => {
            if (a[0] !== b[0]) return a[0] - b[0];
            else return a[1] - b[1];
        });
        // console.log('start', db);
        // for (let i = 0; i < db.length; i++) {
        //     for (let j = i + 1; j < db.length; j++) {
        //         if (db[i][1] < db[j][1]) {
        //             db.splice(j, 1);
        //             j--; continue;
        //         }
        //     }
        // }
        // console.log('end', db);
        // console.log(db.length);
        // 직접 배열에서 빼지 않고 구하는 알고리즘
        let cnt = 1; // 정렬 후 가장 처음에 있는 녀석은 무조건 선발됨.
        let m = db[0][1];
        for(let i = 1; i < db.length; i++) {
            if (db[i][1] < m) { // 현재 최소값보다 더 작으면
                cnt++;
                m = db[i][1]; // 값을 갱신한다.
            }
        }
        console.log(cnt);
    }
    if (N === 0 && TC === 0) {
        process.exit();
    }
});

/*
신입 사원 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	21528	6701	4939	31.828%
문제
언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다. 최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 사원으로 선발하고 싶어 한다.

그래서 진영 주식회사는, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.

이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다. 각 테스트 케이스의 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다. 두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정된다고 가정한다.

출력
각 테스트 케이스에 대해서 진영 주식회사가 선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.

예제 입력 1 
2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1
예제 출력 1 
4
3
*/
