// Flow 연습문제

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ctoi(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

constexpr int INF = 987654321;

int flow[52][52] = {0, }; // a -> b로 가는 flow
int capa[52][52] = {0, }; // a -> b의 용량 -> 이 문제에서는 양방향 용량이 같다.
int d[52];
int inQ[52];
int pre[52];

int main() {
    int N; scanf("%d", &N);

    char buf1[2], buf2[2];
    for(int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%s %s %d", buf1, buf2, &c);
        a = ctoi(buf1[0]);
        b = ctoi(buf2[0]);

        capa[a][b] += c;
        capa[b][a] += c;
    }

    // for(int i = 0; i < 26; ++i) {
    //     for(int j = 0; j < 26; ++j) {
    //         printf("%d ", capa[i][j]);
    //     }
    //     printf("\n");
    // }

    // 알고리즘으로 생각하지 말고 흐름에 몸을 맡기자.
    while (true) {

        // 증가경로를 하나 찾아보자
        fill(d, d+52, INF);
        fill(inQ, inQ+52, 0);
        fill(pre, pre+52, -1);
        d[ctoi('A')] = 0;
        queue<int> q;
        q.push(ctoi('A'));
        inQ[ctoi('A')] = 1;

        while(q.size()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;

            for(int t = 0; t < 52; ++t) {
                int r = capa[cur][t] - flow[cur][t];
                if (r > 0 && d[t] == INF) {
                    d[t] = 1;
                    pre[t] = cur;
                    inQ[t] = 1;
                    q.push(t);
                }
            }
        }
        if (d[ctoi('Z')] == INF) {
            // 더이상 증가 path가 없다
            break;
        }
        // 경로가 있다!
        // printf("path exists!\n");
        
        // for(int p = ctoi('Z'); p != -1; p = pre[p]) {
        //     printf("%d ", p);
        // }
        // printf("\n");

        // 경로에 대해서
        // 1. 해당 경로의 최대 유량을 찾는다
        int maxFlow = INF;
        for(int p = ctoi('Z'); pre[p] != -1; p = pre[p]) {
            maxFlow = min(capa[pre[p]][p] - flow[pre[p]][p], maxFlow);
        }

        // 2. flow를 업데이트 한다. (역방향도 해줘야함)
        for(int p = ctoi('Z'); pre[p] != -1; p = pre[p]) {
            flow[pre[p]][p] += maxFlow;
            flow[p][pre[p]] -= maxFlow;
            // printf("flow[%d][%d] += %d -> %d\n", pre[p], p, maxFlow, flow[pre[p]][p]);
        }
    }

    int ans = 0;
    for(int i = 0; i < 52; ++i) {
        ans += flow[i][ctoi('Z')];
    }

    printf("%d\n", ans);

    return 0;
}