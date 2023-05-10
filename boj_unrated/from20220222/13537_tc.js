/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2
*/

const N = 100000;
console.log(N);
const db = [];
for (let i = 1; i <= N; i++) db.push(i);
console.log(db.join(' '));

const M = 100000;
console.log(M);
for (let i = 1; i <= N; i++) {
    console.log('1 100000 ' + i);
}