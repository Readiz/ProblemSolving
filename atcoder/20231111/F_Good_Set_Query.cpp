#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X first
#define Y second

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

ll N, Q;
ll a[200010];
ll b[200010];
ll d[200010];
ll x[200010];

#define INF 0x7FFFFFFFFFFFFFFFLL
void solve() {
    scanf("%lld %lld", &N, &Q);
    for(int i = 1; i <= Q; ++i) {
        scanf("%lld %lld %lld", &a[i], &b[i], &d[i]);
    }

    for(int i = 1; i <= N; ++i) {
        x[i] = INF;
    }

    set<int> ans;
    for(int q = 1; q <= Q; ++q) {
        ll ca = a[q], cb = b[q], cd = d[q];

        if (ca == cb && cd == 0) {
            ans.insert(q);
        } else if (ca != cb) {
            if (x[ca] == INF && x[cb] == INF) {
                x[ca] = cd;
                x[cb] = 0;
                ans.insert(q);
            } else if (x[ca] == INF) {
                x[ca] = x[cb] + cd;
                ans.insert(q);
            } else if (x[cb] == INF) {
                x[cb] = x[ca] - cd;
                ans.insert(q);
            } else if (x[ca] - x[cb] == cd) {
                ans.insert(q);
            }
        }
    }

    for(int i = 1; i <= N; ++i) {
        if (x[i] != INF) {
            _D("[%d] %lld\n", i, x[i]);
        } else {
            _D("[%d] - \n", i);
        }
    }
    

    for(auto& i: ans) {
        printf("%d ", i);
    }
}

int main() {
    // int TC; scanf("%d", &TC);
    // while(TC--)
    solve();
    return 0;
}