#include <stdio.h>

int main() {
    int v = 0;
    for (int i = 0; i < 5; i++) {
        int tmp;
        scanf("%d", &tmp);
        v = (v + tmp * tmp) % 10;
    }
    printf("%d\n", v);
    return 0;
}

/*
검증수 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	16016	12196	10968	77.611%
문제
컴퓨터를 제조하는 회사인 KOI 전자에서는 제조하는 컴퓨터마다 6자리의 고유번호를 매긴다. 고유번호의 처음 5자리에는 00000부터 99999까지의 수 중 하나가 주어지며 6번째 자리에는 검증수가 들어간다. 검증수는 고유번호의 처음 5자리에 들어가는 5개의 숫자를 각각 제곱한 수의 합을 10으로 나눈 나머지이다.

예를 들어 고유번호의 처음 5자리의 숫자들이 04256이면, 각 숫자를 제곱한 수들의 합 0+16+4+25+36 = 81 을 10으로 나눈 나머지인 1이 검증수이다.

입력
첫째 줄에 고유번호의 처음 5자리의 숫자들이 빈칸을 사이에 두고 하나씩 주어진다.

출력
첫째 줄에 검증수를 출력한다.

예제 입력 1 
0 4 2 5 6
예제 출력 1 
1
*/
