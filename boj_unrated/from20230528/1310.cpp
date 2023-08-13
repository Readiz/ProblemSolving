#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int S[100010];
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

    // 회전하면서 거리를 잰다. (로테이팅 캘리퍼스)
    // https://stonejjun.tistory.com/42
    // 1. 1번점을 A, 2번점을 C라고 하자. 
    // 2. A의 다음 점을 B, C의 다음 점을 D라고 하자. 
    // 3. A와 C의 거리를 잰다.
    // 4. 벡터 AB와 벡터 CD의 CCW를 이용해 두 벡터가 정반대에 가까워지도록 A를 한칸 돌리거나 C를 한칸 돌린다.
    // 5. A가 처음으로 올때까지 반복한다.

    ll maxdist = 0;
    int maxi, maxj;
    int A = 0, C = 1;
    while(true) {
        int B = A + 1, D = C + 1;
        B %= sp, D %= sp;
        ll dx = (v[S[A]].first - v[S[C]].first);
        ll dy = (v[S[A]].second - v[S[C]].second);
        ll curdist = dx * dx + dy * dy;
        if (curdist > maxdist) {
            maxdist = curdist;
            maxi = A;
            maxj = C;
        }

        pll AB = {v[S[B]].first - v[S[A]].first, v[S[B]].second - v[S[A]].second};
        pll CD = {v[S[D]].first - v[S[C]].first, v[S[D]].second - v[S[C]].second};
        
        ll crossproduct = AB.first * CD.second - AB.second * CD.first;
        if (crossproduct > 0) {
            C++; C %= sp;
        } else {
            A++; A %= sp;
            if (A == 0) break;
        }
    }
    printf("%lld\n", maxdist);
}

int main() {
    solve();
    return 0;
}