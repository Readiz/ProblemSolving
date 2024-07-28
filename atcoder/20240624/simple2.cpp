#include <assert.h>
#include <stdio.h>

#define _D(...) // printf(__VA_ARGS__)
#define _A(...) assert(__VA_ARGS__)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)

template <typename T>
struct Vector {
    T* d;
    int capa, sz;
    Vector() { d = 0; clear(); }

    void clear() {
        sz = 0;
        capa = 1;
        if (d) delete[] d;
        d = new T[capa];
    }

    void push_back(T item) {
        if (sz == capa) {
            capa <<= 1;
            T* nd = new T[capa];
            FOR(i, 0, sz) nd[i] = d[i];
            delete[] d;
            d = nd;
        }
        d[sz++] = item;
    }

    T pop_back() {
        return d[--sz];
    }

    T* begin() { return &d[0]; }
    T* end() { return &d[sz]; }
    T& operator[](int idx) {
        _A(idx >= 0 && idx < sz);
        return d[idx];
    }
};

int N;
int R, C; // truck pos
int oMap[20][20];
int Map[20][20];
int Load;
int Score;

struct Point {
    int r, c;
};

Vector<char> Way1;
Vector<int> Ans;


void move(char dir) {
    if (dir == 'R') C++;
    if (dir == 'L') C--;
    if (dir == 'U') R--;
    if (dir == 'D') R++;
}

void moveTo(int tR, int tC, bool write) {
    while(tR < R) {
        if (write) printf("U\n");
        R--;
        Score += Load + 100;
    }
    while(tR > R) {
        if (write) printf("D\n");
        R++;
        Score += Load + 100;
    }
    while(tC < C) {
        if (write) printf("L\n");
        C--;
        Score += Load + 100;
    }
    while(tC > C) {
        if (write) printf("R\n");
        C++;
        Score += Load + 100;
    }
}

int solve(bool write) {
    R = C = 0; // 처음 위치
    Load = 0; // 화물 양
    Score = 0;
    FOR(i,0,N) FOR(j,0,N) {
        Map[i][j] = oMap[i][j];
    }

    // 심플 로직
    // 좌우 BFS
    // 어차피 20 * 20 이다.
    Way1.clear();
    bool isR = true;
    FOR(i,0,20) {
        FOR(j,0,19) {
            if (isR) Way1.push_back('R');
            else Way1.push_back('L');
        }
        if (i != 19)
            Way1.push_back('D');
        isR = !isR;
    }
    _A(Way1.sz == 399);
    
    // 끝까지 이동하면서, +++ --- 하면서 간다. (중간에 채울 수 있을 만큼 채운단 뜻)
    Ans.clear();

    Vector<Point> Remained;
    for(auto& c: Way1) {
        if (Map[R][C] > 0) {
            Ans.push_back(Map[R][C]);
            Score += Map[R][C];
            Load += Map[R][C];
        } else if (Map[R][C] == 0) {
            Ans.push_back(0);
        } else {
            if (-Map[R][C] <= Load) {
                Ans.push_back(Map[R][C]);
                Score += -Map[R][C];
                Load += Map[R][C];
            } else {
                Remained.push_back({R, C});
                Ans.push_back(0);
            }
        }
        Score += Load + 100;
        move(c);
    }
    { // last
        if (Map[R][C] > 0) {
            Ans.push_back(Map[R][C]);
            Score += Map[R][C];
            Load += Map[R][C];
        } else if (Map[R][C] == 0) {
            Ans.push_back(0);
        } else {
            if (-Map[R][C] <= Load) {
                Ans.push_back(Map[R][C]);
                Score += -Map[R][C];
                Load += Map[R][C];
            } else {
                Remained.push_back({R, C});
                Ans.push_back(0);
            }
        }
    }
    _A(R == 19 && C == 0); // 마지막 종착점

    // 일단 write 한다.
    FOR(i, 0, Way1.sz) {
        if (Ans[i] != 0) {
            if (Ans[i] > 0) {
                if (write) printf("+%d\n", Ans[i]);
            } else {
                if (write) printf("%d\n", Ans[i]);
            }
        }
        if (write) printf("%c\n", Way1[i]);
    }

    {
        // last
        if (Ans[399] != 0) {
            if (Ans[399] > 0) {
                if (write) printf("+%d\n", Ans[399]);
            } else {
                if (write) printf("%d\n", Ans[399]);
            }
        }
    }

    // 가까운 곳 돌자, realtime
    // _D("Remained sz: %d\n", Remained.sz);
    while (Remained.sz) {
        auto pos = Remained.pop_back();
        moveTo(pos.r, pos.c, write); // move with realtime
        // 이동했다.
        _A(Map[R][C] < 0);
        if (write) printf("%d\n", Map[R][C]);
        Load += Map[R][C];
        Score += -Map[R][C];
    }

    _A(Load == 0);
    _D("SCORE: %d\n", Score);
    return Score;
}

