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

int N;
set<pair<int,int>> V[200001]; // V_i의 Edge들 -> V_j, idx
void solve() {
    scanf("%d", &N);
    for(int i = 0; i <= N; ++i) V[i].clear();
    int root = -1;
    FOR(i,1,N) {
        int a, b; scanf("%d %d", &a, &b);
        V[a].insert({b, i}); // i: Edge 번호
        if (root == -1) root = a;
    }

    while (true) {
        // leaf 하나 뽑는다.
        int p = root;
        if (V[p].size() == 0) break;
        stack s;
        s.push(p);
        for(; V[p].size() != 0; p = V[p].begin()->first) {
            s.push(p);
        }

    }
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
