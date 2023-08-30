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

int A,B,X,Y;
void solve() {
    scanf("%d%d%d%d", &X,&Y,&A,&B);
    while (A != B && A < 100000 && B < 100000) {
        if (A + X <= B + Y) A += X;
        else B += Y;
    }
    if (A == B) printf("%d\n", A);
    else printf("-1\n");
}

int main() {
    solve();

    return 0;
}