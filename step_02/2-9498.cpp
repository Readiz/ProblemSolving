#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);

    if (a >= 90) {
        printf("A\n");
    } else if (a >= 80) {
        printf("B\n");
    } else if (a >= 70) {
        printf("C\n");
    } else if (a >= 60) {
        printf("D\n");
    } else {
        printf("F\n");
    }
    return 0;
}

/*
시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
*/