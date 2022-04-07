#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

static uint64_t splitmix64(uint64_t x) {
	x += 0x9e3779b97f4a7c15;
	return (x ^ (x >> 27)) * 0x94d049bb133111eb;
}

constexpr int SZ = 22, M = 3;
constexpr int MOD = 1 << SZ;
bitset<MOD> BIT[M];
uint64_t v[M + 1];

int main() {
    struct stat st; fstat(0, &st);
	char w[1 << 18], *p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0), *q = w;
	auto ReadInt = [&]() {
		int ret = 0; char c = *p++, flag = 0;
        if (c == '-') c = *p++, flag = 1;
        for (; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return flag ? -ret : ret;
	};

    for (int n = ReadInt(); n--;) {
		v[0] = ReadInt();
		for (int i = 1; i <= M; i++) v[i] = splitmix64(v[i - 1]);
		for (int i = 0; i < M; i++) BIT[i][v[i + 1] % MOD] = 1;
	}
    for (int m = ReadInt(); m--;) {
		bool flag = 1; v[0] = ReadInt();
		for (int i = 1; i <= M; i++) v[i] = splitmix64(v[i - 1]);
		for (int i = 0; i < M && flag; i++) if (!BIT[i][v[i + 1] % MOD]) flag = 0;
        *q++ = flag | 48, *q++ = '\n';
	}
    syscall(1, 1, w, q - w);
}