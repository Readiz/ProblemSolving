#include <bits/stdc++.h>
using namespace std;

pair<int,int> g, p;
int MCNT[201][201];
char MDIR[201][201];
int N;

int check(int r, int c, bool visited[201][201], int v) {	
	int cnt = MCNT[r][c];
    //printf("[D] %d, %d -> %d!\n", r, c, cnt);
	
    if (MDIR[r][c] == 'R') {
        for(int i = 0; i < cnt; ++i) {
            if (visited[r][(c+1)%N] != 1) {
                c += 1;
                c += N;
                c %= N;
                ++v;

                visited[r][c] = 1;
            } else {
                return v;
            }
        }
	}
	else if (MDIR[r][c] == 'L') {
		for(int i = 0; i < cnt; ++i) {
            if (visited[r][(c-1+N)%N] != 1) {
                c -= 1;
                c += N;
                c %= N;
                ++v;

                visited[r][c] = 1;
            } else {
                return v;
            }
        }
	}
	else if (MDIR[r][c] == 'D') {
		for(int i = 0; i < cnt; ++i) {
            if (visited[(r+1)%N][c] != 1) {
                r += 1;
                r += N;
                r %= N;
                ++v;

                visited[r][c] = 1;
            } else {
                return v;
            }
        }
	}
	else if (MDIR[r][c] == 'U') {
		for(int i = 0; i < cnt; ++i) {
            if (visited[(r-1+N)%N][c] != 1) {
                r -= 1;
                r += N;
                r %= N;
                ++v;

                visited[r][c] = 1;
            } else {
                return v;
            }
        }
	}
    return check(r,c,visited,v);
}

int main() {
	scanf("%d", &N);
	int r, c; scanf("%d %d", &r, &c);
	g = {r - 1, c - 1};
	scanf("%d %d", &r, &c);
	p = {r - 1, c - 1};
	for(int r = 0; r < N; ++r) {
		for(int c = 0; c < N; ++c) {
			int cnt; char dir;
			scanf("%d%c", &cnt, &dir);
			MCNT[r][c] = cnt;
			MDIR[r][c] = dir;
		}
	}
	bool visitedg[201][201] = {false, };
    visitedg[g.first][g.second] = 1;
	int gval = check(g.first, g.second, visitedg, 1);
	bool visitedp[201][201] = {false, };
    visitedp[p.first][p.second] = 1;
	int pval = check(p.first, p.second, visitedp, 1);

    if (gval > pval) {
        printf("goorm %d\n", gval);
    } else {
        printf("player %d\n", pval);
    }
	
	return 0;
}