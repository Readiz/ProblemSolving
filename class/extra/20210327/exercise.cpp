#include <stdio.h>

#define atoi(x) ((x) - '0')
#define itoa(x) ((x) + '0')

int main() {
    char A[4] = "111";
    char B[4] = "111";
    char C[8] = {0, };

    int tC[8] = {0, };

    for (register int i = 0; i < 3; i++) {
        for (register int j = 0; j < 3; j++) {
            tC[i + j] += atoi(A[i]) * atoi(B[i]);
        }
    }

    for (register int i = 0; i < 6; i++) {
        if (tC[i] > 10) {
            tC[i + 1] = tC[i] / 10;
            tC[i] %= 10;
        }
        C[i] = itoa(tC[i]);
    }

    printf("%s\n", C);

}