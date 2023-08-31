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

void solve() {
    int N; scanf("%d", &N);
    printf("%d\n", (int)sqrt(N));
    // N = 24;
    // vector<int> v;
    // v.resize(N+1);
    // FOR(i,1,N+1) {
    //     for(int j=i;j<=N;j+=i){ 
    //         v[j] = 1 - v[j];
    //     }
    // }
    // int cnt = 0;
    // for(int i = 1; i <= N; ++i) {
    //     if (v[i] == 1) ++cnt;
    // }
    // printf("[%d] %d\n", N, cnt);
}

int main() {
    solve();

    return 0;
}