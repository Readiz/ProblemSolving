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

int N;
char str[] = "WelcomeToSMUPC";
void solve() {
    scanf("%d", &N);
    printf("%c", str[(N-1)%14]);
}

int main() {
    solve();
    return 0;
}