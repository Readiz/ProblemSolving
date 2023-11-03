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

int N;
vector<pair<ll, ll>> v;
void solve() {
    scanf("%d", &N);
    FOR(i,0,N) {
        ll a, b; scanf("%lld %lld", &a, &b);
        b += a;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    multiset<pair<ll,ll>> pq;
    pq.insert({v[0].second, v[0].first});
    ll ans = 0;
    ll last = 0;
    for(int i = 1; i < v.size(); ++i) {
        auto it = pq.begin(); // 현재 할 수 있는 것중에 가장 촉박한 것을 수행
        auto cur = *it; pq.erase(it);
    _D("%lld, %lld..\n", cur.first, cur.second);
        if (cur.second > last) {
            last = cur.second + 1;
            ++ans;
        } else {
            if (cur.first > last) {
                last++;
                ++ans;
            }
        }
        pq.insert({v[i].second, v[i].first});
    }
    auto it = pq.begin(); // 현재 할 수 있는 것중에 가장 촉박한 것을 수행
    auto cur = *it; pq.erase(it);
    _D("%lld, %lld..\n", cur.first, cur.second);
    if (cur.second >= last) {
        last = cur.second + 1;
        ++ans;
    } else {
        if (cur.first > last) {
            last++;
            ++ans;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();

    return 0;
}