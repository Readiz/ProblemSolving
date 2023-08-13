#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {

    set<int> S;
    for(int i = 0; i < 5; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (S.find(tmp) == S.end()) {
            S.insert(tmp);
        } else {
            S.erase(tmp);
        }
    }
    printf("%d\n", *S.begin());

    return 0;
}