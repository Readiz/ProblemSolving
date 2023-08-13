#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll pow3[21] = {1, };

// Bitset 활용
set<int> all;

int checkpow(int t) {
    if (t < 0) t = -t;
    int checker = 1;
    int used = 0;
    while(t > 0) {
        if (t % 3 == 2) {
            t += 1;
            used |= checker;
        } else if (t % 3 == 1) {
            t -= 1;
            used |= checker;
        }
        checker <<= 1;
        t /= 3;
    }
    return used;
}

void solve() {
    int x, y; scanf("%d %d", &x, &y);
    int a = checkpow(x);
    int b = checkpow(y);
    if (all.find(a|b) != all.end() && (a & b) == 0) printf("yes\n");
    else printf("no\n");
}
int main() {
    int v = 0;
    for(int i = 0; i < 32; ++i) {
        all.insert(v);
        v <<= 1;
        v |= 1;
    }
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        printf("#%d ", tc);
        solve();
    }

    return 0;
}