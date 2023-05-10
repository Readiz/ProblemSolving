#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    int minx = 0x7FFFFFFF;
    int miny = 0x7FFFFFFF;
    int maxx = 0x80000000;
    int maxy = 0x80000000;
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        if (a < minx) minx = a;
        if (b < miny) miny = b;
        if (a > maxx) maxx = a;
        if (b > maxy) maxy = b;
    }
    printf("%d\n", (maxx - minx) * (maxy - miny));

    return 0;
}