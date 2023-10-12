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

int N;
char board[1001][1001];
char rot[1001][1001];
char rot2[1001][1001];
char rot3[1001][1001];
void solve() {
    // memset(rot, 0, 1001 * 1001);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", board[i]);
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            rot[i][j] = board[N - j - 1][i];
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            rot2[i][j] = rot[N - j - 1][i];
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            rot3[i][j] = rot2[N - j - 1][i];
        }
    }
    // for(int i = 0; i < N; ++i) {
    //     printf("%s\n", rot[i]);
    // }
    
    int ans = 0;
    for(int i = 0; i < N / 2; ++i) {
        for(int j = 0; j < N / 2; ++j) {
            char MAX = max(max(board[i][j], rot[i][j]), max(rot2[i][j], rot3[i][j]));
            ans += MAX - board[i][j] + MAX - rot[i][j] + MAX - rot2[i][j] + MAX - rot3[i][j];
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}