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

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> v(N);
    for(auto& i: v) scanf("%d", &i);
    sort(v.begin(), v.end());
    int cntMax = 0;
    int ans = -1;
    for(auto& i: v) {
        auto s = lower_bound(v.begin(), v.end(), i);
        auto e = lower_bound(v.begin(), v.end(), i + M);
        if (e - s > cntMax) {
            cntMax = e - s;
            ans = i;
        }
    }
    printf("%d\n", cntMax);
}

int main() {
    solve();
    return 0;
}