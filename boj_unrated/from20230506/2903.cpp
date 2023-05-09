#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int pow = 1;
    for (int i = 1; i <= N; ++i)
        pow <<= 1;

    printf("%d\n", (1 + pow) * (1 + pow));
    return 0;
}