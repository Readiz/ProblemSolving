#include <stdio.h>

typedef long long ll;
#define R register


int S[100001];
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    ll curSum = 0LL;
    for (R int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        curSum += (ll)tmp;
        S[i] = curSum;
    }
    for (R int t = 0; t < M; t++) {
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", S[j] - S[i - 1]);
    }
}