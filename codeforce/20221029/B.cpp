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

int N;
void solve() {
    scanf("%d", &N);
    vector<pair<int,int>> t, v;
    int max = -1;
    FOR(i,0,N) {
        int a, b;
        scanf("%d %d", &a, &b);
        t.push_back({a, b});
        if (a < b) {
            if (max < a) max = a;
        } else {
            if (max < b) max = b;
        }
    }
    _D("MAX: %d\n", max);
    
    FOR(i,0,t.size()) {
        pair<int,int> p = t[i];
        if (p.first < p.second) {
            if (max >= p.second) {
                v.push_back({p.second, p.first});
            } else {
                v.push_back(p);
            }
        } else {
            if (max >= p.first) {
                v.push_back(p);
            } else {
                v.push_back({p.second, p.first});
            }
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll sleft = 0, sright = 0, stop = 0, sbottom = 0;
    pair<int,int> cp = v[0];
    ll cl = cp.first, cr = cp.first;
    stop += cp.second, sbottom += cp.second;
    FOR(i, 1, v.size()) {
        cp = v[i];
        if (cl - cp.first < cr - cp.first) {
            sleft += cl - cp.first;
            cl = cp.first;
        } else {
            sright += cr - cp.first;
            cr = cp.first;
        }
        stop += cp.second;
        sbottom += cp.second;
    }
    sleft += cl;
    sright += cr;
    printf("%lld\n", stop + sbottom + sleft + sright);
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
