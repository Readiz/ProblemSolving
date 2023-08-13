#include <stdio.h>

int main() {
    int n, w, h, l; scanf("%d %d %d %d", &n, &w, &h, &l);
    
    int ww = w / l;
    int hh = h / l;
    int r = ww * hh;
    if (r >= n) printf("%d\n", n);
    else printf("%d\n", r);

    return 0;
}