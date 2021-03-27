const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
  
let TC = 0;
let A, B;
readline.on('line', line => {
    if (TC === 0) {
        TC = Number(line.toString());
        return;
    }
    if (!A) {
        A = line.toString();
        return;
    }
    B = line.toString();
    if (A.length > B.length) {
        [B, A] = [A, B];
    }
    let maxMatchLength = 0;
    for (let i = 0; i < A.length; i++) {
        for (let j = 1; j < A.length - i + 1; j++) {
            const t = A.substr(i, j);
            if (B.indexOf(t) > -1) {
                const matchLength = t.length;
                if (maxMatchLength < matchLength) {
                    maxMatchLength = matchLength;
                }
            }
        }
    }
    console.log((A.length - maxMatchLength) + (B.length - maxMatchLength));

    A = undefined; B = undefined;
    TC--;
    if (TC === 0) {
        process.exit();
    }
});
