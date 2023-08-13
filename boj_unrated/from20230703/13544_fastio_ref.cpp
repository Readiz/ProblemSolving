#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <vector>
#include <algorithm>
using namespace std;

#define SZ (1 << 16)
#define all(v) (v).begin(), (v).end()

template<typename T>
int Sol(T& v, int l, int r, int k) {
	int ret = 0; --l |= 1 << 17, --r |= 1 << 17;
	while (l <= r) {
		if (l & 1)  ret += v[l].end() - upper_bound(all(v[l]), k), l++;
		if (~r & 1) ret += v[r].end() - upper_bound(all(v[r]), k), r--;
		l >>= 1, r >>= 1;
	}
	return ret;
}

int main() {
    struct stat st; fstat(0, &st);
	char w[SZ], *p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0), *pp = w;
	auto ReadInt = [&]() {
		int ret = 0;
		for (char c = *p++; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return ret;
	};
    auto WriteInt = [&](int n) {
        if (pp + 20 >= w + SZ) write(1, w, pp - w), pp = w;
        int sz = 1, t = n;
        for (; t >= 10; t /= 10) sz++;
        for (int i = sz; i --> 0; n /= 10) pp[i] = n % 10 | 48;
        pp += sz;
    };
    
	int n = ReadInt(); vector<int> v[1 << 18];
	for (int i = 0; i < n; i++)
		v[i | 1 << 17].push_back(ReadInt());
	for (int i = 1 << 17; i --> 1;)
		v[i].resize(v[i << 1].size() + v[i << 1 | 1].size()),
		merge(all(v[i << 1]), all(v[i << 1 | 1]), v[i].begin());
    for (int q = ReadInt(), ans = 0; q--;) {
		int a = ReadInt(), b = ReadInt(), c = ReadInt();
        WriteInt(ans = Sol(v, a ^ ans, b ^ ans, c ^ ans)); *pp++ = '\n';
	}
    write(1, w, pp - w);
}