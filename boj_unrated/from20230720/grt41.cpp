#include <bits/stdc++.h>
using namespace std;

bool conn[2001][2001];
int N, M;

struct UF {
    int parent[2001];
    UF() {
        for(int i = 0; i <= 2000; ++i) parent[i] = i;
    }
    int getRoot(int v) {
        if (v == parent[v]) return v;
        return parent[v] = getRoot(parent[v]);
    }
    void merge(int a, int b) {
        a = getRoot(a);
        b = getRoot(b);
        if (a == b) return;
        parent[b] = a;
    }
} uf;

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        conn[a][b] = true;
    }

    for(int a = 1; a <= N; ++a) {
        for(int b = a + 1; b <= N; ++b) {
            if (conn[a][b] == true && conn[b][a] == true) {
                uf.merge(a, b);
            }
        }
    }

    set<int> uq;
    for(int a = 1; a <= N; ++a) {
        uq.insert(uf.getRoot(a));
    }

    printf("%d\n", (int)uq.size());
    return 0;
}