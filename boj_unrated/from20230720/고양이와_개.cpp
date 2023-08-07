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
    int like;
    int hate;
    int idx;
};
int C, D, V;
constexpr int S = 1000;
constexpr int T = 1001;
constexpr int INF = 987654321;
void solve() {
    scanf("%d %d %d", &C, &D, &V);
    Group pGroupD[500], pGroupC[500];
    int capa[1002][1002] = {0, };
    int flow[1002][1002] = {0, };
    int pre[1002];
    vector<int> adj[1002];

    auto mlink = [&](int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    };

    int nd = 0, nc = 0;
    // 서로 배타되는 집합을 이분매칭으로 찾을 수 있다.
    FOR(i,0,V) {
        char a;
        do {
            scanf("%c", &a);
        } while(a != 'C' && a != 'D');
        int m, n;
        scanf("%d %c%d", &m, &a, &n);
        if (a == 'D') {
            pGroupC[nc++] = Group{m, n, i};
        } else {
            pGroupD[nd++] = Group{m, n, i};
        }
        _D("%d %d\n", m, n);
    }
    _D("CGroup: %d / DGroup: %d\n", nc, nd);

    for(int i = 0; i < V; ++i) {
        capa[S][i] = 1;
        capa[i+500][T] = 1;
        mlink(S, i);
        mlink(i + 500, T);
    }
    for(int i = 0; i < nc; ++i) {
        for(int j = 0; j < nd; ++j) {
            if (pGroupC[i].like == pGroupD[j].hate || pGroupC[i].hate == pGroupD[j].like) {
                // 서로 함께할 수 없는 경우의 수를 세는 것 - 배제집합
                capa[i][j + 500] = 1;
                mlink(i, j + 500);
            }
        }
    }
    int ans = 0;

    while(true) {
        fill(pre, pre+1002, -1);
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

    printf("%d\n", V - ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef unsigned long long ull;
// typedef long long ll;
// typedef pair<int,int> pii;
// #define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
// #ifndef ONLINE_JUDGE
//     bool isDebug = true;
//     #define _D(...) printf(__VA_ARGS__)
// #else
//     bool isDebug = false;
//     #define _D(...)
// #endif

// struct Group {
//     int like;
//     int hate;
//     int idx;
// };
// int C, D, V;
// constexpr int S = 1000;
// constexpr int T = 1001;
// constexpr int INF = 987654321;
// void solve() {
//     scanf("%d %d %d", &C, &D, &V);
//     Group pGroupD[500], pGroupC[500];
//     int capa[1002][1002] = {0, };
//     int flow[1002][1002] = {0, };
//     int pre[1002];
//     vector<int> adj[1002];

//     auto mlink = [&](int i, int j) {
//         adj[i].push_back(j);
//         adj[j].push_back(i);
//     };

//     int nd = 0, nc = 0;
//     scanf("%c");
//     // 서로 배타되는 집합을 이분매칭으로 찾을 수 있다.
//     FOR(i,0,V) {
//         char a, b;
//         int m, n;
//         scanf("%c%d %c%d", &a, &m, &b, &n);
//         if (a == 'C') {
//             pGroupC[nc++] = Group{m, n, i};
//         } else {
//             pGroupD[nd++] = Group{m, n, i};
//         }
//         scanf("%c");
//         _D("%d %d\n", m, n);
//     }
//     _D("CGroup: %d / DGroup: %d\n", nc, nd);

//     for(int i = 0; i < V; ++i) {
//         capa[S][i] = INF;
//         capa[i+500][T] = 1;
//         mlink(S, i);
//         mlink(i + 500, T);
//     }
//     for(int i = 0; i < nc; ++i) {
//         for(int j = 0; j < nd; ++j) {
//             if (pGroupC[i].like == pGroupD[j].hate) { // 서로 함께할 수 없는 경우의 수를 세는 것
//                 capa[pGroupC[i].idx][pGroupD[j].idx + 500] = 1;
//                 mlink(pGroupC[i].idx, pGroupD[j].idx + 500);
//             }
//             if (pGroupD[i].like == pGroupC[j].hate) {
//                 capa[pGroupD[j].idx][pGroupC[i].idx + 500] = 1;
//                 mlink(pGroupD[j].idx, pGroupC[i].idx + 500);
//             }
//         }
//     }
//     int ans = 0;

//     while(true) {
//         fill(pre, pre+1002, -1);
//         queue<int> q;
//         q.push(S);
//         while(q.size()) {
//             int cur = q.front(); q.pop();
//             for(auto& t: adj[cur]) {
//                 int residual = capa[cur][t] - flow[cur][t];
//                 if (residual > 0 && pre[t] == -1) {
//                     pre[t] = cur;
//                     if (t == T) break;
//                     q.push(t);
//                 }
//             }
//             if (pre[T] != -1) break;
//         }
//         if (pre[T] == -1) break; // no augpath

//         for(int p = T; p != S; p = pre[p]) {
//             flow[pre[p]][p] += 1;
//             flow[p][pre[p]] -= 1;
//         }
//         ans += 1;
//     }

//     printf("%d\n", V - ans);
// }

// int main() {
//     int tc;
//     scanf("%d", &tc);
//     FOR(TC,0,tc) {
//         solve();
//     }

//     return 0;
// }