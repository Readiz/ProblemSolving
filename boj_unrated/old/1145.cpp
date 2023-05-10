#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int lcm(int a, int b, int c) {
    return lcm(lcm(a, b), c);
}

int main() {
    int a[5];
    scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);

    int minArr[10];
    minArr[0] = lcm(a[0], a[1], a[2]);
    minArr[1] = lcm(a[0], a[1], a[3]);
    minArr[2] = lcm(a[0], a[1], a[4]);
    minArr[3] = lcm(a[0], a[2], a[3]);
    minArr[4] = lcm(a[0], a[2], a[4]);
    minArr[5] = lcm(a[0], a[3], a[4]);
    minArr[6] = lcm(a[1], a[2], a[3]);
    minArr[7] = lcm(a[1], a[2], a[4]);
    minArr[8] = lcm(a[1], a[3], a[4]);
    minArr[9] = lcm(a[2], a[3], a[4]);

    int min = 987654321;
    for (int i = 0; i < 10; i++) {
        if (min > minArr[i]) min = minArr[i];
    }
    printf("%d\n", min);

    return 0;
}

/*
문제
다섯 개의 자연수가 있다. 이 수의 적어도 대부분의 배수는 위의 수 중 적어도 세 개로 나누어 지는 가장 작은 자연수이다.

서로 다른 다섯 개의 자연수가 주어질 때, 적어도 대부분의 배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 다섯 개의 자연수가 주어진다. 100보다 작거나 같은 자연수이고, 서로 다른 수이다.

출력
첫째 줄에 적어도 대부분의 배수를 출력한다.

예제 입력 1 
30 42 70 35 90
예제 출력 1 
210
*/
