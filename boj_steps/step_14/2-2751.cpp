#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    bool numStore[2000001] = {false, };
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        numStore[tmp + 1000000] = true;
    }
    for (int i = 0; i < 2000001; i++) {
        if (numStore[i]) {
            printf("%d\n", i - 1000000);
        }
    }
    return 0;
}

/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/
