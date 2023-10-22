#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    char a[2510], b[2510]; scanf("%[^\n]", a); getchar(); scanf("%[^\n]", b);
    int la = strlen(a);
    int lb = strlen(b);
    int cnt = 0;
    for(int i = 0; i < la; ++i) {
        bool same = true;
        for(int j = 0; j < lb; ++j) {
            if (i + j >= la) {
                same = false;
                break;
            }
            if (a[i + j] == b[j]) continue;
            same = false;
            break; 
        }
        if (same) {
            ++cnt;
            i += lb - 1;
        }
    }
    printf("%d\n", cnt);

    return 0;
}