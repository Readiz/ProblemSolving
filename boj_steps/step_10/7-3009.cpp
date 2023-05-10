#include <stdio.h>

int main() {
    int xptr[1001] = {0, };
    int yptr[1001] = {0, };

    int x, y;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &x, &y);
        xptr[x]++;
        yptr[y]++;
    }
    
    int newX, newY;
    for (int i = 0; i < 1001; i++) {
        if (xptr[i] == 1) newX = i;
        if (yptr[i] == 1) newY = i;
    };

    printf("%d %d\n", newX, newY);

    return 0;
}

/*
문제
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

입력
세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

출력
직사각형의 네 번째 점의 좌표를 출력한다.
*/
