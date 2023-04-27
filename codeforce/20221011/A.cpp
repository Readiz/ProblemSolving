#include <stdio.h>
#include <string.h>
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

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    char buf1[100], buf2[100];
    FOR(TC,0,tc) {
        scanf("%s %s", buf1, buf2);
        int l1, l2;
        int v1, v2;
        l1 = strlen(buf1) - 1;
        l2 = strlen(buf2) - 1;
        if (buf1[l1] == 'M') v1 = 0;
        else if (buf1[l1] == 'S') {
            v1 = -l1 - 1;
        } else {
            v1 = l1 + 1;
        }
        
        if (buf2[l2] == 'M') v2 = 0;
        else if (buf2[l2] == 'S') {
            v2 = -l2 - 1;
        } else {
            v2 = l2 + 1;
        }

        if (v1 == v2) printf("=\n");
        else if (v1 > v2) printf(">\n");
        else printf("<\n");
    }
MAIN_END
