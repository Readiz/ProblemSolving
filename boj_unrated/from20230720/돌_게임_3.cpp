#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    set<int> CY;
    CY.insert(2);
    int cur = 2;
    for(int i = 1; i < 1000; ++i) {
        if (i & 1) {
            cur += 5;
        } else {
            cur += 2;
        }
        CY.insert(cur);
    }

    int N; scanf("%d", &N);
    if (CY.find(N) == CY.end()) {
        printf("SK\n");
    } else {
        printf("CY\n");
    }

    return 0;
}