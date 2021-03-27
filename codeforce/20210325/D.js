const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
  
let TC = 0;
let N = 0;
let db;
readline.on('line', line => {
    if (TC === 0) {
        TC = Number(line.toString());
        return;
    }
    if (N === 0) {
        N = Number(line.toString());
        db = new Map();
        return;
    }
    let cache = line.toString().split(' ').map(_=>Number(_));
    for (let i = 0; i < N; i++) {
        const val = cache[i];
        if (db.get(val)) {
            db.set(val, db.get(val) + 1);
        } else {
            db.set(val, 1);
        }
    }
    let sortedDB = [...db].sort((a, b) => b[1] - a[1]);
    let ptr = 1;
    console.log(sortedDB);
    while (ptr < sortedDB.length) {
        if (sortedDB[0][1] < sortedDB[ptr][1]) {
            [sortedDB[0], sortedDB[ptr]] = [sortedDB[ptr], sortedDB[0]];
        }
        sortedDB[0][1] -= sortedDB[ptr][1]; sortedDB[ptr][1] = 0;
        ptr++;
        console.log(sortedDB);
    }
    let sum = 0;
    for (let i = 0; i < sortedDB.length; i++) {
        sum += sortedDB[i][1];
    }
    console.log(sum);

    N = 0;
    TC--;

    if (TC === 0) {
        process.exit();
    }
});
