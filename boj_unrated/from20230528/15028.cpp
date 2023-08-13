#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int S[110];
int N;
void solve() {
    vector<pll> v;
    scanf("%d", &N);
    int miny = 0x7FFFFFFF, minx = 0x7FFFFFFF;
    int minIdx = -1;
    for(int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
        if (y < miny) {
            miny = y; minx = x;
            minIdx = i;
        } else if (y == miny) {
            if (x < minx) {
                minx = x;
                minIdx = i;
            }
        }
    }
    pll offset = v[minIdx];
    v[minIdx] = v[0];
    v[0] = offset;
    for(int i = 0; i < N; ++i)
        v[i] = {v[i].first - offset.first, v[i].second - offset.second};

    sort(v.begin() + 1, v.end(), [&](pll& a, pll& b) {
        ll crossproduct = a.first * b.second - b.first * a.second;
        if (crossproduct == 0) {
            // 거리순 정렬
            return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second);
        }
        return crossproduct > 0;
    });

    // Graham Scan
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

    // printf("sz: %d\n", sp);
    // for(int i = 0; i < sp; ++i) {
    //     printf("(%d, %d)\n", v[S[i]].first, v[S[i]].second);
    // }

    double mindist = 9999999999.;
    // 거리를 재봅시다...
    for(int i = 0; i < sp; ++i) {
        int j = i + 1; j %= sp;
        // 직선의 방정식을 구합시다.
        int x1 = v[S[i]].first;
        int y1 = v[S[i]].second;
        int x2 = v[S[j]].first;
        int y2 = v[S[j]].second;
        int dy = y2 - y1;
        int dx = x2 - x1;
        // y - y1 = (y2 - y1) / (x2 - x1) * (x - x1)
        // (x2 - x1) * (y - y1) = (y2 - y1) * (x - x1)
        // dx * y - y1 * dx = dy * x - x1 * dy
        // dy * x - dx * y - x1 * dy + y1 * dx = 0 <- 직선의 방정식 ax + by + c = 0
        int a = dy;
        int b = -dx;
        int c = y1 * dx - x1 * dy;
        long long lower = a * a + b * b;
        double maxdist = 0;
        for(int k = 0; k < sp; ++k) {
            if (k == i || k == j) continue;
            int x = v[S[k]].first; int y = v[S[k]].second;
            long long upper = a * x + b * y + c;
            double dist = sqrt((double)upper * upper / (double)lower);
            if (dist > maxdist) maxdist = dist;
        }
        if (maxdist < mindist) mindist = maxdist;
    }
    printf("%lf\n", mindist);
}

int main() {
    solve();
    return 0;
}