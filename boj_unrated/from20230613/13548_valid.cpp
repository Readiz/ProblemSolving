#include <bits/stdc++.h>
using namespace std;

int A[100'001];

int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int cnt[100001] = {0, };
        for(int i = a; i <= b; ++i) {
            cnt[A[i]]++;
        }
        sort(cnt, cnt + 100001);
        printf("%d\n", cnt[100000]);
    }

    return 0;
}