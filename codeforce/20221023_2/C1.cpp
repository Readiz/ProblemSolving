#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
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

typedef long long ll;
#define TREE_MAX 1000000 // unreachable

int N, Q, x, y, a;
ll b;
ll T[TREE_MAX];
ll T2[TREE_MAX];

void buildST() {
    for(R int i = N - 1; i >= 1; --i) {
        T[i] = T[i << 1] + T[(i << 1) | 1];
        T2[i] = T2[i << 1] ^ T2[(i << 1) | 1];
    }
}
ll queryST(int l, int r) { // [l, r]
    l += N; r += N;
    ll res1 = 0;
    ll res2 = 0;
    while (l <= r) {
        if (l & 1) {
            res1 += T[l]; // 우측 leaf일때 갱신
            res2 ^= T2[l++];
        }
        if (~r & 1) {
            res1 += T[r]; // 좌측 leaf일때 갱신
            res2 ^= T2[r--];
        }
        l >>= 1; r >>= 1;
    }
    // _D("%d - %d = %d\n", res1, res2, res1 - res2);
    return res1 - res2;
}

void solve() {
    scanf("%d %d", &N, &Q);
    FOR(i,0,N) {
        int t;
        scanf("%d", &t);
        T[i+N] = t;
        T2[i+N] = t;
    }
    buildST();
    FOR(q,0,Q) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l; --r;
        ll max = queryST(l, r);
        ll maxl = l, maxr = r;
        // _D("cur max: %d (%d ~ %d)\n", max, l, r);
        FOR(ml, l, r+1) {
            FOR(mr, ml, r+1) {
                ll v = queryST(ml, mr);
                // _D("cur range: %d ~ %d -> %lld\n", ml, mr, v);
                if (v > max) {
                    max = v;
                    maxl = ml;
                    maxr = mr;
                    // _D("updated!\n");
                } else if (v == max) {
                    if (mr - ml < maxr - maxl) {
                        maxl = ml;
                        maxr = mr;
                        // _D("updated!\n");
                        if (mr == ml) {
                            printf("%lld %lld\n", maxl+1, maxr+1);
                            return;
                        }
                    }
                }
            }
        }
        printf("%lld %lld\n", maxl + 1, maxr + 1);
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
