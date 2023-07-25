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
    vector<int> odd, even;
    vector<int> all;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        if (tmp % 2 == 0) {
            even.push_back(tmp);
        } else {
            odd.push_back(tmp);
        }
        all.push_back(tmp);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int op = 0; int ep = 0;
    for(int i = 0; i < all.size(); ++i) {
        if (all[i] % 2 == 0) {
            all[i] = even[ep++];
        } else {
            all[i] = odd[op++];
        }
    }
    bool valid = true;
    for(int i = 1; i < all.size(); ++i) {
        if (all[i-1] <= all[i]) continue;
        valid = false;
        break;
    }
    if (valid) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}