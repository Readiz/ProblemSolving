#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

struct UF {
    int parent[200001];
    void init(int N) {
        for(int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
    }
    int getRoot(int v) {
        if (v == parent[v]) return v;
        return parent[v] = getRoot(parent[v]);
    }
    void merge(int a, int b) {
        a = getRoot(a); b = getRoot(b);
        parent[a] = b;
    }
} uf;

void solve() {
    vector<int> edges[200001];
    int N; scanf("%d", &N);
    uf.init(N);

    FOR(i,0,N-1) {
        int a, b; scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bool visited[200001] = {false,} ;
    int parent[200001] = {0, };
    long long leafCnt[200001]= {0, };
    queue<int> q;
    q.push(1);
    while(q.size()) {
        int c = q.front(); q.pop();
        if (visited[c]) continue;
        visited[c] = true;

        bool hasChild = false;
        int childNum = 0;
        int lastChild = -1;
        for(auto& t: edges[c]) {
            if (visited[t]) continue;
            hasChild = true;
            ++childNum;
            parent[t] = c;
            q.push(t);
            lastChild = t;
        }
        if (childNum == 1) {
            // Path compression
            uf.merge(lastChild, c); // lastChild == c
        }
        if (hasChild == false) { // leaf
            int p = c;
            for(; p != 0;) {
                p = uf.getRoot(p);
                leafCnt[p]++;
                p = parent[p];
            }
        }
    }
    int Q; scanf("%d", &Q);
    FOR(i,0,Q) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%lld\n", leafCnt[uf.getRoot(a)] * leafCnt[uf.getRoot(b)]);
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
