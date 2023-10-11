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
    vector<int> v(N);
    FOR(i,0,N) {
        scanf("%d", &v[i]);
    }
    vector<int> res;
    res.push_back(v[0]);
    for(int i = 1; i < N; ++i) {
        if (v[i] < v[i-1]) res.push_back(1);
        res.push_back(v[i]);
    }
    printf("%d\n", res.size());
    for(auto& i: res) {
        printf("%d ", i);
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