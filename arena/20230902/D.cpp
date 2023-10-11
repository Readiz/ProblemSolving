

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char M[5001][5001];
int sx[5000], ex[5000];
int N;
int solve() {
    sx[0] = 0;
    for(int i = N - 1; i >= 0; --i) {
        if (M[0][i] == '1') {
            ex[0] = i;
            break;
        }
    }
}

char tmp[5001][5001];
void rotate() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            tmp[j][N - i - 1] = M[i][j];
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            M[i][j] = tmp[i][j];
        }
    }
}

int main() {
    scanf("%d", &N);    
    for(int i = 0; i < N; ++i) {
        scanf("%s", M[i]);
    }
    int cmin = 0x7FFFFFFF;
    for(int i = 0; i < 4; ++i) {
        cmin = min(cmin, solve());
        rotate();
    }
    // edge 확인
    printf("%d\n", cmin);
    return 0;
}