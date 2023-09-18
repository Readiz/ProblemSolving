#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char buf[100'001];
void solve() {
    scanf("%s", buf);
    int l, r;
    int len = strlen(buf);
    bool isZeroCase = true;
    for(int i = 0; i < len / 2; ++i) {
        if (buf[i] == buf[len - i - 1]) continue;
        isZeroCase = false;
        l = i;
        r = len - i - 1;
        break;
    }
    if (isZeroCase) {
        printf("0\n");
        return;
    }

    // check left
    bool lCase = true;
    for(int a = 0, b = len - 1; a < b; ++a, --b) {
        if (a == l) {
            ++b;
            continue;
        }
        if (buf[a] == buf[b]) continue;
        lCase = false;
        break;
    }
    if (lCase) {
        printf("1\n");
        return;
    }
    bool rCase = true;
    for(int a = 0, b = len - 1; a < b; ++a, --b) {
        if (b == r) {
            --a;
            continue;
        }
        if (buf[a] == buf[b]) continue;
        rCase = false;
        break;
    }
    if (rCase) {
        printf("1\n");
        return;
    }
    printf("2\n");
}
int main() {
    int N; scanf("%d", &N);
    while(N--) solve();
    return 0;
}