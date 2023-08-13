#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <immintrin.h>
#include <bits/stdc++.h>
using namespace std;

alignas(32) int v[100'000], C[8];

// int query(int l, int r) {
// 	int ret = 0;
// 	for (; l & 7 && l < r; l++) ret += v[l] & 1;
// 	const __m256i t1 = _mm256_set1_epi32(1);
// 	__m256i res = _mm256_setzero_si256();
// 	for (; l + 8 <= r; l += 8) {
// 		__m256i t2 = _mm256_load_si256((__m256i*)(v + l));
// 		t2 = _mm256_and_si256(t1, t2);
// 		res = _mm256_add_epi32(res, t2);
// 	}
// 	_mm256_store_si256((__m256i*)C, res);
// 	for (; l < r; l++) ret += v[l] & 1;
// 	for (int i = 0; i < 8; i++) ret += C[i];
// 	return ret;
// }

int main() {
    for(int i = 0; i < 100000; ++i) {
        v[i] = 1;
    }
    __m256i ans = _mm256_setzero_si256();
    __m256i ml = _mm256_load_si256((__m256i*)(v+0));
    ans = _mm256_sub_epi32(ans, ml);
    ans = _mm256_abs_epi32(ans);
    _mm256_store_si256((__m256i*)C, ans);

    int fans = 0;
    for(int i = 0; i < 8; ++i) fans += C[i];

    printf("%d\n", fans);
    return 0;
}