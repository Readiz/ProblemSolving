#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("G_input.txt", "rt", stdin); }
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

int N, C;
void solve() {
    scanf("%d %d", &N, &C);
    vector<pair<int,int>> v;
    int minStart = 0x7FFFFFFF;
    int minIdx = -1;
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        v.push_back({t, i + 1});
        if (t + i + 1 < minStart) {
            minIdx = i;
            minStart = t + i + 1;
        }
    }
    if (minStart > C) {
        printf("%d\n", 0);
        return;
    }
    v.erase(v.begin() + minIdx);
    C -= minStart;
    sort(v.begin(), v.end());
    long long sum = 0;
    int r = 0;
    for(auto& item: v) {
        sum += item.first;
        if (sum <= C) ++r;
        else break;
    }
    printf("%d\n", r);
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
