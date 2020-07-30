#include <stdio.h>

int main() {
    int N, T, tc = 0;
    for (scanf("%d", &T); tc < T; tc++) {
        scanf("%d", &N);
        if (N <= 30) {
            printf("NO\n");
        } else {
            // NP
            // 6 10 14 15 21 22 33 35 55 ...
            int fourthNum = N - 30; // Pick 6, 10, 14
            if (fourthNum == 6 || fourthNum == 10 || fourthNum == 14) {
                fourthNum = N - 31; // Pick 6, 10, 15
                printf("6 10 15 %d\n", fourthNum);
            } else {
                printf("6 10 14 %d\n", fourthNum);
            }
        }
    }
    return 0;
}

/*
소수
2 3 5 7 11

NP
6 10 14 22
15 21 33
35 55

=> 6 10 14 15 21 22 33 35 55

제일 작은 합은 6 + 10 + 14 => 30

30보다 작은 애들은 Nearly Prime으로 안되고, 나머지는 가능

즉 무조건 6, 10, 14 쓰고 나머지 하나를 차로 쓰면 됨.

30은 안되고 (나머지 하나가 양의 정수가 아님)
최소가 31.
*/
