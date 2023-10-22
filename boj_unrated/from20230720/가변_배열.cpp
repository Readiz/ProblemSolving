#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int capa, size = 0, N, M; scanf("%d%d%d", &capa, &N, &M);
    for(int i = 0; i < N + M; ++i) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            if (size == capa) capa *= 2;
            ++size;
        } else {
            --size;
        }
    }
    printf("%d\n", capa);
    

    return 0;
}