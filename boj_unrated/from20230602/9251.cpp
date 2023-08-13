#include <bits/stdc++.h>
using namespace std;

int DP[1001][1001];
char a[1001], b[1001];

int main() {
    scanf("%s %s", &a[1], &b[1]);
    int alen = 1, blen = 1;
    for(; a[alen] != 0; ++alen);
    for(; b[blen] != 0; ++blen);

    int maxval = 0;
    for(int ap = 1; ap < alen; ++ap) {
        for(int bp = 1; bp < blen; ++bp) {
            if (a[ap] == b[bp]) {
                DP[ap][bp] = DP[ap-1][bp-1] + 1;
                if (DP[ap][bp] > maxval) maxval = DP[ap][bp];
            } else {
                DP[ap][bp] = max(DP[ap-1][bp], DP[ap][bp-1]);
            }
        }
    }
    printf("%d\n", maxval);
    return 0;
}