#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char board[110][110];
int ans[110][110];
int main() {
    int H, W; scanf("%d %d", &H, &W);
    memset(ans, 0xFF, sizeof(int) * 110 * 110);
    for(int i = 1; i <= H; ++i) {
        scanf("%s", &board[i][1]);
    }

    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            if (board[i][j] == 'c') ans[i][j] = 0;
            else if (ans[i][j - 1] != -1) {
                ans[i][j] = ans[i][j - 1] + 1;
            }
        }
    }

    
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}