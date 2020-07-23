#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

static void swap(Point& a, Point& b) {
    Point* tmp;
    tmp = &a;
    &a = &b;
    &b = tmp;
    
    // printf("A: %d %d / B: %d %d\n", a.x, a.y, b.x, b.y);
    // int tmpx, tmpy;
    // tmpx = a.x;
    // tmpy = a.y;
    
    // a.x = b.x;
    // a.y = b.y;
    
    // b.x = tmpx;
    // b.y = tmpy;

    // printf("A: %d %d / B: %d %d\n", a.x, a.y, b.x, b.y);
    return;
}

int main() {
    int N;
    scanf("%d", &N);
    Point p[100000];

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i].x = x;
        p[i].y = y;
    }
    swap(p[0], p[1]);
    printf("%d %d\n", p[0].x, p[0].y);
    return 0;
}


/*
문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/
