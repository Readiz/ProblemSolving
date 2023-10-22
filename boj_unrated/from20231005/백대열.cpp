#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b; scanf("%d:%d", &a, &b);
    int g = __gcd(a,b);
    printf("%d:%d\n", a / g, b / g);
    return 0;
}