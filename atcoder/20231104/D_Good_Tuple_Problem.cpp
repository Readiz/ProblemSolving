#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif
#define X first
#define Y second

int N, M;
int v[200010];
vector<int> gph[200010];

struct Node {
    int depth;
    int vis;
} n[200010];

bool dfs(int t, int depth) {
    if (n[t].vis == 0) {
        n[t].vis = 1;
    }
    n[t].depth = depth;
    for(auto& next: gph[t]) {
        if (n[next].depth != 0) {
            int diff = depth - n[next].depth;
            if (diff % 2 == 1) continue;
            return false;
        }
        bool ret = dfs(next, depth + 1);
        return ret;
    }
    return true;
}

void solve() {
    scanf("%d %d", &N, &M);
    vector<int> A(M);
    vector<int> B(M);
    for(auto& i: A) scanf("%d", &i);
    for(auto& i: B) scanf("%d", &i);

    set<pair<int,int>> S;
    for(int i = 0; i < M; ++i) {
        int a = A[i];
        int b = B[i];
        if (a == b) {
            printf("No\n");
            return;
        }
        if (S.find({a, b}) != S.end() || S.find({b, a}) != S.end()) {
            // 이미 체크된 간선
            continue;
        }
        S.insert({a, b});

        gph[a].push_back(b);
        gph[b].push_back(a);
    }
    for(int i = 1; i <= N; ++i) {
        if (n[i].vis == 0) {
            bool ret = dfs(i, 1);
            if (ret == false) {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main() {
    solve();
    return 0;
}