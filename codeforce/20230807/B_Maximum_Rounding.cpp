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

char buf[200010];
int val[200010];
void solve() {
    fill(val, val+200010, 0);

    scanf("%s", buf);
    int l = strlen(buf);
    int p = 0;
    for(int i = l - 1; i >= 0; --i) {
        val[p++] = buf[i] - '0';
    }
    int lastp = -1;
    for(int i = 0; i < l; ++i) {
        if (val[i] >= 10) {
            val[i] -= 10;
            val[i + 1]++;
        }
        if (val[i] >= 5) {
            val[i+1]++;
            lastp = i;
        }
    }
    bool isFirst = true;
    for(int i = l; i >= 0; --i) {
        if (isFirst && val[i] == 0) continue;
        isFirst = false;
        if (i <= lastp) printf("0");
        else printf("%d", val[i]);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}