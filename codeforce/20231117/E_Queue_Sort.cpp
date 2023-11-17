#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif
#define X first
#define Y second

int N;
void solve() {
    scanf("%d", &N);
    vector<int> v;
    int mval = 0x7FFFFFFF;
    int midx = -1;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
        if (tmp < mval) {
            midx = i;
            mval = tmp;
        }
    }

    bool flag = true;
    for(int s = midx + 1; s < N; ++s) {
        if (v[s] >= v[s - 1]) continue;
        flag = false;
        break;
    }
    if (flag == false) {
        printf("-1\n");
        return;
    }

    printf("%d\n", midx);

}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}