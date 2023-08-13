#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

enum cmd {
    SUM = 1,
    PRODUCT = 2,
    OVERRITE = 3
};

constexpr int BMASK = 255;
ll bucket[400][256];
ll bucketSum[400];
pair<int, int> bucketLazy[400][50000];
int bucketLazySz[400];

constexpr ll MOD = 1'000'000'007LL;

inline void handleLazy(int b) {
    for(register int j = 0; j < bucketLazySz[b]; ++j) {
        auto& item = bucketLazy[b][j];
        if (item.first == SUM) {
            for(register int i = 0; i < 256; ++i) {
                bucket[b][i] += item.second;
                if (bucket[b][i] > MOD) bucket[b][i] -= MOD;
            }
        } else if (item.first == PRODUCT) {
            for(register int i = 0; i < 256; ++i) {
                bucket[b][i] *= item.second;
                bucket[b][i] %= MOD;
            }
        } else {
            for(register int i = 0; i < 256; ++i) {
                bucket[b][i] = item.second;
            }
        }
    }
    bucketLazySz[b] = 0;
}

inline void updateRange1(int l, int r, ll v) {
    --l; --r;
    int sb = l >> 8;
    int eb = r >> 8;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            bucketSum[sb] += v;
            if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
            bucket[sb][i & BMASK] += v;
            if (bucket[sb][i & BMASK] > MOD) bucket[sb][i & BMASK] -= MOD;
        }
    } else {
        // 1. sb
        if ((l&BMASK) != 0) {
            for(register int i = (l & BMASK); i < 256; ++i) {
                bucketSum[sb] += v;
                if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
                bucket[sb][i] += v;
                if (bucket[sb][i] > MOD) bucket[sb][i] -= MOD;
            }
        }
        // 2. lazy
        for(register int i = sb + ((l&BMASK) != 0); i < eb; ++i) {
            bucketLazy[i][bucketLazySz[i]++] = {SUM, v};
            bucketSum[i] += v * 256;
            bucketSum[i] %= MOD;
        }
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            bucketSum[eb] += v;
            bucketSum[eb] %= MOD;
            bucket[eb][i] += v;
            if (bucket[eb][i] > MOD) bucket[eb][i] -= MOD;
        }
    }
}
inline void updateRange2(int l, int r, ll v) {
    --l; --r;
    int sb = l >> 8;
    int eb = r >> 8;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            bucketSum[sb] += bucket[sb][i & BMASK] * (v - 1);
            bucketSum[sb] %= MOD;
            bucket[sb][i & BMASK] *= v;
            bucket[sb][i & BMASK] %= MOD;
        }
    } else {
        // 1. sb
        if ((l&BMASK) != 0) {
            for(register int i = (l & BMASK); i < 256; ++i) {
                bucketSum[sb] += bucket[sb][i] * (v - 1);
                bucketSum[sb] %= MOD;
                bucket[sb][i] *= v;
                bucket[sb][i] %= MOD;
            }
        }
        // 2. lazy
        for(register int i = sb + ((l&BMASK) != 0); i < eb; ++i) {
            bucketLazy[i][bucketLazySz[i]++] = {PRODUCT, v};
            bucketSum[i] *= v;
            bucketSum[i] %= MOD;
        }
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            bucketSum[eb] += bucket[eb][i] * (v - 1);
            bucketSum[eb] %= MOD;
            bucket[eb][i] *= v;
            bucket[eb][i] %= MOD;
        }
    }
}
inline void updateRange3(int l, int r, ll v) {
    --l; --r;
    int sb = l >> 8;
    int eb = r >> 8;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            ll diff = v - bucket[sb][i & BMASK];
            if (diff < 0) diff += MOD;
            bucketSum[sb] += diff;
            if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
            bucket[sb][i & BMASK] = v;
        }
    } else {
        // 1. sb
        if ((l&BMASK) != 0) {
            for(register int i = (l & BMASK); i < 256; ++i) {
                ll diff = v - bucket[sb][i];
                if (diff < 0) diff += MOD;
                bucketSum[sb] += diff;
                if (bucketSum[sb] > MOD) bucketSum[sb] -= MOD;
                bucket[sb][i] = v;
            }
        }
        // 2. lazy
        for(register int i = sb + ((l&BMASK) != 0); i < eb; ++i) {
            bucketLazySz[i] = 0;
            bucketLazy[i][bucketLazySz[i]++] = {OVERRITE, v};
            bucketSum[i] = v * 256;
            bucketSum[i] %= MOD;
        }
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            ll diff = v - bucket[eb][i];
            if (diff < 0) diff += MOD;
            bucketSum[eb] += diff;
            if (bucketSum[eb] > MOD) bucketSum[eb] -= MOD;
            bucket[eb][i] = v;
        }
    }
}

