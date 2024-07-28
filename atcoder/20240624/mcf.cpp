#include <array>
#include <vector>
#include <iostream>

#include "atcoder/mincostflow.hpp"

using namespace std;

/* ### basic types and constraints ### */

struct P {
    int r, c;

    friend P operator+(const P& lhs, const P& rhs) {
        return P(lhs.r + rhs.r, lhs.c + rhs.c);
    }
    P operator+=(const P& rhs) { return *this = *this + rhs; }
    friend P operator-(const P& lhs, const P& rhs) {
        return P(lhs.r - rhs.r, lhs.c - rhs.c);
    }
    P operator-=(const P& rhs) { return *this = *this - rhs; }

    friend bool operator==(const P& lhs, const P& rhs) {
        return lhs.r == rhs.r && lhs.c == rhs.c;
    }

    bool is_near4(const P& rhs) const { return abs(r - rhs.r) + abs(c - rhs.c) == 1; }
};
// RDLU
const array<P, 4> D4 = {
    P(0, 1),
    P(1, 0),
    P(0, -1),
    P(-1, 0),
};

const int N = 20;
const int INF = 1'000'000'000;

using Board = array<array<int, N>, N>;
// move to p -> load/unload d
struct Action {
    P p;
    int d;
};

/* ### input data ### */

static Board H;
static int BASE;  // sum |H[i][j]|

void input() {
    int n;
    cin >> n;
    assert(n == N);
    BASE = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> H[r][c];
            BASE += abs(H[r][c]);
        }
    }
    assert(BASE % 2 == 0);
}

/* ### utils ### */

void output(const vector<Action>& actions) {
    int k = int(actions.size());
    for (int i = 0; i < k; i++) {
        // move to action.p
        if (i) {
            [&]() {
                for (int dir = 0; dir < 4; dir++) {
                    if (actions[i - 1].p + D4[dir] == actions[i].p) {
                        cout << "RDLU"[dir] << endl;
                        return;
                    }
                }
                assert(false);
            }();
        }

        // load/unload action.d
        int d = actions[i].d;
        if (d > 0) {
            cout << "+" << d << endl;
        }
        if (d < 0) {
            cout << d << endl;
        }
    }
}

// return (best_cost, best_actions)
pair<int, vector<Action>> best_actions(const vector<P>& walk) {
    int m = int(walk.size());

    // walk validation
    assert(walk[0] == P(0, 0));
    for (int i = 0; i < m - 1; i++) {
        assert(walk[i].is_near4(walk[i + 1]));
    }

    int s = m + N * N, t = s + 1;
    atcoder::mcf_graph<int, int> g(m + N * N + 2);

    // walk <-> point
    vector<int> load_e(m), unload_e(m);
    for (int i = 0; i < m; i++) {
        P p = walk[i];
        int walk_v = i, point_v = m + p.r * N + p.c;
        load_e[i] = g.add_edge(point_v, walk_v, INF, 1);
        unload_e[i] = g.add_edge(walk_v, point_v, INF, 1);
    }

    // point <-> s/t
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int v = m + r * N + c;
            if (H[r][c] > 0) {
                g.add_edge(s, v, H[r][c], 0);
            }
            if (H[r][c] < 0) {
                g.add_edge(v, t, -H[r][c], 0);
            }
        }
    }

    // carry
    for (int i = 0; i < m - 1; i++) {
        g.add_edge(i, i + 1, INF, 1);
    }

    auto [flow, cost] = g.flow(s, t);
    if (2 * flow != BASE) return {INF, {}};

    vector<Action> actions;
    for (int i = 0; i < m; i++) {
        int d = g.get_edge(load_e[i]).flow - g.get_edge(unload_e[i]).flow;
        actions.push_back({walk[i], d});
    }
    return {cost + 100 * (m - 1), actions};
}

int main() {
    input();

    vector<P> walk;
    for (int r = 0; r < N; r++) {
        if (r % 2 == 0) {
            for (int c = 0; c < N; c++) {
                walk.push_back(P(r, c));
            }
        } else {
            for (int c = N - 1; c >= 0; c--) {
                walk.push_back(P(r, c));
            }
        }
    }
    for (int c = 0; c < N; c++) {
        if (c % 2 == 0) {
            for (int r = N - 1; r >= 0; r--) {
                if (c == 0 && r == N - 1) continue;
                walk.push_back(P(r, c));
            }
        } else {
            for (int r = 0; r < N; r++) {
                walk.push_back(P(r, c));
            }
        }
    }

    auto [cost, actions] = best_actions(walk);
    cerr << "cost: " << cost << endl;

    output(actions);
    return 0;
}
