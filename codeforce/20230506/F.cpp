#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("F_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int V, E;
void solve() {
    vector<int> adj[201];
    scanf("%d %d", &V, &E);
    int s;
    FOR(i,0,E) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        s = a;
    }
    int visited[201] = {0, };
    while(adj[s].size() != 1) {
        for(auto& i: adj[s]) {
            if (visited[i]) continue;
            s = i;
            visited[s] = 1;
            break;
        }
    }
    int y = adj[adj[s][0]].size() - 1;
    int m;
    for(auto& i: adj[adj[s][0]]) {
        if (i == s) continue;
        if (adj[i].size() == 1) continue;
        m = i;
        break;
    }
    int x = adj[m].size();
    printf("%d %d\n", x, y);
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
