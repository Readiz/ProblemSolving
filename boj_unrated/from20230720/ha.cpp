#include <bits/stdc++.h>
using namespace std;

constexpr long long INF =  0x7FFFFFFFFFFFFFFF;
constexpr long long NINF = -INF;

int main() {
    int N; scanf("%d", &N);
    long long minX = INF;
    long long maxX = NINF;
    long long minY = INF;
    long long maxY = NINF;
    char buf[10];
    long long x, y;
    for(int i = 0; i < N; ++i) {
        scanf("%lld %lld %s", &x, &y, buf);
        switch (buf[0]) {
            case 'L':
            minX = min(minX, x - 1);
            break;
            case 'R':
            maxX = max(maxX, x + 1);
            break;
            case 'U':
            maxY = max(maxY, y + 1);
            break;
            case 'D':
            minY = min(minY, y - 1);
            break;
        }
    }
    if (minX == INF || maxX == NINF || minY == INF || maxY == NINF) {
        printf("Infinity\n");
    } else {
        printf("%lld\n", (maxX - minX + 1LL) * (maxY - minY + 1LL));
        assert((maxX - minX + 1LL) * (maxY - minY + 1LL)>0);
    }
    return 0;
}