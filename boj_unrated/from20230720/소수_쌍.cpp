#include <bits/stdc++.h>
using namespace std;

#define _D(...) printf(__VA_ARGS__)
typedef long long ll;
typedef unsigned long long ull;

bool isPrime(int v) {
    for(int i = 2; i * i <= v; ++i) {
        if (v % i == 0) return false;
    }
    return true;
}

bool match(vector<int>& B) {
    int S = 98, T = 99;
    int capa[100][100] = {0,};
    int flow[100][100] = {0,};
    int pre[100];
    vector<int> adj[100];

    for(int i = 0; i < B.size(); ++i) {
        capa[S][i] = 1;
        adj[S].push_back(i);
        adj[i].push_back(S);

        capa[i+48][T] = 1;
        adj[i+48].push_back(T);
        adj[T].push_back(i+48);

        for(int j = 0; j < B.size(); ++j) {
            if (i == j) continue;
            if(isPrime(B[i] + B[j])) { // 소수면 서로 이어준다.
                capa[i][j+48] = 1;
                adj[i].push_back(j+48);
                adj[j+48].push_back(i);
                // _D("%d + %d -> prime.\n", B[i], B[j]);
            }
        }
    }

    int ans = B.size();
    while(true) {
        fill(pre, pre+100, -1);
        queue<int> q;
        q.push(S);
        while(q.size()) {
            int cur = q.front(); q.pop();
            for(auto& t: adj[cur]) {
                int residual = capa[cur][t] - flow[cur][t];
                if(residual > 0 && pre[t] == -1) {
                    pre[t] = cur;
                    if (t == T) break;
                    q.push(t);
                }
            }
            if (pre[T] != -1) break;
        }
        if(pre[T] == -1) break; // no augpath

        for(int p = T; p != S; p = pre[p]) {
            flow[pre[p]][p] += 1;
            flow[p][pre[p]] -= 1;
        }

        ans--;
    }

    // _D("remained: %d -> false!\n", ans);
    if (ans == 0) return true; // 이분 매칭 되었음
    return false; // 남았음
}

int main() {
    int N; scanf("%d", &N);
    vector<int> ans;
    vector<int> A;
    for(int i = 0; i < N; ++i) {
        int tmp; scanf("%d", &tmp);
        A.push_back(tmp);
    }
    for(int j = 1; j < N; ++j) {
        if (isPrime(A[0] + A[j])) {
            // 0, j를 빼고 이분매칭 시도한다.
            vector<int> B;
            for(int i = 1; i < N; ++i) {
                if (i != j) B.push_back(A[i]);
            }
            bool res = match(B);
            if(res) ans.push_back(A[j]);
        }
    }

    if(ans.size() == 0) {
        printf("-1\n");
        return 0;
    }

    sort(ans.begin(), ans.end());
    for(auto& item: ans) {
        printf("%d ", item);
    }
    printf("\n");

    return 0;
}