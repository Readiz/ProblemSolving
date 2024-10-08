#include <bits/stdc++.h>
using namespace std;

int state[101];
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; ++i) {
        state[i] = i;
    }
    for(int i = 0; i < Q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = a, j = b; i < j; ++i, --j) {
            state[i] ^= state[j] ^= state[i] ^= state[j];
        }
    }
    printf("%d", state[1]);
    for(int i = 2; i <= N; ++i) {
        printf(" %d", state[i]);
    }
    printf("\n");
    return 0;
}