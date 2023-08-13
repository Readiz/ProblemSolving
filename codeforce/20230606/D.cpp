#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int N;
ll calc(vector<ll>& v, vector<ll>& pSum, int l, int r) {
    ll lSum = 0, mSum = 0, rSum = 0;
    // 왼쪽
    int lmedian = (l - 1) >> 1;
    ll lmedianVal = ((l - 1) % 2 == 0) ? v[lmedian] : ((v[lmedian] + v[lmedian + 1]) >> 1);
    // overallDiff += pSum[l - 1] - lrange * v[lmedian];
    lSum += (lmedian + 1) * lmedianVal - pSum[lmedian];
    lSum += (pSum[l - 1] - pSum[lmedian]) - (l - lmedian - 1) * lmedianVal;

    // 중간
    int mmedian = (r - 1 + l) >> 1;
    ll mmedianVal = ((r - 1 + l) % 2 == 0) ? v[mmedian] : ((v[mmedian] + v[mmedian + 1]) >> 1);
    // overallDiff += pSum[r - 1] - pSum[l - 1] - mrange * v[mmedian];
    mSum += (mmedian - l + 1) * mmedianVal - (pSum[mmedian] - pSum[l - 1]);
    mSum += (pSum[r - 1] - pSum[mmedian]) - (r - mmedian - 1) * mmedianVal;

    // 오른쪽
    int rmedian = (N - 1 + r) >> 1;
    ll rmedianVal = ((N - 1 + r) % 2 == 0) ? v[rmedian] : ((v[rmedian] + v[rmedian + 1]) >> 1);
    // overallDiff += pSum[N - 1] - pSum[r - 1] - rrange * v[rmedian];
    rSum += (rmedian - r + 1) * rmedianVal - (pSum[rmedian] - pSum[r - 1]);
    rSum += (pSum[N - 1] - pSum[rmedian]) - (N - rmedian - 1) * rmedianVal;

    _D("MEDIANS: %lld, %lld, %lld\n", lmedianVal, mmedianVal, rmedianVal);
    _D("%lld + %lld + %lld = %lld\n", lSum, mSum, rSum, lSum + mSum + rSum);
    return lSum + mSum + rSum;
}
void solve() {
    scanf("%d", &N);
    _D("N: %d-------\n", N);
    vector<ll> v;
    FOR(i,0,N) {
        ll tmp; scanf("%lld", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    vector<ll> pSum;
    ll curSum = 0;
    FOR(i,0,N) {
        curSum += v[i];
        pSum.push_back(curSum);
    }
    if (N <= 3) {
        printf("0\n");
        return;
    }

    // ll l = 1;
    // ll r = N - 1;
    // // 투 포인터
    // // 좌측: [0, l)
    // // 중간: [l, r)
    // // 우측: [r, N)
    // while (l < r) {
    //     _D("L: %d / R: %d\n", l, r);
    //     int prevl = l, prevr = r;
    //     ll cur = calc(v, pSum, l, r);
    //     // 1. left를 조정해본다
    //     ++l;
    //     if (l < r) {
    //         ll ladj = calc(v, pSum, l, r);
    //         if (ladj <= cur) {
    //             // 바람직
    //         } else {
    //             --l; // 왼쪽 변경 취소
    //             _D("L - REVERT!\n");
    //         }
    //     } else {
    //         --l;
    //     }

    //     // 2. right를 조정해본다.
    //     --r;
    //     if (l < r) {
    //         ll radj = calc(v, pSum, l, r);
    //         if (radj <= cur) {
    //             // 바람직
    //         } else {
    //             ++r;
    //             _D("R - REVERT!\n");
    //         }
    //     } else {
    //         ++r;
    //     }

    //     // 1, 2 개선 없으면 break
    //     if (l == prevl && r == prevr) break;
    // }
    ll min = 0xFFFFFFFFFFFF;
    int minL, minR;
    for(int l = 1; l < N - 1; ++l) {
        for(int r = l + 1; r < N; ++r) {
            ll cur = calc(v, pSum, l, r);
            if (cur < min) {
                min = cur;
                minL = l, minR = r;
            }
        }
    }
    ll cur = calc(v, pSum, minL, minR);
    printf("%lld\n", cur);
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
