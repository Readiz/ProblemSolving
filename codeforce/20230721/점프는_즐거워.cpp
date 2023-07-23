#include <bits/stdc++.h>
using namespace std;

int N;

void solve() {
    vector<int> v;
    v.resize(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }
    if (N == 1) {
        printf("Jolly\n");
        return;
    }

    vector<int> diff;
    vector<int> compare;
    for(int i = 1; i < N; ++i) {
        diff.push_back(abs(v[i] - v[i-1]));
        compare.push_back(i);
    }
    sort(diff.begin(), diff.end());

    for(int i = 0; i < N; ++i) {
        if (diff[i] == compare[i]) continue;
        printf("Not jolly\n");
        return;
    }
    printf("Jolly\n");
}
int main() {
    while(scanf("%d", &N) != EOF) {
        solve();
    }

    return 0;
}

