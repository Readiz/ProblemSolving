#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; scanf("%d", &N);
    vector<int> weights(N + 1);
    for(int i = 1; i <= N; ++i) scanf("%d", &weights[i]);

    int TC; scanf("%d", &TC);
    int ODP[100000] = {0, };
    int *DP = &ODP[50000];
    DP[0] = 1;

    for(int i = 1; i <= N; ++i) {
        // 1. 현재 추를 안쓰기 (암것도 안함)
        // 2. 현재 추를 우측에 놓기
        // 3. 현재 추를 좌측에 놓기
        for(int w = 40000; w >= -40000; --w) { // 더하는 순서랑 순회하는 순서 주의!!
            DP[w] += DP[w - weights[i]]; 
        }
        for(int w = -40000; w <= 40000; ++w) { // 더하는 순서랑 순회하는 순서 주의!!
            DP[w] += DP[w + weights[i]];
        }
    }

    while(TC--) {
        int cur; scanf("%d", &cur);
        if (DP[cur] != 0) printf("Y ");
        else printf("N ");
    }
    printf("\n");
    

    return 0;
}