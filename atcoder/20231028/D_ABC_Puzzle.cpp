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
int R[5] = {0, };
int C[5] = {0, };
int usedR[5][4] = {0,};
int usedC[5][4] = {0,};
int M[5][5] = {0, };
int cntR[5][4] = {0, };
int cntC[5][4] = {0, };

// 가지치기 dfs
bool dfs1(int r, int c, int k) {
    if (r == N - 1 && c == N - 1) {
        // 조건 체크
        bool ret = true;

        for(int i = 0; i < N; ++i) {
            for(int k = 1; k < 4; ++k) {
                if (cntR[i][k] != 1) return false;
                if (cntC[i][k] != 1) return false;
            }
        }

        // row 체크
        for(int i = 0; i < N; ++i) {
            bool ok = false;
            for(int j = 0; j < N; ++j) {
                if (M[i][j] == 0) continue;
                if (M[i][j] == R[i]) {
                    ok = true;
                    break;
                } else {
                    return false;
                }
            }
        }
        // col 체크
        for(int i = 0; i < N; ++i) {
            bool ok = false;
            for(int j = 0; j < N; ++j) {
                if (M[j][i] == 0) continue;
                if (M[j][i] == C[i]) {
                    ok = true;
                    break;
                } else {
                    return false;
                }
            }
        }

        // 종료
        if (1) {
            printf("Yes\n");
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if (M[i][j] == 0) printf(".");
                    else printf("%c", M[i][j] + 'A' - 1);
                }
                printf("\n");
            }
            return true;
        }
        return false;
    }

    if (c < N - 1) {
        for(int k = 0; k < 4; ++k) {
            if (k == 0 || (usedC[c+1][k] != 1 && usedR[r][k] != 1)) {
                if (k != 0 && cntR[r][k] == 1) continue;
                if (k != 0 && cntC[c + 1][k] == 1) continue;
                usedR[r][k] = 1;
                usedC[c + 1][k] = 1;
                M[r][c + 1] = k;
                cntR[r][k]++;
                cntC[c + 1][k]++;
                bool ret = dfs1(r, c + 1, k);
                if (ret) return true;
                cntR[r][k]--;
                cntC[c + 1][k]--;
                usedR[r][k] = 0;
                usedC[c + 1][k] = 0;
            }
        }
    } else {
        for(int k = 1; k < 4; ++k) {
            if (cntR[r][k] != 1) return false;
        }
        for(int k = 0; k < 4; ++k) {
            if (k == 0 || (usedC[0][k] != 1 && usedR[r + 1][k] != 1)) {
                if (k != 0 && cntR[r + 1][k] == 1) continue;
                if (k != 0 && cntC[0][k] == 1) continue;
                usedC[0][k] = 1;
                usedR[r + 1][k] = 1;
                M[r + 1][0] = k;
                cntR[r+1][k]++;
                cntC[0][k]++;
                bool ret = dfs1(r + 1, 0, k);
                if (ret) return true;
                cntR[r+1][k]--;
                cntC[0][k]--;
                usedC[0][k] = 0;
                usedR[r + 1][k] = 0;
            }
        }
    }
    return false;
}

void solve() {
    scanf("%d", &N);
    char buf[10]; scanf("%s", buf);
    for(int i = 0; i < N; ++i) R[i] = buf[i] - 'A' + 1;
    scanf("%s", buf);
    for(int i = 0; i < N; ++i) C[i] = buf[i] - 'A' + 1;
    
    for(int k = 0; k < 4; ++k) {
        if (k == 0 || usedR[0][k] != 1) {
            if (k != 0 && cntR[0][k] == 1) continue;
            if (k != 0 && cntC[0][k] == 1) continue;
            usedR[0][k] = 1;
            usedC[0][k] = 1;
            M[0][0] = k;
            cntR[0][k]++;
            cntC[0][k]++;
            int ret = dfs1(0, 0, k);
            if (ret) return;
            cntR[0][k]--;
            cntC[0][k]--;
            usedR[0][k] = 0;
            usedC[0][k] = 0;
        }
    }
    printf("No\n");
}

int main() {
    solve();
    return 0;
}