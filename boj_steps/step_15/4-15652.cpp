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
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
