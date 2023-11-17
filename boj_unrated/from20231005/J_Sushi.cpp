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
int a, b, c;
double dp[310][310][310];

double get(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) return 0;
    if (i < 0 || j < 0 || k < 0) return 0;
    if (dp[i][j][k] != 0) return dp[i][j][k];
    double& ret = dp[i][j][k];

    // printf("%d %d %d...\n", i, j, k);

    ret += get(i - 1, j, k) * i;
    ret += get(i + 1, j - 1, k) * j;
    ret += get(i, j + 1, k - 1) * k;
    ret += N;

    ret /= i + j + k;

    return ret;
}

void solve() {
    scanf("%d", &N);
    int cnt[4] = {0,};
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        cnt[tmp]++;
    }
    a = cnt[1];
    b = cnt[2];
    c = cnt[3];
    // dp 식으로 계산하자.
    // dp[i][j][k] = dp[i][j][k] * (N - i - j - k) / N // 자기 스스로 전이
    //             + dp[i - 1][j][k] * i / N
    //             + dp[i + 1][j - 1][k] * j / N
    //             + dp[i][j + 1][k - 1] * k / N
    //             + 1
    // dp[i][j][k] * (i + j + k) / N = ~~

    printf("%.15lf\n", get(a, b, c));
}

int main() {
    solve();
    return 0;
}