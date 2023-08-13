#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool isSameSlope(pll& a, pll& b) {
    if (a.first * b.second == a.second * b.first) return true;
    return false;
}

int N;
int main() {
    vector<pll> v;
    scanf("%d", &N);
    pll min = {0x7FFFFFFF, 0x7FFFFFFF};
    int minIdx = -1;
    for(int i = 0; i < N; ++i) {
        int x, y;
        char buf[3];
        scanf("%d %d %s", &x, &y, buf);
        if (buf[0] == 'Y') {
            pll p = {x, y};
            v.push_back(p);
            if (p < min) {
                min = p;
                minIdx = v.size() - 1;
            }
        }
    }
    // printf("\n\n%lld %lld [%d]\n\n", min.first, min.second, minIdx);
    pll offset = v[minIdx];
    v[minIdx] = v[0];
    v[0] = offset;

    for(int i = 0; i < v.size(); ++i) {
        v[i].first -= offset.first;
        v[i].second -= offset.second;
    }

    sort(v.begin() + 1, v.end(), [&](pll& a, pll& b) {        
        // crossproduct이 양수면, a 벡터가 더 우측으로 되어 있단 뜻
        ll crossproduct = a.first * b.second - a.second * b.first;
        if (crossproduct == 0) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }

        return crossproduct > 0;
    });

    pll last = v[v.size() - 1];
    // lower bound로 마지막 녀석과 같은 기울기를 가지는 지점을 찾는다.
    int l = 0, r = v.size() - 1, m;
    int ans = r;
    while (l <= r) {
        m = (l + r) >> 1;
        if (isSameSlope(v[m], last)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    // 같은 기울기 가지는 녀석은 뒤집는다. (마지막 직선 위에 있는 애들은 순서 반대로..)
    reverse(v.begin() + ans, v.end());

    printf("%d\n", v.size());
    for(auto item: v) {
        printf("%lld %lld\n", item.first + offset.first, item.second + offset.second);
    }

    return 0;
}