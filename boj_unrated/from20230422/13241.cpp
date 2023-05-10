#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll GCD(ll a, ll b) {
    while (b != 0) {
        ll tmp = a;
        a = b;
        b = tmp % b;
        //printf("%lld %lld\n", a, b);
    }
    return a;
}
int main() {
    ll a; ll b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", a*b/GCD(a,b));    
    return 0;
}