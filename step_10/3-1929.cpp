#include <stdio.h>
// #define MEMO_MAX
#define FALSE -1
#define TRUE 1
#define UNDEFINED 0
#define BOOL char
// BOOL memo[MEMO_MAX] = { 0, };

BOOL isPrime(int num) {
    if (num == 1) return FALSE;
    // 제곱근까지 소수 아니면 소수 아님
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return FALSE;
    }

    return TRUE;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    for (int i = M; i <= N; i++) {
        if (isPrime(i) == TRUE) {
            printf("%d\n", i);
        }
    }

    return 0;
}


/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/
