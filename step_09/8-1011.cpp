#include <stdio.h>
#define MEMO_MAX 100000000
int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        unsigned int memo[MEMO_MAX] = { 0, 1, 2, 4, 6, 9, 12, 16, };
        unsigned int x, y, diff;
        scanf("%u %u", &x, &y);
        diff = y - x;
        for (int i = 1; i < MEMO_MAX; i++) {
            if (memo[i] == 0) {
                memo[i] = memo[i - 1] + (unsigned int)((i + 1) / 2);
            }
            if (memo[i] >= diff) {
                printf("%d\n", i);
                break;                
            }
        }
    }
    return 0;
}

/*
가장 적게 공간이동 하려면 당연히 가속을 풀로 땡기다가, 서서히 감속해야 할 것.
그리고 직전에는 k = 1이 되어야 하고..
그러면 요런 형태임
1 2 3 4 5 6 5 4 3 2 1 ... => 이 최대값보다 적은 횟수로.. 갈 수 있는 요런 느낌
그럼 요 형태의 배열을 가지고 있으면 될 듯...? (최대거리가 되는거니)

공간이동 장치 발동 수에 따른 max 거리
1: 1                => 1   (  1) <- (i + 1) / 2 의 값
2: 1 1              => 2  ( + 1)
3: 1 2 1            => 4  ( + 2)
4: 1 2 2 1          => 6  ( + 2)
5: 1 2 3 2 1        => 9  ( + 3)
6: 1 2 3 3 2 1      => 12 ( + 3)
7: 1 2 3 4 3 2 1    => 16 ( + 4)

*/
