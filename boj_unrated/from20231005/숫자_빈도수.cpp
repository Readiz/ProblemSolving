#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int cnt;
int M;
void check(int v) {
    while(v) {
        if (v % 10 == M) ++cnt;
        v /= 10;
    }
}

int main() {
    int N; scanf("%d %d", &N, &M);

    for(int i = N; i >= 1; --i) {
        check(i);
    }

    printf("%d\n", cnt);

    return 0;
}