#include <bits/stdc++.h>
using namespace std;

int main() {
    int max = -1;
    int maxPos, v;
    for(int i = 0; i < 81; ++i) {
        scanf("%d", &v);
        if (v > max) {
            max = v;
            maxPos = i;
        }
    }

    printf("%d\n%d %d\n", max, maxPos / 9 + 1, maxPos % 9 + 1);


    return 0;
}