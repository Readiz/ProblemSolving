// 1. 빨리 돌아가는 전략이 유효 함. (애매하게 시간 끌면 쓰레기 더 쌓임)
// 2. 지도의 일부가 더러워 지는 것. 그 일부 주변이 같이 더러워지는 경향
//   > 이쪽을 두번?? 근데 그래봐야 평균이 빠르게 오른다..


#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)

int N, r, c;

struct Board {
    int b[40][40];

    int (& operator[] (size_t i))[40] {
        return b[i];
    }

    void clear() {
        FOR(i,0,N) FOR(j,0,N) b[i][j] = 0;
    }
};

Board T; // 목표로 하는 board: for test, set 1

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0}; // R, D, L, U
char dToChar[5] = "RDLU";

Board ForbidH, ForbidV;
Board DirtyUnit, Dirty;
Board Cnt;

struct Operation {
    size_t sz;
    int dir[4];
} op[40][40]; // i, j에서 이동 가능한 방향

// 차이가 작을 수록 좋다.
int _evaluate(Board& C) {
    int score = 0;

    FOR(i,0,N) {
        FOR(j,0,N) {
            if (T[i][j] > C[i][j]) {
                score += T[i][j] - C[i][j];
            }
            if (C[i][j] == 0) {
                // Add panelty
                score += 10000;
            }
        }
    }

    return score;
}

void tick(int t = 1) {
    FOR(i,0,N) FOR(j,0,N) {
        Dirty[i][j] += t * DirtyUnit[i][j];
        // Dirty[i][j] = min(Dirty[i][j], 100000);
    }
}

int dist(int sr, int sc, int er, int ec) {
    return abs(sr - er) + abs(sc - ec);
}
ll evaluate(vector<int>& cPath) {
    Dirty.clear();

    int r = 0, c = 0;
    // 경로를 찾았으니 스코어 예측을 해보자
    _D("Path Length: %d\n", cPath.size());
    for(auto& d: cPath) {
        tick();
        r += dr[d];
        c += dc[d];
        Dirty[r][c] = 0;
    }
    _D("Start L at %d, %d...\n", r, c);
    assert(r == 0 && c == 0);
    ll score = 0;
    for(auto& d: cPath) { // L ~ 2L - 1
        FOR(i,0,N) FOR(j,0,N) {
            score += Dirty[i][j];
        }

        tick();
        r += dr[d];
        c += dc[d];
        Dirty[r][c] = 0;
    }
    ll eScore = score / cPath.size();
    _D("Expected Score: %lld\n", eScore);
    return eScore;
}


struct QData {
    int r, c;
    vector<int> path;
} q[1000000];
int qf, qr;
int visited[40][40];
int vbase;
vector<int> getPath(int sr, int sc, int er, int ec) {
    ++vbase;

    qf = qr = 0;
    q[qr] = {sr, sc, {}};
    q[qr++].path = {};

    while(qf != qr) {
        auto& cur = q[qf++];

        if (visited[cur.r][cur.c] == vbase) continue;
        visited[cur.r][cur.c] = vbase;
        if(cur.r == er && cur.c == ec) return cur.path;

        size_t sz = op[cur.r][cur.c].sz;
        for(int i = 0; i < sz; ++i) {
            int dir = op[cur.r][cur.c].dir[i];
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];
            if (visited[nr][nc] == vbase) continue;
            
            q[qr] = {nr, nc, {}};
            q[qr].path = cur.path;
            q[qr++].path.push_back(dir);
        }
    }
    return {};
}

vector<int> gPath;

bool goNextNearest(int sr, int sc) {
    if (Cnt[sr][sc] == 0) return true;

    ++vbase;

    qf = qr = 0;
    q[qr] = {sr, sc, {}};
    q[qr++].path = {};

    while(qf != qr) {
        auto& cur = q[qf++];

        if (visited[cur.r][cur.c] == vbase) continue;
        visited[cur.r][cur.c] = vbase;

        if (Cnt[cur.r][cur.c] == 0) { // 제일 가까운 한번도 방문 안한 곳
            for(auto& i: cur.path) {
                gPath.push_back(i);
            }
            r = cur.r;
            c = cur.c;
            return true;
        }

        size_t sz = op[cur.r][cur.c].sz;
        for(int i = 0; i < sz; ++i) {
            int dir = op[cur.r][cur.c].dir[i];
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];
            if (visited[nr][nc] == vbase) continue;
            
            q[qr] = {nr, nc, {}};
            q[qr].path = cur.path;
            q[qr++].path.push_back(dir);
        }
    }
    return false; // 더이상 갈곳 없음
}

