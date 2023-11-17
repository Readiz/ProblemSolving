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
    vector<int> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &v[i]);
    int cnt2[200010] = {0,}; // i까지 2의 수
    int cnt4[200010] = {0,};

    int tmp2 = 0, tmp4 = 0;
    map<int, int> cnt;
    set<int> dup;
    for(int i = 1; i <= N; ++i) {
        if(v[i] == 1) {
            ++tmp2;
        } else if (v[i] == 2) {
            ++tmp4;
        }
        cnt2[i] = tmp2;
        cnt4[i] = tmp4;
        if (dup.find(v[i]) == dup.end()) {
            dup.insert(v[i]);
        } else {
            if (cnt.find(v[i]) == cnt.end()) {
                cnt[v[i]] = 1;
            }
            cnt[v[i]]++;
        }
    }
    ll ans = 0;

    for(auto& c: cnt) {
        // 같은 숫자끼리 고르기 - 조합
        ans += (ll)c.Y * ((ll)c.Y - 1) / 2; // 3이면 3, 2면 1
        _D("[%d] cnt: %d!\n",c.X, c.Y);
    }
    for(int i = 1; i <= N; ++i) {
        if(v[i] == 1) {
            int c4 = cnt4[N] - cnt4[i - 1]; // 뒤쪽에 있는 4의 수
            ans += c4;
        } else if (v[i] == 2) {
            int c2 = cnt2[N] - cnt2[i - 1];
            ans += c2;
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