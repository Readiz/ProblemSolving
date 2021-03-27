#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int r = 1;
    int m = 1;
    for (; K > 0; K--) {
        r *= N;
        r /= m;
        N--;
        m++;
    }
    printf("%d\n", r);
    return 0;
}


/*
이항 계수 출력
*/
