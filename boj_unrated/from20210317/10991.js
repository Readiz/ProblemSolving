const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
    const N = parseInt(line.toString(), 10);
    for (let k = 0; k < N; k++) {
        let line = '';
        for (let i = N - 2 - k; i >= 0; i--) {
            line += ' ';
        }
        for (let j = 1; j <= k + 1; j++) {
            line += '* ';
        }
        console.log(line);
    }
});

/*
예제 입력 1 
1
예제 출력 1 
*
예제 입력 2 
2
예제 출력 2 
 *
* *
예제 입력 3 
3
예제 출력 3 
  *
 * *
* * *
예제 입력 4 
4
예제 출력 4 
   *
  * *
 * * *
* * * *
*/
