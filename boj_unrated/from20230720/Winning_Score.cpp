#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int a, b, c, d, e, f; scanf("%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f);
    if (a * 3 + b * 2 + c > d * 3 + e * 2 + f) {
        printf("A\n");
    } else if (a * 3 + b * 2 + c == d * 3 + e * 2 + f) {
        printf("T\n");
    } else {
        printf("B\n");
    }
    

    return 0;
}