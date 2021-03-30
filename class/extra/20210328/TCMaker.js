function solution(scanner) {
    const A = scanner.readLine();
    const B = scanner.readLine();
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


function makeTC(N) {
    const r = [];


    return r.join('\n');
}


const r = makeTC(100);
console.log(r);
