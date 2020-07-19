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
    int N;
    scanf("%d", &N);

    int numOfPrime = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (isPrime(num) == TRUE) numOfPrime++;
    }
    printf("%d\n", numOfPrime);

    return 0;
}

/*
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.
*/
