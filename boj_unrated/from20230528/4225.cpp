#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll operator-(pll& a, pll& b) {
    return {a.first - b.first, a.second - b.second};
}
ll operator*(pll& a, pll& b) {
    return a.first * b.second - a.second * b.first;
}

bool ccw(pll& a, pll& b, pll& c) {
    pll ba = a - b;
    pll bc = c - b;
    ll r = ba * bc;
    return r < 0; // 이 조건을 만족할 때 둔각이다.
}

int N;
void solve(int TC) {
    vector<pll> v;
    for(int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }

    // Andrew's Algorithm
    sort(v.begin(), v.end());
    int s[110];
    int sp = 0; // stack ptr
    s[sp++] = 0; s[sp++] = 1;
    for(int i = 2; i < v.size(); ++i) {
        while(sp >= 2 && ccw(v[s[sp-2]], v[s[sp-1]], v[i]) == false)
            --sp;
        s[sp++] = i;
    }
    int upperSz = sp + 1;
    // printf("UPPER: %d\n", sp);
    for(int i = v.size() - 2; i >= 0; --i) {
        while(sp >= upperSz && ccw(v[s[sp-2]], v[s[sp-1]], v[i]) == false)
            --sp;
        s[sp++] = i;
    }
    --sp; // 마지막 반복 컷

    // for(int i = 0; i < sp; ++i) {
    //     printf("%d, %d\n", v[s[i]].first, v[s[i]].second);
    // }
    double min = 9999999999.;
    // 직선과 점의 거리
    for(int i = 0; i < sp; ++i) {
        int j = i + 1; j %= sp;
        double lmax = 0;
        for(int p = 0; p < sp; ++p) {
            if (p == i || p == j) continue;
            pll pi = v[s[i]] - v[s[p]];
            pll pj = v[s[j]] - v[s[p]];
            pll base = v[s[j]] - v[s[i]];
            ll upper = pi * pj;
            upper = upper * upper;
            double cmax = (double)upper / (base.first * base.first + base.second * base.second);
            cmax = sqrt(cmax);
            if (cmax > lmax) lmax = cmax;
        }
        if (lmax < min) min = lmax;
    }
    printf("Case %d: %.2lf\n", TC, min + 0.005);
    // printf("ANS: %lf\n", min);
}
int main() {
    int tc = 1;
    while(true) {
        scanf("%d", &N);
        if (N == 0) break;
        solve(tc++);
    }
    return 0;
}