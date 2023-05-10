#include <stdio.h>

#define R register
#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)

int L, K, CUTMAX;
int A[10000];

void qSort(int s, int e) {
    if (s >= e) return;
    int l = s, r = e;
    int pivot = A[(s+e)>>1];
    while(l < r) {
        while(A[l] < pivot) ++l;
        while(pivot < A[r]) --r;
        if (l > r) break;
        if (A[l] != A[r]) A[l] ^= A[r] ^= A[l] ^= A[r];
        ++l; --r;
    }
    qSort(s, r);
    qSort(l, e);
}
int B[10000]; // A -> B
int C[10000]; // CNT -> 중복 있을 때
int makeSet() {
    int ap = 0; int bp = 0;
    B[bp++] = A[ap++];
    FOR(i,1,K) {
        if (A[i] != A[i - 1]) {
            B[bp++] = A[ap++];
        } else {
            ap++;
            C[bp]++;
        }
    }
    return bp;
}

struct BLK {
    int l, r;
    bool operator<(const struct BLK& t) const {
        if (r - l != t.r - t.l) return r - l < t.r - t.l;
        return l < t.l;
    }
};

struct Heap {
    BLK b[1000000];
    int sz;

    void init() {
        sz = 0;
    }
    void push(BLK v) {

    }
    BLK pop() {
        
    }
};
Heap h;

int main() {
    scanf("%d %d %d", &L, &K, &CUTMAX);
    FOR(i,0,K) {
        scanf("%d", &A[i]);
    }
    qSort(0, K-1);
    int nK = makeSet(); // new K

    FOR(i,0,nK) {
        _D("%d ", B[i]);
    }
    _D("\n");

    h.init();

    // Greedy?
    // 가장 중간으로 잘라본다.
    
}
