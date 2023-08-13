#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
using namespace std;
#include <immintrin.h>
alignas(32) int bucket[400][512], TMP[8];
alignas(32) int bucketLazy[400][200'000]; // 구간 전체 적용 query
alignas(32) int bucketLazySz[400]; // 구간 전체 적용 query

inline void handleLazy(int b) {
    assert(b < 400);
    for(int j = 0; j < bucketLazySz[b]; ++j) {
        int& d = bucketLazy[b][j];
        *(__m256i*) TMP = _mm256_set_epi32(d, d, d, d, d, d, d, d);
        int* w = bucket[b];
        for(int i = 0; i < 64; ++i) {
            *(__m256i*)w = _mm256_sub_epi32(*(__m256i*)w, *(__m256i*) TMP);
            *(__m256i*)w = _mm256_abs_epi32(*(__m256i*)w);
            w += 8;
        }
    }
    bucketLazySz[b] = 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int N, M; scanf("%d %d", &N, &M);
    int* p = (int*)bucket;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &p[i]);
    }
    for(int i = 0; i < M; ++i) {
        // if(i % 10000 == 0) printf("[DEBUG] handling %d...\n", i);
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        --l; --r;
        int s = l >> 9;
        int e = r >> 9;
        
        handleLazy(s);
        handleLazy(e);

        if (s == e) {
            for(int i = l; i <= r; ++i) {
                bucket[s][i&511] -= d;
                if (bucket[s][i&511] < 0) bucket[s][i&511] *= -1;
            }
        } else {
            for(int i = (l&511); i < 512; ++i) {
                bucket[s][i] -= d;
                if (bucket[s][i] < 0) bucket[s][i] *= -1;
            }
            for(int b = s + 1; b < e; ++b) {
                bucketLazy[b][bucketLazySz[b]++] = d;
            }
            for(int i = 0; i <= (r&511); ++i) {
                bucket[e][i] -= d;
                if (bucket[e][i] < 0) bucket[e][i] *= -1;
            }
        }
    }
    // handle lazy
    for(int b = 0; b < 400; ++b) {
        handleLazy(b);
    }
    for(int i = 0; i < N; ++i) {
        printf("%d ", p[i]);
    }
}