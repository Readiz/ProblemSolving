// from https://www.acmicpc.net/source/3248036

#include <cstdio>
#include <array>

long long mn, mx;
std::array<bool, 1000001> table {};

void filtering(long long n) {
	n = n * n;
	for (auto i = mx - (mx % n); i >= mn; i -= n)
		table[i - mn] = true;
}

int main(void) {
	scanf("%lld%lld", &mn, &mx);

	filtering(2);
	filtering(3);
	for (long long i = 5; i * i <= mx; i += 6) {
		filtering(i);
		filtering(i + 2);
	}

	int count = 0;
	for (long long i = 0, iE = mx - mn; i <= iE; ++i)
		if (!table[i])
			++count;

	printf("%d\n", count);

	return 0;
}
// 사실 소수만 가지고 해도 됨.