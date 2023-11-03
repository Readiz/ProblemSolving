#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// Greedy 기초
// 작업을 진행하는데 걸리는 시간 T가 주어지지 않았다.
// 그 작업을 채택할지 안할지만 보면 된다.

// 1. 정렬 Phase
// 끝나는 시간 기준으로 정렬한다.
// 2. 할당 Phase
// 앞에서부터 차례대로 할당한다.
struct Meeting {
    int s, e;
};

int main() {
    int N; scanf("%d", &N);
    vector<Meeting> v;
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [&](Meeting& a, Meeting& b) -> bool {
        if (a.e != b.e) return a.e < b.e;
        return a.s < b.s;
    });
    
    int last = 0;
    int ans = 0;
    for(auto& item: v) {
        if (item.s >= last) ++ans, last = item.e;
    }
    printf("%d\n", ans);

    return 0;
}