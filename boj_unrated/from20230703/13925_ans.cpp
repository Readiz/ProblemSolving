#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A[100001];

int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int cmd; scanf("%d", &cmd);
        int x, y, v;
        if (cmd != 4) {
            scanf("%d %d %d", &x, &y, &v);
            // printf("%d ~ %d +*= %d\n", x, y, v);
            for(int i = x; i <= y; ++i) {
                if (cmd == 1) {
                    A[i] += v;
                    A[i] %= 1000000007;
                } else if (cmd == 2) {
                    A[i] *= v;
                    A[i] %= 1000000007;
                } else {
                    A[i] = v;
                }
            }
        } else {
            scanf("%d %d", &x, &y);
            ll s = 0;
            for(int i = x; i <= y; ++i) {
                s += A[i];
            }
            s %= 1000000007;
            if (s == 872757449) printf("X: %d / Y: %d / ", x, y);
            printf("%lld\n", s); 
        }
        
    }

    return 0;
}