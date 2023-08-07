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

struct Group {
    int bbok;
    int kkok;
};
int N, M, K;
constexpr int S = 1024;
constexpr int T = 1025;
constexpr int INF = 987654321;
Group pGroupB[512], pGroupK[512];
int capa[1026][1026];
int flow[1026][1026];
int pre[1026];
vector<int> adj[1026];

int main() {
    scanf("%d %d %d", &N, &M, &K);

    auto mlink = [&](int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    };

    int nd = 0, nc = 0;
    // 서로 배타되는 집합을 이분매칭으로 찾을 수 있다.
    FOR(i,0,K) {
        int m, n, kind;
        scanf("%d %d %d", &m, &n, &kind);
        if (kind == 0) {
            pGroupB[nc++] = Group{m, n};
        } else {
            pGroupK[nd++] = Group{m, n};
        }
    }
    _D("CGroup: %d / DGroup: %d\n", nc, nd);

    for(int i = 0; i < K; ++i) {
        capa[S][i] = 1;
        capa[i+512][T] = 1;
        mlink(S, i);
        mlink(i + 512, T);
    }
    for(int i = 0; i < nc; ++i) {
        for(int j = 0; j < nd; ++j) {
            if (pGroupB[i].bbok == pGroupK[j].bbok || pGroupB[i].kkok == pGroupK[j].kkok) {
                // 서로 함께할 수 없는 경우의 수를 세는 것 - 배제집합
                capa[i][j + 512] = 1;
                mlink(i, j + 512);
            }
        }
    }
    int ans = 0;

    while(true) {
        fill(pre, pre+1026, -1);
        queue<int> q;
        q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(auto& t: adj[cur]) {
                int residual = capa[cur][t] - flow[cur][t];
                if (residual > 0 && pre[t] == -1) {
                    pre[t] = cur;
                    if (t == T) break;
                    q.push(t);
                }
            }
            if (pre[T] != -1) break;
        }
        if (pre[T] == -1) break; // no augpath

        for(int p = T; p != S; p = pre[p]) {
            flow[pre[p]][p] += 1;
            flow[p][pre[p]] -= 1;
        }
        ans += 1;
    }

    printf("%d\n", ans);

    return 0;
}
