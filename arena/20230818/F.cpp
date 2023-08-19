#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, K; scanf("%d %d", &N, &K);
    vector<int> v; v.resize(N);
    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (v[i] > v[j]) {
                v[i] ^= v[j] ^= v[i] ^= v[j];
                ++cnt;
            }
        }
    }
    if (cnt % 2 == 1) {
        printf("Minchan\n");
    } else {
        printf("Junee\n");
    }
    return 0;
}