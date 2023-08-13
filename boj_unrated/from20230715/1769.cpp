#include <bits/stdc++.h>
using namespace std;

char buf[1000010];
int main() {
    scanf("%s", buf);
    int len = strlen(buf);

    if (len > 1) {
        int x = 0;
        for(int i = 0; i < len; ++i) {
            x += buf[i] - '0';
        }
        int cnt = 1;
        while (x >= 10) {
            int nextx = 0;
            while(x > 0) {
                nextx += x % 10;
                x /= 10;
            }
            x = nextx;
            ++cnt;
        }
        printf("%d\n", cnt);
        if (x % 3 == 0) printf("YES\n");
        else printf("NO\n");
    } else {
        printf("0\n");
        if ((buf[0] - '0') % 3 == 0) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}