int solve2(bool write) {
    R = C = 0; // 처음 위치
    Load = 0; // 화물 양
    Score = 0;
    FOR(i,0,N) FOR(j,0,N) {
        Map[i][j] = oMap[i][j];
    }

    // 심플 로직
    // 좌우 BFS
    // 어차피 20 * 20 이다.
    Way1.clear();
    bool isR = true;
    FOR(i,0,20) {
        FOR(j,0,19) {
            if (isR) Way1.push_back('D');
            else Way1.push_back('U');
        }
        if (i != 19)
            Way1.push_back('R');
        isR = !isR;
    }
    _A(Way1.sz == 399);
    
    // 끝까지 이동하면서, +++ --- 하면서 간다. (중간에 채울 수 있을 만큼 채운단 뜻)
    Ans.clear();

    Vector<Point> Remained;
    for(auto& c: Way1) {
        if (Map[R][C] > 0) {
            Ans.push_back(Map[R][C]);
            Score += Map[R][C];
            Load += Map[R][C];
        } else if (Map[R][C] == 0) {
            Ans.push_back(0);
        } else {
            if (-Map[R][C] <= Load) {
                Ans.push_back(Map[R][C]);
                Score += -Map[R][C];
                Load += Map[R][C];
            } else {
                Remained.push_back({R, C});
                Ans.push_back(0);
            }
        }
        Score += Load + 100;
        move(c);
    }
    { // last
        if (Map[R][C] > 0) {
            Ans.push_back(Map[R][C]);
            Score += Map[R][C];
            Load += Map[R][C];
        } else if (Map[R][C] == 0) {
            Ans.push_back(0);
        } else {
            if (-Map[R][C] <= Load) {
                Ans.push_back(Map[R][C]);
                Score += -Map[R][C];
                Load += Map[R][C];
            } else {
                Remained.push_back({R, C});
                Ans.push_back(0);
            }
        }
    }
    _A(R == 0 && C == 19); // 마지막 종착점

    // 일단 write 한다.
    FOR(i, 0, Way1.sz) {
        if (Ans[i] != 0) {
            if (Ans[i] > 0) {
                if (write) printf("+%d\n", Ans[i]);
            } else {
                if (write) printf("%d\n", Ans[i]);
            }
        }
        if (write) printf("%c\n", Way1[i]);
    }

    {
        // last
        if (Ans[399] != 0) {
            if (Ans[399] > 0) {
                if (write) printf("+%d\n", Ans[399]);
            } else {
                if (write) printf("%d\n", Ans[399]);
            }
        }
    }

    // 가까운 곳 돌자, realtime
    // _D("Remained sz: %d\n", Remained.sz);
    while (Remained.sz) {
        auto pos = Remained.pop_back();
        moveTo(pos.r, pos.c, write); // move with realtime
        // 이동했다.
        _A(Map[R][C] < 0);
        if (write) printf("%d\n", Map[R][C]);
        Load += Map[R][C];
        Score += -Map[R][C];
    }

    _A(Load == 0);
    _D("SCORE: %d\n", Score);
    return Score;
}

int main() {
    scanf("%d", &N);
    FOR(i,0,N) FOR(j,0,N) {
        scanf("%d", &oMap[i][j]);
    }
    int sc1 = solve(false);
    int sc2 = solve2(false);
    if (sc1 < sc2) {
        solve(true);
    } else {
        solve2(true);
    }
    return 0;
}
