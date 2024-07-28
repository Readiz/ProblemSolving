#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int N, C; scanf("%d %d", &N, &C);
    for(int i = 0; i < N; ++i) {
        int t; scanf("%d", &t);
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int ans = -1;
    int l = 1, r = 1'000'000'000;

    for(int m = (l + r) >> 1; l <= r; m = (l + r) >> 1) {
        int lx = v[0];
        int cnt = 1;
        for(int i = 1; i < N; ++i) {
            if (v[i] - lx >= m) {
                lx = v[i];
                ++cnt;
            }
        }
        if (cnt >= C) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    printf("%d\n", ans);


    return 0;
}