#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 5000000;
vector<int> primes;
int sp[MAX + 1];

int main() {
    for(register int i = 2; i <= MAX; ++i) {
        if (sp[i] == 0) primes.push_back(i);
        for(auto& p: primes) {
            if (i * p > MAX) break;
            sp[i * p] = p;
            if (i % p == 0) break;
        }
    }

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int k;
        scanf("%d", &k);

        while(sp[k] != 0) {
            printf("%d ", sp[k]);
            k = k / sp[k];
        }
        printf("%d\n", k);
    }

    return 0;
}