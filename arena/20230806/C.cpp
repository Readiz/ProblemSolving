#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define _D(...) printf(__VA_ARGS__)

bool getSub(int& l, int& r, ll& lsum, ll& rsum, int& pGrp, int& mGrp, vector<ll>& v) {
    _D("cur: %d / %d | s: %lld / %lld | g: %d / %d\n", l, r, lsum, rsum, pGrp, mGrp);
    int oril = l; int orir = r; // move checker
    while(v[l] <= 0 && l < r) {
        lsum += v[l++];
    }
    while(v[r] <= 0 && l < r) {
        rsum += v[r--];
    }
    if (l + 1 == r) {
        if (v[l] > 0) pGrp++;
        if (v[r] > 0) pGrp++;
        if (l != oril) mGrp++;
        if (r != orir) mGrp++;
        
        // end case
        if (pGrp > mGrp) {
            _D("l: %d->%d / r: %d->%d / p: %d / m: %d -> true\n", oril, l, orir, r, pGrp, mGrp);
            return true;
        } else {
            return false;
        }
    } else if (l != r) {
        if (oril != l && lsum + v[l] > 0) {
            lsum = lsum + v[l];
        } else {
            if (oril == l) pGrp++;
            lsum = v[l];
        }

        if (orir != r && rsum + v[r] > 0) {
            rsum = rsum + v[r];
        } else {
            if (orir == r) pGrp++;
            rsum = v[r];
        }
    } else if (l == r) {
        // l == r case
        if (oril != l && orir != r) {
            if (lsum + rsum + v[l] > 0) {
                pGrp++;
            } else {
                pGrp++;
                mGrp+=2;
            }
        } else {
            if (oril != l) {
                pGrp++;
                mGrp++;
            } else if (orir != r) {
                pGrp++;
                mGrp++;
            } else {
                pGrp++;
            }
        }

        // end case
        if (pGrp > mGrp) {
            _D("l: %d->%d / r: %d->%d / p: %d / m: %d -> true\n", oril, l, orir, r, pGrp, mGrp);
            return true;
        } else {
            return false;
        }
    }

    if (pGrp > mGrp + 1) {
        _D("l: %d->%d / r: %d->%d / p: %d / m: %d -> true\n", oril, l, orir, r, pGrp, mGrp);
        return true;
    }
    if (l < r) {
        ++l, --r;
        return getSub(l, r, lsum, rsum, pGrp, mGrp, v);
    }
    return false;
}

void solve() {
    int N; scanf("%d", &N);
    vector<ll> v; v.resize(N);
    for(int i = 0; i < N; ++i) scanf("%lld", &v[i]);

    int l = 0, r = N - 1;
    ll lsum = 0; ll rsum = 0;
    int pGrp = 0, mGrp = 0;

    if (getSub(l, r, lsum, rsum, pGrp, mGrp, v) == true) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--){
        solve();
    }
    return 0;
}