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
    set<ll> S;
    for(int i = 1; i <= N; ++i) S.insert(i);
    vector<ll> A;
    A.resize(N-1);
    FOR(i,0,N-1) {
        scanf("%lld", &A[i]);
    }
    vector<ll> D;
    for(int i = 1; i < N-1; ++i) {
        ll diff = A[i] - A[i-1];
        if (S.find(diff) != S.end()) {
            S.erase(diff);
        } else {
            D.push_back(diff);
        }
    }
    if (isDebug) {
        _D("[A] ");
        for(auto& item: A) {
            _D("%lld ", item);
        }
        _D("\n");
        _D("[D] ");
        for(auto& item: D) {
            _D("%lld ", item);
        }
        _D("\n");
        _D("[S] ");
        for(auto& item: S) {
            _D("%lld ", item);
        }
        _D("\n");
    }
    // case 1.
    if (D.size() == 0 && S.size() == 2) {
        ll s1 = *S.begin();
        ll s2 = *(--S.end());
        if (s1 + s2 == A[0]) {
            printf("YES\n");
            return;
        }

        if (S.find(A[0]) != S.end()) {
            printf("YES\n");
            return;
        }
    }
    if (D.size() == 1 && S.size() == 3) {
        if (S.find(A[0]) != S.end()) {
            S.erase(A[0]);
            ll s1 = *S.begin();
            ll s2 = *(--S.end());
            if (s1 + s2 == D[0]) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
}