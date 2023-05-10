#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

int N, k;
int A[1000];

void qSort(int s, int e, int arr[]) {
    if (s >= e) return;
    int l = s, r = e;
    int pivot = arr[(l+r)>>1];
    while (true) {
        while(arr[l] < pivot) ++l;
        while(arr[r] > pivot) --r;
        if (l > r) break;

        if (arr[l] != arr[r])
            arr[l] ^= arr[r] ^= arr[l] ^= arr[r];

        ++l; --r;
    }
    
    qSort(s,r,arr);
    qSort(l,e,arr);
}
int main() {
    scanf("%d %d", &N, &k);

    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }

    qSort(0,N-1,A);
    printf("%d\n", A[N-k]);
}