// 적당한 그리디를 생각해보자...
// 일단 이동을 많이하는거는 무조건 손해임. 기본 점수가 소모되기 때문
// 그렇다고 너무 많이 짐을 들고 다니면 이것도 손해임
// 적당한 짐 크기를 가지고, +인 칸을 갔다가 -인 칸을 가는 것을 반복해야함.
// 2-pass로 일단 깎아봐야하나?
// 2-pass로 깎으려면 일단 경로를 매우 잘 설정해야하는데.. 음
// 그러지 말고, heap 써서 구현하자.
//  1. -가 큰 순서대로 방문한다.
//  2. -보다 큰, 혹은 안되면 제일 큰 +들을 greedy 하게 방문해서 -보다 클 때까지 반복해서 방문
//  3. -로 가면서, 남는 것은 경로에 뿌려줌. 
//   -> 좋은 greedy 인지 잘 몰겠음.


#include <assert.h>
#include <stdio.h>

#define _D(...) printf(__VA_ARGS__)
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

void moveTo(int tR, int tC) {
    while(tR < R) {
        printf("U\n");
        R--;
    }
    while(tR > R) {
        printf("D\n");
        R++;
    }
    while(tC < C) {
        printf("L\n");
        C--;
    }
    while(tC > C) {
        printf("R\n");
        C++;
    }
}

void solve() {
    R = C = 0; // 처음 위치
    Load = 0; // 화물 양
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
            Load += Map[R][C];
        } else if (Map[R][C] == 0) {
            Ans.push_back(0);
        } else {
            if (-Map[R][C] <= Load) {
                Ans.push_back(Map[R][C]);
                Load += Map[R][C];
            } else {
                Remained.push_back({R, C});
                Ans.push_back(0);
            }
        }
        move(c);
    }
    { // last
        if (Map[R][C] > 0) {
            Ans.push_back(Map[R][C]);
            Load += Map[R][C];
        } else if (Map[R][C] == 0) {
            Ans.push_back(0);
        } else {
            if (-Map[R][C] <= Load) {
                Ans.push_back(Map[R][C]);
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
                printf("+%d\n", Ans[i]);
            } else {
                printf("%d\n", Ans[i]);
            }
        }
        printf("%c\n", Way1[i]);
    }

    {
        // last
        if (Ans[399] != 0) {
            if (Ans[399] > 0) {
                printf("+%d\n", Ans[399]);
            } else {
                printf("%d\n", Ans[399]);
            }
        }
    }

    // 가까운 곳 돌자, realtime
    // _D("Remained sz: %d\n", Remained.sz);
    while (Remained.sz) {
        auto pos = Remained.pop_back();
        moveTo(pos.r, pos.c); // move with realtime
        // 이동했다.
        _A(Map[R][C] < 0);
        printf("%d\n", Map[R][C]);
    }
}

int main() {
    scanf("%d", &N);
    FOR(i,0,N) FOR(j,0,N) {
        scanf("%d", &oMap[i][j]);
    }
    solve();
    return 0;
}
