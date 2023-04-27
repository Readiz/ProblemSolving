#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define R register
#define FOR(i,a,b) for(R int i=(a);((i)^(b)); ++i)
#define _D(...) printf(__VA_ARGS__)


char buf1[500001];
char buf2[500001];
int main() {
    scanf("%s %s", buf1, buf2);
    int i;
    bool isPrinted = false;
    for(i = 0; buf1[i] != 0; ++i) {
        if (buf1[i] != buf2[i]) {
            printf("%d\n", i + 1);
            isPrinted = true;
            break;
        }
    }
    if (!isPrinted) {
        printf("%d\n", i + 1);
    }
    return 0;
}