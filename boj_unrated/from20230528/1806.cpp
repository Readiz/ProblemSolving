#include <bits/stdc++.h>
using namespace std;

long long A[100000];
int main() {
    int N; long long S; scanf("%d %lld", &N, &S);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    int l = 0, r = 0; int len = 1;
    int minLen = 99999999;
    long long cSum = A[0];
    while(true) {
        // printf("%d %d %lld\n", l, r, cSum);
        if (cSum >= S && len < minLen) minLen = len;
        if (cSum < S || l >= r) {
            cSum += A[++r];
            len++;
            if (r >= N) break;
        } else {
            cSum -= A[l++];
            len--;
        }
    }
    if (cSum >= S && len < minLen) minLen = len;
    if (minLen == 99999999) printf("0\n");
    else printf("%d\n", minLen);
    return 0;
}