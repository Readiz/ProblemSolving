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
    int cnt[5] = {0, };
    FOR(i,0,5) {
        int tmp; scanf("%d", &tmp);
        cnt[tmp]++;
    }
    printf("%d\n", cnt[N]);
}

int main() {
    solve();
    return 0;
}