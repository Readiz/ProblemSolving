#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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

int N;
void solve() {
    scanf("%d", &N);
    map<ll, int> cnt;
    vector<ll> A;
    FOR(i,0,N) {
        ll tmp; scanf("%lld", &tmp);
        if (cnt.find(tmp) == cnt.end()) {
            cnt[tmp] = 1;
        } else {
            cnt[tmp]++;
        }
        if (tmp < 0) tmp = -tmp;
        A.push_back(tmp);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    scanf("%d", &N);
    FOR(i,0,N) {
        ll x, y; scanf("%lld %lld", &x, &y);
        // logic start
        // x = a + b / y = ab
        ll ans = 0;
        if (y > 0) {
            for(auto& a: A) {
                if (a * a > y) break;
                if (y % a == 0) {
                    ll b = y / a;
                    if (a == b) {
                        if (a + b == x) {
                            if (cnt.find(a) != cnt.end()) {
                                ans += cnt[a] * (cnt[a] - 1) / 2;
                            } 
                        } else if (a + b == -x) {
                            if (cnt.find(-a) != cnt.end()) {
                                ans += cnt[-a] * (cnt[-a] - 1) / 2;
                            }
                        }
                    } else if (a + b == x) {
                        if (cnt.find(a) != cnt.end() && cnt.find(b) != cnt.end()) {
                            ans += cnt[a] * cnt[b];
                        }
                    } else if (a + b == -x) {
                        if (cnt.find(-a) != cnt.end() && cnt.find(-b) != cnt.end()) {
                            ans += cnt[-a] * cnt[-b];
                        }
                    }
                }
            }
        } else if (y == 0) {
            // 0은 오지 않음
        } else {
            y = -y; // 양수로 변환
            for(auto& a: A) {
                if (a * a > y) break;
                if (y % a == 0) {
                    ll b = y / a;
                    if (a - b == x) {
                        if (cnt.find(a) != cnt.end() && cnt.find(-b) != cnt.end()) {
                            ans += cnt[a] * cnt[-b];
                        }
                    } else if (b - a == x) {
                        if (cnt.find(-a) != cnt.end() && cnt.find(b) != cnt.end()) {
                            ans += cnt[-a] * cnt[b];
                        }
                    }
                }
            }
        }
        printf("%lld ", ans);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}