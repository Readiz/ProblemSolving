#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
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
char buf[400001];
void solve() {
    char t;
    scanf("%d %c %s", &N, &t, buf);
    if (t == 'g') {
        printf("0\n");
        return;
    }
    string s = buf;
    s += buf; // * 2;
    _D("%s\n", s.c_str());
    int pi = -1;
    int max = 0;
    for(int i = 0; i < s.size(); ++i) {
        if (pi == -1 && s[i] == t) {
            pi = i;
            continue;
        }
        if (pi != -1 && s[i] == 'g') {
            if (max < i - pi) {
                max = i - pi;
            }
            pi = -1;
        }
    }
    printf("%d\n", max);
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
