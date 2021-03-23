const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
let N, K;
let db = [];
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        [N, K] = line.toString().split(' ').map(_=>parseInt(_, 10));
        return;
    }
    N--;
    // 금 은 동
    [id, a, b, c] = line.toString().split(' ').map(_=>parseInt(_, 10));
    db.push({
        a, b, c, id
    });
    if (N === 0) {
        db.sort((a, b) => {
            if (a.a === b.a) {
                if (a.b === b.b) {
                    if (a.c === b.c) return 0;
                    return a.c - b.c;
                }
                return a.b - b.b;
            }
            return a.a - b.a;
        });
        db = db.reverse();
        // console.log(db);
        const rank = [];
        let curRank = 1;
        let idleRank = 0;
        for (let i = 0; i < db.length; i++) {
            rank[db[i].id] = curRank; // 각 국가의 등수를 저장해준다.
            if (i !== db.length - 1 && db[i].a === db[i + 1].a && db[i].b === db[i + 1].b && db[i].c === db[i + 1].c) {
                // 뒤 녀석과 값이 같을 경우 그 녀석도 지금과 순위 같아야 함.
                // 우선은 Rank를 증가시키지 않지만, 이후에 한번에 올려주기 위해 저장.
                idleRank++;
            } else {
                // 값이 달라지면 다음 순위로 할당함
                curRank++;
                curRank += idleRank;
                idleRank = 0;
            }
            
        }
        // console.log(rank);
        console.log(rank[K]);
        process.exit();
    }
});


/*
올림픽 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	11296	4020	3278	35.888%
문제
올림픽은 참가에 의의가 있기에 공식적으로는 국가간 순위를 정하지 않는다. 그러나, 많은 사람들이 자신의 국가가 얼마나 잘 하는지에 관심이 많기 때문에 비공식적으로는 국가간 순위를 정하고 있다. 두 나라가 각각 얻은 금, 은, 동메달 수가 주어지면, 보통 다음 규칙을 따라 어느 나라가 더 잘했는지 결정한다.

금메달 수가 더 많은 나라 
금메달 수가 같으면, 은메달 수가 더 많은 나라
금, 은메달 수가 모두 같으면, 동메달 수가 더 많은 나라 
각 국가는 1부터 N 사이의 정수로 표현된다. 한 국가의 등수는 (자신보다 더 잘한 나라 수) + 1로 정의된다. 만약 두 나라가 금, 은, 동메달 수가 모두 같다면 두 나라의 등수는 같다. 예를 들어, 1번 국가가 금메달 1개, 은메달 1개를 얻었고, 2번 국가와 3번 국가가 모두 은메달 1개를 얻었으며, 4번 국가는 메달을 얻지 못하였다면, 1번 국가가 1등, 2번 국가와 3번 국가가 공동 2등, 4번 국가가 4등이 된다. 이 경우 3등은 없다. 

각 국가의 금, 은, 동메달 정보를 입력받아서, 어느 국가가 몇 등을 했는지 알려주는 프로그램을 작성하시오. 

입력
입력의 첫 줄은 국가의 수 N(1 ≤ N ≤ 1,000)과 등수를 알고 싶은 국가 K(1 ≤ K ≤ N)가 빈칸을 사이에 두고 주어진다. 각 국가는 1부터 N 사이의 정수로 표현된다. 이후 N개의 각 줄에는 차례대로 각 국가를 나타내는 정수와 이 국가가 얻은 금, 은, 동메달의 수가 빈칸을 사이에 두고 주어진다. 전체 메달 수의 총합은 1,000,000 이하이다.

출력
출력은 단 한 줄이며, 입력받은 국가 K의 등수를 하나의 정수로 출력한다. 등수는 반드시 문제에서 정의된 방식을 따라야 한다. 

예제 입력 1 
4 3
1 1 2 0
2 0 1 0
3 0 1 0
4 0 0 1
예제 출력 1 
2
예제 입력 2 
4 2
1 3 0 0
3 0 0 2
4 0 2 0
2 0 2 0
예제 출력 2 
2
*/
