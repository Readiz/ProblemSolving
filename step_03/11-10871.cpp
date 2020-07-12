#include <stdio.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp < X) printf("%d ", tmp);
    }

    return 0;
}


/*
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
*/