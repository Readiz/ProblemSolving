#include <stdio.h>
#define MEMO_MAX 1000000
int main() {
    int memo[MEMO_MAX] = {-1, 1, 2, 4, 7, 11, };
    int X;
    scanf("%d", &X);
    for (int i = 1; i < MEMO_MAX; i++) {
        if (memo[i] == 0) { // update
            memo[i] = memo[i - 1] + (memo[i - 1] - memo[i - 2] + 1);
        }

        if (X < memo[i]) {
            // 이 경우 분모는 i - 1임
            // X == memo[i] 인 경우, 출력값은 1/(i - 1) 가 됨
            // 차이가 있는 경우, (1 + offset) / (i - 1 - offset) 이 됨.
            int offset = X - memo[i - 1];
            if (i % 2) { // 지그재그로 출력하므로
                printf("%d/%d\n", (1 + offset), (i - 1 - offset));
            } else {
                printf("%d/%d\n", (i - 1 - offset),  (1 + offset));
            }
            break;
        }
    }
    return 0;
}


/*
이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
*/
