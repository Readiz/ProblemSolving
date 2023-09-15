#include <stdio.h>


// 해당 셀 기준..
struct Data {
    int hNum; // 가로방향 선분 수
    int vNum; // 세로방향 선분 수
    int rStart;
    int lStart;
    int uStart;
    int dStart;
};

Data map[102][102];
int main() {
    int N, M; scanf("%d%d", &N, &M);
    for(int i = 0; i < M; ++i) {
        int a, b; char buf[2];
        scanf("%d%d%s", &a, &b, buf);
        if (buf[0] == 'R') {
            map[a][b].rStart++;
        } else if (buf[0] == 'L') {
            map[a][b].lStart++;
        } else if (buf[0] == 'U') {
            map[a][b].uStart++;
        } else {
            map[a][b].dStart++;
        }
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            map[i][j].rStart += map[i][j-1].rStart;
            map[i][j].dStart += map[i-1][j].dStart;
        }
    }
    
    for(int i = N; i >= 1; --i) {
        for(int j = N; j >= 1; --j) {
            map[i][j].lStart += map[i][j+1].lStart;
            map[i][j].uStart += map[i+1][j].uStart;
        }
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            map[i][j].hNum = map[i][j].lStart + map[i][j].rStart;
            map[i][j].vNum = map[i][j].uStart + map[i][j].dStart;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            ans += (long long)map[i][j].hNum * map[i][j].vNum;
        }
    }
    printf("%lld\n", ans);
    return 0;
}