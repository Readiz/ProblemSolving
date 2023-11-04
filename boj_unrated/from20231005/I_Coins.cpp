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
// double DP[3000]; // 무언가의 확률... 앞면이 N개 일 때의 확률?
// DP[0] = (1 - p_1)(1 - p_2)(1 - p_3)...(1 - p_N)
// DP[N] = p_1 * p_2 * p_3 * ... p_N
// DP[0] -> DP[1]... how?

// 동전을 한번에 다 보지 말자
double DP[3000][3000]; // 동전을 i개 봤을 때 j 개가 앞면일 확률.. 로 정의
// DP[1][0] = 1 - p_1
// DP[1][31] = p_1

// DP[2][0] = DP[1][0] * (1 - p_2)
// DP[2][1] = DP[1][1] * (1 - p_2) + DP[1][0] * p_2
// DP[2][2] = DP[1][1] * p_2

// DP[3][0] = DP[2][0] * (1 - p_3)
// DP[3][1] = DP[2][1] * (1 - p_3) + DP[2][0] * p_3
// DP[3][2] = DP[2][2] * (1 - p_3) + DP[2][1] * p_3
// DP[3][3] = DP[2][2] * p_
// ... 다 채울 수 있는듯?
double p[3000];
void solve() {
    scanf("%d", &N); // odd number (N <= 2999)
    // p_i : head / 1 - p_i : tail
    for(int i = 1; i <= N; ++i) scanf("%lf", &p[i]);
    DP[1][0] = 1.0 - p[1];
    DP[1][1] = p[1];
    for(int i = 2; i <= N; ++i) {
        for(int j = 0; j <= i; ++j) {
            if (j == 0) {
                DP[i][0] = DP[i - 1][0] * (1 - p[i]);
            } else if (j < i) {
                DP[i][j] = DP[i - 1][j] * (1 - p[i]) + DP[i - 1][j - 1] * p[i];
            } else {
                DP[i][j] = DP[i - 1][j - 1] * p[i]; 
            }
        }
    }

    double sum = 0;
    for(int i = N / 2 + 1; i <= N; ++i) {
        sum += DP[N][i];
    }
    printf("%.15lf\n", sum);
}

int main() {
    solve();
    return 0;
}