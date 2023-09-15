#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int T, W; scanf("%d%d", &T, &W);
    vector<int> t(T+1);
    for(int i = 1; i <= T; ++i) scanf("%d", &t[i]);
    
    int DP[1001][31] = {0, }; // t 시간에서 w 만큼 이동했을 때 받아먹을 수 있는 자두의 최대의 수
    int maxVal = 0;
    for(int i = 1; i <= T; ++i) {
        for(int j = W; j >= 0; --j) {
            // j: 이동 횟수
            // j: 0, 2, ... : 1번 나무에 있다
            //  : 1, 3, ... : 2번 나무에 있다.
            if (j == 0) {
                DP[i][j] = DP[i - 1][j] + (t[i] == 1);
            } else {
                if (j % 2 == 0) {
                    DP[i][j] = max(DP[i - 1][j] + (t[i] == 1), DP[i - 1][j - 1] + (t[i] == 1));
                } else {
                    DP[i][j] = max(DP[i - 1][j] + (t[i] == 2), DP[i - 1][j - 1] + (t[i] == 2));
                }
            }
            maxVal = max(maxVal, DP[i][j]);
        }
    }
    printf("%d\n", maxVal);

    // for(int i = 1; i <= T; ++i) {
    //     printf("[%d] %d %d %d\n",i, DP[i][0],DP[i][1],DP[i][2]);
    // }
    return 0;
}