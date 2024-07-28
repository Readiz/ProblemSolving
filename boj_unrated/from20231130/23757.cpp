#include <stdio.h>

#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
template<typename T>
struct Vector {
    T* d;
    int sz, capa;
    Vector() { sz = 0; capa = 1; d = 0; clear(); }
    void clear() {
        if (d) delete[] d;
        d = new T[capa];
    }
    void push_back(T item) {
        if (sz == capa) {
            capa <<= 1;
            T* nd = new T[capa];
            FOR(i, 0, sz) nd[i] = d[i];
            delete[] d;
            d = nd;
        }
    }
    void removeAt(int idx) {
        d[idx] = d[--sz];
    }
};
template<typename T>
void zwap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
template<typename T>
struct Heap {
    T h[100010];
    int sz;
    Heap() { sz = 0; }
    void push(T item) {
        h[++sz] = item;
        int c = sz;
        for(; c > 1; c >>= 1) {
            int p = c >> 1;
            if (h[p] < h[c]) zwap(h[p], h[c]);
            else break;
        }
    }
    T pop() {
        T ret = h[1];
        h[1] = h[sz--];
        int c = 2;
        for(; c <= sz; c <<= 1) {
            if (c+1 <= sz && h[c] < h[c+1]) ++c;
            int p = c >> 1;
            if (h[p] < h[c]) zwap(h[p], h[c]);
            else break;
        }
        return ret;
    }
};

int main() {
    int N, M; scanf("%d %d", &N, &M);
    Heap<int> h;
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        h.push(tmp);
    }
    FOR(i,0,M) {
        int tmp; scanf("%d", &tmp);
        auto top = h.pop();
        if (top >= tmp) {
            top -= tmp;
            h.push(top);
        } else {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}