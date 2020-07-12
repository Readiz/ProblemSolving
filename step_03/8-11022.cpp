#include <stdio.h>

int main() {
    int T, a, b;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }

    return 0;
}

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
*/