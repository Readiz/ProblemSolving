#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d,e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    if (a <= 0) {
        printf("%d\n", -a * c + d + b * e);
    } else {
        printf("%d\n", (b - a) * e);
    }

    return 0;
}