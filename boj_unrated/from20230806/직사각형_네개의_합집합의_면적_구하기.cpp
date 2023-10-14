#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

int main() {
    int area[101][101] = {0, };
    for(int k = 0; k < 4; ++k) {
        int x, y, tx, ty; scanf("%d %d %d %d", &x, &y, &tx, &ty);
        for(int i = y; i < ty; ++i) {
            for(int j = x; j < tx; ++j) {
                area[i][j]++;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 100; ++i) {
        for(int j = 1; j <= 100; ++j) {
            if (area[i][j]) ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}