const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let positiveDB = [];
let negativeDB = [];
let countPositive1 = 0;
let isZeroExist = false;
rl.on('line', (line) => {
    if (N === 0) {
        N = parseInt(line.toString(), 10);
        return;
    }
    N--;
    const input = parseInt(line.toString(), 10);
    if (input === 1) countPositive1++;
    else if (input < 0) negativeDB.push(input);
    else if (input > 0) positiveDB.push(input);
    else if (input === 0) isZeroExist = true;

    if (N === 0) {
        positiveDB.sort((a, b) => b - a);
        negativeDB.sort((a, b) => a - b);
        // console.log(positiveDB);
        // console.log(negativeDB);
        let sum = 0;
        for (let i = 0; i < positiveDB.length - 1; i+=2) {
            sum += positiveDB[i] * positiveDB[i + 1];
        }
        for (let i = 0; i < negativeDB.length - 1; i+=2) {
            sum += negativeDB[i] * negativeDB[i + 1];
        }
        if (positiveDB.length % 2 === 1) sum += positiveDB[positiveDB.length - 1];
        // 0이 존재하면, 마지막 남은 음수를 0으로 처리 가능함. 0이 없으면, 뺄 수밖에..
        if (!isZeroExist && negativeDB.length % 2 === 1) sum += negativeDB[negativeDB.length - 1];
        // 1의 경우 곱하지 않는 것이 이득. -1의 경우 곱하는게 이득 (빠지니깐)
        sum += countPositive1;
        console.log(sum);
        process.exit();
    }
});


/*
수 묶기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	13958	3808	3085	26.870%
문제
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.

예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.

수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N이 주어진다. N은 10,000보다 작은 자연수이다. 둘째 줄부터 N개의 줄에, 수열의 각 수가 주어진다. 수열의 수는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

출력
수를 합이 최대가 나오게 묶었을 때 합을 출력한다. 정답은 항상 231보다 작다.

예제 입력 1 
4
-1
2
1
3
예제 출력 1 
6
*/
