#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct Node {
    int priority; // 높을수록 위쪽에
    int id;
    bool operator<(const Node& t) const {
        if (priority != t.priority) return priority < t.priority;
        return id < t.id;
    }
    bool operator>(const Node& t) const {
        return t < *this;
    }
};
#define ordered_set tree<Node, null_type, less<Node>, rb_tree_tag,tree_order_statistics_node_update>


void solve() {
    ordered_set S;
    unordered_map<int, ordered_set::point_iterator> M;

    int N, CASE; scanf("%d %d", &N, &CASE);
    for(int i = 1; i <= N; ++i) {
        auto res = S.insert({N - i + 1, i});
        auto it = res.first;
        M.emplace(i, it);
    }

    // for(auto& it: S) {
    //     printf("(%d, %d)\n", it.priority, it.id);
    // }

    int priority = N + 1;

    for(int i = 0; i < CASE; ++i) {
        int c; scanf("%d", &c);
        auto mit = M.find(c);
        auto sit = mit->second;
        M.erase(mit);
        int cdist = S.order_of_key(*sit); //distance(sit, S.end());
        int cid = sit->id;
        S.erase(sit);
        auto res = S.insert({priority, cid});
        auto it = res.first;
        priority++;
        M.emplace(cid, it);
        printf("%d ", N - cdist - 1);
    }
    printf("\n");
}

int main() {
    int TC; scanf("%d", &TC);
    while(TC--) solve();
    return 0;
}