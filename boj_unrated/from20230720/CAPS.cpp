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
char buf[2000000];
int main() {
    scanf("%s", buf);
    for(char* p = buf; *p != 0; ++p) {
        printf("%c", *p + 'A' - 'a');
    }
    return 0;
}