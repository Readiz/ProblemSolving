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

int N, K;
char buf[200010];
void solve() {
    scanf("%d %d", &N, &K);
    scanf("%s", buf);
    int cnt[30] = {0, };
    for(int i = 0; i < N; ++i) {
        cnt[buf[i] - 'a']++;
    }
    N -= K;

    _D("ori K: %d\n", K);
    // 1. odd 제거
    for(int i = 0; i < 26 && K > 0; ++i) {
        if (cnt[i] % 2 == 1) --cnt[i], --K;
    }
    // 2. even에서 감소
    for(int i = 0; i < 26 && K > 0; ++i) {
        if (cnt[i] % 2 == 0) {
            if (cnt[i] < K) K -=cnt[i], cnt[i] = 0;
        }
    }
    int oddcnt = 0;
    for(int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 == 1) oddcnt++;
    }
    _D("K: %d / ODD: %d\n", K, oddcnt);
    
    if (N % 2 == 1 && oddcnt == 1) printf("YES\n");
    else if (oddcnt == 0) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}