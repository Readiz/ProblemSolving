#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...)
    inline void testInit() { freopen("F_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N, M, sy, sx, ey, ex;
char buf[10];
int dx, dy;
void solve() {
    scanf("%d %d %d %d %d %d %s", &N, &M, &sy, &sx, &ey, &ex, buf);
    _D("%d, %d -> %d, %d\n", sy, sx, ey, ex);
    if (buf[0] == 'D') dy = 1;
    else dy = -1;
    if (buf[1] == 'R') dx = 1;
    else dx = -1;
    set<pii> visited;
    int cx = sx;
    int cy = sy;
    int cnt = 0;
    int ny = dy, nx = dx;
    if (cy == ey && cx == ex) {
        _D("END!\n");
        printf("%d\n", cnt);
        return;
    }

    while(visited.find({(cy << 16) | cx, dy * -4 + dx}) == visited.end()) {
        visited.insert({(cy << 16) | cx, dy * -4 + dx});
        _D("%d, %d\n", cy, cx);
        if (cy == N) ny = -1;
        else if (cy == 1) ny = 1;
        if (cx == M) nx = -1;
        else if (cx == 1) nx = 1;
        if (ny != dy || nx != dx) {
            ++cnt;
            dy = ny; dx = nx;
            _D("BUMP!\n");
        }
        cy += dy;
        cx += dx;
        if (cy == ey && cx == ex) {
            _D("END!\n");
            printf("%d\n", cnt);
            return;
        }
    }
    printf("-1\n");
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
