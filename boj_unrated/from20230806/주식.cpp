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
    vector<int> v;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    stack<int> S;
    long long ans = 0;
    for(int i = N - 1; i >= 0; --i) {
        auto& cur = v[i];
        if (S.size() == 0) S.push(cur);
        else {
            if (S.top() > cur) {
                ans += S.top() - cur;
            } else if (S.top() < cur) {
                while(S.size() && S.top() < cur) S.pop();
                S.push(cur);
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