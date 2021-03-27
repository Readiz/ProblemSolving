const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        return;
    }
    const inputs = line.toString().split(' ').map(_ => parseInt(_, 10));
    console.log([...new Set(inputs)].sort((a, b) => a - b).join(' '));
    process.exit();
});


/*
중복 빼고 정렬하기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	7662	4376	3676	57.482%
문제
N개의 정수가 주어진다. 이때, N개의 정수를 오름차순으로 정렬하는 프로그램을 작성하시오. 같은 정수는 한 번만 출력한다.

입력
첫째 줄에 수의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 수를 오름차순으로 정렬한 결과를 출력한다. 이때, 같은 수는 한 번만 출력한다.

예제 입력 1 
10
1 4 2 3 1 4 2 3 1 2
예제 출력 1 
1 2 3 4
*/