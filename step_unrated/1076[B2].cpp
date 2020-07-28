#include <stdio.h>

int main() {
    char color[20];
    long long val = 0;
    for (int i = 0; i < 2; i++) {
        val *= 10;
        scanf("%s", color);
        if (color[0] == 'b') {
            if (color[1] == 'r') {
                val += 1;
            } else if (color[2] == 'u') {
                val += 6;
            }
        } else if (color[0] == 'r') {
            val += 2;
        } else if (color[0] == 'o') {
            val += 3;
        } else if (color[0] == 'y') {
            val += 4;
        } else if (color[0] == 'g') {
            if (color[3] == 'e') {
                val += 5;
            } else if (color[3] == 'y') {
                val += 8;
            }
        } else if (color[0] == 'v') {
            val += 7;
        } else if (color[0] == 'w') {
            val += 9;
        }
    }

    scanf("%s", color);
    if (color[0] == 'b') {
        if (color[1] == 'r') {
            val *= 10;
        } else if (color[2] == 'u') {
            val *= 1000000;
        }
    } else if (color[0] == 'r') {
        val *= 100;
    } else if (color[0] == 'o') {
        val *= 1000;
    } else if (color[0] == 'y') {
        val *= 10000;
    } else if (color[0] == 'g') {
        if (color[3] == 'e') {
            val *= 100000;
        } else if (color[3] == 'y') {
            val *= 100000000;
        }
    } else if (color[0] == 'v') {
        val *= 10000000;
    } else if (color[0] == 'w') {
        val *= 1000000000;
    }
    printf("%lld\n", val);
    return 0;
}

/*
#저항

문제
전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.

처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다.

저항의 값은 다음 표를 이용해서 구한다.

색	값	곱
black	0	1
brown	1	10
red	2	100
orange	3	1000
yellow	4	10000
green	5	100000
blue	6	1000000
violet	7	10000000
grey	8	100000000
white	9	1000000000
예를 들어, 저항에 색이 yellow, violet, red였다면 저항의 값은 4,700이 된다.

입력
첫째 줄에 첫 번째 색, 둘째 줄에 두 번째 색, 셋째 줄에 세 번째 색이 주어진다. 색은 모두 위의 표에 쓰여 있는 색만 주어진다.

출력
입력으로 주어진 저항의 저항값을 계산하여 첫째 줄에 출력한다.
*/
