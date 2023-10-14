#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; long long P; scanf("%d %d %lld", &N, &M, &P);
    int numItem = 0;
    for(int i = 0; i < N; ++i) {
        vector<int> e;
        for(int j = 0; j < M; ++j) {
            int tmp; scanf("%d", &tmp);
            if (tmp == -1) ++numItem;
            else e.push_back(tmp);
        }
        sort(e.begin(), e.end());

        for(auto& i: e) {
            while (i > P) {
                if (numItem > 0) {
                    --numItem;
                    P *= 2;
                    // printf("[f] item used -> %lld\n", P);
                } else {
                    printf("0\n");
                    return 0;
                }
            }
            P += i;
            // printf("[e] added %d.\n", i);
        }
        while (numItem > 0) {
            P *= 2;
            --numItem;
        }
        // printf("[d] %lld\n", P);
    }
    printf("1\n");

    return 0;
}