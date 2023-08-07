// Max Flow 연습

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

int N, P;
int capa[401][401];
int flow[401][401];
int visited[401];
int pre[401];
vector<int> edges[401];

constexpr int INF = 987654321;
int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    for(int i = 0; i < P; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        capa[a][b] = 1;
        edges[a].push_back(b);
        edges[b].push_back(a); // 역방향 flow 발생 가능
    }

    int ans = 0;
    while(true) {
        fill(visited, visited+N+1, 0);
        fill(pre, pre+N+1, 0);
        // 경로 1개를 찾는다.
        queue<int> q; q.push(1);
        while(q.size()) {
            int cur = q.front(); q.pop();
            if (cur == 2) break;
            if (visited[cur]) continue;
            visited[cur] = 1;

            for(auto& t: edges[cur]) {
                if(visited[t]) continue;
                int residual = capa[cur][t] - flow[cur][t];
                if (residual > 0) {
                    // printf("checking %d -> %d...\n", cur, t);
                    pre[t] = cur;
                    q.push(t);
                }
            }
        }
        if (pre[2] == 0) break; // 더이상 augmenting path 없음

        for(int p = 2; p != 1; p = pre[p]) {
            flow[pre[p]][p] += 1;
            flow[p][pre[p]] -= 1;
        }
        ans += 1;
    }

    printf("%d\n", ans);

    return 0;   
}