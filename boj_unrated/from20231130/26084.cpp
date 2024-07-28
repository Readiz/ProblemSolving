#include <stdio.h>

#define FOR(i,a,b) for(int i=(a); i<(b); ++i)

long long nCk(long long n, long long k) {
    if (k == 1) return n;
    if (k == 2) return n * (n - 1) / 2;
    if (k == 3) return n * (n - 1) * (n - 2) / 6;
    return -1;
}

char buf[100];
int main() {
    scanf("%s", buf);
    int tcnt[300] = {0, };
    FOR(i,0,3) {
        tcnt[buf[i]]++;
    }

    int ncnt[300] = {0,};
    int N; scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%s", buf);
        ncnt[buf[0]]++;
    }

    long long ans = 1;
    FOR(c,'A','Z'+1) {
        if (tcnt[c] > 0) {
            ans *= nCk(ncnt[c], tcnt[c]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}