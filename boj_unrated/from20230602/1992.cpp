#include <stdio.h>

char rows[65][65];

void check(int hs, int he, int ws, int we) {
    // 전체 영역 확인 시작
    bool allSame = true;
    char sameC = rows[hs][ws];
    for(int i = hs; i < he; ++i) {
        for (int j = ws; j < we; ++j) {
            if (sameC == rows[i][j]) continue;
            allSame = false;
            break;
        }
        if (!allSame) break;
    }
    if (allSame) {
        printf("%c", sameC);
        return;
    }
    printf("(");
    int hm = (hs + he) >> 1; int wm = (ws + we) >> 1;
    check(hs, hm, ws, wm);
    check(hs, hm, wm, we);
    check(hm, he, ws, wm);
    check(hm, he, wm, we);
    printf(")");
}

int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", rows[i]);
    }
    check(0,N,0,N);
    printf("\n");
}