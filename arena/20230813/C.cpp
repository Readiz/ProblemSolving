// 비트연산과 전혀 상관없었음.. 관찰부족.
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

int main() {
    int N; scanf("%d", &N);
    vector<ll> v;
    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ll cmax = *v.rbegin();

    for(auto& item: v) {
        while ((item<<1) < cmax) item <<= 1;
    }
    sort(v.begin(), v.end());

    ll gdiff = cmax - *v.begin();
    ll last = *v.begin();
    for(auto& item: v) {
        _D("%lld ", item);
        ll curdiff = abs(last * 2 - item);
        if (curdiff < gdiff) gdiff = curdiff;
        last = item;
    }
    _D("\n");

    printf("%lld\n", gdiff);
    

    return 0;
}