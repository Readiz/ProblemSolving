#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

int main() {
    long long tmp; scanf("%lld", &tmp);
    ll N = tmp;
    ll l = 0, r = 0x7FFFFFFFFFFFFFFF;
    ll ans = 0;
    for(ll m = l + ((r - l) >> 1); l <= r;  m = l + ((r - l) >> 1)) {
        ll cur = m * m;
        if (cur >= N) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    long long pans = ans;
    printf("%lld\n", pans);

    return 0;
}