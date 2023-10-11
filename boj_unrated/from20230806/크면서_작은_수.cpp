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

void check(int k, int cnt[]) {
    while(k > 0) {
        cnt[k % 10]++;
        k /= 10;
    }
}

int main() {
    int N; scanf("%d", &N);
    int cnta[10] = {0, };
    check(N, cnta);
    for(int i = N + 1; i < 1000000; ++i) {
        int cntb[10] = {0, };
        check(i, cntb);
        bool isSame = true;
        for(int k = 0; k < 10; ++k) {
            if (cnta[k] == cntb[k]) continue;
            isSame = false; break;
        }
        if (isSame) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");

    return 0;
}