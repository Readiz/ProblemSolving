#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int conn[101][101];
int main() {
    int N, M; scanf("%d %d", &N, &M);
    memset(conn, 0x3A, sizeof(int) * 101 * 101);
    for(int i = 1; i <= N; ++i) {
        conn[i][i] = 0;
    }

    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        conn[a][b] = 1; // 반대는 연결하지 않는다.
    }

    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if (conn[i][j] > conn[i][k] + conn[k][j]) {
                    conn[i][j] = conn[i][k] + conn[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        int cnt = 0;
        for(int j = 1; j <= N; ++j) {
            if (conn[i][j] == 0x3A3A3A3A && conn[j][i] == 0x3A3A3A3A) ++cnt;
        }
        printf("%d\n", cnt);
    }
    

    return 0;
}