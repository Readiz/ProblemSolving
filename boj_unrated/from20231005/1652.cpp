#include <stdio.h>

char map[110][110];

void dfs(int i, int j){
    if (map[i][j] == 'X' || map[i][j] == 0) return;
    map[i][j] = 'H';
    dfs(i, j + 1);
}
void dfs2(int i, int j){
    if (map[i][j] == 'X' || map[i][j] == 0) return;
    map[i][j] = 'V';
    dfs2(i + 1, j);
}

int main() {
    int N; scanf("%d", &N);

    for(int i = 1; i <= N; ++i) {
        scanf("%s", &map[i][1]);
    }
    int H = 0, V = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j){
            if (map[i][j] =='.' && map[i][j + 1] =='.') {
                dfs(i,j);
                ++H;
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j){
            if ((map[i][j] =='.' || map[i][j] == 'H') && (map[i+1][j] == '.'|| map[i+1][j] == 'H')) {
                dfs2(i,j);
                ++V;
            }
        }
    }
    printf("%d %d", H, V);

    return 0;
}