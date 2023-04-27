#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
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

vector<pair<ll,ll>> vec;
int N;
void solve() {
    scanf("%lld", &N);

}

bool check4(ll v) {
    while (v > 0) {
        if (v % 10 == 4) return true;
        v /= 10;
    }
}

void init() {
    bool startRange = false;
    int spos = -1;
    for(int i = 1; i < 1000000000000LL; ++i) {
        if (check4(i)) {
            if (startRange) continue;
            else {
                startRange = true;
                spos = i;
            }
        } else {
            if (startRange) {
                vec.push_back({spos, i});
                startRange = false;
                _D("%lld %lld\n", spos, i);
            }
        }
    }
    _D("INIT END\n");
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    init();
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
