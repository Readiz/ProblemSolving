#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, M; scanf("%d %d", &N, &M);
    vector<ll> v(N);
    int x, y;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d %lld", &x, &y, &v[i]);
    }
    sort(v.begin(), v.end());
    int g = __gcd(abs(x), abs(y));
    x = x / g;
    y = y / g;
    ll base = 0;
    for(int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g = __gcd(abs(a), abs(b));
        a = a / g;
        b = b / g;
        if (a == x && b == y) {
            base += c;
        }
        auto it = upper_bound(v.begin(), v.end(), base);
        int cnt = v.end() - it;
        printf("%d\n", cnt);
    }

    return 0;
}