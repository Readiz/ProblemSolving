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
    int x, y; scanf("%d %d", &x, &y);
    if ((y - x <= 2 && y - x >= 0) || (x - y <= 3 && x - y >= 0)) printf("Yes\n");
    else printf("No\n");
}

int main() {
    solve();

    return 0;
}