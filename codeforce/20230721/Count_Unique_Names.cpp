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
char buf[10000];

void solve() {
    scanf("%d", &N);
    unordered_set<string> M;
    FOR(i,0,N) {
        scanf("%s", buf);
        string name = buf;
        M.insert(name);
    }
    printf("%d\n", M.size());
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        printf("#%d ", TC+1);
        solve();
    }
}