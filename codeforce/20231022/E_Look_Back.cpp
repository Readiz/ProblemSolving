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

struct BigInt {
    ll ori;
    ll len;
    ll base;

    BigInt(ll v) {
        ori = v;
        base = len = 0;
        
        while(v > 0) v >>= 1, len++;
    }

    ll adjust(BigInt t) {
        ll ans = 0;
        ll diff = t.len + t.base - len - base;
        if (diff > 0) base += diff, ans += diff;
        
        // 길이 맞췄음
        BigInt tmp = *this;

        ll mval = min(tmp.base, t.base);
        tmp.base -= mval; t.base -= mval;
        tmp.ori <<= tmp.base;
        t.ori <<= t.base;
        if(tmp.ori < t.ori) ++base, ++ans;

        return ans;
    }

    bool operator<(BigInt t) {
        if (len + base < t.len + t.base) return true;
        else if (len + base > t.len + t.base) return false;
        BigInt tmp = *this;

        ll mval = min(tmp.base, t.base);
        tmp.base -= mval; t.base -= mval;
        tmp.ori <<= tmp.base;
        t.ori <<= t.base;
        return tmp.ori < t.ori;
    }
};

int N;
void solve() {
    scanf("%d", &N);
    ll tmp; scanf("%lld\n", &tmp);
    BigInt last(tmp);
    ll ans = 0;
    FOR(i,1,N) {
        ll tmp; scanf("%lld\n", &tmp);
        BigInt cur(tmp);
        if (cur < last) ans += cur.adjust(last);
        
        last = cur;
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}