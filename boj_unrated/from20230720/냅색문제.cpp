// MITM 기본 문제

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, C; scanf("%d%d", &N, &C);

    vector<int> w(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &w[i]);
    }

    int ans = 0;
    if (N <= 15) {
        // 그냥 센다
        int maxloop = 1 << N;
        for(int cur = 0; cur < maxloop; ++cur) {
            ll overallWeight = 0;
            for(int i = 0, mask = 1; i < N; ++i, mask <<= 1) {
                if (cur & mask) {
                    overallWeight += w[i];
                }
            }
            if (overallWeight <= C) {
                ++ans;
            }
        }
        
    } else {
        vector<int> forward;
        int fmaxloop = 1 << 15;
        for(int cur = 0; cur < fmaxloop; ++cur) {
            ll overallWeight = 0;
            for(int i = 0, mask = 1; i < N; ++i, mask <<= 1) {
                if (cur & mask) {
                    overallWeight += w[i];
                }
            }
            if (overallWeight <= C) {
                forward.push_back(overallWeight);
            }
        }
        // forward에 15개에 대한 가능한 모든 조합이 들어있다.
        sort(forward.begin(), forward.end());
        // printf("[d] forward size: %d\n", (int)forward.size());

        int bmaxloop = 1 << (N-15);
        for(int cur = 0; cur < bmaxloop; ++cur) {
            ll overallWeight = 0;
            for(int i = 0, mask = 1; i < (N-15); ++i, mask <<= 1) {
                if (cur & mask) {
                    overallWeight += w[i+15];
                }
            }
            if (overallWeight <= C) {
                int remained = C - overallWeight;
                auto it = upper_bound(forward.begin(), forward.end(), remained);
                ans += it - forward.begin();
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}