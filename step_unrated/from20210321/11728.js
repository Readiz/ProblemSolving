const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


let isFirst = true;
let A = [];
let B = [];
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        return;
    }
    if (A.length === 0) {
        A = line.toString().split(' ').map(_ => parseInt(_, 10));
        return;
    }
    B = line.toString().split(' ').map(_ => parseInt(_, 10));
    console.log(merge(A, B).join(' '));
    process.exit();
});

function merge(A, B) {
    let r = [];
    let i = 0; let j = 0;
    while (i < A.length && j < B.length) {
        if (A[i] < B[j]) {
            r.push(A[i++]);
        } else {
            r.push(B[j++]);
        }
    }
    while (i < A.length) {
        r.push(A[i++]);
    }
    while (j < B.length) {
        r.push(B[j++]);
    }
    return r;
}

/*
배열 합치기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1.5 초	256 MB	14676	6492	4204	44.081%
문제
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.

예제 입력 1 
2 2
3 5
2 9
예제 출력 1 
2 3 5 9
예제 입력 2 
2 1
4 7
1
예제 출력 2 
1 4 7
예제 입력 3 
4 3
2 3 5 9
1 4 7
예제 출력 3 
1 2 3 4 5 7 9
*/
