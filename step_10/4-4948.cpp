#include <stdio.h>
#define MEMO_MAX 400000
#define FALSE -1
#define TRUE 1
#define UNDEFINED 0
#define BOOL char
BOOL memo[MEMO_MAX] = { 0, };

BOOL isPrime(int num) {
    int memoVal = memo[num];
    if (memoVal != UNDEFINED) return memoVal;
    if (num == 1) return FALSE;

    // 제곱근까지 소수 아니면 소수 아님
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            memo[num] = FALSE;
            return FALSE;
        }
    }
    memo[num] = TRUE;
    return TRUE;
}

int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;

        int numOfPrime = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (isPrime(i) == TRUE) numOfPrime++;
        }
        printf("%d\n", numOfPrime);
    }

    return 0;
}

/*
문제
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. 

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하며, 한 줄로 이루어져 있다. (n ≤ 123456)

입력의 마지막에는 0이 주어진다.

출력
각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.
*/
