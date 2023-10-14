

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;



int main() {
    ll a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    for(int i = 0; i < 4; ++i) {
        ll n, m; scanf("%lld %lld", &n, &m);
        a1 += n;
        b1 += m;
    }
    for(int i = 0; i < 4; ++i) {
        ll n, m; scanf("%lld %lld", &n, &m);
        a2 += n;
        b2 += m;
    }
    ll pu = b2 - b1;
    ll pd = a2 - a1;

    ll pgcd = __gcd(pu, pd);
    pu = pu / pgcd;
    pd = pd / pgcd;

    if (pu < 0 && pd < 0) {
        pu *= -1;
        pd *= -1;
    } else if ((pu > 0 && pd < 0)) {
        pu *= -1;
        pd *= -1;
    }

    ll qd = 4 * pd;
    ll qu = -a1 * pu + b1 * pd;

    ll qgcd = __gcd(qd, qu);
    qd = qd / qgcd;
    qu = qu / qgcd;

    if (qu < 0 && qd < 0) {
        qu *= -1;
        qd *= -1;
    } else if ((qu > 0 && qd < 0)) {
        qu *= -1;
        qd *= -1;
    }

    if (pd != 1 && qd != 1) {
        printf("%lld/%lld %lld/%lld\n", pu, pd, qu, qd);
    } else if (pd == 1 && qd == 1) {
        printf("%lld %lld\n", pu, qu);
    } else if (qd == 1) {
        printf("%lld/%lld %lld\n", pu, pd, qu);
    } else if (pd == 1) {
        printf("%lld %lld/%lld\n", pu, qu, qd);
    }

    return 0;
}