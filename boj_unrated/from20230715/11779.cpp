#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

constexpr int INF = 987654321;

vector<pii> edges[1001];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({b, c});
    }
    int start, end; scanf("%d %d", &start, &end);

    int dist[1001];
    int prev[1001];
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;

    
    priority_queue<pii> pq;
    pq.push({0, start});

    while(pq.size()) {
        auto item = pq.top(); pq.pop();
        if (-item.first != dist[item.second]) continue;

        // update
        for(auto& v: edges[item.second]) {
            int curDist = dist[v.first]; // 현재거리
            int newDist = dist[item.second] + v.second; // 업데이트 되는지 보려는 거리: 거쳐가는 것
            if (newDist < curDist) {
                dist[v.first] = newDist; // update
                prev[v.first] = item.second;
                pq.push({-newDist, v.first}); // 다음 탐색 대상
            }
        }
    }

    printf("%d\n", dist[end]);

    int st[1000];
    int sp = 0;
    st[sp++] = end;
    while(st[sp-1] != start) {
        st[sp++] = prev[st[sp-1]];
    }
    printf("%d\n", sp);
    for(int i = sp - 1; i >= 0; --i) {
        printf("%d ", st[i]);
    }
    printf("\n");

    return 0;
}