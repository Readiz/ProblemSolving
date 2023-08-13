#include <stdio.h>
#include <string.h>

int main() {
    char buf[1010];
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", buf);
        int len = strlen(buf);
        if (len >= 6 && len <= 9) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}