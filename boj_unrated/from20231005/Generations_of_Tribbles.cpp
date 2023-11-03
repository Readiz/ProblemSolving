#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// n < 2 :                         1
// n = 2 :                         2
// n = 3 :                         4
// n > 3 : koong(n − 1) + koong(n − 2) + koong(n − 3) + koong(n − 4)
int main() {
    int N; scanf("%d", &N);
    ll fib[68] = {1, 1, 2, 4, };
    for(int i = 4; i <= 67; ++i) fib[i] = fib[i-1] + fib[i-2] + fib[i-3] + fib[i-4];
    for(int i = 0; i < N; ++i) {
        int idx; scanf("%d", &idx);
        printf("%lld\n", fib[idx]);
    }   

    return 0;
}