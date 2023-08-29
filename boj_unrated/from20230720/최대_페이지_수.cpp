#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, M; scanf("%d %d", &N, &M);
    int cost[20], pages[20];
    for(int i = 0; i < M; ++i) scanf("%d %d", &cost[i], &pages[i]);

    int maxPage = 0;
    int tM = 1 << M;
    for(int cur = 0; cur < tM; ++cur) {
        int overallCost = 0;
        int overallPage = 0;
        for(int i = 0, m = 1; i < M; ++i, m <<= 1) {
            if (cur & m) {
                overallCost += cost[i];
                overallPage += pages[i];
            }
        }
        if (overallCost <= N) {
            if (overallPage > maxPage) maxPage = overallPage;
        }
    }
    
    printf("%d\n", maxPage);

    return 0;
}