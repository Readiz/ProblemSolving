const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isFirst = true;
let c;
rl.on('line', (line) => {
    if (isFirst) {
        isFirst = false;
        c = parseInt(line.toString(), 10);
        return;
    }
    const r = line.toString().split(' ').map(_ => parseInt(_, 10));
    let s = 0;
    for (let i = 0; i < r.length; i++) {
        if (r[i] == c) {
            s++
        }
    }
    console.log(s);
    process.exit();
});

/*
예제 입력 2 
3
1 2 3 5 3
예제 출력 2 
2
*/
