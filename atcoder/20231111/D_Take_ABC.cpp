#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X first
#define Y second

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) // printf(__VA_ARGS__)
#endif

int N;
char buf[200010];
int l[200010];
int r[200010];
void solve() {
    scanf("%s", &buf[1]);
    N = strlen(&buf[1]);
    for(int i = 1; i <= N; ++i) {
        r[i] = i + 1;
        l[i + 1] = i;
    }
    r[0] = 1;
    l[0] = 0;
    r[N + 1] = N + 1;
    l[N + 1] = N;

    int p = 1;
    while(true) {
        _D("p: %d\n", p);
        if (buf[p] == 'A') {
            int pp = r[p];
            int ppp = r[pp];
            if (buf[pp] == 'B' && buf[ppp] == 'C') {
                r[l[p]] = r[ppp];
                l[r[ppp]] = l[p];

                _D("pos %d, %d, %d deleted.\n", p, pp, ppp);
                p = l[l[p]]; // 지웠으니 돌아가서 확인
            } else {
                p = r[p];
            }
        } else {
            p = r[p];
        }
        if (p == N + 1) break;
    }

    p = r[0];
    while(true) {
        if (p == N + 1) break;
        printf("%c", buf[p]);
        p = r[p];
    }
}

int main() {
    // int TC; scanf("%d", &TC);
    // while(TC--)
    solve();
    return 0;
}