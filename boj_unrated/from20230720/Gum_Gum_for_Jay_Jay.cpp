#include <stdio.h>

int main() {
    int i = 0;
    char buf[100];
    while(scanf("%s", buf) != EOF) ++i;
    printf("%d\n", i / 5);
    return 0;
}