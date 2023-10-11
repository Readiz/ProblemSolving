#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; scanf("%d", &N);    
    int p[6] = {0,};
    for(int i = 1; i <= 5; ++i) scanf("%d", &p[i]);
    multiset<int> S[6];
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        S[a].insert(b);
    }

    int ans = 240;
    for(int i = 1; i <= 5; ++i) {
        int last = *S[i].begin();
        S[i].erase(S[i].begin());
        ans += last;
        while(--p[i]) {
            ans += *S[i].begin() - last;
            ans += *S[i].begin();
            last = *S[i].begin();
            S[i].erase(S[i].begin());
        }
    }
    printf("%d\n", ans);
    return 0;
}