#include <stdio.h>

int main() {
    int T, a, b;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= T - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

/*
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
우측 정렬 버전
*/