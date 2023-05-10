#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define R register
#define FOR(i,a,b) for(R int i=(a);((i)^(b)); ++i)
#define _D(...) printf(__VA_ARGS__)


int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char buf[100];
    int cnt = 0;
    FOR(i,0,H) {
        scanf("%s", buf);
        char* p = buf;
        while (*p != 0) {
            if (*p == '#') ++cnt;
            ++p;
        }
    }
    printf("%d\n", cnt);

    return 0;
}