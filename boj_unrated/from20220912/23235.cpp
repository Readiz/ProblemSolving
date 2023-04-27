#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

int N, d;
int main() {
    int T = 1;
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        FOR(i, 0, N) scanf("%d", &d);
        printf("Case %d: Sorting... done!\n", T);
        ++T;
    }
    return 0;
}