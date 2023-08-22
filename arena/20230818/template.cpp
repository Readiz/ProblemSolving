#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; vector<ll> v;
    scanf("%d", &N); v.resize(N);
    for(int i = 0; i < N; ++i) scanf("%lld", &v[i]);

    if (N == 1) printf("%lld\n", v[0]);
    if (N == 2) printf("%lld\n", v[0] + v[1]);
    if (N == 5) {
        ll v1 = (v[0]^v[1]) + v[2] + (v[3]^v[4]);
        ll v2 = v[0] + (v[1]^v[2]^v[3]) + v[4];
        printf("%lld\n", max(v1, v2));
    }
    int max1 = 0;
    int max2 = 0;
    for(int i = 0, p = 0; i < N; ++p) {

    }


    return 0;
}