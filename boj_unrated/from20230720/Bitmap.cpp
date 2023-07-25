#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Data {
    int x, y, dist;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int M[200][200];
constexpr int INF = 987654321;

char buf[200][200];
char visited[200][200];
int main() {
    int R, C; scanf("%d %d", &R, &C);
    
    for(int r = 0; r < R; ++r) {
        scanf("%s", buf[r]);
    }

    for(int r = 0; r <= R+1; ++r) {
        for(int c = 0; c <= C+1; ++c) {
            M[r][c] = 0;
            visited[r][c] = 1;
        }
    }
    
    queue<Data> q;

    for(int r = 1; r <= R; ++r) {
        for(int c = 1; c <= C; ++c) {
            M[r][c] = buf[r-1][c-1];
            visited[r][c] = 0;
            if (M[r][c] == '0') M[r][c] = INF;
            else {
                M[r][c] = 0;
                visited[r][c] = 1;
                for(int i = 0; i < 4; ++i) {
                    q.push(Data{c + dx[i], r + dy[i], 1});
                }
            }
        }
    }
    while(q.size()) {
        Data cur = q.front(); q.pop();
        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = 1;
        M[cur.y][cur.x] = cur.dist;
        for(int i = 0; i < 4; ++i) {
            q.push(Data{cur.x + dx[i], cur.y + dy[i], cur.dist + 1});
        }
    }

    for(int r = 1; r <= R; ++r) {
        for(int c = 1; c <= C; ++c) {
            printf("%d ", M[r][c]);
        }
        printf("\n");
    }

    return 0;
}