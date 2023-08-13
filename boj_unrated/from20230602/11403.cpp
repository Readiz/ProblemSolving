#include <bits/stdc++.h>
using namespace std;

int M[101][101];
int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        scanf("%d", &M[i][j]);
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        if (M[i][k] && M[k][j]) {
            M[i][j] = 1;
        }
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}