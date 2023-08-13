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

long long N;

int main() {
    scanf("%lld", &N);
    ll A = N * (N + 1) / 2;
    ll B = A * A;
    printf("%lld\n", A);
    printf("%lld\n", B);
    printf("%lld\n", B);

    return 0;
}