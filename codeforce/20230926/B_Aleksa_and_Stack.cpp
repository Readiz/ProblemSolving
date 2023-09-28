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
int A[200000];
void solve() {
    scanf("%d", &N);
    A[0] = 2; A[1] = 4;
    for(int i = 2; i < N; ++i) {
        int before = A[i - 1] + A[i - 2];
        int t = A[i - 1] + 1;
        while ((t * 3) % before == 0) ++t;
        A[i] = t;
    }
    for(int i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}