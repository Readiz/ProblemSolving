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

char buf[110];
void solve() {
    scanf("%s", buf);
    for(int i = 0; buf[i] != 0; ++i) {
        printf("%c ", buf[i]);
    }
}

int main() {
    solve();

    return 0;
}