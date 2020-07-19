#include <stdio.h>
#define ABS(x) ( ((x)<0)?-(x):(x) )
int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int d[4];
    d[0] = ABS(w - x);
    d[1] = ABS(h - y);
    d[2] = ABS(x);
    d[3] = ABS(y);
    
    int min = 10000;
    for (int i = 0; i < 4; i++) {
        if (d[i] < min) min = d[i];
    }
    printf("%d\n", min);   

    return 0;
}

/*
문제
한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 x y w h가 주어진다. w와 h는 1,000보다 작거나 같은 자연수이고, x는 1보다 크거나 같고, w-1보다 작거나 같은 자연수이고, y는 1보다 크거나 같고, h-1보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.
*/
