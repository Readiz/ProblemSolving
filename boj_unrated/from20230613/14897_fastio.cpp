#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#include <unistd.h>
namespace io {
	const signed IS=1<<25, OS=1<<25;
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


int A[1'000'001];

// 1000007로 나눈 위치에 들어간다.
struct Node {
    int num;
    int cnt;
};

constexpr int BSIZE = 1 << 20;
constexpr int BMASK = BSIZE - 1;

Node bucket[BSIZE][10]; // 숫자 n은 n % BSIZE에 들어가야한다.
int bucketSZ[BSIZE];
inline bool add(int& num) {
    int bNum = num & BMASK;
    bool found = false;
    for(int i = 0; i < bucketSZ[bNum]; ++i) {
        auto& item = bucket[bNum][i];
        if (item.num == num) {
            item.cnt++;
            if (item.cnt == 1) return true;
            found = true;
            break;
        }
    }
    if (!found) {
        bucket[bNum][bucketSZ[bNum]++] = Node{num, 1};
        return true;
    }
    return false;
}
inline bool erase(int& num) {
    int bNum = num & BMASK;
    for(int i = 0; i < bucketSZ[bNum]; ++i) {
        auto& item = bucket[bNum][i];
        if (item.num == num) {
            item.cnt--;
            if (item.cnt == 0) return true;
            break;
        }
    }
    return false;
}

struct Q {
    int l, r, n;
    bool operator<(const struct Q& t) const {
        if (r / 1000 != t.r / 1000) return r / 1000 < t.r / 1000;
        return l < t.l;
    }
} q[1'000'000];

int ans[1'000'000];

int main() {
    int N; N = io::geti();
    for(int i = 1; i <= N; ++i) A[i] = io::geti();
    
    N = io::geti();
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int a = io::geti();
        int b = io::geti();
        q[i] = Q{a, b, i};
    }
    sort(q, q + N);

    int l = q[0].l; int r = q[0].r;
    int s = 0;
    for(int i = l; i <= r; ++i) {
        if (add(A[i])) ++s;
    }
    ans[q[0].n] = s;

    for(int i = 1; i < N; ++i) {
        int cl = q[i].l, cr = q[i].r;
        while(cl < l) s += add(A[--l]);
        while(l < cl) s -= erase(A[l++]);
        while(cr < r) s -= erase(A[r--]);
        while(r < cr) s += add(A[++r]);
        ans[q[i].n] = s;
    }

    for(int i = 0; i < N; ++i) {
        io::puti(ans[i]);
    }

    return 0;
}


/*
총 N개의 정수로 이루어진 배열 A가 주어진다. 이때, 다음 쿼리를 총 Q번 반복 수행하는 프로그램을 작성하시오. 배열은 1번부터 시작한다.

l r: l번째 수부터 r번째 수 중에서 서로 다른 수의 개수를 세고 출력한다.
입력
첫째 줄에 배열의 크기 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 배열에 포함된 수가 1번째 수부터 주어진다. 수는 공백으로 구분되어져 있다. 배열에 포함된 수는 1,000,000,000보다 작거나 같은 자연수이다.

셋째 줄에는 쿼리의 개수 Q(1 ≤ Q ≤ 1,000,000)가 주어진다. 넷째 줄부터 Q개의 줄에는 쿼리 li, ri가 주어진다. (1 ≤ li ≤ ri ≤ N)
*/