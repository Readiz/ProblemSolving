#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; scanf("%d", &N);
    int A; scanf("%d", &A);
    for(int i = 1; i < N; ++i) {
        int B; scanf("%d", &B);
        int g = __gcd(A, B);
        printf("%d/%d\n", A / g, B / g);
    }

    return 0;
}