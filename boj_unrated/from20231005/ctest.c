#include <unistd.h>
#define SZ (1 << 14)
#define readInt(n) {                            \
    while (!(*p & 16)) p++;                     \
    while (*p & 16) n = 10 * n + (*p++ & 15); }

#define writeInt(n) {                                          \
    int sz = GetSize(n), m = n;                                \
    for (int j = sz; j --> 0; m /= 10) w[i + j] = m % 10 | 48; \
    i += sz; }

inline int GetSize(int n) {
    int sz = 1;
    for (; n >= 10; n /= 10) sz++;
    return sz; }

__libc_start_main() {
    char r[SZ], w[SZ], *p = r; syscall(0, 0, r, SZ);
    int dp[41][2]; dp[1][1] = dp[0][0] = 1;
	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
    int N = 0, i = 0; readInt(N);
    while (N--) {
        int n = 0; readInt(n);
        writeInt(dp[n][0]); w[i++] = ' ';
        writeInt(dp[n][1]); w[i++] = '\n';
    }
    syscall(1, 1, w, i);
    _exit(0);
} main;