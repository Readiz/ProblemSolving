#include <stdio.h>

int main() {
    int N;
    int A[500][500] = {0, };
    // int dp[500][500] = {0, }; <- A 배열로 대체 가능.
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = N - 2; i >= 0; i--) { // 맨 뒷줄부터 차례대로 더해간다.. 마지막 줄 - 1 부터.. 더 큰놈을 써서..
        for (int j = 0; j < i + 1; j++) {
            if (A[i + 1][j] > A[i + 1][j + 1]) {
                A[i][j] += A[i + 1][j];
            } else {
                A[i][j] += A[i + 1][j + 1];
            }
        }
    }
    printf("%d\n", A[0][0]);
    return 0;
}


/*
정수 삼각형 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	42931	25458	18866	59.297%
문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

예제 입력 1 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
예제 출력 1 
30
*/
