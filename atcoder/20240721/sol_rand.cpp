#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
bool isDebug = true;
#else
#define _D(...)
bool isDebug = false;
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int N, M, T;
int CurTurn;
int C;

struct Seed_t {
    int M[15];
    double score;
    bool used;
} Seed[1000];

int Order[1000];

void sort(int s, int e) {
    if (s >= e) return;

    int l = s, r = e, m = (s+e)>>1;
    double pivot = Seed[Order[m]].score;
    
    while(l < r) {
        while(Seed[Order[l]].score > pivot) ++l;
        while(pivot > Seed[Order[r]].score) --r;
        if (l > r) break;
        swap(Order[l], Order[r]);
        ++l; --r;
    }

    sort(s, r); sort(l, e);
}

int Plant[6][6];
Seed_t Nxt_Seed[1000];

bool isFirst = true;
void Get(int i, int j) {
    if (isDebug && !isFirst) {
        Seed[i].M[j] = Nxt_Seed[i].M[j];
        return;
    }
    scanf("%d", &Seed[i].M[j]);
}
int gidx;
void Generate() {
    gidx = 0;
    // 좌우
    char buf[20];
    FOR(i,0,N) FOR(j,0,N-1) {
        scanf("%s", buf);
        _D("#");
        FOR(k,0,M) {
            if (buf[k] == '0') {
                Nxt_Seed[gidx].M[k] = Seed[Plant[i][j]].M[k];
            } else {
                Nxt_Seed[gidx].M[k] = Seed[Plant[i][j+1]].M[k];
            }
            _D("%d ", Nxt_Seed[gidx].M[k]);
        }
        ++gidx;
        _D("\n");
    }
    // 상하
    FOR(i,0,N-1) FOR(j,0,N) {
        scanf("%s", buf);
        _D("#");
        FOR(k,0,M) {
            if (buf[k] == '0') {
                Nxt_Seed[gidx].M[k] = Seed[Plant[i][j]].M[k];
            } else {
                Nxt_Seed[gidx].M[k] = Seed[Plant[i+1][j]].M[k];
            }
            _D("%d ", Nxt_Seed[gidx].M[k]);
        }
        ++gidx;
        _D("\n");
    }
}

int BaseScore;
void GetBaseScore() {
    BaseScore = 0;
    FOR(k,0,M) {
        int maxval = 0;
        FOR(i,0,C) {
            if (Seed[i].M[k] > maxval) maxval = Seed[i].M[k];
        }
        BaseScore += maxval;
    }
}

void In() {
    if (!isFirst && isDebug) Generate();

    double coeff = -0.25 * CurTurn + 3;
    FOR(i,0,C) {
        double s = 0;
        FOR(j,0,M) {
            Get(i,j);
            s += pow(Seed[i].M[j], coeff);
        }
        Seed[i].score = s;
    }

    if (isFirst) {
        GetBaseScore();
        isFirst = false;
    }
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
double GetSingleScore(int r, int c) {
    double ret = 0;
    double coeff = -0.25 * CurTurn + 3;
    FOR(p,0,4) {
        int tr = r + dr[p];
        int tc = c + dc[p];

        FOR(k,0,M) {
            // ret += pow(double(Seed[Plant[tr][tc]].M[k] + Seed[Plant[r][c]].M[k]) / 2, coeff);
            ret += double(Seed[Plant[tr][tc]].M[k] + Seed[Plant[r][c]].M[k]);
        }
    }

    return ret;
}

struct Coord_t {
    int r, c;
} Coord[1000];
Coord_t Center;
int COrder[1000];
int CKey[1000];

void csort(int s, int e) {
    if (s >= e) return;

    int l = s, r = e, m = (s+e)>>1;
    int pivot = CKey[COrder[m]];
    
    while(l < r) {
        while(CKey[COrder[l]] < pivot) ++l;
        while(pivot < CKey[COrder[r]]) --r;
        if (l > r) break;
        swap(COrder[l], COrder[r]);
        ++l; --r;
    }

    csort(s, r); csort(l, e);
}

int seed = 5;
unsigned int prand() {
    seed = 214013 * seed + 2531011;
    return (seed >> 16) & 0x7FF;
}
void Out() {
    FOR(i,0,C) Order[i] = i, Seed[i].used = false;
    sort(0,C - 1);

    int idx = 0;
    FOR(z,0,N*N) {
        int i = COrder[z];
        Seed[Order[idx]].used = true;
        Plant[Coord[i].r][Coord[i].c] = Order[idx++];
    }


    // 랜덤스왑 시작
    if (CurTurn == T - 1) {
        int swapcnt = 0;
        FOR(r,0,1'000'000) {
            int ar = (prand() % (N - 1)) + 1;
            int ac = (prand() % (N - 1)) + 1;
            int t = (prand()) % C;
            if (Seed[t].used) continue;

            int old = Plant[ar][ac];
            double before = GetSingleScore(ar, ac);
            Plant[ar][ac] = t;
            double after = GetSingleScore(ar, ac);
            
            if (before < after) {
                // swap!
                _D("#before: %lf / after: %lf\n", before, after);
                Seed[Plant[ar][ac]].used = true;
                Seed[old].used = false;
                ++swapcnt;
            } else {
                // no!
                Plant[ar][ac] = old;
            }
        }

        // 랜덤스왑 끝
        _D("#swap: %d\n", swapcnt);
    }

    FOR(i,0,N) {
        FOR(j,0,N) {
            printf("%d ", Plant[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
}

void GetScore() {
    int maxval = 0;
    FOR(i,0,C) {
        int curScore = 0;
        FOR(k,0,M) {
            curScore += Seed[i].M[k];
        }
        if (curScore > maxval) maxval = curScore;
    }
    _D("#Base: %d\n", BaseScore);
    _D("#Max: %d\n", maxval);
    _D("#%.0lf\n", round((double)maxval * 1'000'000 / BaseScore));
}

int main() {
    isFirst = true;
    scanf("%d %d %d", &N, &M, &T);
    C = 2 * N * (N - 1); // 60

    Center = {N / 2, N / 2};
    FOR(i,0,N) FOR(j,0,N) {
        COrder[i*N+j] = i*N+j;
        CKey[i*N+j] = abs(i - Center.r) + abs(j - Center.c);
        Coord[i*N+j] = {i, j};
    }
    csort(0,N*N-1);
    
    FOR(i,0,N*N) {
        _D("#[%d] %d, %d\n", i, Coord[COrder[i]].r, Coord[COrder[i]].c);
    }

    FOR(i,0,T) {
        _D("#Turn %d\n", i);
        CurTurn = i;
        In();
        Out();
        GetScore();
    }
    In(); // We can use it to evalute score
    GetScore();

    return 0;
}