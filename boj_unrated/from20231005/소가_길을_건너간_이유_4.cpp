#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main() {
    int N, M; scanf("%d %d", &N, &M);
    vector<int> chicken(N);
    vector<pair<int,int>> cow(M);
    for(auto& item: chicken) scanf("%d", &item);
    for(auto& item: cow) scanf("%d %d", &item.x, &item.y);

    sort(cow.begin(), cow.end());
    sort(chicken.begin(), chicken.end());

    // deadline을 순서대로 넣자. 현재 유효한 녀석들만 들어가 있게 된다.
    priority_queue<int, vector<int>, greater<>> pq;
    int cowPtr = 0;
    int ans = 0;
    
    for(auto& c: chicken) {
        int cur = c; // 현재 보는 chicken의 T_i
        for(; cowPtr < M; ++cowPtr) {
            if (cow[cowPtr].y < cur) continue; // 버린다. 이미 다 지나갔다.
            if (cow[cowPtr].x <= cur && cur <= cow[cowPtr].y) {
                pq.push(cow[cowPtr].y); // deadline 순서로 정렬하는 pq에 넣기.
            } else {
                // 앞으로 쓸 녀석들을 만났다. 더이상 pq에 넣지않고 종료
                break;
            }
        }
        while(pq.size() && pq.top() < cur) pq.pop(); // 유효하지 않은것 버리기
        if (pq.size()) {
            // printf("[d] deadline: %d / chicken: %d matched!\n", pq.top(), cur);
            pq.pop();
            ++ans;
        }
    }   
    printf("%d\n", ans);

    return 0;
}