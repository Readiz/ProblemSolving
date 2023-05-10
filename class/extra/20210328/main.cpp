#include <stdio.h>
#include <string.h>
#include <time.h>

char jnum_a[15000];
char jnum_b[15000];
char result[33000];
char real_ret[33000];

extern void solution(char*, char*, char*);

int main() {
    freopen("input.txt", "r", stdin);
    fflush(stdin);
    int testcase;
    int score = 0;
    int panelty = 0;
    register int i;
    clock_t start;
    for (testcase = 0; testcase < 100; ++testcase) {
        scanf("%s", jnum_a);
        scanf("%s", jnum_b);
        scanf("%s", real_ret);
        start = clock();
        solution(result, jnum_a, jnum_b);
        score += (clock() - start) * 1000 / CLOCKS_PER_SEC;
        if (strcmp(result, real_ret)) panelty++;
    }

    printf("%d %d\n", score, panelty);
}