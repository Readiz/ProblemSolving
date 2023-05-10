const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N, M;
let dbUpdated = false;
let db = new Map();
rl.on('line', (line) => {
    if (!N) {
        N = parseInt(line.toString(), 10);
        return;
    }
    if (!dbUpdated) {
        const inputs = line.toString().split(' ');
        inputs.forEach(_ => {
            if (!db.has(_)) {
                db.set(_, 1);
            } else {
                db.set(_, db.get(_) + 1);
            }
        });
        dbUpdated = true;
        return;
    }
    if (!M) {
        M = parseInt(line.toString(), 10);
        return;
    }
    console.log(line.toString().split(' ').map(_ => db.has(_) ? db.get(_) : 0).join(' '));
    process.exit();
});

// Map을 쓰면 빨라짐.. 참고. 이 경우 일반 object를 사용하면, timeout이 난다. (db = {}를 사용할 경우..)
// db[idx] 와 같은 연산도 결국은 O(n) 이라고 생각하면 됨.

/*
숫자 카드 2 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	32007	11331	8095	35.725%
문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

예제 입력 1 
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
예제 출력 1 
3 0 0 1 2 0 0 2
*/
