#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X first
#define Y second

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

int N, S;

void solve() {
    scanf("%d %d", &N, &S);
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        int tmp; scanf("%d", &tmp);
        if (tmp <= S) ans += tmp;
    }
    
    printf("%d\n", ans);
}

int main() {
    // int TC; scanf("%d", &TC);
    // while(TC--)
    solve();
    return 0;
}