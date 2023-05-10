#include <bits/stdc++.h>
using namespace std;

int main() {
    char buf[1000];
    int N;
    scanf("%s %d", buf, &N);
    int p = 0;
    while(buf[p] != 0) ++p;
    --p;

    int unit = 1;
    int res = 0;
    for(;p >= 0; --p, unit *= N) {
        if (buf[p] >= '0' && buf[p] <= '9') {
            res += unit * (buf[p] - '0');
        } else {
            res += unit * (buf[p] - 'A' + 10);
        }
    }
    printf("%d\n", res);
    return 0;
}