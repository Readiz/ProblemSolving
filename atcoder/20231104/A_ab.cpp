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
char buf[1000];
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    FOR(i,1,N) {
        if (buf[i] == 'a' && buf[i - 1] == 'b') {
            printf("Yes\n");
            return;
        }
        if (buf[i] == 'b' && buf[i - 1] == 'a') {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main() {
    solve();

    return 0;
}