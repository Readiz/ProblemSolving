#include <bits/stdc++.h>
using namespace std;

int state[101];
int tmp[101];
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; ++i) {
        state[i] = i;
    }
    for(int i = 0; i < Q; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int j = a;
        for(int i = c; i <= b; ++i, ++j) {
            tmp[j] = state[i];
        }
        for(int i = a; i < c; ++i, ++j) {
            tmp[j] = state[i];
        }
        for(int i = a; i <= b; ++i) {
            state[i] = tmp[i];
        }
    }
    printf("%d", state[1]);
    for(int i = 2; i <= N; ++i) {
        printf(" %d", state[i]);
    }
    printf("\n");
    return 0;
}