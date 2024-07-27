#include <bits/stdc++.h>
using namespace std;

char buf[210];
int main () {
    int N, Q; scanf("%d %d", &N, &Q);
    scanf("%s", &buf[1]);

    for(int i=0;i<Q;++i) {
        int cmd, l, r;
        scanf("%d %d %d", &cmd, &l, &r);
        if (cmd == 2) {
            for(int k=l;k<=r;++k) {
                buf[k]++;
                if (buf[k] == 'Z'+1) buf[k] = 'A';
            }
        } else {
            char last=buf[l];
            int cnt=1;
            for(int k=l+1;k<=r;++k) {
                if (buf[k]==last) continue;
                last=buf[k];
                ++cnt;
            }
            printf("%d\n", cnt);
        }
    }

    return 0;
}