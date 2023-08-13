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

void solve() {
    int N; scanf("%d", &N);
    char op1[2], op2[2];
    int a, b;
    int cur[7] = {0, 1, };
    for(int n = 0; n < N; ++n) {
        scanf("%s %d %s %d", op1, &a, op2, &b);
        int newCur[7] = {0, };
        if (op1[0] == '+') {
            for(int i = 0; i < 7; ++i) {
                newCur[(i + a) % 7] += cur[i];
            }
        } else {
            for(int i = 0; i < 7; ++i) {
                newCur[(i * a) % 7] += cur[i];
            }
        }
        if (op2[0] == '+') {
            for(int i = 0; i < 7; ++i) {
                newCur[(i + b) % 7] += cur[i];
            }
        } else {
            for(int i = 0; i < 7; ++i) {
                newCur[(i * b) % 7] += cur[i];
            }
        }
        for(int i = 0; i < 7; ++i) {
            if (newCur[i] > 0) {
                cur[i] = 1;
            } else {
                cur[i] = 0;
            }
        }
    }
    if (cur[0] == 0) {
        printf("UNLUCKY\n");
    } else {
        printf("LUCKY\n");
    }
}
int main() {
    int TC; scanf("%d", &TC);
    while(TC--) {
        solve();
    }
    return 0;
}