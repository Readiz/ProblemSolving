#include <bits/stdc++.h>
using namespace std;

constexpr long long INF =  0x7FFFFFFFFFFFFFFF;
constexpr long long NINF = -INF;

int main() {
    int N; scanf("%d", &N);
    long long minX = NINF;
    long long maxX = INF;
    long long minY = NINF;
    long long maxY = INF;
    char buf[10];
    long long x, y;
    for(int i = 0; i < N; ++i) {
        scanf("%lld %lld %s", &x, &y, buf);
        switch (buf[0]) {
            case 'L':
            maxX = min(maxX, x - 1);
            break;
            case 'R':
            minX = max(minX, x + 1);
            break;
            case 'U':
            minY = max(minY, y + 1);
            break;
            case 'D':
            maxY = min(maxY, y - 1);
            break;
        }
    }
    if (minX == NINF || maxX == INF || minY == NINF || maxY == INF) {
        printf("Infinity\n");
    } else {
        printf("%lld\n", (maxX - minX + 1LL) * (maxY - minY + 1LL));
        assert((maxX - minX + 1LL) * (maxY - minY + 1LL)>0);
    }
    return 0;
}