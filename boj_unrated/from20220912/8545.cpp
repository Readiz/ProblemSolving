#include <stdio.h>
char buf[5];
int main() {
    scanf("%s", buf);
    printf("%c%c%c", buf[2], buf[1], buf[0]);
    return 0;
}