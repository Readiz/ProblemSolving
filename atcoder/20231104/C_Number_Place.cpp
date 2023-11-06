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
int M[10][10];
void solve() {
    for(int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &M[i][j]);
        }
    }

    for(int i = 0; i < 9; ++i) {
        int checker[10] = {0, };
        for (int j = 0; j < 9; ++j) {
            checker[M[i][j]]++;
        }
        for(int j = 1; j <= 9; ++j) {
            if (checker[j] != 1) {
                _D("HORIZONTAL / i: %d %d = %d\n", i, j, checker[j]);
                printf("No\n");
                return;
            }
        }
    }

    for(int i = 0; i < 9; ++i) {
        int checker[10] = {0, };
        for (int j = 0; j < 9; ++j) {
            checker[M[j][i]]++;
        }
        for(int j = 1; j <= 9; ++j) {
            if (checker[j] != 1) {
                _D("VERTICAL\n");
                printf("No\n");
                return;
            }
        }
    }
    int checker[3][3][10] = {0, };
    for(int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            checker[i / 3][j / 3][M[i][j]]++;
        }
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 1; k <= 9; ++k) {
                if (checker[i][j][k] != 1) {
                    _D("SUDOKU\n");
                    printf("No\n");
                    return;
                }
            }
        }
    }
    printf("Yes\n");
}

int main() {
    solve();

    return 0;
}