#include <stdio.h>

int main() {
    int a;
    scanf("%x", &a);
    printf("%d\n", a);
}

/*
16진수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	10112	6660	5939	66.760%
문제
16진수 수를 입력받아서 10진수로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 16진수 수가 주어진다. 이 수의 최대 길이는 6글자이다. 16진수 수는 0~9와 A~F로 이루어져 있고, A~F는 10~15를 뜻한다. 또, 이 수는 음이 아닌 정수이다.

출력
첫째 줄에 입력으로 주어진 16진수 수를 10진수로 변환해 출력한다.

예제 입력 1 
A
예제 출력 1 
10
*/
