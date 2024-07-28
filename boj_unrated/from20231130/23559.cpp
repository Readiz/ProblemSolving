#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); ++i)

struct Heap {
    int h[100'010];
    int sz;
    Heap() { sz = 0; }
    void push(int v) {
        h[++sz] = v;
        int c = sz;
        for(; c > 1; c >>= 1) {
            int p = c >> 1;
            if (h[p] < h[c]) swap(h[p], h[c]);
            else break;
        }
    }
    int pop() {
        int ret = h[1];
        h[1] = h[sz--];
        int c = 2;
        for(; c <= sz; c <<= 1) {
            if (c + 1 <= sz && h[c + 1] > h[c]) c++;
            int p = c >> 1;
            if (h[p] < h[c]) swap(h[p], h[c]);
            else break;
        }
        return ret;
    }
} h;

int main() {
    int N, X; scanf("%d %d", &N, &X);
    X /= 1000;

    long long ans = 0;
    // 처음에는 모두 천원짜리 선택.
    FOR(i,0,N) {
        long long a, b; scanf("%lld %lld", &a, &b);
        ans += b;
        h.push(a - b);
        X -= 1;
    }
    // 남은 돈이 부족하지 않을 때까지 5천원 메뉴로 변경. 그리디임.
    while(X >= 4) {
        auto nxt = h.pop();
        if (nxt <= 0) break;
        X -= 4;
        ans += nxt;
    }
    printf("%lld\n", ans);

    return 0;
}