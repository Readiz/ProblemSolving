#include <bits/stdc++.h>
using namespace std;

int buf[100000];
bool chk(int N, int b) {
    int idx = 0;
    while(N) {
        buf[idx++] = N % b;
        N /= b;
    }
    for(int i = 0; i < idx / 2; ++i) {
        if (buf[i] == buf[idx - i - 1]) continue;
        return false;
    }
    return true;
}

void solve() {
    int N; scanf("%d", &N);
    for(int i = 2; i <= 64; ++i) {
        bool ret = chk(N, i);
        if (ret) {
            printf("1\n");
            return;
        }
    }
    printf("0\n");
}

int main() {
    int TC; scanf("%d", &TC);
    for(int i = 0; i < TC; ++i) solve();
    return 0;
}