#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int MenOfPassion(int n) {
    int sum = 0;
    for (int i = 1; i <= n - 2; ++i)
    for (int j = i+1; j <= n - 1; ++j)
    for (int k = j+1; k <= n; ++k)
    sum++;
    return sum;
}

int main() {
    int N; scanf("%d", &N);

    // for(int i = 1; i <= 100; ++i) {
    //     printf("%d: %d\n", i, MenOfPassion(i));
    // }

    if (N <= 2) {
        printf("0\n3\n"); return 0;
    }
    if (N == 3) {
        printf("1\n3\n"); return 0;
    }
    
    ll sum;
    if (N % 2 == 1) {
        sum = 1;
        ll k = 3;
        for(int i = 5; i <= N; i += 2, k += 2) {
            sum += k * k;
        }
    } else {
        sum = 4;
        ll k = 4;
        for(int i = 6; i <= N; i += 2, k += 2) {
            sum += k * k;
        }
    }
    printf("%lld\n3\n", sum);

    return 0;
}