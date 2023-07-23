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
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    if (a+b >= 10 || b+c >= 10 || a+c >= 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}
