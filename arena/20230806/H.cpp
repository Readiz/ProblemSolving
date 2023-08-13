#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M;
struct F {
    vector<vector<ll>> v;
    void init(int N, int M) {
        v.resize(N + 2);
        for(int i = 0; i < N + 2; ++i) {
            v[i].resize(M + 2);
            fill(v[i].begin(), v[i].end(), 0);
        }
    }
    void update(int sx, int sy, ll val) {
        for(int y = sy; y <= N + 1; y += y & -y) {
            for(int x = sx; x <= M + 1; x += x & -x) {
                v[y][x] += val;
            }
        }
    }

    ll get(int sx, int sy) {
        ll r = 0;
        for(int y = sy; y > 0; y -= y & -y) {
            for(int x = sx; x > 0; x -= x & -x) {
                r += v[y][x];
            }
        }
        return r;
    }
} f;

int main() {
    int Q; scanf("%d %d %d", &N, &M, &Q);
    f.init(N, M);
    for(int q = 0; q < Q; ++q) {
        int cmd, p, v; scanf("%d %d %d", &cmd, &p, &v);

        if (cmd == 1) {
            f.update(1, p, v);
            f.update(1, p + 1, -v);
        } else {
            f.update(p, 1, v);
            f.update(p + 1, 1, -v);
        }
    }

    for(int r = 1; r <= N; ++r) {
        for(int c = 1; c <= M; ++c) {
            printf("%lld ", f.get(c, r));
        }
        printf("\n");
    }


    return 0;
}