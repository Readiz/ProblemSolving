#include <bits/stdc++.h>
using namespace std;

struct Node {
    int score;
    int remain;
};
Node mstack[1'000'010];
int msp = 0;

int main() {
    int N; scanf("%d", &N);
    int score = 0;
    while(N--) {
        int cmd; scanf("%d", &cmd);
        if (cmd) {
            int a, b;
            scanf("%d %d", &a, &b);
            mstack[msp++] = Node{a, b};
        }
        if (msp) {
            mstack[msp-1].remain--;
            if (mstack[msp-1].remain == 0) {
                score += mstack[msp-1].score;
                msp--;
            }
        }
    }
    printf("%d\n", score);

    return 0;
}