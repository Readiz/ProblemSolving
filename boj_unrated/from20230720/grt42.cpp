#include <bits/stdc++.h>
using namespace std;

int N, M;
typedef long long ll;
struct UF {
    int parent[100001];
    UF() {
        for(int i = 0; i <= 100000; ++i) parent[i] = i;
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

vector<int> adj[100001];

struct Component {
    ll numComputer;
    ll numConnection;
    vector<int> members;

    bool operator<(const Component& t) const {
        // 1. 커넥션 수 / 컴퓨터 수
        // 2. 밀도 같으면 컴퓨터 적은 수
        // 3. 더 작은 번호 컴퓨터 순
        if (numComputer * t.numConnection != numConnection * t.numComputer) {
            return numComputer * t.numConnection < numConnection * t.numComputer;
        }
        if (numComputer != t.numComputer) {
            return numComputer < t.numComputer;
        }
        return members[0] < t.members[0];
    }
} com[100000];

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        uf.merge(a, b);
    }

    int cid = 0;
    map<int, int> uq;
    for(int a = 1; a <= N; ++a) {
        if (uq.find(uf.getRoot(a)) == uq.end()) {
            uq[uf.getRoot(a)] = cid;
            ++cid;    
        }
        int gid = uq[uf.getRoot(a)];
        com[gid].members.push_back(a);
        com[gid].numComputer++;
    }
    for(int c = 0; c < cid; ++c) {
        ll cnt = 0;
        for(auto& cur: com[c].members) {
            cnt += adj[cur].size();
        }
        com[c].numConnection = cnt;
    }
    sort(com, com + cid);

    for(auto& item: com[0].members) {
        printf("%d ", item);
    }
    printf("\n");
    return 0;
}