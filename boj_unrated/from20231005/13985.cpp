#include <stdio.h>

int main() {
    char buf[10]; scanf("%[^\n]", buf);

    if ((buf[0] - '0' + buf[4] - '0') == (buf[8] - '0')) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}