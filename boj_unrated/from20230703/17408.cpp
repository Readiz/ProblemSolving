#include <stdio.h>

#define _D(...)
int bucket[320]; // bucket의 max값 저장
int bucketIdx[320]; // bucket의 max값 저장
int A[100001];
struct RET {
    int v;
    int p;
};
RET query(int l, int r) {
    _D("[Q] %d ~ %d\n", l, r);
    int bl = l / 320; int br = r / 320;
    int res = 0;
    int respos = 0;
    if (bl == br) {
        // 같은 bucket일때..
        for(int i = l; i <= r; ++i) {
            if (res < A[i]) {
                res = A[i];
                respos = i;
            }
        }
    } else {
        // bl이 속한 곳과 br이 속한 곳은 건너 뛴다.
        ++bl;
        for(int i = l; i < bl * 320; ++i) {
            if (res < A[i]) {
                res = A[i];
                respos = i;
            }
        }
        for(int b = bl; b < br; ++b) {
            if (res < bucket[b]) {
                res = bucket[b];
                respos = bucketIdx[b];
            }
        }
        for(int i = br * 320; i <= r; ++i) {
            if (res < A[i]) {
                res = A[i];
                respos = i;
            }
        }
    }

    _D("-> %d, %d\n", res, respos);

    return RET{res, respos};
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        if (A[i] > bucket[i/320]) {
            bucket[i/320] = A[i];
            bucketIdx[i/320] = i;
        }
    }
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            int a, b;
            scanf("%d %d", &a, &b);
            int bid = a / 320;
            if (A[a] == bucket[bid]) { // 현재 bucket의 최대값이면..
                A[a] = b;
                bucket[bid] = 0;
                for(int i = bid * 320; i < (bid+1) * 320; ++i) {
                    if (bucket[bid] < A[i]) {
                        bucket[bid] = A[i];
                        bucketIdx[bid] = i;
                    }
                }
            } else {
                A[a] = b;
                if (b > bucket[bid]) {
                    bucket[bid] = b;
                    bucketIdx[bid] = a;
                }
            }
        } else {
            int l, r; scanf("%d %d", &l, &r);
            RET ret = query(l, r);
            int max = ret.v;
            int max2 = 0;
            if (ret.p - 1 >= l) {
                RET ret2 = query(l, ret.p - 1);
                if (max2 < ret2.v) max2 = ret2.v;
            }
            if (ret.p + 1 <= r) {
                RET ret2 = query(ret.p + 1, r);
                if (max2 < ret2.v) max2 = ret2.v;
            }
            printf("%d\n", max + max2);
        }
    }

    return 0;
}