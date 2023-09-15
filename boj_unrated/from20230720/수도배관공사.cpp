#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Pipe {
    int len, capa;
};
int DP[100'001] = {0, }; // 길이 L에서의 max Capacity
int main() {
    int D, P; scanf("%d %d", &D, &P);
    vector<Pipe> pipe(P+1);
    for(int i = 1; i <= P; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        pipe[i] = {a, b};
    }

    for(int i = 1; i <= P; ++i) {
        for(int j = D; j >= pipe[i].len; --j) {
            if (DP[j - pipe[i].len] != 0) {
                DP[j] = max(DP[j], min(DP[j - pipe[i].len], pipe[i].capa));
            }
        }
        DP[pipe[i].len] = max(DP[pipe[i].len], pipe[i].capa);
    }

    printf("%d\n", DP[D]);

    return 0;
}