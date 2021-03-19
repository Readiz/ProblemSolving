#include <stdio.h>

int X;
int minCalTry;

int calcStandardMin(int X) {
    int tmp = 0;
    while (X != 1) {
        tmp++;
        if (X % 3 == 0) {
            X /= 3;
            continue;
        }
        if (X % 2 == 0) {
            X /= 2;
            continue;
        }
        X -= 1;
    }
    return tmp;
}

void DFS(int X, int tryNum) {
    // 의미없게 되는 순간은 바로 리턴 처리.. 더 이상 계산 할 필요 없음.
    if (tryNum >= minCalTry) return;
    if (X != 1) {
        if (X % 3 == 0) {
            DFS(X / 3, tryNum + 1);
        }
        if (X % 2 == 0) {
            DFS(X / 2, tryNum + 1);
        }
        DFS(X - 1, tryNum + 1);
    } else {
        minCalTry = tryNum;
    }
}

int main() {
    scanf("%d", &X);

    // 가장 간단한 방법으로 우선 최소값을 넣어둔다 (최적화 차원..)
    minCalTry = calcStandardMin(X);

    // DFS로 최소값보다 적은 case를 찾아서 시작..
    DFS(X, 0);

    printf("%d\n", minCalTry);
    return 0;
}



/*
문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
*/
