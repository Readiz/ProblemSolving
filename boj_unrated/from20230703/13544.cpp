#include <bits/stdc++.h>
using namespace std;

int A[100'001];
vector<int> b[320];
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        b[i / 320].push_back(A[i]);
    }
    for(int i = 0; i < 320; ++i) {
        sort(b[i].begin(), b[i].end());
    }
    int last_ans = 0;
    scanf("%d", &N); // 쿼리 개수
    for(int q = 0; q < N; ++q) {
        int aa, bb, cc; scanf("%d %d %d", &aa, &bb, &cc);
        int i = aa ^ last_ans;
        int j = bb ^ last_ans;
        int k = cc ^ last_ans;
        last_ans = 0;

        int sb = i / 320 + 1;
        int eb = j / 320;
        if (sb > eb) {
            // 직접 계산한다.
            for(int p = i; p <= j; ++p) {
                if (A[p] > k) ++last_ans;
            }
        } else {
            for (int p = i; p < sb * 320; ++p) {
                if (A[p] > k) ++last_ans;
            }
            for(int p = sb; p < eb; ++p) {
                auto it = upper_bound(b[p].begin(), b[p].end(), k);
                last_ans += b[p].end() - it;
            }
            for (int p = eb * 320; p <= j; ++p) {
                if (A[p] > k) ++last_ans;
            }
        }
        printf("%d\n", last_ans);
    }
    return 0;
}