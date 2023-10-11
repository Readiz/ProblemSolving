#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;



int main() {
    int N, M; scanf("%d%d", &N, &M);
    if (N%2 == 1 && M%2 == 0) {
        printf("%d\n", M);
        for(int i = 1; M > 0; --M, i+=2) {
            printf("%d ", i);
        }
        printf("\n");
    } else if (N%2 == 0 && M%2 == 1) {
        printf("%d\n", M);
        for(int i = 2; M > 0; --M, i+=2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}