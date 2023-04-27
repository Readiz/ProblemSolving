#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
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

int N;
void solve() {
    scanf("%d", &N);
    int last, lastp = 1;
    scanf("%d", &last);
    bool zeromode = false;
    if (last == 0) zeromode = true;

    vector<pair<int,int>> fl; // {0, 1, 1, ...}
    vector<pair<int,int>> fnl; // {0, -1, -1, ...}
    vector<pair<int,int>> l; // {1, 1, 1, 1, ...}
    vector<pair<int,int>> nl; // {-1, -1, -1, ...}
    vector<pair<int,int>> z; // {0, 0, 0, ...}
    FOR(i,1,N+1) {
        int c;
        scanf("%d", &c);
        if (last == c) continue;
        // 여기 온건 이제 다르다는 뜻
        if (last == 0) {
            // 0, 0, ... , 0, +-1 <- i
            if (i - 2 >= lastp) {
                z.push_back(make_pair(lastp, i-2));
            }
            lastp = i-1; // 0이 있는 지점
            zeromode = true;
        } else {
            if (c == 1) {
                // -1 -> 1
                if (zeromode) {
                    fnl.push_back(make_pair(lastp, i-1));
                } else {
                    nl.push_back(make_pair(lastp, i-1));
                }
                lastp = i;
                zeromode = false;
            } else if (c == -1) {
                // 1 -> -1
                if (zeromode) {
                    fl.push_back(make_pair(lastp, i-1));
                } else {
                    l.push_back(make_pair(lastp, i-1));
                }
                lastp = i;
                zeromode = false;
            } else {
                lastp = i;
                zeromode = true;
            }
        }
        last = c;
    }
    if (zeromode) {
        if (last == 1) {
            fl.push_back(make_pair(lastp, N));
        } else if (last == -1) {
            fnl.push_back(make_pair(lastp, N));
        } else {
            z.push_back(make_pair(lastp, N));
        }
    } else {
        if (last == 1) {
            l.push_back(make_pair(lastp, N));
        } else if (last == -1) {
            nl.push_back(make_pair(lastp, N));
        } else {
            z.push_back(make_pair(lastp, N));
        }
    }
    _D("[FL] ");
    for(auto& i: fl) {
        _D("(%d, %d) ", i.first, i.second);
    }
    _D("\n");
    _D("[FNL] ");
    for(auto& i: fnl) {
        _D("(%d, %d) ", i.first, i.second);
    }
    _D("\n");
    _D("[L] ");
    for(auto& i: l) {
        _D("(%d, %d) ", i.first, i.second);
    }
    _D("\n");
    _D("[NL] ");
    for(auto& i: nl) {
        _D("(%d, %d) ", i.first, i.second);
    }
    _D("\n");
    _D("[Z] ");
    for(auto& i: z) {
        _D("(%d, %d) ", i.first, i.second);
    }
    _D("\n");
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
