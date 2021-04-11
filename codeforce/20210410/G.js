const { checkServerIdentity } = require("tls");

const db = new Map();
for (let i = 1; i <= 10000; i++) {
    const sum = check(i);
    if (!db.has(sum)) {
        db.set(sum, i);
    }
    console.log('processing...', i);
}
console.log(JSON.stringify([...db]));
console.log('size', db.size);

function check(num) {
    let r = 0;
    for (let i = 1; i <= num; i++) {
        if (num % i == 0) {
            r += i;
        }
    }
    return r;
}
