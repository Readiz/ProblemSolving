#include <bits/stdc++.h>
using namespace std;

int N, M;
struct Pos {
    int r, c;

    bool operator==(const struct Pos& t) const {
        return r == t.r && c == t.c;
    }
    bool operator!=(const struct Pos& t) const {
        return !(*this == t);
    }
    bool operator<(const struct Pos& t) const {
        if (r != t.r) return r < t.r;
        return c < t.c;
    }
};

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

struct Board {
    char data[11][11];
    Pos R, B, O;
    char(& operator[](int idx))[11] {
        return data[idx];
    }

    bool operator<(const struct Board& t) const {
        if (R != t.R) return R < t.R;
        return B < t.B;
    }

    bool move(int dr, int dc) {
        Pos oR = R, oB = B;
        Pos nR = R, nB = B;
        do {
            R = nR, B = nB;
            nB.r += dr; nB.c += dc;
            if (data[nB.r][nB.c] == 'O') {
                data[B.r][B.c] = '.';
                data[R.r][R.c] = '.';
                B = oB, R = oR;
                data[B.r][B.c] = 'B';
                data[R.r][R.c] = 'R';
                return false;
            }
            if (data[nB.r][nB.c] != '.') nB = B;

            nR.r += dr; nR.c += dc;
            if (data[nR.r][nR.c] == 'O') {
                data[R.r][R.c] = '.';

                // B check
                if (nB == B) nB.r += dr, nB.c += dc; // R에 막혔을 ㄸ
                while(data[nB.r][nB.c] == '.') {
                    nB.r += dr; nB.c += dc;
                }
                if (data[nB.r][nB.c] == 'O') {
                    data[B.r][B.c] = '.';
                    data[R.r][R.c] = '.';
                    B = oB, R = oR;
                    data[B.r][B.c] = 'B';
                    data[R.r][R.c] = 'R';
                    return false;
                }
                // B가 안빠지면 true.
                return true;
            }
            if (data[nR.r][nR.c] != '.') nR = R;

            data[R.r][R.c] = '.';
            data[B.r][B.c] = '.';
            data[nR.r][nR.c] = 'R';
            data[nB.r][nB.c] = 'B';
        } while (nR != R || nB != B); // 그 방향으로 갈 수 있을 때까지 간다.
        return false;
    }
} ori;

struct QData {
    int step;
    Board b;
} q[100000];
int qf, qr;

set<Board> visited;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        scanf("%s", ori[i]);
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if (ori[i][j] == 'R') ori.R.r = i, ori.R.c = j;
            if (ori[i][j] == 'B') ori.B.r = i, ori.B.c = j;
            if (ori[i][j] == 'O') ori.O.r = i, ori.O.c = j;
        }
    }

    // printf("[d] %d, %d / %d, %d / %d, %d\n", ori.R.r, ori.R.c, ori.B.r, ori.B.c, ori.O.r, ori.O.c);
    qf = qr = 0;
    q[qr++] = {0};
    q[qr-1].b = ori;

    while(qf != qr) {
        auto& cur = q[qf++];
        if (visited.find(cur.b) != visited.end()) continue;
        visited.insert(cur.b);
        if (cur.step >= 10) break;
        // printf("[d] check step %d...\n", cur.step);

        for(int p = 0; p < 4; ++p) {
            // printf("[d] p: %d\n", p);
            Board cpy = cur.b;
            bool ret = cpy.move(dr[p], dc[p]);
            if (ret == false) {
                if (visited.find(cpy) != visited.end()) continue;
                q[qr++] = {cur.step + 1};
                q[qr-1].b = cpy;
            } else {
                printf("%d\n", cur.step + 1);
                return 0;
            }
        }
    }
    printf("-1\n");

    return 0;
}