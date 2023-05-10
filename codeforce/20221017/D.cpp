#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
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
char buf[1000001];
string res, maxstring;

void check(string& a, string& b) {
    int len = a.size();
    res = "";
    FOR(i,0,len) {
        if (b[i] == '1') {
            res += "1";
        }
        else {
            res += a[i];
        }
    }
}
void solve() {
    scanf("%d", &N);
    scanf("%s", buf);
    // 한 10000까지 밀어보고 정답 찾으면 될듯 (일감)
    // 더 많이 밀면 솔직히 낭비임
    string a = buf, b = buf;
    maxstring = a;
    int max = -1;
    for(int i = 1; i < 100; ++i) {
        b = "0" + b;
        check(a, b);
        if (maxstring < res) maxstring = res;
    }
    int len = maxstring.size();
    int p = 0;
    FOR(i,0,len) {
        if (maxstring[i] == '0') ++p;
        else break;
    }
    if (p != len) {
        printf("%s\n", &maxstring.c_str()[p]);
    } else {
        printf("0\n");
    }
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    solve();
MAIN_END
