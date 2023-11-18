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
#define X first
#define Y second



int N, M;
void solve() {
    scanf("%d %d", &N, &M);
    map<int, int> cnt;
    FOR(i,1,N+1) {
        cnt[i] = 0;
    }
    priority_queue<pii> pq;
    for(int i = 0; i < M; ++i) {
        int a; scanf("%d", &a);
        cnt[a]++;
        pq.push({cnt[a], -a});
        while(pq.top().first != cnt[-pq.top().second]) pq.pop();
        printf("%d\n", -pq.top().second);
    }
}

int main() {
    solve();
    return 0;
}