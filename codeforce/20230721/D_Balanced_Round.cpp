#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

int N, K;
void solve() {
    scanf("%d %d", &N, &K);
    vector<ll> v;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    vector<ll> diff;
    for(int i = 1; i < v.size(); ++i) {
        diff.push_back(v[i] - v[i-1]);
    }
    diff.push_back(0x7FFFFFFF);
    int last = 0;
    int maxLast = -1;
    for(auto& item: diff) {
        if (item <= K) ++last;
        else {
            if (last > maxLast) maxLast = last;
            last = 0;
        }
    }
    printf("%d\n", N - maxLast - 1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}