#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

void solve() {
    int l, r;
    scanf("%d%d", &l, &r);
    int d = r - l;
    if (d >= 2) {
        int a = 2;
        int b = (l+1) >> 1 << 1;
        if (a + b >= l && a + b <= r) {
            printf("2 %d\n", b);
        } else {
            a = l+r>>2;
            b = l+r>>2;
            if (a == 1 && b == 1) {
                printf("-1\n");
            } else if (a+b >= l && a + b <= r) {
                printf("%d %d\n", a, b);
            } else {
                printf("-1\n");
                _D("EXCEPTION!!!\n");
            }
        }
    } else {
        if (l % 2 == 0) {
            int a = l >> 1;
            int b = l >> 1;
            if (a == 1 && b == 1) {
                printf("-1\n");
            } else if (a+b >= l && a + b <= r) {
                printf("%d %d\n", a, b);
            } else {
                printf("-1\n");
                _D("EXCEPTION!!!\n");
            }
        } else if (r % 2 == 0) {
            int a = r >> 1;
            int b = r >> 1;
            if (a == 1 && b == 1) {
                printf("-1\n");
            } else if (a+b >= l && a + b <= r) {
                printf("%d %d\n", a, b);
            } else {
                printf("-1\n");
                _D("EXCEPTION!!!\n");
            }
        } else {
            // _D("checking... %d / %d\n", l, r);
            for(int i = 2; i * i <= l; ++i) {
                if (l % i == 0) {
                    int a = i;
                    int b = l - a;
                    if (__gcd(a, b) != 1) {
                        printf("%d %d\n", a, b);
                        return;
                    }
                }
            }
            printf("-1\n");
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}