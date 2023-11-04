#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
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

struct Node {
    int depth;
    int inCnt;
    vector<int> edges;
} n[100010];

int dfs(int i) {
    if (n[i].edges.size() == 0) {
        // leaf
        return 0;
    }
    if (n[i].depth != 0) return n[i].depth;

    for(auto& t: n[i].edges) {
        int res = dfs(t);
        n[i].depth = max(n[i].depth, res + 1);
    }
    return n[i].depth;
}

void solve() {
    scanf("%d %d", &N, &M);
    // Simple Back and Forth
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        n[a].edges.push_back(b);
        ++n[b].inCnt; // 특정 정점으로 들어가는 간선 수 (indegree)
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        if (n[i].inCnt == 0) {
            ans = max(ans, dfs(i));
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
=======
typedef long long ll;
typedef unsigned long long ull;

int N, M;

vector<int> gph[100010];
vector<int> igph[100010];
int in[100010];
int out[100010];
int visited[100010];

struct Result {
    int idx;
    int depth;
    bool operator<(const Result& t) const {
        if (depth != t.depth) return depth < t.depth;
        return idx < t.idx;
    }
};

struct Fenwick {
    int data[100010]; // depth saver

    int get(int idx) { // summation
        int ret = 0;
        for(; idx > 0; idx -= idx & -idx) {
            ret += data[idx];
        }
        return ret;
    }
    int getIdx(int idx) {
        return get(idx) - get(idx - 1);
    }
    int update(int idx, int diff) {
        for(; idx <= N; idx += idx & -idx) {
            data[idx] += diff;
        }
    }
} f;

Result dfs1(int idx, int depth) {
    if (gph[idx].size() == 0) {
        // leaf
        return {idx, depth};
    }
    // cycle 없다 했음
    if (depth != 0 && visited[idx] >= depth) return {idx, visited[idx]}; // 이미 더 최적인 경로가 있어서 할 필요 없음
    Result maxRes = {0, 0};
    visited[idx] = depth;
    for(auto& t: gph[idx]) {
        auto cur = dfs1(t, depth + 1);
        if (maxRes < cur) maxRes = cur;
    }
    return maxRes;
}

Result dfs2(int idx, int depth) {
    if (igph[idx].size() == 0) {
        // leaf
        return {idx, depth};
    }
    // cycle 없다 했음
    Result maxRes = {0, 0};
    for(auto& t: igph[idx]) { // 거꾸로 간다.
        auto cur = dfs2(t, depth + 1);
        if (maxRes < cur) maxRes = cur;
    }
    return maxRes;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        gph[a].push_back(b);
        igph[b].push_back(a);
        in[b]++;
        out[a]++;
    }

    Result maxDepth = {0, 0};
    for(int i = 1; i <= N; ++i) {
        if (in[i] == 0 && visited[i] == 0) {

            auto res = dfs1(i, 0);
            if (maxDepth < res) maxDepth = res;
        }
    }

    auto result = dfs2(maxDepth.idx, 0);
    printf("%d\n", result.depth);

>>>>>>> 94f4284ccefbdb47fb7af991885c547f5cde555f
    return 0;
}