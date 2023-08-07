#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<short,short> pss;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

char M[110][110];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};


map<pss, char> capa;
map<pss, char> flow;
vector<short> adj[10010];
short pre[10010];

void connect(short i, short j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
    capa[pss{i, j}] = 1;
}

int getResidual(short i, short j) {
    int res = 0;
    if (capa.find({i,j}) != capa.end()) {
        res += capa[pss{i,j}];
    }

    if (flow.find({i,j}) != flow.end()) {
        res -= flow[pss{i,j}];
    }

    return res;
}

void handleFlow(int i, int j) {
    if (flow.find({i,j}) != flow.end()) {
        flow[{i,j}] += 1;
    } else {
        flow[{i,j}] = 1;
    }
    if (flow.find({j,i}) != flow.end()) {
        flow[{j,i}] -= 1;
    } else {
        flow[{j,i}] = -1;
    }
}

constexpr int S = 10005;
constexpr int T = 10006;

int id(int r, int c) {
    return r * 100 + c;
}
int main() {
    int R, C; scanf("%d %d", &R, &C);
    for(int i = 1; i <= R; ++i) {
        scanf("%s", &M[i][1]);
    }
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            if (M[i][j] != 'K') continue;
            for(int k = 0; k < 4; ++k) {
                int ti = i + dr[k];
                int tj = j + dc[k];
                if (M[ti][tj] == 'H') {
                    printf("-1\n");
                    return 0;
                } else {
                    continue;
                }
            }
        }
    }
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            if (M[i][j] == '#' || M[i][j] == 0) continue;
            int cur = id(i, j);
            if (M[i][j] == 'K') cur = S;
            else if (M[i][j] == 'H') continue;
            for(int k = 0; k < 4; ++k) {
                int ti = i + dr[k];
                int tj = j + dc[k];
                if (M[ti][tj] == '#' || M[ti][tj] == 0) continue;
                int target = id(ti, tj);
                if (M[ti][tj] == 'K') continue;
                if (M[ti][tj] == 'H') target = T;
                connect(cur, target);
            }
        }
    }

    int ans = 0;

    while(true) {
        fill(pre, pre+10010, -1);
        queue<short> q;
        q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(auto& t: adj[cur]) {
                int residual = getResidual(cur, t);
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
            handleFlow(pre[p], p);
        }
        ans += 1;
    }

    printf("%d\n", ans);

    return 0;
}