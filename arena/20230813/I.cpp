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

char buf[500010];
char stk[500010];
int sp;
void solve() {
    scanf("%s", buf);
    int loop = 0;
    while (loop++ < 1) {
        sp = 0;
        for(int p = 0; buf[p] != 0; ++p) {
            if (buf[p] == '(') {
                stk[sp++] = '(';
            } else if (buf[p] == ')') {
                if (sp == 0) {
                    printf("NO\n");
                    return;
                }
                if (sp && stk[sp-1] == '(') {
                    sp--;
                    continue;
                }
                if (sp && stk[sp-1] == '*') {
                    continue;
                }
                if (sp) {
                    stk[sp++] = ')';
                }
            } else if (buf[p] == '*') {
                if (sp > 0 && stk[0] == '*') {
                    sp = 1;
                    continue;
                } else {
                    int close = 0;
                    for(int i = 0; i < sp; ++i) {
                        if (stk[i] == '(') --close;
                        if (stk[i] == '?') {
                            --close;
                        }
                        if (stk[i] == ')') {
                            ++close;
                            if (close > 0) {
                                printf("NO\n");
                                return;
                            }
                        }
                    }
                }
                stk[0] = '*';
                sp = 1;
            } else if (buf[p] == '?') {
                stk[sp++] = '?';
            }
        }
        buf[sp] = 0;
        stk[sp] = 0;
        if (sp == 1 && stk[sp - 1] == '*') {
            printf("YES\n");
            return;
        }
        if (sp == 0) {
            printf("YES\n");
            return;
        }
    }
    if (stk[sp - 1] == '(') {
        printf("NO\n");
        return;
    }

    _D("%s\n", stk);

    // case 1) * 로 시작하는 case
    if (stk[0] == '*') {
        int open = 0;
        for(int i = 1; i < sp; ++i) {
            if (stk[i] == '(') open++;
            if (stk[i] == '?') {
                if (open > 0) --open;
            }
            if (stk[i] == ')') {
                if (open > 0) --open;
            }
        }
        if (open == 0) {
            printf("YES\n");
            return;
        }
        printf("NO\n");
    }
    else {
        // case 2 ) *로 시작하지 않는 case
        // ???((??????))
        // ?))((??????))
        // ?)(((????(((())
        if (sp % 2 == 1) {
            printf("NO\n");
            return;
        }
        int open = 0;
        for(int i = 0; i < sp; ++i) {
            if (stk[i] == '(') open++;
            if (stk[i] == '?') {
                if (open > 0) --open;
            }
            if (stk[i] == ')') {
                if (open > 0) --open;
            }
        }
        if (open > 0) {
            printf("NO\n");
            return;
        }

        //reverse
        open = 0;
        for(int i = sp - 1; i >= 0; --i) {
            if (stk[i] == ')') open++;
            if (stk[i] == '?') {
                if (open > 0) --open;
            }
            if (stk[i] == '(') {
                if (open > 0) --open;
            }
        }
        if (open > 0) {
            printf("NO\n");
            return;
        }

        printf("YES\n");
    }
}
int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) solve();
    return 0;
}