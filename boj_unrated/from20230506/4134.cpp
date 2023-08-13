#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; scanf("%d", &N);

    long long p;
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &p);
        if (p < 2) {
            printf("2\n");
            continue;
        }

        while(true) {
            bool isPrime = true;
            for(long long k = 2; k * k <= p; ++k) {
                if (p % k == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) break;
            ++p;
        }
        printf("%lld\n", p);
    }
    return 0;
}