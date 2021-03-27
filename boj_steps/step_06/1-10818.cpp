#include <stdio.h>

int main() {
    int N;
    int min = 1000000;
    int max = -1000000;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp < min) min = tmp;
        if (tmp > max) max = tmp;
    }
    printf("%d %d\n", min, max);
    return 0;
}


/*
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
*/