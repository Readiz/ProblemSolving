#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        int N;
        int score[1001] = {0, };
        scanf("%d", &N);
        double avg;
        int sum = 0;
        for (int j = 0; j < N; j++) {
            int tmp;
            scanf("%d", &tmp);
            sum += tmp;
            score[j] = tmp;
        }
        avg = (double)sum / N;
        int number_of_above_avg = 0;
        for (int j = 0; j < N; j++) {
            if (score[j] > avg) number_of_above_avg++;
        }
        printf("%.3lf%\n", (double)number_of_above_avg / N * 100);
    }
    return 0;
}

/*
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 
점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
*/