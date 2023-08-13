#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    vector<ll> v;
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        ll tmp;
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }
    int l = 0;
    int r = v.size() - 1;

    // l: 음수일동안, r: 양수일동안
    ll mindiffabs = 0xFFFFFFFF;
    int minl = -1, minr = -1;

    while(l < r && v[l] < 0 && v[r] > 0) {
        ll cursum = v[l] + v[r];
        if (abs(cursum) < mindiffabs) {
            // update
            mindiffabs = abs(cursum);
            minl = l; minr = r;
        }
        if (cursum < 0) {
            ++l;
        } else {
            --r;
        }
    }
    // 예외처리 ing
    ll checker;
    if (l > 0) {
        checker = v[l-1] + v[l];
        if (abs(checker) < mindiffabs) {
            mindiffabs = abs(checker);
            minl = l-1; minr = l;
        }
    }
    checker = v[l] + v[l+1];
    if (abs(checker) < mindiffabs) {
        mindiffabs = abs(checker);
        minl = l; minr = l+1;
    }
    if (r+1 < v.size()) {
        checker = v[r] + v[r+1];
        if (abs(checker) < mindiffabs) {
            mindiffabs = abs(checker);
            minl = r; minr = r+1;
        }
    }
    checker = v[r-1] + v[r];
    if (abs(checker) < mindiffabs) {
        mindiffabs = abs(checker);
        minl = r-1; minr = r;
    }
    printf("%d %d\n", v[minl], v[minr]);
    return 0;
}