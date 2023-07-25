#include <bits/stdc++.h>
using namespace std;


void solve() {
    char buf[10]; scanf("%s", buf);
    int len = strlen(buf);
    for(int i = 0; i < len; ++i) buf[i] -= '0';

    // 덧셈기호 꽂아넣기
    int cases = 1 << (len - 1);
    int caseCnt = 0;
    for(int m = 1; m <= 20; ++m) {
        long long compareSum = 0;
        for(int i = 0; i < len; ++i) {
            long long r = 1;
            for(int k = 0; k < m; ++k) {
                r *= buf[i];
            }
            compareSum += r;
        }
        bool hasSame = false;
        for(int cur = 0; cur < cases; ++cur) {
            int csum = buf[0];
            int osum = 0;
            for(int c = 1; c < len; c++) {
                if (cur & (1<<(c-1))) {
                    osum += csum;
                    csum = buf[c];
                } else {
                    csum *= 10;
                    csum += buf[c];
                }
            }
            osum += csum;
            // printf("checking %d...\n", osum);
            

            if (compareSum == osum) {
                hasSame = true;
                break;
            }
        }
        if (hasSame) {
            ++caseCnt;
        }
    }
    if (caseCnt == 20) printf("Hello, BOJ 2023!\n");
    else printf("%d\n", caseCnt);
}
int main() {
    int TC; scanf("%d", &TC);
    while(TC--) {
        solve();
    }
    return 0;
}