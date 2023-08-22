// 발상을 알면 풀이는 쉽다. 이분탐색 + 라빈카프를 활용한다.
#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)
typedef long long ll;
typedef unsigned long long ull;

char buf[200'001];

constexpr int HLEN = 10'000'007;
char cnt[4][HLEN];
int p[4] = {11, 37, 5381, 10007};
bool rk(int f, int len) {
    _D("rabinkarp: %d / %d\n", f, len);
    memset(cnt, 0, 4 * HLEN * sizeof(char));
    ll ival[4] = {0, };
    ll unit[4] = {1, 1, 1, 1};
    for(int k = 0; k < 4; ++k) {
        for(int i = 0; i < f; ++i) {
            ival[k] = ival[k] * p[k] + buf[i];
            ival[k] %= HLEN;

            unit[k] *= p[k];
            unit[k] %= HLEN;
        }
        cnt[k][ival[k]]++;
        _D("unit %d: %lld\n", k, unit[k]);
    }
    for(int i = f; i < len; ++i) {
        char cur = buf[i];
        char last = buf[i - f];
        int ansCnt = 0;
        for(int k = 0; k < 4; ++k) {
            ival[k] = ival[k] * p[k] + cur;
            ival[k] -= unit[k] * last;
            while (ival[k] < 0) ival[k] += HLEN;
            ival[k] %= HLEN;

            // _D("[%d] ival: %d\n", k, ival[k]);
            cnt[k][ival[k]]++;
            if (cnt[k][ival[k]] >= 2) ansCnt++;
        }
        _D("ansCnt: %d at %d\n", ansCnt, i);
        if (ansCnt >= 4) return true;
    }
    return false;
}

int main() {
    int N; scanf("%d", &N);
    scanf("%s", buf);

    int l = 1; int r = N;
    int ans = 0;
    for(int m = (l+r)>>1; l <= r; m=(l+r)>>1) {
        if (rk(m, N)) {
            l = m + 1; // 찾았으니 길이를 늘려본다.
            ans = m;
        } else {
            r = m - 1; // 못찾았으니 길이를 줄인다.
        }
    }
    printf("%d\n", ans);   

    return 0;
}