const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let db = {};
rl.on('line', (line) => {
    if (N === 0) {
        N = parseInt(line.toString(), 10);
        return;
    }
    N--;
    const key = line.toString();
    if (db[key]) { db[key] += 1 }
    else { db[key] = 1 }
    if (N === 0) {
        let arr = [];
        for (const key in db) {
            arr.push({key: BigInt(key), count: db[key], originalKey: key})
        }
        arr.sort((a, b) => {
            if (b.count - a.count !== 0) return b.count - a.count;
            return Number(a.key - b.key);
        });
        console.log(arr[0].originalKey);
        process.exit();
    }
});

/*
카드 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	18833	5155	3862	28.042%
문제
준규는 숫자 카드 N장을 가지고 있다. 숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -262보다 크거나 같고, 262보다 작거나 같다.

준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오. 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.

입력
첫째 줄에 준규가 가지고 있는 숫자 카드의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 숫자 카드에 적혀있는 정수가 주어진다.

출력
첫째 줄에 준규가 가장 많이 가지고 있는 정수를 출력한다.

예제 입력 1 
5
1
2
1
2
1
예제 출력 1 
1
예제 입력 2 
6
1
2
1
2
1
2
예제 출력 2 
1
*/
