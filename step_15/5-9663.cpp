#include <stdio.h>

int N, M;

void printCurrentNumIfItIsAcending(int num) {
    int reverse = 0;
    while (num != 0) {
        reverse *= 10;
        reverse += num % 10;
        if (num % 10 >= (num / 10) % 10) {
            // do nothing
        } else {
            // Not acending, so it's return and do nothing
            return;
        }
        num /= 10;
    }
    while (reverse != 0) {
        printf("%d ", reverse % 10);
        reverse /= 10;
    }
    printf("\n");
}

void printNum(int step, int currentNum) {
    if (step == M) { // 최종까지 왔을 경우
        // 출력한다.
        printCurrentNumIfItIsAcending(currentNum);
        return;
    }

    for (int i = 1; i <= N; i++) {
        // 안쓰인 숫자들에 한해 아래 단계로 내린다.
        printNum(step + 1, currentNum * 10 + i);
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    printNum(0, 0);

    return 0;
}

/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/
