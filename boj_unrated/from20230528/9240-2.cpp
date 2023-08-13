#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int S[100001];
int N;
int main() {
    vector<pll> v;

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int sp = 0;
    S[sp++] = 0; S[sp++] = 1;
    for(int i = 2; i < v.size(); ++i) {
        pll will = v[i];
        while(sp > 1) {
            pll cur = v[S[sp - 1]];
            pll prev = v[S[sp - 2]];
            pll v1 = {prev.first - cur.first, prev.second - cur.second};
            pll v2 = {will.first - cur.first, will.second - cur.second};
            ll crossproduct = v1.first * v2.second - v1.second * v2.first;
            if (crossproduct < 0) {
                // 둔각
                // 이 경우에는 accept 하는 case 임.
                break; // 종료
            }
            // 예각 & 평행
            // cur을 버린다.
            --sp;
            // 루프 계속..
        }
        S[sp++] = i;
    }
    for(int i = v.size() - 2; i > 0; --i) {
        pll will = v[i];
        while(sp > 1) {
            pll cur = v[S[sp - 1]];
            pll prev = v[S[sp - 2]];
            pll v1 = {prev.first - cur.first, prev.second - cur.second};
            pll v2 = {will.first - cur.first, will.second - cur.second};
            ll crossproduct = v1.first * v2.second - v1.second * v2.first;
            if (crossproduct < 0) {
                // 둔각
                // 이 경우에는 accept 하는 case 임.
                break; // 종료
            }
            // 예각 & 평행
            // cur을 버린다.
            --sp;
            // 루프 계속..
        }
        S[sp++] = i;
    }
    // 최종적으로 stack에 남은 것이 이루는 개수
    printf("%d\n", sp);

    for(int i = 0; i < sp; ++i) {
        printf("%d %d\n", v[S[i]].first, v[S[i]].second);
    }
    
    double maxdist = 0;
    for(int i = 0; i < sp; ++i) {
        for(int j = i + 1; j < sp; ++j) {
            ll dx = (v[S[i]].first - v[S[j]].first);
            ll dy = (v[S[i]].second - v[S[j]].second);
            ll cdist = dx * dx + dy * dy;
            double curdist = sqrt(cdist);
            if (curdist > maxdist) maxdist = curdist;
        }
    }

    printf("%lf\n", maxdist);

    return 0;
}