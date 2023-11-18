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

vector<bitset<200001>> bs(20000);
vector<int> s[200010];
stack<int> deleted;
int bsCnt;

int newBs() {
    if (deleted.size() == 0) {
        if (bsCnt >= 20000) assert("MEM OVERFLOW!");
        return bsCnt++;
    }
    int ret = deleted.top(); deleted.pop();
    return ret;
}
int N, Q;
void solve() {
    scanf("%d %d", &N, &Q);
    FOR(i,1,N+1) {
        int c; scanf("%d", &c);
        s[i].push_back(c);
    }

    for(int q = 0; q < Q; ++q) {
        int a, b; scanf("%d %d", &a, &b);
        if (s[a].size() == 0 && s[b].size() == 0) {
            printf("0\n");
            continue;
        } else if (s[a].size() == 0) {
            if (s[b][0] == -1) {
                printf("%d\n", bs[s[b][1]].count());
            } else {
                printf("%d\n", s[b].size());
            }
            continue;
        } else if (s[b].size() == 0) {
            if (s[a][0] == -1) {
                s[b].push_back(-1);
                s[b].push_back(s[a][1]);
                s[a].clear();
                printf("%d\n", bs[s[b][1]].count());
            } else {
                s[b] = s[a];
                s[a].clear();
                printf("%d\n", s[b].size());
            }
            continue;
        }

        if (s[a][0] == -1 && s[b][0] == -1) {
            bs[s[b][1]] |= bs[s[a][1]];
            bs[s[a][1]].reset();
            deleted.push(s[a][1]);
            s[a].clear();
        } else if (s[a][0] == -1) {
            for(auto& i: s[b]) {
                bs[s[a][1]].set(i);
            }
            s[b].clear();
            s[b].push_back(-1);
            s[b].push_back(s[a][1]);
            s[a].clear();
        } else if (s[b][0] == -1) {
            for(auto& i: s[a]) {
                bs[s[b][1]].set(i);
            }
            s[a].clear();
        } else {
            for(auto& i: s[a]) {
                s[b].push_back(i);
            }
            sort(s[b].begin(), s[b].end());
            s[b].erase(unique(s[b].begin(), s[b].end()), s[b].end());
            s[a].clear();

            if (s[b].size() > 4000) {
                int idx = newBs();
                for(auto& i: s[b]) {
                    bs[idx].set(i);
                }
                s[b].clear();
                s[b].push_back(-1);
                s[b].push_back(idx);
            }
        }
        if (s[b][0] == -1) {
            printf("%d\n", bs[s[b][1]].count());
        } else {
            printf("%d\n", s[b].size());
        }
    }
    // _D("bitset used: %d\n", bsCnt);
}

int main() {
    solve();
    return 0;
}