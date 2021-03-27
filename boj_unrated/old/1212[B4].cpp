#include <stdio.h>

int main() {
    char octa[333335];
    scanf("%s", octa);
    bool isFirst = true;
    for (int p = 0; octa[p] != 0; p++) {
        switch (octa[p]) {
            case '1':
                if (isFirst) printf("1");
                else printf("001");
            break;
            case '2':
                if (isFirst) printf("10");
                else printf("010");
            break;
            case '3':
                if (isFirst) printf("11");
                else printf("011");
            break;
            case '4':
                printf("100");
            break;
            case '5':
                printf("101");
            break;
            case '6':
                printf("110");
            break;
            case '7':
                printf("111");
            break;
            case '0':
                if (isFirst) printf("0");
                else printf("000");
            break;
        }
        isFirst = false;
    }
    printf("\n");
    return 0;
}

/*
문제
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.

출력
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.
*/
