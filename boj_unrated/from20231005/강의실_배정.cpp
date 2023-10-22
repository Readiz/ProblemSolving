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
        int l, r; scanf("%d %d", &l, &r);
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());

    int 

    return 0;
}