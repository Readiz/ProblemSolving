#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)<(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int N, M, K;
char buf[200010];
int vis[200100];
struct Data {
    int pos;
    int srem;
} q[10'000'010];
void solve() {
    scanf("%d %d %d", &N, &M, &K);
    scanf("%s", &buf[1]);
    memset(vis, 0xFF, sizeof(int) * (N + 20));
    buf[0] = 'L';
    int qf = 0, qr = 0;
    q[qr++] = {0, K};

    while(qf != qr) {
        auto& cur = q[qf++];
        if (vis[cur.pos] > cur.srem) continue;
        vis[cur.pos] = cur.srem;
        if (cur.pos >= N + 1) {
            printf("YES\n");
            return;
        }
        if (buf[cur.pos] == 'C') continue; // invalid
        if (buf[cur.pos] == 'L') {
                FOR(i,1,M+1) {
                    q[qr++] = {cur.pos+i, cur.srem};
                }
        } else if (buf[cur.pos] == 'W' && cur.srem >= 1) {
                q[qr++] = {cur.pos+1, cur.srem-1};
        }
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
