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
void solve() {
    scanf("%d", &N);
    vector<int> v;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ll anger = 0;
    FOR(i,0,N) {
        anger += abs(v[i] - i - 1);
    }
    printf("%lld\n", anger);
}

int main() {
    solve();
    return 0;
}