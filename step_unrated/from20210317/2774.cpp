#include <stdio.h>
#ifndef BOJ
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

MAIN_START
    int T;
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &T);
    printd("Input - T: %d", T);
    printd("--------------------------");
    for (int tc = 0; tc < T; tc++) {
        int sum = 0;
        char s[1000] = {0, };
        bool appeared[10] = {false, };
        scanf("%s", s);
        printd("%s", s);
        for (int p = 0; s[p] != 0; p++) {
            int a = s[p] - '0';
            if (appeared[a] == false) {
                sum++;
                appeared[a] = true;
            }
        }
        // printf("%d\n", sum);
    }
MAIN_END


/*
아름다운 수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	2389	1608	1469	69.687%
문제
윤정이는 뭐든지 아름다운 것이 좋다고 생각한다. 그래서 윤정이는 사물을 볼 때 자신이 정한 방법으로 아름다운 정도를 평가한다. 윤정이는 수를 볼 때도 이런 아름다운 수의 정도를 따지는데, 윤정이에게 있어서 아름다운 수의 정도는 그 수를 이루고 있는 10진수의 중복되지 않은 숫자의 개수를 의미한다.  예를 들어 122이라는 수는 1과 2 라는 2개의 숫자로 이루어져 있으므로 아름다운 정도가 2가 된다. 윤정이의 방법으로 여러 수들의 아름다운 정도를 알아보자.

입력
첫째 줄에는 테스트 케이스의 개수 T가 주어진다. 다음 줄부터는 아름다운 정도를 알고 싶은 수 X(1 ≤ X ≤ 1000000000)가 주어진다.

출력
각각의 테스트 케이스마다 X의 아름다운 정도를 한 줄에 하나씩 입력으로 주어진 순서대로 출력한다.

예제 입력 1 
2
7
122
예제 출력 1 
1
2
*/
