#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int tc = 0; tc < T; tc++) {
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);
        printf("%d\n", ((N % H == 0) ? H: N % H) * 100 + ((N % H == 0) ? (N / H) : (N / H + 1)));
    }
}

/*
T
H W N
호텔 방 배정
*/