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
    set<int> S;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        S.insert(tmp);
    }
    auto it = S.end();
    --it;
    --it;
    printf("%d\n", *it);
}

int main() {
    solve();
    return 0;
}