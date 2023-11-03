#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Range {
    int l, r;
    bool operator<(const Range& t) {
        if (l != t.l) return l < t.l;
        return r < t.r;
    }
};

int main() {
    int N; scanf("%d", &N);
    vector<Range> v;
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end()); // 빨리 끝나는 순서대로 정렬

    priority_queue<int, vector<int>, greater<>> pq;
    for(auto& item: v) {
        if (pq.size() == 0) {
            pq.push(item.r);
            continue;
        }
        if (item.l >= pq.top()) { // 일단 들어갈 수 있다.
            pq.pop();
            pq.push(item.r); // 기존 녀석을 대체
        } else { // 못들어가는 case이다. (현재 가장 빨리 끝나는 녀석보다도 시작이 빠름)
            pq.push(item.r);
        }
    }

    printf("%ld\n", pq.size());
    return 0;
}