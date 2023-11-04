#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Info {
    int cnt;
    int order;
    int num;
    bool operator<(const Info& t) const {
        if (cnt != t.cnt) return cnt > t.cnt;
        return order < t.order;
    }
};
int main() {
    int N, C; scanf("%d %d", &N, &C);
    set<int> checker;
    map<int, int> cnt;
    int orderNum = 0;
    map<int, int> order;
    for(int i = 0; i < N; ++i) {
        int tmp; scanf("%d", &tmp);
        if (checker.find(tmp) == checker.end()) {
            order[tmp] = orderNum++;
            checker.insert(tmp);
            cnt[tmp] = 0;
        }
        cnt[tmp]++;
    }
    vector<Info> v;
    for(auto& item: checker) {
        v.push_back({cnt[item], order[item], item});
    }
    sort(v.begin(), v.end());
    
    for(auto& item: v) {
        for(int i = 0; i < item.cnt; ++i) {
            printf("%d ", item.num);
        }
    }
    printf("\n");

    return 0;
}