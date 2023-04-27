#include <bits/stdc++.h>
using namespace std;

int N;
struct Node {
    int p;
    int depth;
    vector<int> c;
};
Node n[10001];

void dfs(int v, int d) {
    n[v].depth = d;
    for(auto& c: n[v].c) {
        dfs(c, d+1);
    }
}
void solve() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        n[i].p = -1;
        n[i].c.clear();
    }
    for(int i = 0; i < N-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b); // a가 b의 부모
        n[b].p = a;
        n[a].c.push_back(b);
    }
    int root = 1;
    while(n[root].p != -1) root = n[root].p;
    dfs(root, 0);

    int a, b;
    scanf("%d %d", &a, &b);
    if (n[a].depth < n[b].depth) a^=b^=a^=b;
    while(n[a].depth != n[b].depth) {
        a = n[a].p;
    }
    if (a == b) {
        printf("%d\n", a);
        return;
    }
    while(a!=b) {
        a = n[a].p;
        b = n[b].p;
    }
    printf("%d\n", a);
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        solve();
    }

    return 0;
}