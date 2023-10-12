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
void solve(set<int>& primes) {
    scanf("%d", &N);
    map<int, int> M;
    for(int i = 0; i < N; ++i) {
        int k; scanf("%d", &k);
        for(int i = 2; i <= k; ++i) {
            if (primes.find(k) != primes.end()) {
                // _D("%d is prime!!! add and break!\n", k);
                if (M.find(k) == M.end()) M[k] = 0;
                M[k]++;
                break;
            }
            if (k % i == 0) {
                if (M.find(i) == M.end()) M[i] = 0;
                M[i]++;
                k /= i;
                --i;
            }
        }
    }
    bool ans = true;
    for(auto it = M.begin(); it != M.end(); ++it) {
        auto cur = *it;
        if (cur.second % N != 0) {
            ans = false;
            break;
        }
        // _D("%d: CNT %d\n", cur.first, cur.second);
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}

bool isPrime(int N) {
    for(int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    set<int> primes;
    for(int i = 2; i <= 1000000; ++i) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve(primes);
    }

    return 0;
}