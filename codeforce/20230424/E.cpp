#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
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

int N;
char buf[200010];
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    if (N % 2 == 1) {
        printf("-1\n");
        return;
    }
    int nHalf = N >> 1;
    // 전체 카운트
    {
        int cnt[26] = {0, };
        FOR(i,0,N) {
            cnt[buf[i] - 'a']++;
        }
        FOR(i,0,26) {
            // 과반 넘는애가 나오면 안됨
            if (cnt[i] > nHalf) { // 불가능
                printf("-1\n");
                return;
            }
        }
    }
    // 본격 같은애 카운트
    int p1 = nHalf - 1;
    int p2 = nHalf;
    int cnt[26] = {0, };
    int overallCnt = 0;
    for(int i = 0; i < nHalf; ++i, --p1, ++p2) {
        if (buf[p1] == buf[p2]) {
            cnt[buf[p1] - 'a']++;
            overallCnt++;
        }
    }
    int cntHalf = overallCnt >> 1;
    FOR(i,0,26) {
        if (cnt[i] > cntHalf) {
            // 커버되는 녀석
            int canCover = overallCnt - cnt[i]; // 나머지 녀석들
            int remain = cnt[i] - canCover;
            printf("%d\n", canCover + remain);
            return;
        }
    }
    // 절반넘는애가 없으면, 해피함
    printf("%d\n", cntHalf + overallCnt % 2);
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
