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
char buf[100];
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    char last = 'm';
    FOR(i,0,N) {
        if (last == 'm') {
            if (buf[i] == 'm' || buf[i] == 'M') continue;
            if (buf[i] == 'e' || buf[i] == 'E') {
                last = 'e';
            } else {
                printf("NO\n");
                return;
            }
        } else if (last == 'e') {
            if (buf[i] == 'e' || buf[i] == 'E') continue;
            if (buf[i] == 'o' || buf[i] == 'O') {
                last = 'o';
            } else {
                printf("NO\n");
                return;
            }
        } else if (last == 'o') {
            if (buf[i] == 'o' || buf[i] == 'O') continue;
            if (buf[i] == 'w' || buf[i] == 'W') {
                last = 'w';
            } else {
                printf("NO\n");
                return;
            }
        } else if (last == 'w') {
            if (buf[i] == 'w' || buf[i] == 'W') {
                continue;
            } else {
                printf("NO\n");
                return;
            }
        }
    }
    if (last == 'w') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
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
