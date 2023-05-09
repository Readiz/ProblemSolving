#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int N;
void solve() {
    int s, t;
    scanf("%d %d", &s, &t);
    if (s < t) {
        printf("NO\n");
        return;
    }
    if (s == t) {
        printf("YES\n");
        return;
    }
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int c = q.front(); q.pop();
        if (c % 3 != 0) continue;
        int d = c / 3;
        if (d == t || d * 2 == t) {
            printf("YES\n");
            return;
        }
        q.push(d);
        q.push(d * 2);
    }
    printf("NO\n");
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
