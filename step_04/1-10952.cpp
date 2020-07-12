#include <stdio.h>

int main() {
    int a = -1, b = -1;
    while (a != 0 && b != 0) {
        scanf("%d %d", &a, &b);
        if (a != 0 && b != 0)
            printf("%d\n", a + b);
    }

    return 0;
}

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
*/