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
    int K = N * (N - 1) / 2;
    vector<ll> B;
    FOR(i,0,K) {
        ll tmp; scanf("%lld", &tmp);
        B.push_back(tmp);
    }
    sort(B.begin(), B.end());
    int len = N;
    vector<ll> A;
    for(int p = 0; p < B.size(); p += len) {
        A.push_back(B[p]);
        len--;
    }
    A.push_back(B[B.size() - 1]);
    for(auto& item: A) {
        printf("%lld ", item);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}