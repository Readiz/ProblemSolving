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

char buf[100][100];
void solve() {
    FOR(i,0,8) {
        scanf("%s", buf[i]);
    }
    int v = -1;
    int s = -1;
    ([&](){
        FOR(i,0,8) {
            FOR(j,0,8) {
                if (buf[i][j] != '.') {
                    v = j;
                    s = i;
                    return;
                }
            }
        }
    })();
    while(buf[s][v] != '.' && s < 8) {
        printf("%c", buf[s][v]);
        ++s;
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}