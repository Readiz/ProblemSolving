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
    int R, C; scanf("%d %d", &R, &C);
    set<char> cols[100];
    FOR(i,0,R) {
        char buf[100]; scanf("%s", buf);
        FOR(i,0,C) {
            cols[i].insert(buf[i]);
        }
    }
    bool chkV = false; bool chkI = false; bool chkK = false; bool chkA = false;
    for(int i = 0; i < C; ++i) {
        if (chkV == false) {
            if (cols[i].find('v') != cols[i].end()) {
                chkV = true;
                continue;
            }
        } else {
            if (chkI == false) {
                if (cols[i].find('i') != cols[i].end()) {
                    chkI = true;
                    continue;
                }
            } else {
                if (chkK == false) {
                    if (cols[i].find('k') != cols[i].end()) {
                        chkK = true;
                        continue;
                    }
                } else {
                    if (chkA == false) {
                        if (cols[i].find('a') != cols[i].end()) {
                            chkA = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (chkA) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}