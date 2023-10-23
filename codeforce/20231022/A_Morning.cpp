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
char buf[10];
void solve() {
    scanf("%s", &buf);
    int cur = '1';
    int ans = 4;
    for(int i = 0; i < 4; ++i) {
        if (buf[i] == '0') buf[i] += 10;
        ans += abs(buf[i] - cur);
        cur = buf[i];
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}