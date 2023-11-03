#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

string intToStr(int v) {
    string ret = "";
    while(v > 0) {
        char cc = v % 10 + '0';
        ret = cc + ret;
        v /= 10;
    }
    return ret;
}

int N, M;
vector<int> v;
set<string> printed;
void dfs(set<int> used, vector<int> cur) {
    if (cur.size() >= M) {
        string s = "";
        for(auto& item: cur) {
            s += intToStr(item);
            s += " ";
        }
        if (printed.find(s) == printed.end()) {
            printf("%s\n", s.c_str());
            printed.insert(s);
        }
        return;
    }
    for(int i = 0; i < v.size(); ++i) {
        if (used.find(i) != used.end()) continue;
        vector<int> nv = cur;
        set<int> nu = used;
        nv.push_back(v[i]);
        nu.insert(i);
        dfs(nu, nv);
    }
}

void solve() {
    scanf("%d %d", &N, &M);
    FOR(i,0,N) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); ++i) {
        vector<int> tmp; tmp.push_back(v[i]);
        set<int> used; used.insert(i);
        dfs(used, tmp);
    }
}

int main() {
    solve();
    return 0;
}