#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int visited[10];
int N, M;
void dfs(int v, int depth, vector<int>& cur) {
    if (visited[v]) return;
    visited[v] = 1;
    
    if (depth == M) {
        for(auto& v: cur) {
            printf("%d ", v);
        }
        printf("\n");
        return;
    }

    for(int s: vec) {
        if (visited[s]) continue;
        cur.push_back(s);
        dfs(s, depth + 1, cur);
        cur.pop_back();
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        int a; scanf("%d", &a);
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    for(int s: vec) {
        printf("check %d...\n", s);
        for(int i = 1; i <= N; ++i) visited[i] = false;
        vector<int> cur;
        cur.push_back(s);
        dfs(s, 1, cur);
    }
    
    return 0;
}