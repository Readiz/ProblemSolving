#include <stdio.h>


#define R register
#define _D(...) printf(__VA_ARGS__)

int seed = 5;
short pseudo_rand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFFF;
}

// Heap utils
#define DMAX 1000
#define l(i) ((i) << 1)
#define r(i) (((i) << 1) | 1)
#define p(i) ((i) >> 1)
struct H {
    int data[DMAX + 1];
    int sz; // pIdx.. 넣을 때는 1 더한것이 idx가 됨
    H(): sz(0) {}
    void init() {
        sz = 0;
    }
    void push(int mdata) {
        data[++sz] = mdata;
        checkUp(sz);
    }
    void checkUp(int p) {
        while(p > 0) { // 제일 root가 1이므로, 0 전까지 확인..
            
            p = p(p);
        }
    }
};

H h;

int main() {
    


    return 0;
}