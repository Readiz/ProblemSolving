#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

vector<int> primes;
vector<vector<int>> factors;

int N;
int visited[200001];
int visitedCnt;
void solve() {
    scanf("%d", &N);
    int M[200001] = {0, };
    int one = 0;
    FOR(i,0,N) {
        int a; scanf("%d", &a);
        if (a == 1) one++;
        else if (a <= N) {
            M[a]++;
        }
    }
    int maxx = 0;
    if (N == 1 && one == 1) maxx = 1;

    for(int i = N; i >= 2; --i) {
        vector<int> f = factors[i];

        int cases = 1 << f.size();
        int cans = one;
        ++visitedCnt;
        for(int c = 0; c < cases; ++c) {
            int cv = 1;
            for(int k = 0; k < f.size(); ++k) {
                if ((1<<k) & c) {
                    cv *= f[k];
                }
            }
            if (M[cv] && visited[cv] != visitedCnt) {
                cans += M[cv];
                _D("added %d... (cv: %d)\n", M[cv], cv);
            }
            visited[cv] = visitedCnt;
        }
        if (cans > maxx) {
            _D("cans: %d / N: %d\n", cans, i);
            maxx = cans;
        }
    }
    printf("%d\n", maxx);
}

int MAX = 200000;
int main() {
    vector<int> sp(MAX + 1, 0);
    for(int i = 2; i <= MAX; ++i) {
        if (sp[i] == 0) primes.push_back(i);
        for(auto& j: primes) {
            if (i * j > MAX) break;
            sp[i * j] = j;
            if (i % j == 0) break; // 이미 체로 걸러졌으므로 더이상 보지 않음
        }
    }

    factors.resize(200001);
    for(int i = 200000; i >= 2; --i) {
        int v = i;
        while(sp[v] != v) {
            if (sp[v] == 0) {
                factors[i].push_back(v);
                break;
            } else {
                factors[i].push_back(sp[v]);
                v /= sp[v];
            }
        }
    }

    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}