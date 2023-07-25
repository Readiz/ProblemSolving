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

int N, M, K, H;
int A[60];
void solve() {
    scanf("%d %d %d %d", &N, &M, &K, &H);
    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }
    sort(A, A+N);
    int maxdiff = (M - 1) * K;
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        int diff = abs(A[i] - H);
        if (maxdiff >= diff) {
            int remain = maxdiff - diff;
            if (diff > 0 && remain % K == 0) {
                // _D("[D] %d / %d / %d\n", A[i], diff, maxdiff);
                ans++;
            }
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
}