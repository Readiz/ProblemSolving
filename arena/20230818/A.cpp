#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char buf[20];
int main() {
    scanf("%s", buf);
    int len = strlen(buf);
    printf("YES\n");
    bool isFirst = true;
    for(int i = 2; i < len; ++i) {
        if (buf[i] == '0' && isFirst) continue;
        isFirst = false;
        printf("%c", buf[i]);
    }
    printf(" 1");
    for(int i = 2; i < len; ++i) printf("0");
    printf("\n");

    return 0;
}