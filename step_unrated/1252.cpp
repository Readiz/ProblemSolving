#include <stdio.h>

int len(char a[]) {
    int p;
    for (p = 0; a[p] != 0; p++);
    return p;
}

void trimFirst0s(char a[]) {
    int s = 0;
    int p = 0;
    bool isNoneZero = true;
    for (p = 0; a[p] != 0; p++) {
        if (a[p] == '1') {
            s = p;
            isNoneZero = false;
            break;
        }
    }
    if (isNoneZero) { // 000000 출력 방지
        a[0] = '0';
        a[1] = 0;
        return;
    }
    for (p = 0; a[p] != 0; p++) {
        a[p] = a[p + s];
    }
    a[p] = 0;
}

int main() {
    char a[81] = {0, };
    char b[81] = {0, };
    scanf("%s %s", a, b);
    trimFirst0s(a); trimFirst0s(b);
    if (len(a) < len(b)) {
        for (int i = 0; i < 81; i++) {
            char tmp = a[i];
            a[i] = b[i];
            b[i] = tmp;
        }
    }

    int pb = len(b) - 1;
    bool carry = false;
    for (int pa = len(a) - 1; pa >= 0; pa--, pb--) {
        char ca = a[pa];
        char cb = (pb >= 0) ? b[pb] : '0';

        if (carry) { // 받아 올림이 있는 경우
            if ((ca == '1' && cb == '0') || (ca == '0' && cb == '1')) {
                carry = true;
                a[pa] = '0';
            } else if (ca == '1' && cb == '1') {
                carry = true;
                a[pa] = '1';
            } else { // 0 + 0 + 1
                carry = false;
                a[pa] = '1';
            }
        } else {
            if (ca == '1' && cb == '1') {
                carry = true;
                a[pa] = '0';
            } else if ((ca == '1' && cb == '0') || (ca == '0' && cb == '1')) {
                carry = false;
                a[pa] = '1';
            } else {
                carry = false;
                a[pa] = '0';
            }
        }
    }

    if (carry) {
        printf("1%s\n", a);
    } else {
        printf("%s\n", a);
    }

    return 0;
}

/*
이진수 덧셈 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	6041	1680	1479	29.334%
문제
두 개의 이진수를 입력받아 이를 더하는 프로그램을 작성하시오.

입력
첫째 줄에 두 개의 이진수가 빈 칸을 사이에 두고 주어진다. 각 이진수는 1 또는 0으로만 이루어져 있으며, 0으로 시작할 수도 있다. 또한 각 이진수의 길이는 80을 넘지 않는다.

출력
첫째 줄에 이진수 덧셈 결과를 출력한다. 결과가 0인 경우를 제외하고는 출력되는 이진수는 항상 1로 시작해야 한다.

예제 입력 1 
1001101 10010
예제 출력 1 
1011111
*/
