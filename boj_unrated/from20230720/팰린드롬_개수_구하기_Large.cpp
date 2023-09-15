#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    char str[1001]; scanf("%s", str);
    int len = strlen(str);

    int DP[1001][1001] = {0, }; // s ~ e 영역의 팰린드롬 갯수
    for(int i = 0; i < len; ++i) DP[i][i] = 1;
    for(int i = 0; i < len - 1; ++i) {
        if (str[i] == str[i+1]) {
            DP[i][i+1] = 3; // b, b, bb
        } else {
            DP[i][i+1] = 2; // a, b
        }
    }

    for(int d = 2; d < len; ++d) {
        for(int s = 0; s < len; ++s) {
            int e = s + d;
            if (e >= len) break;
            
            DP[s][e] = DP[s+1][e] + DP[s][e-1] - DP[s+1][e-1] + (str[s] == str[e]);
            DP[s][e] %= 10007;
        }
    }
    
    printf("%d\n", DP[0][len-1]);
    return 0;
}