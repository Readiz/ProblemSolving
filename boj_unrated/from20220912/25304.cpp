#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

int X, N;
int V;
int a, b;
int main() {
    scanf("%d", &X);
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%d %d", &a, &b);
        V += a * b;
    }
    if (X == V) printf("Yes\n");
    else printf("No\n");
}