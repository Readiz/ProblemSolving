#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Diamond {
    int weight;
    int value;
    bool operator<(const Diamond& t) const {
        if (value != t.value) return t.value < value;
        return weight < t.weight;
    }
};

int main() {
    int N, M; scanf("%d %d", &N, &M);
    vector<Diamond> diamond(N);
    multiset<int> bag;
    for(auto& item: diamond) scanf("%d %d", &item.weight, &item.value);
    for(int i = 0; i < M; ++i) {
        int tmp; scanf("%d", &tmp);
        bag.insert(tmp);
    }

    ll ans = 0;
    sort(diamond.begin(), diamond.end());
    for(auto& item: diamond) {
        auto it = bag.lower_bound(item.weight);
        if(it != bag.end()) {
            bag.erase(it);
            ans += item.value;
        }
    }

    printf("%lld\n", ans);

    return 0;
}