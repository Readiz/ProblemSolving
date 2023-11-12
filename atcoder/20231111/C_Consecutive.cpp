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

int N, Q;
char buf[300010];
int p[300010];
void solve() {
    scanf("%d %d", &N, &Q);
    scanf("%s", &buf[1]);
    for(int i = 1; i <= N; ++i) {
        p[i] += p[i - 1];
        if(buf[i] == buf[i - 1]) p[i]++;
    }

    for(int q = 0; q < Q; ++q) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", p[r] - p[l]);
    }
}

int main() {
    // int TC; scanf("%d", &TC);
    // while(TC--)
    solve();
    return 0;
}