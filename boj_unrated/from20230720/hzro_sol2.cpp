#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

constexpr int POINT_MAX = 500;
constexpr int AXIS_MAX = 2010;
constexpr int LEVEL_MAX = 31;

/*
$A (x-1,y)$ 
$Q (x-1,y+1)$ 
$W (x,y+1)$ 
$E (x+1,y+1)$ 
$D (x+1,y)$ 
$C (x+1,y-1)$ 
$X (x,y-1)$ 
$Z (x-1,y-1)$ */
enum MOVE {
A,Q,W,E,D,C,X,Z
};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char dirToChar[9] = "AQWEDCXZ";

struct RawPoint {
    int x, y;
};
struct Point {
    RawPoint curPos;
    vector<MOVE> history;
} p[POINT_MAX];
int NUM_POINTS;

Point* M[AXIS_MAX][AXIS_MAX];

int getCurArea(Point& p) {
    if (p.curPos.x >= 0 && p.curPos.y > 0) return 1;
    if (p.curPos.x < 0 && p.curPos.y >= 0) return 2;
    if (p.curPos.x <= 0 && p.curPos.y < 0) return 3;
    if (p.curPos.x > 0 && p.curPos.y <= 0) return 4;
}

int mapToIdx(int x) {
    return x + 1001;
}

void moveAround(Point& p) {
    // M에서 기존 좌표 삭제 필요
    // history 업데이트 필요
    // 얘는 방문체크 필요없음
    // 시계방향으로 돌린다.
    M[mapToIdx(p.curPos.y)][mapToIdx(p.curPos.x)] = 0;

    int nx = -999999, ny = -999999;
    MOVE history;
    switch(getCurArea(p)) {
        case 1:
        // 1사분면, 우하단 이동
        nx = p.curPos.x + 1;
        ny = p.curPos.y - 1;
        history = C;
        break;
        case 2:
        // 2사분면, 우상단 이동
        nx = p.curPos.x + 1;
        ny = p.curPos.y + 1;
        history = E;
        break;
        case 3:
        // 3사분면, 좌상단 이동
        nx = p.curPos.x - 1;
        ny = p.curPos.y + 1;
        history = Q;
        break;
        case 4:
        // 4사분면, 좌하단 이동
        nx = p.curPos.x - 1;
        ny = p.curPos.y - 1;
        history = Z;
        break;
    }

    M[mapToIdx(ny)][mapToIdx(nx)] = &p;
    p.curPos.x = nx; p.curPos.y = ny;
    p.history.push_back(history);
}

bool moveIn(Point& p) { // 안으로 들어갈 수 있으면..
    // 2칸 들어가는거 아님, 1칸임
    // M에서 기존 좌표 삭제 필요!
    // 들어갔으면 true 리턴

    int nx = -999999, ny = -999999;
    MOVE history;
    switch(getCurArea(p)) {
        case 1:
        // 1사분면, 좌측 / 하단 중 택 1
        if (p.curPos.x != 0 && M[mapToIdx(p.curPos.y)][mapToIdx(p.curPos.x - 1)] == 0) {
            nx = p.curPos.x - 1;
            ny = p.curPos.y;
            history = A;
        } else if (M[mapToIdx(p.curPos.y - 1)][mapToIdx(p.curPos.x)] == 0) {
            nx = p.curPos.x;
            ny = p.curPos.y - 1;
            history = X;
        }
        break;
        case 2:
        // 2사분면, 우측 / 하단 택 1
        if (p.curPos.x != 0 && M[mapToIdx(p.curPos.y)][mapToIdx(p.curPos.x + 1)] == 0) {
            nx = p.curPos.x + 1;
            ny = p.curPos.y;
            history = D;
        } else if (M[mapToIdx(p.curPos.y - 1)][mapToIdx(p.curPos.x)] == 0) {
            nx = p.curPos.x;
            ny = p.curPos.y - 1;
            history = X;
        }
        break;
        case 3:
        // 3사분면, 우측 / 상단 택 1
        if (p.curPos.x != 0 && M[mapToIdx(p.curPos.y)][mapToIdx(p.curPos.x + 1)] == 0) {
            nx = p.curPos.x + 1;
            ny = p.curPos.y;
            history = D;
        } else if (M[mapToIdx(p.curPos.y + 1)][mapToIdx(p.curPos.x)] == 0) {
            nx = p.curPos.x;
            ny = p.curPos.y + 1;
            history = W;
        }
        break;
        case 4:
        // 4사분면, 좌측 / 상단 택 1
        if (p.curPos.x != 0 && M[mapToIdx(p.curPos.y)][mapToIdx(p.curPos.x - 1)] == 0) {
            nx = p.curPos.x - 1;
            ny = p.curPos.y;
            history = A;
        } else if (M[mapToIdx(p.curPos.y + 1)][mapToIdx(p.curPos.x)] == 0) {
            nx = p.curPos.x;
            ny = p.curPos.y + 1;
            history = W;
        }
        break;
    }

    if (ny != -999999 && nx != -999999) {    
        M[mapToIdx(p.curPos.y)][mapToIdx(p.curPos.x)] = 0;
        M[mapToIdx(ny)][mapToIdx(nx)] = &p;
        p.curPos.x = nx; p.curPos.y = ny;
        p.history.push_back(history);
        return true;
    }
    else return false;
}

