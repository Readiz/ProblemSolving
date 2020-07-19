#include <stdio.h>
#define MAX_SIZE 6563
// 일정 크기 이상의 board는 지역에서 선언하면 Segmentation fault 뜸
// https://kldp.org/node/47473
char board[MAX_SIZE][MAX_SIZE];

int log3(int num) {
    int step = 0;
    while (num /= 3) step++;
    return step;
}

int pow3(int num) {
    int result = 1;
    for (int i = 0; i < num; i++) {
        result *= 3;
    }
    return result;
}

int main() {
    // 보드 초기화
    board[0][0] = '*'; board[0][1] = '*'; board[0][2] = '*';
    board[1][0] = '*'; board[1][1] = ' '; board[1][2] = '*';
    board[2][0] = '*'; board[2][1] = '*'; board[2][2] = '*';

    int N;
    scanf("%d", &N);
    for (int step = 1; step <= log3(N); step++) {
        if (step == 1) continue;
        // 이전 step 크기 만큼을 copy 하여 paste 하는 구조로 계산 하면 됨
        // step 1이 위 초기값이고, step 2는 이 초기값 전체를 복사.. 하는 구조.
        // 일단 복제한 뒤, 중간 부분을 ' '로 채우는 방법이 제일 간단할 듯.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0 && j == 0) continue;
                // 복사하는 부분, x & y => offset_x & offset_y
                int jump_step;
                jump_step = pow3(step - 1);
                for (int x = 0; x < jump_step; x++) {
                    for (int y = 0; y < jump_step; y++) {
                        // ' ' 로 채우는 부분
                        if (i == 1 && j == 1) {
                            board[i * jump_step + x][j * jump_step + y] = ' ';
                        } else {
                            board[i * jump_step + x][j * jump_step + y] = board[x][y];
                        }
                    }
                }
            }
        }
    }

    // 출력 시작
    for (int i = 0; i < MAX_SIZE; i++) {
        if (board[i][0] != 0) 
            printf("%s\n", board[i]);
    }
    return 0;
}
// MAX: 3^8 => 6561

/*
문제
재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.

크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.

***
* *
***
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

입력
첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.

출력
첫째 줄부터 N번째 줄까지 별을 출력한다.
*/
