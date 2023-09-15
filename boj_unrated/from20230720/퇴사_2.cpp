#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Data {
    ll T, P;
};
ll DP[1'500'001];
int main() {
    int N; scanf("%d", &N);
    vector<Data> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%lld%lld", &v[i].T, &v[i].P);

    ll mval = 0;
    for(int j = 1; j <= N; ++j) {
        DP[j] = mval;
        for(int d = 0; d <= 49; ++d) { // d일전의 일 확인
            if (j - d > 0 && v[j - d].T <= d + 1) {
                DP[j] = max(DP[j], DP[j - d - 1] + v[j - d].P);
                // printf("[%d] checking %lld...\n", j, DP[j - d - 1] + v[j - d].P);
            }
        }
        mval = max(mval, DP[j]);
    }
    printf("%lld\n", DP[N]);
    return 0;
}