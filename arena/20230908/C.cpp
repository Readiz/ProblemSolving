#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Boss {
    ll HP;
    ll Coin;
    bool operator<(const Boss& t) const {
        if (Coin != t.Coin) return Coin > t.Coin;
        return HP < t.HP;
    }
};
constexpr ll TIME = 900;

int main() {
    int N, M, K; scanf("%d%d%d", &N, &M, &K);
    vector<ll> C;
    for(int i = 0; i < N; ++i) {
        ll tmp; scanf("%lld", &tmp);
        C.push_back(tmp);
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    vector<Boss> B;
    for(int i = 0; i < K; ++i) {
        ll a, b; scanf("%lld%lld", &a, &b);
        B.push_back({a,b});
    }
    // sort(B.begin(), B.end());
    ll ans = 0;
    for(int i = 0; i < M; ++i) {
        ll& cur = C[i];
        // for(auto& b: B) {
        //     if (b.HP <= cur) {
        //         ans += b.Coin;
        //         break;
        //     }
        // }
        // Knapsack
        ll DP[910] = {0,}; // k 시간을 썼을 때 얻을 수 있는 코인의 최대값
        ll maxDeal = TIME * cur;
        for(auto& b: B) {
            if (maxDeal >= b.HP) {
                ll elapseTime = b.HP / cur + (b.HP % cur != 0);
                for(int t = 900; t >= elapseTime; --t) {
                    DP[t] = max(DP[t], DP[t - elapseTime] + b.Coin);
                }
            }
        }
        
        ll lmax = 0;
        for(int t = 0; t <= 900; ++t) {
            lmax = max(lmax, DP[t]);
        }
        // printf("[d] player deal: %lld, max: %lld\n", cur, lmax);
        ans += lmax;
    }
    printf("%lld\n", ans);

    return 0;
}