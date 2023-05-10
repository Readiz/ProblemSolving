#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[100][100];
    FOR(i,0,M) FOR(j,0,N) {
        scanf("%d", &A[i][j]);
    }
    FOR(i,0,M) FOR(j,0,N) {
        int t; scanf("%d", &t);
        A[i][j] += t;
    }
    FOR(i,0,M) {
        printf("%d", A[i][0]);
        FOR(j,1,N) {
            printf(" %d", A[i][j]);
        }
        printf("\n");
    }
}