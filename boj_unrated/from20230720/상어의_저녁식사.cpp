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

struct Shark {
    int size;
    int speed;
    int intel;
} s[51];

constexpr int S = 0;
constexpr int T = 101;

int capa[102][102];
int flow[102][102];
vector<int> adj[102];
int pre[102];
int N;
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        s[i] = Shark{a, b, c};
        capa[S][i] = 2;
        adj[S].push_back(i);
        adj[i].push_back(S);
        capa[i+50][T] = 1;
        adj[i+50].push_back(T);
        adj[T].push_back(i+50);
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (i == j) continue;
            if (s[i].intel >= s[j].intel && s[i].size >= s[j].size && s[i].speed >= s[j].speed) {
                if (s[i].intel == s[j].intel && s[i].size == s[j].size && s[i].speed == s[j].speed && i < j) continue;
                capa[i][j+50] = 1;
                adj[i].push_back(j+50);
                adj[j+50].push_back(i);
            }
        }
    }
    int ans = 0;
    while (true) {
        fill(pre, pre+102, -1);
        queue<int> q;
        q.push(S);
        while(q.size() > 0) {
            int cur = q.front(); q.pop();
            for(auto& t: adj[cur]) {
                int residual = capa[cur][t] - flow[cur][t];
                if (pre[t] == -1 && residual > 0) {
                    pre[t] = cur;
                    if (t == T) break;
                    q.push(t);
                }
            }
            if (pre[T] != -1) break;
        }
        if (pre[T] == -1) break; // no augpath

        for(int p = T; p != S; p = pre[p]) {
            flow[pre[p]][p] += 1;
            flow[p][pre[p]] -= 1;
        }
        ans += 1;
    }
    printf("%d\n", N - ans);
    return 0;
}

// ------------------- old ----------------------

// #include <bits/stdc++.h>
// using namespace std;

// typedef unsigned long long ull;
// typedef long long ll;
// typedef pair<int,int> pii;
// #define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
// #ifndef ONLINE_JUDGE
//     bool isDebug = true;
//     #define _D(...) printf(__VA_ARGS__)
// #else
//     bool isDebug = false;
//     #define _D(...)
// #endif

// struct UF { // union find
//     int parent[51];
//     UF() {
//         for(int i = 1; i <= 50; ++i) {
//             parent[i] = i;
//         }
//     }

//     int getRoot(int i) {
//         if (i == parent[i]) return i;
//         return parent[i] = getRoot(parent[i]);
//     }

//     void merge(int i, int j) {
//         i = getRoot(i);
//         j = getRoot(j);
        
//         parent[j] = i;
//     }

// } uf;

// struct Shark {
//     int size;
//     int speed;
//     int intel;
// } s[51];

// constexpr int INF = 987654321;
// constexpr int S = 0;
// constexpr int T = 151;

// // Group: 101 ~ 150

// int capa[152][152];
// int flow[152][152];
// vector<int> adj[152];
// int pre[152];
// int N;
// int main() {
//     scanf("%d", &N);
//     for(int i = 1; i <= N; ++i) {
//         int a, b, c; scanf("%d %d %d", &a, &b, &c);
//         s[i] = Shark{a, b, c};
//     }

//     for(int i = 1; i <= N; ++i) {
//         for(int j = 1; j <= N; ++j) {
//             if (i == j) continue;
//             if (s[i].intel >= s[j].intel && s[i].size >= s[j].size && s[i].speed >= s[j].speed) {
//                 // 잡아먹을 수 있는 상어 그룹을 나눈다.
//                 uf.merge(i, j);

//                 // 상어 1 -> 상어 2
//                 capa[i][j+50] = 1;
//                 adj[i].push_back(j+50);
//                 adj[j+50].push_back(i);
//             }
//         }
//     }
    
//     set<int> Groups;
//     // S -> G -> 상어 1 -> 상어 2 -> T
//     for(int i = 1; i <= N; ++i) {
//         // Group 확인 / G -> 상어 1
//         int gidx = uf.getRoot(i);
//         Groups.insert(gidx);
//         capa[gidx + 100][i] = 2;
//         adj[gidx + 100].push_back(i);
//         adj[i].push_back(gidx + 100);

//         // S -> G
//         capa[S][i + 100] = INF;
//         adj[S].push_back(i + 100);
//         adj[i + 100].push_back(S);

//         // 상어 2 -> T
//         capa[i+50][T] = 1;
//         adj[i+50].push_back(T);
//         adj[T].push_back(i+50);
//     }

//     _D("G NUM: %d\n", Groups.size());

//     int ans = 0;
//     while (true) {
//         fill(pre, pre+152, -1);
//         queue<int> q;
//         q.push(S);
//         while(q.size() > 0) {
//             int cur = q.front(); q.pop();
//             for(auto& t: adj[cur]) {
//                 int residual = capa[cur][t] - flow[cur][t];
//                 if (pre[t] == -1 && residual > 0) {
//                     pre[t] = cur;
//                     if (t == T) break;
//                     q.push(t);
//                 }
//             }
//             if (pre[T] != -1) break;
//         }
//         if (pre[T] == -1) break; // no augpath

//         for(int p = T; p != S; p = pre[p]) {
//             flow[pre[p]][p] += 1;
//             flow[p][pre[p]] -= 1;
//         }
//         ans += 1;
//     }
//     int emptycheck = 0;
//     // 그룹별 상황 보기 -> 그룹의 모든 상어가 죽었으면 보정해준다.
//     int visited[51] = {0,};
//     for(int i = 1; i <= N; ++i) {
//         // group idx 구하기
//         int gidx = uf.getRoot(i);
//         if (visited[gidx]) continue;
//         visited[gidx] = 1;
//         bool valid = true;
//         for(int j = 1; j <= N; ++j) {
//             int cgidx = uf.getRoot(j);
//             if (cgidx == gidx) {
//                 // 안 죽었는지 체크
//                 if (flow[j+50][T] == 0) {
//                     valid = false; // 하나라도 살아있다
//                     break;
//                 }
//             }
//         }
//         if (valid == true) {
//             // 보정치 증가
//             ++emptycheck;
//         }
//     }
//     _D("All die group num: %d\n",  emptycheck);

//     printf("%d\n", N - ans + emptycheck);
//     return 0;
// }