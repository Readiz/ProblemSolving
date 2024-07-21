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
#define X first
#define Y second

int N;
bool check(int v) {
    int a = v / 100;
    int b = v / 10 % 10;
    int c = v % 10;
    if (a * b == c) return true;
    return false;
}

void solve() {
    scanf("%d", &N);
    int i = N;
    for(; i < 1000; ++i) {
        if (check(i)) break;
    }
    printf("%d\n", i);

}

int main() {
    solve();
    return 0;
}