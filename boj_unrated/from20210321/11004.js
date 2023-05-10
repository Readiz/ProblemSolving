const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function cmp(a, b) {
    if (a > b) return 1;
    if (a === b) return 0;
    return -1;
}

let isFirst = true;
let K;
let dummy;
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        [dummy, K] = line.toString().split(' ').map(_ => parseInt(_, 10));
        return;
    }
    let inputs = line.toString().split(' ').map(_ => parseInt(_, 10)).sort(cmp);
    console.log(inputs[K - 1]);
    process.exit();
});


/*
K번째 수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	32584	10417	6550	37.144%
문제
수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.

둘째에는 A1, A2, ..., AN이 주어진다. (-109 ≤ Ai ≤ 109)

출력
A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.

예제 입력 1 
5 2
4 1 2 3 5
예제 출력 1 
2
*/