inline ll getRange(int l, int r) {
    if (l == r) {
        --l;
        handleLazy(l>>8);
        return bucket[l>>8][l&BMASK];
    }
    --l, --r;

    int sb = l >> 8;
    int eb = r >> 8;
    ll res = 0;

    handleLazy(sb);
    handleLazy(eb);

    if (sb == eb) {
        for(register int i = l; i <= r; ++i) {
            res += bucket[sb][i & BMASK];
        }
        res %= MOD;
    } else {
        // 1. sb
        for(register int i = (l & BMASK); i < 256; ++i) {
            res += bucket[sb][i];
        }
        res %= MOD;
        // 2. lazy
        for(register int i = sb + 1; i < eb; ++i) {
            res += bucketSum[i];
        }
        res %= MOD;
        // 3. eb
        for(register int i = 0; i <= (r & BMASK); ++i) {
            res += bucket[eb][i];
        }
        res %= MOD;
    }
    return res;
}

#include <unistd.h>
namespace io {
	const signed IS=1<<22, OS=1<<20;
	char I[IS+1],*J=I,O[OS],*K=O;

	inline void daer(){if(J>=I+IS-64){char*p=I;do*p++=*J++;while(J!=I+IS);p[read(0,p,I+IS-p)]=0;J=I;}}
	template<int N=10,typename T=int>inline T getu(){daer();T x=0;int k=0;do x=x*10+*J-'0';while(*++J>='0'&&++k<N);++J;return x;}
	template<int N=10,typename T=int>inline T geti(){daer();bool e=*J=='-';J+=e;return(e?-1:1)*getu<N,T>();}
	inline void flush(){write(1,O,K-O);K=O;}

	template<int N=10,typename T=int>inline void putu(T n){char s[(N+7)/8*8],*p=s;int k=0;do*p++=n%10+48;while((n/=10)&&++k<N);do*K++=*--p;while(p!=s);*K++=10;if(K>=O+OS-64)flush();}
	template<int N=10,typename T=int>inline void puti(T n){if(n<0)*K++='-',n=-n;putu<N,T>(n);}
	struct f{f(){I[read(0,I,IS)]=0;}~f(){flush();}}flu;
};
using namespace io;

int main() {
    int N = getu();
    for(register int i = 0; i < N; ++i) {
        bucket[i >> 8][i & BMASK] = getu();
        bucketSum[i >> 8] += bucket[i >> 8][i & BMASK];
        bucketSum[i >> 8] %= MOD;
    }
    N = getu();
    for(register int i = 0; i < N; ++i) {
        int cmd = getu();
        if (cmd != 4) {
            int x = getu();
            int y = getu();
            int v = getu();
            switch (cmd) {
                case 1:
                updateRange1(x, y, v);
                break;
                case 2:
                updateRange2(x, y, v);
                break;
                case 3:
                updateRange3(x, y, v);
                break;
            }
        } else {
            int l = getu();
            int r = getu();
            putu(getRange(l,r));
        }
    }
    return 0;
}