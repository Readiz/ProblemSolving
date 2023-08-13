#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<pair<int,int>> v;

    int N; scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        v.push_back({a,b});
    }

    if (N == 1) {
        printf("1\n"); return 0;
    }

    sort(v.begin(), v.end());
    int ans = 1;
    for(int i = 1; i < N; ++i) {
        if (v[i-1].second + v[i-1].first >= v[i].first) continue;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}