struct Level {
    //set<Point*, cmp> points;
    vector<Point*> points;
    int capa;
} level[LEVEL_MAX];

int getDist(RawPoint& p) {
    return abs(p.x) + abs(p.y);
}

void getInput() {
    scanf("%d", &NUM_POINTS);
    _D("N: %d\n", NUM_POINTS);
    for(int i = 0; i < NUM_POINTS; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        p[i].curPos = {x, y};
        M[mapToIdx(y)][mapToIdx(x)] = &p[i];
        _D("%d, %d\n", p[i].curPos.x, p[i].curPos.y);
    }
}
void assignLevel() {
    _D("N: %d\n", NUM_POINTS);
    
    for(int i = 0; i < NUM_POINTS; ++i) {
        int cLevel = getDist(p[i].curPos);
        _D("dist: %d\n", cLevel);
        level[cLevel].points.push_back(&p[i]);
    }
    for(int i = 0; i < LEVEL_MAX; ++i) {
        level[i].capa = (i+1)*(i+1);
    }
}

int getRemainCnt() {
    int ret = 0;
    for(int i = 1; i < LEVEL_MAX; ++i) {
        // if (level[i].points.size() > 0) _D("[LEVEL %d] size: %d\n", i, level[i].points.size());
        ret += level[i].points.size();
    }
    return ret;
}

int main() {
    freopen("hzro_input.txt", "r", stdin);
    
    getInput();
    assignLevel();

    while(getRemainCnt() > 0) {
        _D("[REMAINED] CNT: %d\n", getRemainCnt());
        for(int i = 1; i < LEVEL_MAX; ++i) { // 안쪽 레벨부터 탐색
            if (level[i-1].points.size() < level[i-1].capa) {
                for(auto it = level[i].points.begin(); it != level[i].points.end(); ) {
                    auto& cp = *it;
                    _D("Checking %d, %d...\n", cp->curPos.x, cp->curPos.y);
                    bool ret = moveIn(*cp);
                    if (ret) {
                        _D("  -> Moved! %d, %d...\n", cp->curPos.x, cp->curPos.y);
                        // level에서 삭제, 아래 레벨로 이동
                        level[i - 1].points.push_back(cp);
                        // it = level[i].points.erase(it);
                        break; // 하나만 내린다.
                    }
                }
            }
            for(auto it = level[i].points.begin(); it != level[i].points.end(); ++it) {
                auto& cp = *it;
                // moveAround(*cp);
                // 둥글게둥글게~
            }
        }

        level[0].points.clear(); // 하나 있는거 제거한다.
        M[mapToIdx(0)][mapToIdx(0)] = 0;
    }

    for(int i = 0; i < NUM_POINTS; ++i) {
        for(auto& d: p[i].history) {
            printf("%c", dirToChar[d]);
        }
        printf("\n");
    }

    return 0;
}
