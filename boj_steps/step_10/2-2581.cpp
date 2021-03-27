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

    int minPrime = 100000;
    int sumPrime = 0;
    for (int i = M; i <= N; i++) {
        if (isPrime(i) == TRUE) {
            if (minPrime > i) minPrime = i;
            sumPrime += i;
        }
    }

    if (sumPrime == 0) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", sumPrime, minPrime);
    }        

    return 0;
}

/*
문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.

입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다. 

단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.
*/
