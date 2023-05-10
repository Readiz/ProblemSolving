function solution(A, B) {
    let A10 = 0n; let B10 = 0n;
    let posA = 1n; let posB = 1n;
    for (let i = A.length - 1; i >= 0; i--) {
        A10 += BigInt(parseInt(A[i], 32)) * posA;
        posA *= 32n;
    }
    for (let i = B.length - 1; i >= 0; i--) {
        B10 += BigInt(parseInt(B[i], 32)) * posB;
        posB *= 32n;
    }
    let r = 0n;
    if (A10 - B10 > 0) {
        r = (A10 + B10) * (A10 - B10);
    } else {
        r = (A10 + B10) * (B10 - A10);
    }
    let strResult = '';
    if (r === 0n) strResult = '0';
    else {
        while (r > 0) {
            const v = r % 32n;
            strResult += String(v.toString(32)).toUpperCase();
            r /= 32n;
        }
    }
    return strResult.split('').reverse().join('');
}

function getRadix32Number() {
    const v = Math.floor(Math.random() * 32);
    return String(v.toString(32)).toUpperCase();
}

function getRandomNum(len) {
    let rnum = '';
    for (let i = 0; i < len; i++) {
        rnum += getRadix32Number(32);
    }
    return rnum;
}


function makeTC(N) {
    const r = [];


    for (let i = 0; i < N; i++) {
        const A = getRandomNum(15000);
        const B = getRandomNum(15000);
        r.push(A);
        r.push(B);
        r.push(solution(A, B));
    }

    return r.join('\n');
}


const r = makeTC(100);
console.log(r);
