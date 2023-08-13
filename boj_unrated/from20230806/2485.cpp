#include <bits/stdc++.h>
using namespace std;

// [참고] Iterative function to return gcd of a and b
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}
int main() {
    int N; scanf("%d", &N);
    vector<int> pos;
    pos.resize(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &pos[i]);
    }
    sort(pos.begin(), pos.end());

    vector<int> diff;
    for(int i = 1; i < N; ++i) {
        diff.push_back(pos[i] - pos[i-1]);
    }

    int lgcd = diff[0];
    for(int i = 1; i < diff.size(); ++i) {
        lgcd = __gcd(lgcd, diff[i]);
    }

    int ans = 0;

    for(int i = 0; i < diff.size(); ++i) {
        int res = diff[i] / lgcd;
        ans += res - 1;
    }

    printf("%d\n", ans);
    return 0;
}