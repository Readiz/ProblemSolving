#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
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

ll pyr[2024][2024];
ll presum[2024][2024];
map<int, pair<int,int>> M;

int N;
void solve() {
    scanf("%d", &N);
    _D("POS: %d, %d\n", M[N].first, M[N].second);
    int l = M[N].second;
    int r = l;
    --l;
    ll oSum = 0;
    for(int row = M[N].first; row >= 1; --row) {
        ll csum = presum[row][r] - presum[row][l];
        oSum += csum;
        //_D("[%d] %d - %d: %lld\n", row, r, l, oSum);
        --l;
        if (l < 0) l = 0;
        if (r >= row) r = row - 1;
    }
    printf("%lld\n", oSum);
}

void build() {
    int n = 1;
    for(int row = 1; row <= 2023; ++row) {
        ll psum = 0;
        for(int i = 1; i <= row; ++i, ++n) {
            pyr[row][i] = (ll)n * n;
            psum += (ll)n * n;
            presum[row][i] = psum;
            M[n] = {row, i};
        }
    }
}

MAIN_START
    build();

    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
