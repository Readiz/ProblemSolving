process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();
});

function readline() {
    return inputString[currentLine++];
}
// Make a Snippet for the code above this and then write your logic in main();


function main() {
    const TC = readline();
    const r = [];
    for (let tc = 0; tc < TC; tc++) {
        const str = readline();
        let isDejavu = true;
        if (isAllA(str)) {
            r.push('NO'); // Edge case
            continue;
        }
        for (let i = 0; i <= str.length; i++) {
            const left = str.substr(0, i);
            const right = (i === str.length) ? '' : str.substr(-(str.length - i));
            const newStr = left + 'a' + right;
            if (isPalindrome(newStr)) continue;
            r.push('YES');
            r.push(newStr);
            isDejavu = false;
            break;
        }
        if (isDejavu) r.push('NO');
    }
    process.stdout.write(r.join('\n'));   // without auto '\n' (newline)
}
function isAllA(str) {
    for (let i = 0; i < str.length; i++) {
        if (str[i] !== 'a') return false;
    }
    return true;
}
function isPalindrome(str) {
    const lenhalf = Math.floor(str.length / 2);
    const a = str.substr(0, lenhalf);
    const b = str.substr(-lenhalf).split('').reverse().join('');
    if (a == b) return true;
    return false;
    // for (let i = 0; i <= lenhalf; i++) {
    //     if (str[i] === str[str.length - i - 1]) continue;
    //     return false;
    // }
    // return true;
}


// const readline = require('readline').createInterface({
//     input: process.stdin,
//     output: process.stdout
// });
  
// let TC = 0;
// const r = [];
// readline.on('line', line => {
//     if (TC === 0) {
//         TC = Number(line.toString());
//         return;
//     }
//     const str = line.toString();
//     let isDejavu = true;
//     for (let i = 0; i <= str.length; i++) {
//         const left = str.substr(0, i);
//         const right = (i === str.length) ? '' : str.substr(-(str.length - i));
//         const newStr = left + 'a' + right;
//         if (isPalindrome(newStr)) continue;
//         r.push('YES');
//         r.push(newStr);
//         isDejavu = false;
//         break;
//     }
//     if (isDejavu) r.push('NO');

//     TC--;
//     if (TC === 0) {
//         process.exit();
//     }
// });

// function isPalindrome(str) {
//     const lenhalf = Math.floor(str.length / 2);
//     for (let i = 0; i <= lenhalf; i++) {
//         if (str[i] === str[str.length - i - 1]) continue;
//         return false;
//     }
//     return true;
// }