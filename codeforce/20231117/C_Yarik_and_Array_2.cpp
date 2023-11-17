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
    vector<int> v(N + 1), p(N+1), s(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &v[i]);
    for(int i = 1; i <= N; ++i) p[i] = p[i - 1] + v[i];
    s[1] = 1;
    int last = 1;
    vector<pair<int, int>> sPoses;
    for(int i = 2; i <= N; ++i) {
        if ((v[i - 1] % 2 == 0) != (v[i] % 2 == 0)) {
            s[i] = last;
        } else {
            sPoses.push_back({last, i - 1});
            last = i;
            s[i] = i;
        }
    }
    sPoses.push_back({last, N});
    for(int i = 1; i <= N; ++i) {
        _D("%d ", s[i]);
    }
    _D("\n");
    for(auto& i: sPoses) {
        _D("%d, %d\n", i.X, i.Y);
    }
    return;

    ll ans = -9876543210000000;

    for(auto& s: sPoses) {
        int l = s.X; int r = s.Y;
        ll cur = p[r] - p[l - 1];
        ans = max(cur, ans);
        while(l <= r) {
            
        }
    }
    // for(int l = 1; l <= N; ++l) {
    //     if ((v[l] % 2 == 0) != (v[l + 1] % 2 == 0)) {
    //         int r = l + 1;
    //         for(; r + 1 <= N; ++r) { // 영역을 최대한 확장
    //             if ((v[r] % 2 == 0) != (v[r + 1] % 2 == 0)) {
    //                 ll cur = p[r + 1] - p[l - 1];
    //                 if (cur > ans) ans = cur;
    //                 continue;
    //             }
    //             break;
    //         }
    //         ll cur = p[r] - p[l - 1];
    //         if (cur > ans) ans = cur;

    //         bool foundNeg = false;
    //         int negk = -1;
    //         for(int k = l; k <= N; ++k) {
    //             if (v[k] < 0) {
    //                 negk = k;
    //                 foundNeg = true;
    //                 break;
    //             }
    //         }
    //         if (foundNeg) {
    //             l = negk + 1;
    //         } else {
    //             l = r;
    //         }
    //     } else {
    //         // 1개 case
    //         ll cur = v[l];
    //         if (cur > ans) ans = cur;
    //     }
    // }
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