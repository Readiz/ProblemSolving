#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
bool isDebug = false;
#define _D(...)
#define MAIN_START int main(){
#define MAIN_END return 0;}

int N, M;

int MAP[1010][1010];
int visited[1010][1010];
int csum;
pair<int,int> q[10000000];
int qf, qr;
void bfs(int i, int j) {
    qf = qr = 0;
    q[qr++] = {i,j};
    while(qf != qr) {
        auto c = q[qf++];
        int i = c.first, j = c.second;
        if (i <= 0 || j <= 0 || i > N || j > M) continue;
        if (visited[i][j]) continue;
        visited[i][j] = 1;
        if (MAP[i][j] == 0) continue;
        csum += MAP[i][j];
        if (!visited[i+1][j]) q[qr++] = {i+1,j};
        if (!visited[i-1][j]) q[qr++] = {i-1,j};
        if (!visited[i][j+1]) q[qr++] = {i,j+1};
        if (!visited[i][j-1]) q[qr++] = {i,j-1};
    }
}
void solve() {
    scanf("%d %d", &N, &M);
    // _D("%d / %d\n", N, M);
    for(int i = 0; i <= N + 1; ++i) {
        for(int j = 0; j <= M + 1; ++j) {
            MAP[i][j] = visited[i][j] = 0;
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            scanf("%d", &MAP[i][j]);
        }
    }

    int cmax = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if (visited[i][j]) continue;
            csum = 0;
            bfs(i,j);
            if (csum > cmax) cmax = csum;
        }
    }
    printf("%d\n", cmax);
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
