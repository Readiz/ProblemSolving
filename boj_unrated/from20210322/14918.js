const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
    console.log(line.toString().split(' ').map(_=>parseInt(_, 10)).reduce((_, i)=>_+i));
    process.exit();
});

/*
더하기 출처분류번외
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	3485	2793	2665	80.562%
문제
두 개의 정수 입력 a, b를 받아서 a+b를 출력하시오.

C 입출력 예제

#include <stdio.h>
…
scanf(“%d%d”, &a, &b);
printf(“%d\n”, a+b);
C++ 입출력 예제

#include <iostream>
…
cin >> a >> b;
cout << a+b << endl;
JAVA 입출력 예제

import java.util.Scanner;
Scanner sc = new Scanner(System.in);
a = sc.nextInt();
b = sc.nextInt();
System.out.println((a+b));
입력
a b; a와 b는 -100,000과 100,000 사이의 정수이다.

출력
a+b
*/
