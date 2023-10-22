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

int N;
void solve() {
    scanf("%d", &N);
    int num[25] = {0, };
    FOR(i,0,N) {
        int a, b; scanf("%d %d", &a, &b);
        num[b] += a;
    }
    ll ans = 0;
    for(int i = 0; i < 24; ++i) {
        ll base = 0;
        for(int j = i; j < i + 9; ++j) {
            base += num[j % 24];
        }
        ans = max(ans, base);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();

    return 0;
}