bool dfs(int rr, int cc) {
    r = rr; c = cc;
    Cnt[r][c]++;
    size_t sz = op[r][c].sz;

    for(int k = 0; k < sz; ++k) {
        int nr = r + dr[op[r][c].dir[k]];
        int nc = c + dc[op[r][c].dir[k]];
        if (Cnt[nr][nc] == 0) {
            gPath.push_back(op[r][c].dir[k]);
            dfs(nr, nc);
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &N);
    char buf[50][50];
    
    FOR(i,0,N-1) scanf("%s", buf[i]);
    FOR(i,0,N-1) FOR(j,0,N) ForbidH[i][j] = (buf[i][j] == '0') ? 0 : 1;
    FOR(i,0,N) scanf("%s", buf[i]);
    FOR(i,0,N) FOR(j,0,N-1) ForbidV[i][j] = (buf[i][j] == '0') ? 0 : 1;
    FOR(i,0,N) FOR(j,0,N) {
        int c; scanf("%d", &c);
        DirtyUnit[i][j] = c;
    }
    
    FOR(i,0,N) FOR(j,0,N) {
        // op 업데이트 시작
        bool R = true, L = true, U = true, D = true;
        if (i == 0) U = false;
        if (j == 0) L = false;
        if (i == N - 1) D = false;
        if (j == N - 1) R = false;

        if (R && ForbidV[i][j] == 1) R = false;
        if (L && ForbidV[i][j - 1] == 1) L = false;
        if (D && ForbidH[i][j] == 1) D = false;
        if (U && ForbidH[i - 1][j] == 1) U = false;

        size_t& sz = op[i][j].sz;
        if (R) op[i][j].dir[sz++] = 0;
        if (D) op[i][j].dir[sz++] = 1;
        if (L) op[i][j].dir[sz++] = 2;
        if (U) op[i][j].dir[sz++] = 3;
    }
    
    // 전략 1: dfs + bfs
    ll minScore = 0x7FFFFFFFFFFFFFFF;
    vector<int> ansPath;
    {
        gPath.clear();
        Cnt.clear();

        r = 0, c = 0;
        while (true) {
            bool ret = goNextNearest(r, c);
            if (ret == false) break;
            dfs(r, c); // 아직 안간 곳중 제일 깊은 경로 탐색            
        }

        // move to 원점
        if (r != 0 || c != 0) {
            vector<int> res = getPath(r, c, 0, 0);
            for(auto& item: res) {
                gPath.push_back(item);
            }
        }

        ll score = evaluate(gPath);
        if (score < minScore) {
            minScore = score;
            ansPath = gPath;
        }
    }


    // 전략 2: dfs 방문 순서를 반대로
    {
        FOR(i,0,N) FOR(j,0,N) {
            size_t sz = op[i][j].sz;
            int l = 0, r = sz - 1;
            while(l < r) {
                int tmp = op[i][j].dir[l];
                op[i][j].dir[l] = op[i][j].dir[r];
                op[i][j].dir[r] = tmp;
                ++l; --r;
            }
        }

        gPath.clear();
        Cnt.clear();

        r = 0, c = 0;
        while (true) {
            bool ret = goNextNearest(r, c);
            if (ret == false) break;
            dfs(r, c); // 아직 안간 곳중 제일 깊은 경로 탐색            
        }

        // move to 원점
        if (r != 0 || c != 0) {
            vector<int> res = getPath(r, c, 0, 0);
            for(auto& item: res) {
                gPath.push_back(item);
            }
        }
        ll score = evaluate(gPath);
        if (score < minScore) {
            minScore = score;
            ansPath = gPath;
        }
    }


    // 전략 3: 랜덤스왑??? 특정지역 우선 방문??
    {
        // gPath.clear();
        // Cnt.clear();

        // r = 0, c = 0;


        // move to 원점
        // if (r != 0 || c != 0) {
        //     vector<int> res = getPath(r, c, 0, 0);
        //     for(auto& item: res) {
        //         gPath.push_back(item);
        //     }
        // }
        // int score = evaluate(gPath);
        // if (score < minScore) {
        //     minScore = score;
        //     ansPath = gPath;
        // }
    }

    _D("%lld\n", minScore);


#ifdef ONLINE_JUDGE
    for(auto& item: ansPath) {
        printf("%c", dToChar[item]);
    }
    printf("\n");
#endif

    return 0;
}