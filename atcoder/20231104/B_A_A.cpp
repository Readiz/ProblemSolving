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

ll pow(ll a, ll p) {
    ll res = 1LL;
    while (p) {
        if (p & 1LL) res = res * a;
        a = a * a;
        p >>= 1LL;
    }
    return res;
}

ll N;
void solve() {
    scanf("%lld", &N);
    for(ll a = 1; pow(a, a) <= N; ++a) {
        if (pow(a, a) == N) {
            printf("%lld\n", a);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    solve();
    return 0;
}