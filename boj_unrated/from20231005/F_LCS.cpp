#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char A[3010];
char B[3010];
int DP[3010][3010];

char C[3010];

int main() {
    scanf("%s %s", &A[1], &B[1]);
    int lena = strlen(&A[1]);
    int lenb = strlen(&B[1]);
    int lenc = min(lena, lenb);

    // DP N * N
    for(int b = 1; b <= lenb; ++b) {
        for(int a = 1; a <= lena; ++a) {
            if (A[a] == B[b]) {
                DP[b][a] = DP[b - 1][a - 1] + 1;
            } else {
                DP[b][a] = max(DP[b - 1][a], DP[b][a - 1]);
            }
        }
    }
    
    // for(int b = 0; b <= lenb; ++b) {
    //     for(int a = 0; a <= lena; ++a) {
    //         printf("%d ", DP[b][a]);
    //     }
    //     printf("\n");
    // }

    //printf("%d\n", DP[lenb - 1][lena - 1]);
    int ca = lena, cb = lenb;
    int cp = 0;
    while(DP[cb][ca] != 0) {
        if (DP[cb - 1][ca] == DP[cb][ca]) {
            --cb;
        } else if (DP[cb][ca - 1] == DP[cb][ca]) {
            --ca;
        } else if (DP[cb - 1][ca - 1] + 1 == DP[cb][ca]) {
            C[cp++] = B[cb];
            // printf("detect: %c\n", B[cb]);
            cb--; ca--;
        }
    }
    int clen = cp;
    for(int i = cp - 1; i >= 0; --i) {
        printf("%c", C[i]);
    }
    printf("\n");

    return 0;
}