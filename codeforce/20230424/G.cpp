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
    map<ll,ll> cnt;
    for(int i = 0; i < N; ++i) {
        if (prev != A[i]) {
            cnt[A[i]] = 1;
            B[P++] = A[i];
        } else {
            cnt[A[i]]++;
        }
        prev = A[i];
    }

    ll ans = 0;
    // M = 10^9
    // -> 3번 곱하는 것을 보므로 1000까지 돌면 됨
    // 중앙의 값인 A_j를 살펴보자....
    for(int j = 0; j < P; ++j) {
        ll s = B[j];
        ll cs = cnt[s];
        if (s <= 1'000'000) {
            for(ll b = 2; b * b <= s; ++b) {
                if (s % b != 0) continue;
                ll i = s / b;
                ll k = s * b;
                _D("Checking %d, %d, %d...\n", i, s, k);
                if (cnt.find(i) != cnt.end() && cnt.find(k) != cnt.end()) {
                    ans += cnt[i] * cnt[k] * cs;
                }
                if (b * b != s) {
                    ll b = i;
                    i = s / b;
                    k = s * b;
                    _D("Checking %d, %d, %d...\n", i, s, k);
                    if (cnt.find(i) != cnt.end() && cnt.find(k) != cnt.end()) {
                        ans += cnt[i] * cnt[k] * cs;
                    }
                }
            }
            if (s != 1) {
                ll i = 1;
                ll k = s * s;
                _D("Checking %d, %d, %d...\n", i, s, k);
                if (cnt.find(i) != cnt.end() && cnt.find(k) != cnt.end()) {
                    ans += cnt[i] * cnt[k] * cs;
                }
            }
        } else {
            for(ll b = 2; b <= 1000; ++b) {
                if (s * b > 1'000'000'000) break;
                if (s % b != 0) continue;
                ll i = s / b;
                ll k = s * b;
                if (cnt.find(i) != cnt.end() && cnt.find(k) != cnt.end()) {
                    ans += cnt[i] * cnt[k] * cs;
                }
            }
        }
        if (cs >= 3) {
            // 하나는 뽑혔고, 나머지 두개를 뽑는 case
            ans += cs * (cs - 1) * (cs - 2);
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
