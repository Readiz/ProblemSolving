#include <stdio.h>

char map[10000][10000] = {0, };

void getSum() {
    int sum = 0;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            sum += map[i][j];
        }
    }
    printf("%d", sum);
}

int main() {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            map[a][b] = c;
        }
    }

    getSum();

}