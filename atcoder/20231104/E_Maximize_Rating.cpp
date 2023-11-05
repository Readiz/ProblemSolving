#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif
#define X first
#define Y second

int N;

double get(vector<double>& v) {
    double factor = 1.0;
    double upper = 0;
    double lower = 0;
    for(auto it = v.rbegin(); it != v.rend(); ++it) {
        upper += factor * *it;
        lower += factor;
        factor *= 0.9;
    }
    return upper / lower - 1200 / sqrt(v.size());
}
void solve() {
    scanf("%d", &N);
    vector<double> P;
    for(int i = 0; i < N; ++i) {
        double tmp; scanf("%lf", &tmp);
        P.push_back(tmp);
    }
    double max = get(P);
    for(int k = 0; k < N - 1; ++k) {
        double min = 999999;
        int idx = -1;
        for(int i = 0; i < P.size(); ++i) {
            if (P[i] <= min) {
                min = P[i];
                idx = i;
            }
        }
        P.erase(P.begin() + idx);
        double cur = get(P);
        if (cur > max) max = cur;
    }
    printf("%.15lf\n", max);
}

int main() {
    solve();
    return 0;
}