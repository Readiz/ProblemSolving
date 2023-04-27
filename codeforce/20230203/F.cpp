#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("F_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

#define TREE_MAX 1000000 // unreachable

struct D { // Data
    int val;
    int idx;
    bool operator<(const struct D& t) const {
        if (val != t.val) return val < t.val;
        return idx < t.idx;
    }
};

int N, M, tmp, cmd, i, j;
D T[TREE_MAX];
int TS; // Tree size

void buildST() {
    for(R int i = TS - 1; i >= 1; --i) {
        T[i] = D{0, 1};
    }
}
int update(int k) {
    if (k >= TS) {
        int r = 0;
        int v = T[k].val;
        while (v != 0) {
            r += v % 10;
            v /= 10;
        }
        T[k].val = r;
        if (r <= 9) {
            T[k].idx = 0;
            return 0;
        } else {
            return 1;
        }
    } else {
        if (T[k].idx == 0) return 0;
        T[k].idx = update(k<<1) + update(k<<1|1);
        return T[k].idx;
    }
}
void queryST(int l, int r) { // [l, r]
    l += TS; r += TS;
    while (l <= r) {
        if (l & 1) {
            update(l);
            ++l;
        }
        if (~r & 1) {
            update(r);
            --r;
        }
        l >>= 1; r >>= 1;
    }
}

void solve() {
    scanf("%d %d", &N, &M);
    TS = 1;
    while (TS < N) TS <<= 1;
    FOR(i,0,N) {
        scanf("%d", &tmp);
        if (tmp <= 9) {
            T[TS+i] = D{tmp, 0};
        } else {
            T[TS+i] = D{tmp, 1};
        }
    }
    buildST();
    FOR(m,0,M) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %d", &i, &j);
            queryST(i - 1, j - 1);
        } else {
            scanf("%d", &i);
            printf("%d\n", T[TS + i - 1].val);
        }
    }
}


MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
