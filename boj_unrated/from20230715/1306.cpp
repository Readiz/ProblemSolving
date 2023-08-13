#include <bits/stdc++.h>
using namespace std;

multiset<int> v;
int A[1000000];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);
    int k = (M<<1) - 1;
    if (k > N) {
        printf("\n");
        return 0;
    }
    int cur = 0;
    for(int i = 0; i < k; ++i) {
        v.insert(A[i]);
    }
    printf("%d", *v.rbegin());
    int l = 0;
    int r = k;
    for(; r < N; ++r, ++l) {
        v.insert(A[r]);
        v.erase(v.find(A[l]));
        printf(" %d", *v.rbegin());
    }
    printf("\n");
    return 0;
}