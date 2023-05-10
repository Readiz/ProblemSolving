#include <stdio.h>

static unsigned short pseudo_rand() {
    static unsigned long long seed = 5;
    unsigned short r = (unsigned short)((seed = seed * 25214903917ULL + 11ULL) >> 16);
    // printf("VAL: %d\n", r);
    return r;
}

#define NUM 100
typedef long long ll;

int A[NUM + 1] = {0, };
int ST[NUM + 1] = {0, };
int ST_old[NUM + 1] = {0, };

void update(int idx, int val) {
    while (idx <= NUM) {
        ST[idx] += val;
        idx += (idx & -idx);
    }
}

ll getSum(int idx) {
    ll r = 0LL;

    while (idx > 0) {
        r += ST[idx];
        idx -= (idx & -idx);
    }

    return r;
}
int main() {
    ll acc = 0;
    for (int i = 1; i <= NUM; i++) {
        A[i] = pseudo_rand() % 1000;
        update(i, A[i]);

        acc += A[i];
        ST_old[i] = acc;
    }

    for (int i = 1; i <= NUM; i++) {
        printf("%lld = %lld\n", ST_old[i], getSum(i));
    }

    return 0;
}