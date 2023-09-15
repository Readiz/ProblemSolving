#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Item {
    int weight;
    int satisfaction;
};
int main() {
    int N, M; scanf("%d%d", &N, &M);
    vector<Item> v;
    
    for(int i = 0; i < N; ++i) {
        int V, C, K;
        scanf("%d%d%d", &V, &C, &K);
        int covered = 0;
        int mask = 1;
        while(true) {
            if (K - covered == 0) {
                // 종료 조건 1. 이미 커버가 완료 되었다.
                break;
            } else if (K - covered <= mask) {
                // 종료 조건 2. 이제 남은거 묶음으로 처리하면 더 생각 안해도 된다.
                int unit = K - covered;
                v.push_back({V * unit, C * unit});
                break;
            } else {
                // 진행 조건. 현재의 묶음을 아이템으로 생성한다.
                int unit = mask;
                v.push_back({V * unit, C * unit});
            }
            covered |= mask;
            mask <<= 1;
        }
    }

    // 이렇게 구현했을 때 당연히 중복되는 조합이 생기긴 한다.

    // for(auto item: v) {
    //     printf("[d] %d, %d\n", item.weight, item.satisfaction);
    // }

    // 이후에는 일반적인 냅색 진행과 동일
    int DP[10001] = {0, }; // 무게 i에서의 최대 행복도
    for(int i = 0; i < v.size(); ++i) {
        for(int j = M; j >= v[i].weight; --j) {
            DP[j] = max(DP[j], DP[j - v[i].weight] + v[i].satisfaction);
        }
    }

    int maxSatisfation = 0;
    for(int i = 0; i <= M; ++i) {
        maxSatisfation = max(DP[i], maxSatisfation);
    }
    printf("%d\n", maxSatisfation);

    return 0;
}