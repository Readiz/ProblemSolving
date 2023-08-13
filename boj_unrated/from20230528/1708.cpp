#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int S[100001];
int N;
int main() {
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
    { 
        pll tmp = v[minIdx];
        v[minIdx] = v[0];
        v[0] = tmp;
        for(int i = 0; i < N; ++i)
            v[i] = {v[i].first - tmp.first, v[i].second - tmp.second};
    }
    sort(v.begin() + 1, v.end(), [&](pll& a, pll& b) {
        ll crossproduct = a.first * b.second - b.first * a.second;
        if (crossproduct == 0) {
            // 거리순 정렬
            return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second);
        }
        return crossproduct > 0;
    });
    // for(auto item: v) {
    //     printf("%d %d\n", item.first, item.second);
    // }

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
    // 최종적으로 stack에 남은 것이 이루는 개수
    printf("%d\n", sp);

    // for(int i = 0; i < sp; ++i) {
    //     printf("%d %d\n", v[S[i]].first, v[S[i]].second);
    // }

    return 0;
}