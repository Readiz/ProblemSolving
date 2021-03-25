const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const db = [
    [0, 1, 2, 4, 5, 6], // 0
    [2, 5], // 1
    [0, 2, 3, 4, 6], // 2
    [0, 2, 3, 5, 6], // 3
    [1, 2, 3, 5], // 4
    [0, 1, 3, 5, 6], // 5
    [0, 1, 3, 4, 5, 6], // 6
    [0, 2, 5], // 7
    [0, 1, 2, 3, 4, 5, 6], // 8
    [0, 1, 2, 3, 5, 6] // 9
]
function mul(char, num) {
    let r = '';
    for (let i = 0; i < num; i++) {
        r += char;
    }
    return r;
}

function addStr(str, num, s) {
    // 맨 윗줄 추가
    str[0] += ' ';
    if (db[num].includes(0)) {
        str[0] += mul('-', s);
    } else {
        str[0] += mul(' ', s);
    }
    str[0] += ' ';
    for (let v = 1; v < 1 + s; v++) {
        if (db[num].includes(1)) {
            str[v] += '|';
        } else {
            str[v] += ' ';
        }
        str[v] += mul(' ', s);
        if (db[num].includes(2)) {
            str[v] += '|';
        } else {
            str[v] += ' ';
        }
    }
    // 중앙 줄 추가
    str[s + 1] += ' ';
    if (db[num].includes(3)) {
        str[s + 1] += mul('-', s);
    } else {
        str[s + 1] += mul(' ', s);
    }
    str[s + 1] += ' ';
    for (let v = s + 2; v < s * 2 + 2; v++) {
        if (db[num].includes(4)) {
            str[v] += '|';
        } else {
            str[v] += ' ';
        }
        str[v] += mul(' ', s);
        if (db[num].includes(5)) {
            str[v] += '|';
        } else {
            str[v] += ' ';
        }
    }
    // 맨 아랫 줄 추가
    str[s * 2 + 2] += ' ';
    if (db[num].includes(6)) {
        str[s * 2 + 2] += mul('-', s);
    } else {
        str[s * 2 + 2] += mul(' ', s);
    }
    str[s * 2 + 2] += ' ';

    // 글자 사이 공백 추가
    for (let v = 0; v < s * 2 + 3; v++) {
        str[v] += ' ';
    }
    return str;
}

rl.on('line', (line) => {
    let [s, num]= line.toString().split(' ');
    s = parseInt(s, 10);
    let str = [];
    for (let i = 0; i < s * 2 + 3; i++) {
        str.push('');
    }
    for (let i = 0; i < num.length; i++) {
        str = addStr(str, parseInt(num[i], 10), s);
    }
    for (let i = 0; i < str.length; i++) {
        console.log(str[i]);
    }
});


/*
LCD Test 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1549	804	565	52.558%
문제
지민이는 새로운 컴퓨터를 샀다. 하지만 새로운 컴퓨터에 사은품으로 온 LC-디스플레이 모니터가 잘 안나오는 것이다. 지민이의 친한 친구인 지환이는 지민이의 새로운 모니터를 위해 테스트 할 수 있는 프로그램을 만들기로 하였다.

입력
첫째 줄에 두 개의 정수 s와 n이 들어온다. (1 ≤ s ≤ 10, 0 ≤ n ≤ 9,999,999,999)이다. n은 LCD 모니터에 나타내야 할 수 이며, s는 크기이다.

출력
길이가 s인 '-'와 '|'를 이용해서 출력해야 한다. 각 숫자는 모두 s+2의 가로와 2s+3의 세로로 이루어 진다. 나머지는 공백으로 채워야 한다. 각 숫자의 사이에는 공백이 한 칸 있어야 한다.

예제 입력 1 
2 1234567890
예제 출력 1 
      --   --        --   --   --   --   --   --  
   |    |    | |  | |    |       | |  | |  | |  | 
   |    |    | |  | |    |       | |  | |  | |  | 
      --   --   --   --   --        --   --       
   | |       |    |    | |  |    | |  |    | |  | 
   | |       |    |    | |  |    | |  |    | |  | 
      --   --        --   --        --   --   --  
*/
