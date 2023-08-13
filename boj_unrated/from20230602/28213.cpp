#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <immintrin.h>
#include <bits/stdc++.h>
using namespace std;

#include <unistd.h>
namespace io {
	const signed IS=1<<22, OS=1<<20;
	char I[IS+1],*J=I,O[OS],*K=O;

	inline void daer(){if(J>=I+IS-64){char*p=I;do*p++=*J++;while(J!=I+IS);p[read(0,p,I+IS-p)]=0;J=I;}}
	template<int N=10,typename T=int>inline T getu(){daer();T x=0;int k=0;do x=x*10+*J-'0';while(*++J>='0'&&++k<N);++J;return x;}
	template<int N=10,typename T=int>inline T geti(){daer();bool e=*J=='-';J+=e;return(e?-1:1)*getu<N,T>();}
	inline void flush(){write(1,O,K-O);K=O;}

	template<int N=10,typename T=int>inline void putu(T n){char s[(N+7)/8*8],*p=s;int k=0;do*p++=n%10+48;while((n/=10)&&++k<N);do*K++=*--p;while(p!=s);*K++=' ';if(K>=O+OS-64)flush();}
	template<int N=10,typename T=int>inline void puti(T n){if(n<0)*K++='-',n=-n;putu<N,T>(n);}
	struct f{f(){I[read(0,I,IS)]=0;}~f(){flush();}}flu;
};
using namespace io;

alignas(32) int v[200'000], TMP[8];

int main() {
    // const __m256i simdtmp = _mm256_set1_epi32(0xFFFFFFFE);
    int N = io::geti();
    int M = io::geti();
    register int l, r, d, i, temp;
    for(i = 0; i < N; ++i) v[i] = io::geti();
    for(i = 0; i < M; ++i) {
        l = io::geti();
        r = io::geti();
        d = io::geti();
        l--; r--;

        for (; l & 7 && l <= r; ++l) {
            int& vv = v[l];
            vv = vv - d;
            temp = vv >> 31;
            vv ^= temp;
            vv += temp & 1;
        }
        memset(TMP, d, sizeof(int) * 8);
        int* w = v + l;
        for(; l + 8 <= r; l += 8, w += 8) {
            *(__m256i*)w = _mm256_sub_epi32(*(__m256i*)w, *(__m256i*) TMP);
            // __m256i wtmp = _mm256_srai_epi32(*(__m256i*)w, 31);
            // *(__m256i*)w = _mm256_xor_si256(*(__m256i*)w, wtmp);
            // wtmp = _mm256_andnot_si256(simdtmp, wtmp);
            // *(__m256i*)w = _mm256_add_epi32(*(__m256i*)w, wtmp);
            *(__m256i*)w = _mm256_abs_epi32(*(__m256i*)w);
        }
        for(; l <= r; ++l) {
            int& vv = v[l];
            vv = vv - d;
            temp = vv >> 31;
            vv ^= temp;
            vv += temp & 1;
        }
    }
    for(i = 0; i < N; ++i) io::puti(v[i]);
    return 0;
}