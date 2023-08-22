#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

/*
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스의 첫 번째 줄에는 동전의 가지 수 N(1 ≤ N ≤ 20)이 주어지고 두 번째 줄에는 N가지 동전의 각 금액이 오름차순으로 정렬되어 주어진다. 각 금액은 정수로서 1원부터 10000원까지 있을 수 있으며 공백으로 구분된다. 세 번째 줄에는 주어진 N가지 동전으로 만들어야 할 금액 M(1 ≤ M ≤ 10000)이 주어진다.
*/

void solve() {
    int N; scanf("%d", &N);
    vector<int> C(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &C[i]);
    int T; scanf("%d", &T);
    int DP[200001] = {1, };
    for(int i = 1; i <= N; ++i) {
        for(int w = 1; w <= T; ++w) {
            if (w - C[i] >= 0) {
                DP[w] += DP[w - C[i]]; // mod는 필요 없다
            }
        }
    }
    printf("%d\n", DP[T]);
}
int main() {
    int TC; scanf("%d", &TC);
    while(TC--) solve();
    return 0;
}