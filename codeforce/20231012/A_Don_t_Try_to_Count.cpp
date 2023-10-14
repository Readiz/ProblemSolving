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
char buf[100];
void solve() {
    int tmp; scanf("%d", &tmp); scanf("%d", &tmp);
    string a, b;
    scanf("%s", buf);
    a = buf;
    scanf("%s", buf);
    b = buf;

    int ans = 0;
    int i;
    for(i = 0; i < 10; ++i) {
        // _D("checking %s / %s...\n", a.c_str(), b.c_str());
        if (a.find(b) != string::npos) {
            break;
        }
        a += a;
        ++ans;
    }
    if (i == 10) printf("-1\n");
    else printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}