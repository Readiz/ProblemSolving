#include <bits/stdc++.h>
#define endl '\n'
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define PER(i,front,back) for (int i = back; i >= front; --i)
#define all(x) x.begin(), x.end()
#define debug cout << "dbg"
#define debugprint(x) cout << endl << #x << " is " << x << endl
using namespace std; void solve(); int main() {ios::sync_with_stdio(0); cin.tie(0); solve();}
using ll = long long; using ii = pair<int,int>; using iii = tuple<int,int,int>;

const int N = 4e5+3;
ii tree[N];

void update(int t, int x, iii node) {
    auto [k,l,r] = node;
    if (t < l || r < t) return;
    if (l == r) {tree[k] = {x,t}; return;}
    int m = (l+r)>>1;
    update(t,x,{k<<1,l,m}); update(t,x,{(k<<1)|1,m+1,r});
    tree[k] = min(tree[k<<1],tree[(k<<1)|1]);
}

auto query(ii range, iii node) {
    auto [s,e] = range; auto [k,l,r] = node;
    if (e < l || r < s) return tree[0];
    if (s <= l && r <= e) return tree[k];
    int m = (l+r)>>1;
    return min(query(range,{k<<1,l,m}),query(range,{(k<<1)|1,m+1,r}));
}

void solve() {
    int n; cin >> n;
    REP(i,1,n) {
        int x; cin >> x;
        update(i,x,{1,1,n});
    }
    int m; cin >> m;
    REP(i,1,m) {
        int command; cin >> command;
        if (command == 1) {
            int i, v; cin >> i >> v;
            update(i,v,{1,1,n});
        } else cout << query({1,n},{1,1,n}).second << endl;
    }
}