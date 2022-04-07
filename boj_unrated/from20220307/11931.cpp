#include <stdio.h>

#define R register
int N;
int A[1000000];
// bucket sort
int B_H[1000000];
int B_L[1000000];
int cnt_l[1002];
int cnt_h[2002];

int main() {
    scanf("%d", &N);

    for (R int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmp = 1000000 - tmp;
        A[i] = tmp;
        cnt_h[tmp / 1000]++;
        cnt_l[tmp % 1000]++;
    }

    // 누적합으로 변경
    int acc = 0;
    for (R int i = 0; i <= 1000; i++) {
        acc += cnt_l[i];
        cnt_l[i] = acc;
    }
    for (R int i = 1000; i >= 0; i--) {
        cnt_l[i + 1] = cnt_l[i];
    }
    cnt_l[0] = 0;

    acc = 0;
    for (R int i = 0; i <= 2000; i++) {
        acc += cnt_h[i];
        cnt_h[i] = acc;
    }
    for (R int i = 2000; i >= 0; i--) {
        cnt_h[i + 1] = cnt_h[i];
    }
    cnt_h[0] = 0;

    // bucket sort 시작
    // 1. 낮은 자리수에 대해 정렬
    for (R int i = 0; i < N; i++) {
        int v = A[i] % 1000;
        B_L[cnt_l[v]++] = A[i];
    }
    // 2. 높은 자리수에 대해 정렬
    //   -> 영향력이 더 큰걸 나중에 써야 함
    for (R int i = 0; i < N; i++) {
        int v = B_L[i] / 1000;
        B_H[cnt_h[v]++] = B_L[i];
    }

    // 출력
    for (R int i = 0; i < N; i++) {
        printf("%d\n", 1000000 - B_H[i]);
    }
}

/*
수 정렬하기 4
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	256 MB	8167	4333	3455	55.183%
문제
N개의 수가 주어졌을 때, 이를 내림차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 내림차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

예제 입력 1 
5
1
2
3
4
5
예제 출력 1 
5
4
3
2
1
*/
