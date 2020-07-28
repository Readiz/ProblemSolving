#include <stdio.h>

int main() {
    char binary[1000005] = {0, };
    scanf("%s", binary);
    int len = 0;
    while (binary[len] != 0)
        len++;

    if (len % 3 == 1) {
        // Shift 2번
        for (int i = len; i >= 0; i--) {
            binary[i + 2] = binary[i];
        }
        binary[0] = binary[1] = '0';
    } else if (len % 3 == 2) {
        // Shift 1번
        for (int i = len; i >= 0; i--) {
            binary[i + 1] = binary[i];
        }
        binary[0] = '0';
    }
    
    int offset;
    for (offset = 0; binary[offset] != 0; offset += 3) {
        if (binary[offset] == '0' && binary[offset + 1] == '0' && binary[offset + 2] == '0') {
            binary[offset / 3] = '0';
        } else if (binary[offset] == '0' && binary[offset + 1] == '0' && binary[offset + 2] == '1') {
            binary[offset / 3] = '1';
        } else if (binary[offset] == '0' && binary[offset + 1] == '1' && binary[offset + 2] == '0') {
            binary[offset / 3] = '2';
        } else if (binary[offset] == '0' && binary[offset + 1] == '1' && binary[offset + 2] == '1') {
            binary[offset / 3] = '3';
        } else if (binary[offset] == '1' && binary[offset + 1] == '0' && binary[offset + 2] == '0') {
            binary[offset / 3] = '4';
        } else if (binary[offset] == '1' && binary[offset + 1] == '0' && binary[offset + 2] == '1') {
            binary[offset / 3] = '5';
        } else if (binary[offset] == '1' && binary[offset + 1] == '1' && binary[offset + 2] == '0') {
            binary[offset / 3] = '6';
        } else if (binary[offset] == '1' && binary[offset + 1] == '1' && binary[offset + 2] == '1') {
            binary[offset / 3] = '7';
        }
    }
    binary[offset / 3] = 0;
    printf("%s\n", binary);
    
    return 0;
}

/*
문제
2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.
*/
