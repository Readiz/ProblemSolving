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
    vector<pair<int,int>> v(N);
    for(auto& i:v) scanf("%d %d", &i.X, &i.Y);
    sort(v.begin(), v.end(), [&](auto& a, auto& b) {
        return a.Y < b.Y;
    });

    int ctime = v[N - 1].Y - v[N - 1].X;
    for(int i = N - 2; i >= 0; --i) {
        ctime = min(ctime - v[i].X, v[i].Y - v[i].X);
    }
    printf("%d\n", ctime);
}

int main() {
    solve();
    return 0;
}