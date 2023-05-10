#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
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

int N;
void solve() {
    scanf("%d", &N);
    _D("N: %d\n", N);
    if (N == 1) {
        printf("1\n1 2\n");
        return;
    } else if (N == 2) {
        printf("1\n2 6\n");
        return;
    }
    string debug = "";
    FOR(i,0,N) {
        debug += "BAN";
    }
    _D("%s  / %d\n", debug.c_str(), debug.size());
    int l = 0, r = debug.size() - 1;
    vector<pii> v;
    while (l < r) {
        while(l < debug.size() && debug[l] != 'A') ++l;
        while(r >= 0 && debug[r] != 'N') --r;
        if (l > r) break;
        v.push_back({l, r});
        char c = debug[l];
        debug[l] = debug[r];
        debug[r] = c;
    }
    _D("%s\n", debug.c_str());
    printf("%d\n", v.size());
    FOR(i,0,v.size()) {
        printf("%d %d\n", v[i].first + 1, v[i].second + 1);
    }
    _D("----------\n");
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
