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
#define X first
#define Y second

int N;
void solve() {
    scanf("%d", &N);
    vector<ll> v(N + 1), p(N+1), s(N+1);
    ll ans = -9876543210000000;
    for(int i = 1; i <= N; ++i) {
        scanf("%lld", &v[i]);
        ans = max(ans, v[i]);
    } 
    for(int i = 1; i <= N; ++i) p[i] = p[i - 1] + v[i];

    v[0] = -1;
    for(int l = 1; l <= N; ++l) {
        if ((v[l - 1] < 0 && v[l] >= 0) || ((v[l] % 2 == 0) == (v[l - 1] % 2 == 0))) { // 시작점 설정
        // _D("l: %d...\n", l);
            int r = l;
            for(; r + 1 <= N; ++r) { // 영역을 최대한 확장
                if ((v[r] % 2 == 0) != (v[r + 1] % 2 == 0)) {
                    ll cur = p[r + 1] - p[l - 1];
                    if (cur > ans) ans = cur;
                    continue;
                }
                break;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}