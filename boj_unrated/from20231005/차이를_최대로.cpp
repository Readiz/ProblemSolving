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

int N;
int gmax;
void dfs(int depth, vector<int> _cur, vector<int> _remain) {
    if (depth == N) {
        int cval = 0;
        for(int i = 1; i < N; ++i) {
            cval += abs(_cur[i] - _cur[i - 1]);
        }
        if (cval > gmax) gmax = cval;
        return;
    }
    for(int i = 0; i < _remain.size(); ++i) {
        vector<int> cur = _cur;
        vector<int> remain = _remain;
        cur.push_back(remain[i]);
        remain.erase(remain.begin() + i);
        dfs(depth + 1, cur, remain);
    }
}

void solve() {
    scanf("%d", &N);
    gmax = -(0x3A3A3A3A);
    vector<int> v(N);
    for(auto& i: v) scanf("%d", &i);
    for(int i = 0; i < N; ++i) {
        vector<int> cur;
        vector<int> remain = v;
        cur.push_back(remain[i]);
        remain.erase(remain.begin() + i);
        dfs(1, cur, remain);
    }
    printf("%d\n", gmax);
}

int main() {
    solve();
    return 0;
}