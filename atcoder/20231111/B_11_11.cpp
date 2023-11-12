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

int N;

void solve() {
    scanf("%d", &N);
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        int tmp; scanf("%d", &tmp);
        _D("%d: %d---\n", i, tmp);
        if (i < 10) {
            int ii = i < 10 ? i * 10 + i : 999;
            if (tmp >= ii) {
                _D("%d: 2\n", i);
                ans += 2;
            } else if (tmp >= i) {
                _D("%d: 1\n", i);
                ans += 1;
            }
        } else if ((i <= 99 && i >= 10 && i / 10 == i % 10)) {
            int k = i / 10;
            int ii = k * 10 + k;
            if (tmp >= ii) {
                _D("%d: 2\n", i);
                ans += 2;
            } else if (tmp >= k) {
                _D("%d: 1\n", i);
                ans += 1;
            }
        }
    }   
    printf("%d", ans);
}

int main() {
    // int TC; scanf("%d", &TC);
    // while(TC--)
    solve();
    return 0;
}