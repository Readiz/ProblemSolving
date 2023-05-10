#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char num[102];
    scanf("%s", num);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += num[i] - '0';
    }

    printf("%d\n", sum);
}

/*
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
*/
