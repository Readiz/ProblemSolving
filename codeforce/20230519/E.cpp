#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

struct Cycle {
    set<int> members;
} cycle[200001];

int N;
int A[200001], C[200001];
void solve() {
    scanf("%d", &N);
    int cidx = 0;
    set<int> checker;
    FOR(i,1,N+1) {
        scanf("%d", &A[i]);
        C[i] = -1;
        checker.insert(i);
    }
    while(checker.size()) {
        int i = *checker.begin();
        queue<int> q;
        q.push(A[i]);
    }
    // FOR(i,1,N+1) {
    //     // i <-> A[i]는 사이클
    //     if (C[i] == -1 && C[A[i]] == -1) { // 신규 사이클
    //         cycle[cidx].members.clear();
    //         cycle[cidx].members.insert(i);
    //         cycle[cidx].members.insert(A[i]);
    //         C[i] = cidx;
    //         C[A[i]] = cidx;
    //         cidx++;
    //     } else {
    //         // 기존 사이클 편입
    //         if (C[A[i]] != -1) {
    //             cycle[C[A[i]]].members.insert(i);
    //             C[i] = C[A[i]];
    //         } else {
    //             cycle[C[i]].members.insert(A[i]);
    //             C[A[i]] = C[i];
    //         }
    //     }
    // }
    for(int i = 0; i < cidx; ++i) {
        _D("CYCLE %d: ", i);
        for(auto& j: cycle[i].members) {
            _D("%d ", j);
        }
        _D("\n");
    }
    // max: cidx
    printf("%d\n", cidx);
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
