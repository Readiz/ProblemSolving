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

int N, K;
void solve() {
    scanf("%d %d", &N, &K);
    int A[11] = {0, };
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        A[tmp]++;
    }
    if (K == 2) {
        if (A[2] >= 1 || A[4] >= 1 || A[6] >= 1 || A[8] >= 1 || A[10] >= 1) printf("0\n");
        else printf("1\n");
    } else if (K == 3) {
        if (A[3] >= 1 || A[6] >= 1 || A[9] >= 1) printf("0\n");
        else if (A[2] >= 1 || A[5] >= 1 || A[8] >= 1) printf("1\n");
        else printf("2\n");
    } else if (K == 4) {
        int cnt2 = 0;
        for(int i = 2; i <= 10; i += 2) cnt2 += A[i];
        int cntodd = 0;
        for(int i = 1; i <= 9; i += 2) cntodd += A[i];
        bool chkOnly159 = true;
        for(int i = 1; i <= 10; i++) {
            if (i == 1 || i == 5 || i == 9) continue;
            if (A[i] >= 1) chkOnly159 = false;
        }

        if (cnt2 >= 2 || A[4] >= 1 || A[8] >= 1) printf("0\n");
        else {
            if (cnt2 == 1 && cntodd >= 1) printf("1\n");
            else if (A[3] >= 1 || A[7] >= 1) printf("1\n");
            else if (cnt2 == 1 || cntodd >= 2) printf("2\n");
            else printf("3\n");
        }
    } else if (K == 5) {
        if (A[5] >= 1 || A[10] >= 1) printf("0\n");
        else if (A[4] >= 1 || A[9] >= 1) printf("1\n");
        else if (A[3] >= 1 || A[8] >= 1) printf("2\n");
        else if (A[2] >= 1 || A[7] >= 1) printf("3\n");
        else printf("4\n");
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}