#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
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

int N;
void solve() {
    scanf("%d", &N);
    vector<ll> v;
    ll sum = 0;
    FOR(i,0,N) {
        ll tmp; scanf("%lld", &tmp);
        v.push_back(tmp);
        if (tmp < 0) sum += -tmp;
        else sum += tmp;
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        if (v[i] < 0) {
            int j;
            for(j = i + 1; j < N; ++j) {
                if (v[j] <= 0) continue;
                break;
            }
            i = j;
            ++cnt;
        }
    }

    printf("%lld %d\n", sum, cnt);
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
