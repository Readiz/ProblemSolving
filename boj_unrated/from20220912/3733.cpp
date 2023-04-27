#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

int main() {
    int N, S;
    while(scanf("%d %d", &N, &S) != EOF) {
        printf("%d\n", S / (N+1));
    }

    return 0;
}