#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Data {
    ll W, V, T;
};

int main() {
    int N, K; scanf("%d %d", &N, &K);
    vector<Data> v;
    for(int i = 0; i < N; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        v.push_back({a, b, c});
    }

    if (N > 21) return 0;
    int end = 1 << N;
    ll ans = 0x7FFFFFFFFFFF;
    vector<int> ansVec;
    for(int cur = 0; cur < end; ++cur) {
        if (__builtin_popcount(cur) != K) continue;

        ll m = 0x7FFFFFFF;
        ll M = 0;
        ll S = 0;
        vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            int pos = 1 << i;
            if (cur & pos) {
                S += v[i].W;
                M = max(M, v[i].V);
                m = min(m, v[i].T);
                tmp.push_back(i + 1);
            }
        }
        if (ans > S + M + m) {
            ans = S + M + m;
            ansVec = tmp;
        }
    }
    printf("%lld\n", ans);
    for(auto& i: ansVec) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}