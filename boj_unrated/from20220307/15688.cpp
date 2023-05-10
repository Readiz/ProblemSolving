#include <stdio.h>

#define R register
int N, tmp;
int A[1'000'000];
int B_L[1'000'000];
int B_H[1'000'000];
int C_L[1'001];
int C_H[2'002];

int main() {
    scanf("%d", &N);
    for (R int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        tmp += 1000000;
        A[i] = tmp; // 변환된 범위: 0 ~ 2000000
        C_L[tmp % 1000]++;
        C_H[tmp / 1000]++;
    }

    // cnt 배열을 누적합으로 변환
    int acc = 0;
    for (R int i = 0; i < 1000; i++) {
        acc += C_L[i];
        C_L[i] = acc;
    }
    for (R int i = 999; i >= 0; i--) {
        C_L[i + 1] = C_L[i];
    }
    C_L[0] = 0;
    acc = 0;
    for (R int i = 0; i <= 2000; i++) {
        acc += C_H[i];
        C_H[i] = acc;
    }
    for (R int i = 2000; i >= 0; i--) {
        C_H[i + 1] = C_H[i];
    }
    C_H[0] = 0;

    // Bucket sort
    // 낮은 bit 부터 정렬해야 올바른 순서로 담김
    for (R int i = 0; i < N; i++) {
        tmp = A[i] % 1000;
        B_L[C_L[tmp]++] = A[i];
    }
    for (R int i = 0; i < N; i++) {
        tmp = B_L[i] / 1000;
        B_H[C_H[tmp]++] = B_L[i];
    }

    for (R int i = 0; i < N; i++) {
        printf("%d\n", B_H[i] - 1000000);
    }
}



/*
수 정렬하기 5 시간 누적
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
10 초 (하단 참고)	128 MB	4728	2233	1566	49.936%
문제
N개의 수가 주어졌을 때, 이를 비내림차순으로 정렬하는 프로그램을 작성하시오.

길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이며, 같은 수가 여러 번 중복될 수도 있다.

출력
첫째 줄부터 N개의 줄에 비내림차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/
