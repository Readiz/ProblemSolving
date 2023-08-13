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

int N, K;
void solve() {
    scanf("%d %d", &N, &K);
    vector<pair<int, int>> v, p;
    vector<int> res;
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        v.push_back({t, i});
    }
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        p.push_back({t, i});
        res.push_back(0);
    }

    sort(v.begin(), v.end());
    sort(p.begin(), p.end());

    FOR(i,0,N) {
        //_D("DIFF: %d\n", v[i].first - p[i].first);
        res[v[i].second] = p[i].first;
    }

    FOR(i,0,N) {
        printf("%d ", res[i]);
    }
    printf("\n");
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
