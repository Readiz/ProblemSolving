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
    const [a, b] = line.toString().split(' ').map(_ => parseInt(_, 10));
    let k = Math.floor(a / b);
    let r = a % b;
    console.log(`You get ${k} piece(s) and your dad gets ${r} piece(s).`);
});
