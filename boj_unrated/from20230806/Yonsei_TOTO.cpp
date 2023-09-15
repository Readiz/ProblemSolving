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


int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> promising;
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        int p, l;
        scanf("%d%d", &p, &l);
        vector<int> t;
        for(int i = 0; i < p; ++i) {
            int tmp; scanf("%d", &tmp); t.push_back(tmp);
        }
        if (p < l) {
            if (M > 0) {
                ++ans;
                M--;
            }
        } else {
            sort(t.begin(), t.end());
            reverse(t.begin(), t.end());
            promising.push_back(t[l - 1]);
        }
    }
    sort(promising.begin(), promising.end());
    for(auto& item: promising) {
        if(item <= M) {
            M -= item;
            ++ans;
            // printf("[d] %d\n", item);
        } else {
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}