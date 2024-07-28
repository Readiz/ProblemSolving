#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif

int main() {
    int N; scanf("%d", &N);
    long long one = 0, two = 0;
    for(int i=0;i<N;++i) {
        int tmp; scanf("%d", &tmp);
        long long a = tmp / 2;
        long long b = tmp % 2;
        two += a; one += b;
    }
    _D("%lld %lld\n", two, one);
    if (two >= one) two -= one, one = 0;
    long long h = 1LL << 40;
    while (two > one) {
        long long amount = two / 3;
        if (amount == 0) break;
        two %= 3;
        two = amount + two;
        one = amount;
        _D("%lld %lld\n", two, one);
        two -= one, one = 0;
    }

    // while (one - two >= 2) {
    //     one -= 2;
    //     two++;
    //     _D("%lld %lld\n", two, one);
    // }

    if (one == two) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }


    return 0;
}