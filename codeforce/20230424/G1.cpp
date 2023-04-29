#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("G_input.txt", "rt", stdin); }
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
ll A[200010];
ll B[200010];
void solve() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%lld", &A[i]);
    }
    sort(A, A+N);
    ll prev = -1;
    int P = 0;
    unordered_map<ll,int> cnt;
    for(int i = 0; i < N; ++i) {
        if (prev != A[i]) {
            B[P++] = A[i];
            cnt[A[i]] = 1;
        } else {
            cnt[A[i]]++;
        }
        prev = A[i];
    }
    ll ans = 0;
    for(register int i = 0; i < P; ++i) {
        for(register int j = i + 1; j < P; ++j) {
            if (B[j] % B[i] == 0) { // 나누어 떨어지는 것을 발견
                int b = B[j] / B[i];
                // _D("Checking... %d, %d -> %d\n", B[j], B[i], B[j]*b);
                if (cnt.find(B[j] * b) != cnt.end()) { // 있음
                    ans += cnt[B[i]] * cnt[B[j]] * cnt[B[j] * b];
                    _D("Found! %d %d %d\n", B[i], B[j], b * B[j]);
                }
            }
        }
        // 3개인지 체크 (예외 케이스)
        ll CNT = cnt[B[i]];
        if (CNT >= 3) {
            // k_P_3
            //_D("Dup Found! %d\n", B[i]);
            ans += CNT * (CNT - 1) * (CNT - 2);
        }
    }
    printf("%lld\n", ans);
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