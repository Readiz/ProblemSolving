// 2D Fenwick 연습
// https://nahwasa.com/entry/%ED%8E%9C%EC%9C%85-%ED%8A%B8%EB%A6%ACFenwick-tree-BIT-%EA%B8%B0%EB%B3%B8-2D-lazy-propagationrange-update-point-query-range-update-range-query

#include <bits/stdc++.h>
using namespace std;

int A[1025][1025]; // origin
int N;
struct Fenwick2D {
    int d[1025][1205];
    void update(int r, int c, int diff) {
        for(; r <= N; r += r & -r) {
            int cc = c;
            for(; cc <= N; cc += cc & -cc) {
                d[r][cc] += diff;
            }
        }
    }
    int get(int r, int c) {
        int res = 0;
        for(; r > 0; r -= r & -r) {
            int cc = c;
            for(; cc > 0; cc -= cc & -cc) {
                res += d[r][cc];
            }
        }
        return res;
    }
} f;

int main() {
    int M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &A[i][j]);
            f.update(i, j, A[i][j]);
        }
    }
    for(int q = 0; q < M; ++q) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 0) {
            int r, c, v;
            scanf("%d %d %d", &r, &c, &v);
            int diff = v - A[r][c];
            A[r][c] = v;
            f.update(r, c, diff);
        } else {
            int r1, c1, r2, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            printf("%d\n", f.get(r2, c2) - f.get(r2, c1-1) - f.get(r1-1, c2) + f.get(r1-1, c1-1));
        }
    }
    return 0;
}