#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Switch {
    int num;
    ll cost;
};

ll DP[100001] = {0, }; // 스위치 i개를 썼을 때 + 컴퓨터 j대를 연결했을 때의 최소 비용
int main() {
    int N; scanf("%d", &N);
    vector<Switch> s(N+1);
    for(int i = 1; i <= N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        s[i] = {a - 1, b}; // 1개씩은 기본적으로 못쓴다.
    }
    int M; scanf("%d", &M);
    
    memset(DP, 0x3A, sizeof(ll) * (100001));
    for(int i = 1; i <= N; ++i) {
        for(int j = M; j >= s[i].num - 1; --j) {
            DP[j] = min(DP[j], DP[j - s[i].num + 1] + s[i].cost);
        }
        // 한개만 써서 연결 case
        DP[s[i].num] = min(DP[s[i].num], s[i].cost);
    }
    DP[1] = 0; // 랜선을 컴퓨터에 바로 연결 [Edge Case]
    if (DP[M] != 0x3A3A3A3A3A3A3A3A) {
        printf("%lld\n", DP[M]);
    } else {
        printf("-1\n");
    }

    return 0;
}