#include <bits/stdc++.h>
using namespace std;

#if ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

#define rint register int
typedef long long ll;
int N;

ll A[100'010];

void solve() {
    for (rint i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    A[0] = A[N+1] = 0;
    stack<int> idx;
    idx.push(0);

    ll maxArea = 0;
    for(rint i = 1; i <= N + 1; ++i) { // N + 1, 마지막 fake 원소로 끝내기 위함
        _D("checking A[%d] = %d\n", i, A[i]);
        while(idx.size() && A[idx.top()] > A[i]) {
            int c = idx.top(); idx.pop(); // 더 작으면 pop한다.
            ll w = i - idx.top() - 1; // c - i가 아님에 유의! **자기보다 더 작은 애가 있는 곳까지..
            ll h = A[c];
            ll area = w * h;
            _D("area: %lld\n", area);
            if (area > maxArea) maxArea = area;
        }
        idx.push(i); // 신규 원소 push
    }

    printf("%lld\n", maxArea);
}

int main() {
    while(1) {
        scanf("%d", &N);
        if (N == 0) break;
        solve();
    }
    return 0;
}