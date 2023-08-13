#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int A[100001], T[100001];
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        A[tmp] += 1;
    }
    int ans[100001];
    memcpy(ans, A, sizeof(int) * 100001);

    for(int step = 0; step < 20; ++step) {
        memset(T, 0, sizeof(int) * 100001);
        for(ll k = 2; k <= 100000; ++k) {
            for(ll i = 1; i <= 100000; ++i) {
                if (k * i > 100000) break;
                T[k*i] += A[i];
            }
        }
        for(ll i = 1; i <= 100000; ++i) {
            ans[i] += T[i];
        }
        memcpy(A, T, sizeof(int) * 100001);
    }

    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {
        int tmp; scanf("%d", &tmp);
        printf("%d ", ans[tmp]);
    }
    printf("\n");

    return 0;
}