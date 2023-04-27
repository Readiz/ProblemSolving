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

int N;
void solve() {
    scanf("%d", &N);
    int A[50];
    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }
    map<int, char> M;
    char buf[100];
    scanf("%s", buf);
    FOR(i,0,N) {
        if (M.find(A[i]) == M.end()) {
            M[A[i]] = buf[i];
            //_D("%d -> %c\n", A[i], buf[i]);
        } else {
            if (M[A[i]] == buf[i]) continue;
            else {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
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
