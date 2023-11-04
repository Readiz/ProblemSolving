#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int N, K;
vector<int> v;

void dfs(int a, vector<int> cur) {
    if (cur.size() == K) {
        for(int i = 0; i < cur.size(); ++i) {
            printf("%d ", cur[i]);
        }
        printf("\n");
        return;
    }
    for(int i = a; i < N; ++i) {
        vector<int> tmp = cur;
        tmp.push_back(v[i]);
        dfs(i, tmp);
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; ++i) {
        vector<int> cur;
        cur.push_back(v[i]);
        dfs(i, cur);
    }

    return 0;
}