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

struct STACK {
    int v[1000000];
    int sz;
    void push(int k) {
        v[sz++] = k;
    }
    int pop() {
        if (sz == 0) return -1;
        return v[--sz];
    }
    int top() {
        if (sz == 0) return -1;
        return v[sz-1];
    }
} S;

int N;
void solve() {
    scanf("%d", &N);
    FOR(i,0,N) {
        int cmd; scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
        int v; scanf("%d", &v);
        S.push(v);
        break;
        case 2:
        printf("%d\n", S.pop());
        break;
        case 3:
        printf("%d\n", S.sz);
        break;
        case 4:
        printf("%d\n", S.sz == 0);
        break;
        case 5:
        printf("%d\n", S.top());
        break;
        }
    }
}

int main() {
    solve();
    return 0;
}