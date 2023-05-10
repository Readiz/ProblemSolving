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
let a, b, c;
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        let inputs = line.toString().split(' ').map(_ => parseInt(_, 10));
        inputs.sort(cmp);
        [a, b, c] = inputs;
        return;
    }
    let input = line.toString();
    input = input.replace('A', a + ' ');
    input = input.replace('B', b + ' ');
    input = input.replace('C', c + ' ');
    console.log(input);
    process.exit();
});


/*
ABC 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	6152	3572	3265	60.085%
문제
세 수 A, B, C가 주어진다. A는 B보다 작고, B는 C보다 작다.

세 수 A, B, C가 주어졌을 때, 입력에서 주어진 순서대로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 세 수 A, B, C가 주어진다. 하지만, 순서는 A, B, C가 아닐 수도 있다. 세 수는 100보다 작거나 같은 자연수이다. 둘째 줄에는 A, B, C로 이루어진 세 글자가 주어지며, 이 순서대로 출력하면 된다.

출력
주어진 세 수를 주어진 출력 순서대로 출력하면 된다.

예제 입력 1 
1 5 3
ABC
예제 출력 1 
1 3 5
예제 입력 2 
6 4 2
CAB
예제 출력 2 
6 2 4
*/
