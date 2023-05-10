#include <bits/stdc++.h>
using namespace std;

int v[100][100];
int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = a; i < a + 10; ++i) {
            for(int j = b; j < b + 10; ++j) {
                v[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            if (v[i][j]) ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}