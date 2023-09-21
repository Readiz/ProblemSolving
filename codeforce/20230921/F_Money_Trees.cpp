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
    scanf("%d%d", &N, &K);
    vector<int> A(N), H(N);
    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }
    FOR(i,0,N) {
        scanf("%d", &H[i]);
    }
    if (N == 1) {
        if (A[0] <= K) printf("1\n");
        else printf("0\n");
        return;
    }

    int curSum, lastH;
    int l;
    int curLen = 0;
    for(int i = 0; i < N; ++i) {
        if (A[i] <= K) {
            lastH = H[i];
            curSum = A[i];
            l = i;
            curLen = 1;
            break;
        }
    }
    int maxLen = curLen;
    for(int r = l + 1; r < N; ++r) {
        if (lastH % H[r] == 0) {
            // printf("[d] %d mod %d == 0\n", lastH, H[r]);
            int newSum = curSum + A[r];
            curLen++;
            lastH = H[r];
            curSum += A[r];
            while(curSum > K) {
                curSum -= A[l++];
                curLen -= 1;
            }
            if (curLen > maxLen) maxLen = curLen;
        } else {
            // l 새시작
            for(int i = r; i < N; ++i) {
                if (A[i] <= K) {
                    lastH = H[i];
                    curSum = A[i];
                    l = i;
                    curLen = 1;
                    r = l;
                    break;
                }
            }
        }
    }

    printf("%d\n", maxLen);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}