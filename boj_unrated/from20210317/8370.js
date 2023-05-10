const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
rl.on('line', (line) => {
    const [n1, k1, n2, k2] = line.split(' ').map(_ => parseInt(_));
    console.log(n1 * k1 + n2 * k2);
    return;
});

/*
Plane 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	1262	1141	1087	91.653%
문제
Byteland Airlines recently extended their aircraft fleet with a new model of a plane. The new acquisition has n1 rows of seats in the business class and n2 rows in the economic class. In the business class each row contains k1 seats, while each row in the economic class has k2 seats.

Write a program which:

reads information about available seats in the plane,
calculates the sum of all seats available in that plane,
writes the result.
입력
In the first and only line of the standard input there are four integers n1, k1, n2 and k2 (1 ≤ n1, k1, n2, k2 ≤ 1 000), separated by single spaces.

출력
The first and only line of the standard output should contain one integer - the total number of seats available in the plane.

예제 입력 1 
2 5 3 20
예제 출력 1 
70
*/
