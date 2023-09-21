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

int N;
char buf[200010];
void solve() {
    scanf("%s", buf);
    int len = strlen(buf);
    if (len == 1) {
        printf("0\n");
        return;
    }
    int ans = 0;
    if (buf[0] == 'B') {
        // left go
        for(int i = 0; i < len; ++i) {
            if (buf[i] == 'B' && buf[i + 1] == 'A') {
                // BA start!
                int j;
                for(j = i + 1; buf[j] == 'A'; ++j);
                --j;
                ans += j - i;
                for(int k = i; k <= j; ++k) buf[k] = 'O';
            }
        }
        // printf("[d] 1 %s\n", buf);
        // right go
        for(int i = len - 1; i >= 1; --i) {
            if (buf[i] == 'B' && buf[i - 1] == 'A') {
                // BA start rev!
                int j;
                for(j = i - 1; buf[j] == 'A'; --j);
                ++j;
                ans += i - j;
                for(int k = i; k >= j; --k) buf[k] = 'O';
            }
        }
        // printf("[d] 2 %s\n", buf);
    } else if (buf[len - 1] == 'B') {
        // right go
        for(int i = len - 1; i >= 1; --i) {
            if (buf[i] == 'B' && buf[i - 1] == 'A') {
                // BA start rev!
                int j;
                for(j = i - 1; buf[j] == 'A'; --j);
                ++j;
                ans += i - j;
                for(int k = i; k >= j; --k) buf[k] = 'O';
            }
        }
        // left go
        for(int i = 0; i < len; ++i) {
            if (buf[i] == 'B' && buf[i + 1] == 'A') {
                // BA start!
                int j;
                for(j = i + 1; buf[j] == 'A'; ++j);
                --j;
                ans += j - i;
                for(int k = i; k <= j; ++k) buf[k] = 'O';
            }
        }
    } else {
        // A 개수 많은 쪽을 선택
        int leftACnt = 0, rightACnt = 0;
        for(int i = 0; i < len; ++i) {
            if (buf[i] == 'A') {
                ++leftACnt;
                continue;
            }
            break;
        }
        for(int i = len - 1; i >= 0; --i) {
            if (buf[i] == 'A') {
                ++rightACnt;
                continue;
            }
            break;
        }
        if (leftACnt >= rightACnt) {
            // right go
            for(int i = len - 1; i >= 1; --i) {
                if (buf[i] == 'B' && buf[i - 1] == 'A') {
                    // BA start rev!
                    int j;
                    for(j = i - 1; buf[j] == 'A'; --j);
                    ++j;
                    ans += i - j;
                    for(int k = i; k >= j; --k) buf[k] = 'O';
                }
            }
            // left go
            for(int i = 0; i < len; ++i) {
                if (buf[i] == 'B' && buf[i + 1] == 'A') {
                    // BA start!
                    int j;
                    for(j = i + 1; buf[j] == 'A'; ++j);
                    --j;
                    ans += j - i;
                    for(int k = i; k <= j; ++k) buf[k] = 'O';
                }
            }
        } else {
            // left go
            for(int i = 0; i < len; ++i) {
                if (buf[i] == 'B' && buf[i + 1] == 'A') {
                    // BA start!
                    int j;
                    for(j = i + 1; buf[j] == 'A'; ++j);
                    --j;
                    ans += j - i;
                    for(int k = i; k <= j; ++k) buf[k] = 'O';
                }
            }
            // printf("[d] 1 %s\n", buf);
            // right go
            for(int i = len - 1; i >= 1; --i) {
                if (buf[i] == 'B' && buf[i - 1] == 'A') {
                    // BA start rev!
                    int j;
                    for(j = i - 1; buf[j] == 'A'; --j);
                    ++j;
                    ans += i - j;
                    for(int k = i; k >= j; --k) buf[k] = 'O';
                }
            }
            // printf("[d] 2 %s\n", buf);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }

    return 0;
}