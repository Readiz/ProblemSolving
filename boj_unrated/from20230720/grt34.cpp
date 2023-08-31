#include <bits/stdc++.h>
using namespace std;

int N, M, K;
set<int> edges[2001];
int visited[2001];
int last, cnt;
void go(int k) {
    if (visited[k]) return;
    visited[k] = 1;
    last = k;
    ++cnt;

    for(auto& t: edges[k]) {
        if (visited[t] == 0) {
            go(t);
            return;
        }
    }
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d%d", &a,&b);
        edges[a].insert(b);
        edges[b].insert(a);
    }
    go(K);
    printf("%d %d", cnt, last);
    return 0;
}