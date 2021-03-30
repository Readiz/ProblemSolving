function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min) + min);
}

// const db = [];
// // 무조건 전체 TC는 1로 만들고
// console.log(1);

// // 삽입할 수
// const N = 50;
// // 지울 수
// const D = N / 2;

// // 전체 Test 수 (2회 반복)
// console.log((N + D) * 2);

// // 숫자 랜덤 생성 스타트
// // N 개의 Insert를 시작한다.
// for (let i = 0; i < N; i++) {
//     const val = getRandomInt(-1000, 1000);
//     console.log('I ' + val);
//     db.push(val);
// }

// db.sort((a, b) => a - b);

// for (let i = 0; i < D; i++) {
//     db.pop();
//     console.log('D 1');
// }

// // 숫자 랜덤 생성 스타트 -----------  2
// // N 개의 Insert를 시작한다.
// for (let i = 0; i < N; i++) {
//     const val = getRandomInt(-1000, 1000);
//     console.log('I ' + val);
//     db.push(val);
// }

// db.sort((a, b) => a - b);

// // 이번에는 MIN 에서 뺀다
// for (let i = 0; i < D; i++) {
//     db.shift();
//     console.log('D -1');
// }

// // Expected Result 출력
// if (db.length > 0) {
//     console.log('[Expected] ' + db[db.length - 1] + ' ' + db[0]);
// } else {
//     console.log('[Expected] EMPTY');
// }


// 전체 TC 수
console.log(1);
// let N = 100; // 커맨드 수
// console.log(N);
// for (let i = 0; i < N; i++) {
//     const cmd = getRandomInt(1, 4);
//     if (cmd === 1) {
//         console.log('I ' + getRandomInt(0, 5));
//     } else if (cmd === 2) {
//         console.log('D 1');
//     } else if (cmd === 3) {
//         console.log('D -1');
//     }
// }
// N = 30000; // 커맨드 수
// console.log(N);!
// for (let i = 0; i < N; i++) {
//     const cmd = getRandomInt(0, 4);
//     if (cmd === 0 || cmd === 1) {
//         console.log('I ' + getRandomInt(0, 100));
//     } else if (cmd === 2) {
//         console.log('D 1');
//     } else if (cmd === 3) {
//         console.log('D -1');
//     }
// }
N = 1000000; // 커맨드 수
console.log(N);
for (let i = 0; i < N; i++) {
    const cmd = getRandomInt(0, 4);
    if (cmd === 0 || cmd === 1) {
        console.log('I ' + getRandomInt(-500000, 5000000));
    } else if (cmd === 2) {
        console.log('D 1');
    } else if (cmd === 3) {
        console.log('D -1');
    }
}