#include <stdio.h>

int A[1001] = {0, };
int dp[1001] = {0, };
int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
    }
    for (int i = N - 2; i >= 0; i--) {
        int max = dp[i];
        for (int j = i + 1; j < N; j++) {
            if (A[i] < A[j]) {
                if (max < dp[i] + dp[j]) max = dp[i] + dp[j];
            }
        }
        dp[i] = max;
        
    }
    int max = -1;
    // printf("[DP result] ");
    for (int i = 0; i < N; i++) {
        // printf("%d ", dp[i]);
        if (max < dp[i]) max = dp[i];
    }
    // printf("\n");
    printf("%d\n", max);
    return 0;
}

/*
가장 긴 증가하는 부분 수열 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	68446	26234	17327	36.786%
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1 
6
10 20 10 30 20 50
예제 출력 1 
4
*/
