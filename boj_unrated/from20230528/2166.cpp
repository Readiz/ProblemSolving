#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main() {
    int N; scanf("%d", &N);
    vector<pll> v;
    for (int i = 0; i < N; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back({x, y});
    }

    long long sum = 0;
    for(int i = 0; i < N; ++i) {
        int j = i + 1; j %= N;
        pll& a = v[i]; pll& b = v[j];
        sum += a.first * b.second - a.second * b.first;
    }
    if (sum < 0) sum = -sum;
    printf("%.1lf\n", (double) sum / 2);
    return 0;
}