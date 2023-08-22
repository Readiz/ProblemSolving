#include <bits/stdc++.h>
using namespace std;
struct Number {
	int v;
	bool operator<(const struct Number& t) const {
		if (__builtin_popcount(v) != __builtin_popcount(t.v))
			return __builtin_popcount(v) > __builtin_popcount(t.v);
		return v > t.v;
	}
};
int main() {
	int N, K; scanf("%d %d", &N, &K);
	vector<Number> A;
	for(int i = 0; i < N; ++i) {
		int tmp; scanf("%d", &tmp);
		A.push_back({tmp});
	}
	sort(A.begin(), A.end());
	printf("%d\n", A[K - 1].v);
	return 0;
}