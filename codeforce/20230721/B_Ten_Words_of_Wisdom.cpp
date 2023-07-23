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

int N;
void solve() {
    scanf("%d", &N);
    priority_queue<pair<int,int> > pq;
    FOR(i,0,N) {
        int a, b; scanf("%d %d", &a, &b);
        if (a <= 10) {
            pq.push({b, i+1});
        }
    }
    if (pq.size()) {
        printf("%d\n", pq.top().second);
    } else {

    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}