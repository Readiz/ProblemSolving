#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        int n;
        scanf("%d", &n);
        int count[101] = {0, };
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            count[tmp]++;
        }
        int p = 0;
        int remain = n;
        while (remain > 0) {
            if (count[p] > 0) {
                printf("%d ", p);
                count[p]--;
                remain--;
            }
            p++;
            if (p > 100) p = 0;
        }
        printf("\n");
    }

}
