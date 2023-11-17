#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char a[100], b[100];
int main() {
    scanf("%s %s", a, b);
    int la = strlen(a);
    int lb = strlen(b);

    int mmin = 987654321;
    for(int offset = 0; offset + la <= lb; ++offset) {
        int cur = 0;
        for(int i = 0; i < la; ++i) {
            if (a[i] != b[i + offset]) {
                cur += 1;
            }
        }
        if (cur < mmin) mmin = cur;
    }

    printf("%d\n", mmin);

    return 0;
}