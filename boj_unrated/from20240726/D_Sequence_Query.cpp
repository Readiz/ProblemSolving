#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Number {
    ll num;
    ll id;
    bool operator<(const Number& t) const {
        if (num != t.num) return num < t.num;
        return id < t.id;
    }
};


set<Number> s;
ll cid = 0;
void input() {
    int cmd; scanf("%d", &cmd);
    if (cmd == 1) {
        ll a;
        ++cid;
        scanf("%lld", &a);
        s.insert({a, cid});
    } else if (cmd == 2) {
        ll x; int k; scanf("%lld %d", &x, &k);
        auto it = s.lower_bound({x+1, 0});
        if (it != s.begin() && s.size() != 0) {
            --it;
        } else {
            printf("-1\n");
            return;
        }
        while(--k) {
            if (it != s.begin() && s.size() != 0) {
                --it;
            } else {
                printf("-1\n");
                return;
            }
        }
        printf("%lld\n", it->num);
    } else {
        ll x; int k; scanf("%lld %d", &x, &k);
        auto it = s.lower_bound({x, 0});
        do {
            if (k == 1 || it == s.end()) {
                break;
            }
            ++it;
        } while(--k);
        if (it == s.end()) {
            printf("-1\n");
        } else {
            printf("%lld\n", it->num);
        }
    }
}

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        input();
    }

    return 0;
}