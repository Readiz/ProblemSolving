#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int capa[302][302]; // 2~N+1: 사람(+2) / N+2 ~ N+D+1: 음식(+N+2)
int flow[302][302]; // 0: S / 1: T
int pre[302];
int visited[302];

int PersonOffset;
int DishOffset;

constexpr int S = 0;
constexpr int T = 1;


int main() {
    int N, K, D; scanf("%d %d %d", &N, &K, &D);
    
    PersonOffset = 2;
    DishOffset = N + 2;
    // O(VE^2) - Max Flow
    // S -> 사람 간선 추가
    for(int i = 0; i < N; ++i) {
        capa[S][i+PersonOffset] = K;
    }
    for(int i = 0; i < D; ++i) {
        scanf("%d", &capa[i+DishOffset][T]);
    }
    for(int i = 0; i < N; ++i) {
        int C; scanf("%d", &C);
        for(int c = 0; c < C; ++c) {
            int dish;
            scanf("%d", &dish); // 1-indexed
            capa[i+PersonOffset][dish-1+DishOffset] = 1;
        }
    }
    // for(int i = 0; i < 10; ++i) {
    //     for(int j = 0; j < 10; ++j) {
    //         printf("%d ", capa[i][j]);
    //     }
    //     printf("\n");
    // }

    int ans = 0;

    while(true) {
        fill(pre,pre+302,-1);
        fill(visited,visited+302,0);

        visited[S] = 1;
        queue<int> q;
        q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            // printf("q: %d\n", cur);

            for(int t = 1; t < 302; ++t) {
                if (visited[t]) continue;
                int res = capa[cur][t] - flow[cur][t];
                if (res > 0) {
                    visited[t] = 1;
                    pre[t] = cur;
                    q.push(t);
                    if (t == T) break;
                }
            }
            if (visited[T] == 1) break;
        }
        // printf("iter! %d\n", pre[T]);

        if (pre[T] == -1) break; // no update!

        int amount = 0x7FFFFFFF;
        for(int p = T; p != S; p = pre[p]) {
            amount = min(amount, capa[pre[p]][p] - flow[pre[p]][p]);
        }
        for(int p = T; p != S; p = pre[p]) {
            flow[pre[p]][p] += amount;
            flow[p][pre[p]] -= amount;
        }

        ans += amount;
        // printf("ans: %d\n", ans);
    }

    printf("%d\n", ans);
    return 0;
}