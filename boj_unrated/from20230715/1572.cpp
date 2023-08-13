#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct Node {
    int degree;
    int id;
    bool operator<(const Node& t) const {
        if (degree != t.degree) return degree < t.degree;
        return id < t.id;
    }
    bool operator>(const Node& t) const {
        return t < *this;
    }
};
#define ordered_set tree<Node, null_type, less<Node>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set v;
int A[250000];
int main() {
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);
    int cur = 0;
    for(int i = 0; i < K; ++i) {
        v.insert({A[i], i});
    }
    int mid = (K - 1) / 2;
    long long ans = v.find_by_order(mid)->degree;

    int l = 0;
    int r = K;
    for(; r < N; ++r, ++l) {
        v.insert({A[r], r});
        v.erase(v.find({A[l], l}));
        ans += v.find_by_order(mid)->degree;
    }
    printf("%lld\n", ans);
    return 0;
}
