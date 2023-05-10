#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)<(b)); ++i)
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

struct P {
    int l, r, c, idx;
    bool operator<(const struct P& t) const {
        if (l != t.l) return l < t.l;
        return r < t.r;
    }
};

int N;
int ANS[200000];
void solve() {
    vector<P> v;
    scanf("%d", &N);
    FOR(i,0,N) {
        ANS[i] = 0x7FFFFFFF;
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(P{a, b, c, i});
    }
    sort(v.begin(), v.end());
    FOR(i,0,N) {
        P& cp = v[i];
        FOR(j,i+1,N) {
            P& tp = v[j];
            // 색이 다르면 -> 연산 대상임
            if (cp.c != tp.c) {
                // 거리 계산 후 ANS 배열에 넣기
                if (cp.r >= tp.l) {
                    ANS[cp.idx] = 0;
                    ANS[tp.idx] = 0;
                } else {
                    int newVal = tp.l - cp.r;
                    if (newVal < ANS[cp.idx]) ANS[cp.idx] = newVal;
                    if (newVal < ANS[tp.idx]) ANS[tp.idx] = newVal;
                }
            }
        }
    }
    FOR(i,0,N) {
        printf("%d ", ANS[i]);
    }
    printf("\n");
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
