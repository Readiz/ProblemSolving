#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B; scanf("%d %d", &A, &B);
    set<int> S;
    for(int i = A; i <= B; ++i) {
        S.insert(i);
    }
    int K, X; scanf("%d %d", &K, &X);
    int ans = 0;
    for(auto& s: S) {
        if (abs(s - K) <= X) ++ans;
    }
    if (ans == 0) printf("IMPOSSIBLE\n");
    else printf("%d", ans);

    return 0;
}