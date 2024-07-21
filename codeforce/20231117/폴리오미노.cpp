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
char buf[60];
void solve() {
    scanf("%s", buf);
    int len = strlen(buf);
    int p = 0;
    for(; p < len;) {
        if (buf[p] == 'X' && buf[p + 1] == 'X' && buf[p + 2] == 'X' && buf[p + 3] == 'X') {
            buf[p++] = 'A';
            buf[p++] = 'A';
            buf[p++] = 'A';
            buf[p++] = 'A';
        } else if (buf[p] == 'X' && buf[p + 1] == 'X') {
            buf[p++] = 'B';
            buf[p++] = 'B';
        } else if (buf[p] == '.') {
            ++p;
        } else {
            printf("-1\n");
            return;
        }
    }
    printf("%s\n", buf);
}

int main() {
    solve();

    return 0;
}