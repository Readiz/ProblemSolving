#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

int A[100'001];
int b[200][512];
int bs[200];
int main() {
    int N, aa, bb, cc, i, j, k, l, r, m, ans;
    scanf("%d", &N);
    for(register int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        b[i >> 9][bs[i >> 9]++] = A[i];
    }
    for(register int i = 0; i < 200; ++i) {
        sort(b[i], b[i] + 512);
    }
    int last_ans = 0;
    scanf("%d", &N); // 쿼리 개수
    for(register int q = 0; q < N; ++q) {
        scanf("%d %d %d", &aa, &bb, &cc);
        i = aa ^ last_ans;
        j = bb ^ last_ans;
        k = cc ^ last_ans;
        last_ans = 0;

        int sb = (i >> 9) + 1;
        int eb = (j >> 9);
        if (sb > eb) {
            // 직접 계산한다.
            for(register int p = i; p <= j; ++p) {
                if (A[p] > k) ++last_ans;
            }
        } else {
            for(register int p = i; p < (sb << 9); ++p) {
                if (A[p] > k) ++last_ans;
            }
            for(register int p = sb; p < eb; ++p) {
                // auto it = upper_bound(b[p].begin(), b[p].end(), k);
                // last_ans += b[p].end() - it;
                l = 0; r = 512; ans = 512;
                for(m = 256; l <= r; m = (l+r) >> 1) {
                    if (b[p][m] > k) {
                        ans = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                last_ans += 512 - ans;
            }
            for(register int p = (eb << 9); p <= j; ++p) {
                if (A[p] > k) ++last_ans;
            }
        }
        printf("%d\n", last_ans);
    }
    return 0;
}