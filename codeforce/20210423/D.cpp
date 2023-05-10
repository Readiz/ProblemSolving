#include <stdio.h>
#include <queue>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;

typedef struct {
    int x;
    int y;
    int curW;
    char step;
} Node;

int n, m, k;
int w[500][500][4]; // 0: L, 1: R, 2: U, 3: D

int calcDistance(int si, int sj, int ti, int tj) {
    int a = (ti > si)? (ti - si) : (si - ti);
    int b = (tj > sj)? (tj - sj) : (sj - tj);

    return a + b;
}

std::queue<Node> q; // BFS Queue

ull BFSStart(int startY, int startX) {
    printd("BFS %d, %d started...", startY, startX);
    ull min = 0ULL;
    Node nn;
    nn.step = 0;
    nn.x = startX;
    nn.y = startY;
    nn.curW = 0;
    q.push(nn);

    while (q.size() > 0) {
        nn = q.front();
        q.pop();
        int sy = nn.y; int sx = nn.x; int sw = nn.curW; int ss = nn.step;
        // 탈출 조건들 체크
        if (ss == k) {
            if (sy == startY && sx == startX) {// 돌아왔으면..
                if (min == 0ULL || min > sw) {
                    min = sw; // 더 작은 값을 발견했으니 업데이트
                    printd("brd[%d][%d] is updated => %d", sy, sx, sw);
                } else {
                    // printd("brd[%d][%d] is not updated, curVal: %d", sy, sx, sw);
                }
            }
            continue;
        }
        // 기존에 업데이트한 w보다 초과되기 시작하면 더 볼 필요 없다.
        // printd("checking %d, %d, current weight: %d... / curMin: %llu", sy, sx, sw, min[startY][startX]);
        if (min != 0ULL && sw >= min) continue;
        // 아직 step이 남아있거나, w가 아직 업데이트 가능하면 queue에 계속 넣자..
        nn.step = ss + 1;
        if (sy > 0) {
            nn.curW = sw + w[sy][sx][2];
            nn.x = sx;
            nn.y = sy - 1;
            // 돌아올 수 있는 거리일 때만 queue에 넣는다.
            if (calcDistance(nn.y, nn.x, startY, startX) <= k - nn.step) {
                // printd("added %d, %d...", nn.y, nn.x);
                q.push(nn);
            }
        }
        if (sy < n - 1) {
            nn.curW = sw + w[sy][sx][3];
            nn.x = sx;
            nn.y = sy + 1;
            // 돌아올 수 있는 거리일 때만 queue에 넣는다.
            if (calcDistance(nn.y, nn.x, startY, startX) <= k - nn.step) {
                // printd("added %d, %d...", nn.y, nn.x);
                q.push(nn);
            }
        }
        if (sx > 0) {
            nn.curW = sw + w[sy][sx][0];
            nn.x = sx - 1;
            nn.y = sy;
            // 돌아올 수 있는 거리일 때만 queue에 넣는다.
            if (calcDistance(nn.y, nn.x, startY, startX) <= k - nn.step) {
                // printd("added %d, %d...", nn.y, nn.x);
                q.push(nn);
            }
        }
        if (sx < m - 1) {
            nn.curW = sw + w[sy][sx][1];
            nn.x = sx + 1;
            nn.y = sy;
            // 돌아올 수 있는 거리일 때만 queue에 넣는다.
            if (calcDistance(nn.y, nn.x, startY, startX) <= k - nn.step) {
                // printd("added %d, %d...", nn.y, nn.x);
                q.push(nn);
            }
        }
    }
    return min;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d %d", &n, &m, &k);
    if (k % 2 != 0) { // 홀수번인 경우 원래자리 돌아오는 것 불가능함
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                int tmp;
                scanf("%d", &tmp);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                int tmp;
                scanf("%d", &tmp);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("-1 ");
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                int tmp;
                scanf("%d", &tmp);
                w[i][j][1] = tmp;
                w[i][j + 1][0] = tmp;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                int tmp;
                scanf("%d", &tmp);
                w[i][j][3] = tmp;
                w[i + 1][j][2] = tmp;
            }
        }
        // 각 점에 대해서, BFS 연산을 시작한다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%llu ", BFSStart(i, j));
            }
            printf("\n");
        }
    }
MAIN_END
