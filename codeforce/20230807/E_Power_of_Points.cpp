#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pll;
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
    vector<ll> ans; ans.resize(N);
    vector<pll> A;
    FOR(i,0,N) {
        ll tmp; scanf("%lld", &tmp);
        A.push_back({tmp, i});
    }
    sort(A.begin(), A.end());

    ll last = 0;
    for(int i = 1; i < N; ++i) {
        last += A[i].first - A[0].first + 1;
    }
    last += 1;
    ans[A[0].second] = last;
    for(int p = 1; p < N; ++p) {
        ll diff = A[p].first - A[p - 1].first;
        last = last - diff * (N - p) + diff * p;
        ans[A[p].second] = last;
    }
    for(auto& item: ans) {
        printf("%lld ", item);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}