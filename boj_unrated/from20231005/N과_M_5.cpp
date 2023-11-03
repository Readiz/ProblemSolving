#include <bits/stdc++.h>
using namespace std;

int N, M; 
int check[10];
int v[10];

void dfs(int m, vector<int> sel) {
    if (m == M) {
        for(auto& i: sel) printf("%d ", i);
        printf("\n");
        return;
    }
    for(int i = 0; i < N; ++i) {
        if (check[i] == 1) continue;
        vector<int> sel2 = sel;
        sel2.push_back(v[i]);
        check[i] = 1;
        dfs(m + 1, sel2);
        check[i] = 0;
    }
    
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);
    sort(v, v + N);

    for(int i = 0; i < N; ++i) {
        vector<int> sel;
        sel.push_back(v[i]);
        check[i] = 1;
        dfs(1, sel);
        check[i] = 0;
    }
    

    return 0;
}