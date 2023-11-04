#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Job {
    int t;
    int d; // deadline
    bool operator<(const Job& t) const {
        if (d != t.d) return d > t.d;
        return this->t < t.t;
    }
};

int main() {
    int N; scanf("%d", &N);
    vector<Job> v(N);
    for(auto& i: v) scanf("%d %d", &i.t, &i.d);
    sort(v.begin(), v.end());

    int ctime = v[0].d - v[0].t;
    for(int i = 1; i < v.size(); ++i) {
        ctime = min(ctime, v[i].d); // backward scheduling
        ctime -= v[i].t;
    }
    if (ctime < 0) printf("-1\n");
    else printf("%d\n", ctime);

    return 0;
}