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

int main() {
    int N, M; scanf("%d %d", &N, &M);

    if (M == 1) {
        // special case
        int last = 1;
        int diff = 0;
        for(int i = 0; i < N; ++i) {
            printf("%d\n", last + diff);
            last = last + diff;
            ++diff;
        }
        return 0;
    }

    vector<vector<int>> v;
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

    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            printf("%d ", v[r][c] + bias);
        }
        printf("\n");
    }

    return 0;
}