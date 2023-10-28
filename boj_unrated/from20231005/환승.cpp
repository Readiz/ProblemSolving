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

struct QData {
    int v;
    int dist;
};

int N, M, K;
vector<int> adjrow[100'001]; // 봐야 하는 row
vector<int> row[1000];
QData q[400'000]; int qf, qr;
char visited[100'001];
void solve() {
    scanf("%d %d %d", &N, &M, &K);
    FOR(r,0,K) {
        FOR(i,0,M) {
            int tmp; scanf("%d", &tmp);
            row[r].push_back(tmp);
            adjrow[tmp].push_back(r);
        }
    }
    // for(int i = 1; i <= 100'000; ++i) {
    //     if (adj[i].size() != 0) {
    //         _D("#%d -> ", i);
    //         for(auto& item: adj[i]) {
    //             _D("%d ", item);
    //         }
    //         _D("\n");
    //     }
    // }
    q[qr++] = {1, 1};
    visited[1] = 1;
    while (qf != qr) {
        auto& cur = q[qf++];
        if (cur.v == N) {
            printf("%d\n", cur.dist);
            return;
        }
        for(auto& ridx: adjrow[cur.v]) {
            for(auto& next: row[ridx]) {
                if (visited[next]) continue;
                visited[next] = 1;
                q[qr++] = {next, cur.dist + 1};
            }
        }
    }
    printf("-1\n");
}

int main() {
    solve();

    return 0;
}