#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N,H; scanf("%d%d", &N,&H);    
    char buf[1000001]; scanf("%s", buf);
    int len = strlen(buf);
    if (H == 1) {
        printf("0\n");
        return 0;
    } else if (H == 2) {
        int ans = 0;
        for(int i = 1; i < len; ++i) {
            if (buf[i] == buf[i - 1]) {
                ++ans;
                ++i;
            }
        }
        printf("%d\n", ans);
    } else if (H == 3) {
        int ans = 0;
        for(int i = 2; i < len; ++i) {
            if (buf[i] == buf[i-1] && buf[i-2] == buf[i]) {
                ans += 2;
                i += 2;
                continue;
            }
            if (buf[i] == buf[i-1]) {
                continue;
            }
            if (buf[i-1] == buf[i-2]) {
                ans += 1;
                ++i;
                continue;
            }
            if (buf[i] == buf[i-2]) {
                if (buf[i-2] == 'S' && buf[i-1] == 'R' || buf[i-2] == 'R' && buf[i-1] == 'S') {
                    buf[i] = 'W';
                } else if (buf[i-2] == 'R' && buf[i-1] == 'W' || buf[i-2] == 'W' && buf[i-1] == 'R') {
                    buf[i] = 'S';
                } else if (buf[i-2] == 'S' && buf[i-1] == 'W' || buf[i-2] == 'W' && buf[i-1] == 'S') {
                    buf[i] = 'R';
                }
            }
        }
        printf("%d\n", ans);
    } else if (H >= 4) {
        if (N >= 4) {
            printf("-1\n");
            return 0;
        }
        if (N == 3) {
            if (buf[0] != buf[1] && buf[1] != buf[2] && buf[0] != buf[2]) {
                printf("0\n");
                return 0;
            }
            if (buf[0] == buf[1] && buf[1] == buf[2]) {
                printf("2\n");
                return 0;
            }
            printf("1\n");
            return 0;
        }
        if (N == 2) {
            if (buf[0] == buf[1]) {
                printf("1\n");
                return 0;
            }
            printf("0\n");
            return 0;
        }
        printf("0\n");
        return 0;
    }
    return 0;
}