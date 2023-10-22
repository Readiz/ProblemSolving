#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char buf[1'000'010];
int main() {
    scanf("%s", buf);
    int zero = 0, one = 0;
    int len = strlen(buf);
    char last = buf[0];
    for(int i = 1; i <= len; ++i) {
        if (buf[i] == last) continue;
        if (last == '1') one++;
        else zero++;
        last = buf[i];
    }
    printf("%d\n", min(zero, one));

    return 0;
}