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
char buf[200010];
void solve() {
    scanf("%d", &N);
    scanf("%s", &buf[1]);
    char last = 0;
    int cnt = 0;
    map<char, int> Map;
    for(int i = 1; i <= N + 1; ++i) {
        if (last != buf[i]) {
            if (Map.find(last) != Map.end()) {
                int old = Map[last];
                if (old < cnt) Map[last] = cnt;
            } else {
                Map[last] = cnt;
            }
            cnt = 1;
            last = buf[i];
        } else {
            ++cnt;
        }
    }
    int ans = 0;
    for(auto& i: Map) {
        ans += i.second;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}