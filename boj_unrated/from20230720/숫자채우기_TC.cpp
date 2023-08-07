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

void check(int N, int M) {
    vector<vector<int>> v;
    if (M == 1) {
        v.resize(N);
        // special case
        int last = 1;
        int diff = 0;
        for(int i = 0; i < N; ++i) {
            v[i].push_back(last + diff);
            last = last + diff;
            ++diff;
        }
    } else {
        v.resize(N);

        constexpr int bias = 1e6;

        v[0].resize(M);
        v[0][0] = 0;
        for(int c = 1; c < M; ++c) {
            if (c % 2 == 1) v[0][c] = abs(v[0][c-1]) + 1;
            else v[0][c] = -v[0][c-1];
        }

        for(int r = 1; r < N; ++r) {
            v[r].resize(M);
            if (v[r-1][0] <= 0) v[r][0] = v[r-1][0] + (abs(v[r-1][M-1] - v[r-1][M-2]) + 1);
            else v[r][0] = v[r-1][0] - (abs(v[r-1][M-1] - v[r-1][M-2]) + 1);
            for(int c = 1; c < M; ++c) {
                if (v[r][0] > 0) {
                    if (c % 2 == 0) v[r][c] = abs(v[r][c-1]) + 1;
                    else v[r][c] = -v[r][c-1];
                } else {
                    if (c % 2 == 1) v[r][c] = abs(v[r][c-1]) + 1;
                    else v[r][c] = -v[r][c-1];
                }
            }
        }
    }



    vector<int> vals;
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            if (c != 0) vals.push_back(abs(v[r][c] - v[r][c-1]));
            if (r != 0) {
                vals.push_back(abs(v[r][c] - v[r-1][c]));
            }
        }
    }

    sort(vals.begin(), vals.end());
    for(int i = 0; i < vals.size(); ++i) {
        if (vals[i] != i + 1) {
            printf("WRONG!!! N: %d / M: %d\n", N, M);
            return;
        }
    }
}
int main() {
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j <= 1000; ++j) {
            
            check(i, j);
        }
    }
    return 0;
}