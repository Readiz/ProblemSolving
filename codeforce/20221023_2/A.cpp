#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("A_input.txt", "rt", stdin); }
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


int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int N;
int A[20];

int gcdAll() {
    int r = gcd(A[0], A[1]);
    FOR(i,2,N) {
        r = gcd(r, A[i]);
    }
    return r;
}
vector<int> testIdx;
int ccost;
int minCost;
void dfs(int dep) {
    if (dep == testIdx.size()) {
        if (gcdAll() == 1) {
            if (ccost < minCost) {
                minCost = ccost;
            }
        }
        return;
    }
    int ori = A[testIdx[dep]];
    A[testIdx[dep]] = gcd(A[testIdx[dep]], testIdx[dep]+1);
    ccost += N - testIdx[dep];
    dfs(dep+1);
    ccost -= N - testIdx[dep];
    A[testIdx[dep]] = ori;
    dfs(dep+1);
}

void solve() {
    testIdx.clear();
    ccost = 0;
    minCost = 0x7FFFFFFF;
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }
    if (N == 1) {
        if (A[0] == 1) {
            printf("0\n");
            return;
        } else {
            printf("1\n");
            return;
        }
    }
    int r = gcdAll();
    if (r == 1) {
        printf("0\n");
        return;
    }
    FOR(i,0,N) {
        if (A[i] % r == 0) {
            testIdx.push_back(i);
        }
    }
    dfs(0);
    printf("%d\n", minCost);
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
