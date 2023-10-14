

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


void llprint(ll v) {
    if (v % 2 == 0) {
        printf("%lld.00\n", v >> 1);
    } else {
        printf("%lld.50\n", v >> 1);
    }
}

int main() {
    int N; scanf("%d", &N);    
    vector<ll> blocks(N+1);
    vector<ll> pSum(N+1);
    for(int i = 1; i <= N; ++i) scanf("%lld", &blocks[i]);
    for(int i = 1; i <= N; ++i) {
        pSum[i] = pSum[i - 1] + blocks[i];
    }
    ll overallSum = pSum[N];

    ll L;
    int Q;
    scanf("%lld %d", &L, &Q);

    if (L >= overallSum) {
        // 다 표시 가능
        for(int q = 0; q < Q; ++q) {
            int want; scanf("%d", &want);
            printf("0.00\n");
        }
    } else {
        for(int q = 0; q < Q; ++q) {
            int want; scanf("%d", &want);

            ll lpos = pSum[want] * 2 - blocks[want];
            ll rpos = overallSum * 2 - lpos;
            if (lpos - L < 0) {
                llprint(0);
            } else if (rpos - L < 0) {
                printf("%lld.00\n", overallSum - L);
            } else {
                llprint(lpos - L);
            }
        }
    }


    return 0;
}