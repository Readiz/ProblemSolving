#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int L[21], J[21];
int main() {
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &L[i]);
    for(int i = 0; i < N; ++i) scanf("%d", &J[i]);
    
    int tmask = 1 << N;
    int maxjoy = 0;
    for(int cur = 0; cur < tmask; ++cur) {
        int clife = 100;
        int cjoy = 0;
        for(int p = 1, i = 0; i < N; ++i, p <<= 1) {
            if (p & cur) {
                clife -= L[i];
                cjoy += J[i];
            }
        }
        if (clife > 0) {
            if (cjoy > maxjoy) maxjoy = cjoy;
        }
    }
    printf("%d\n", maxjoy);
    return 0;
}