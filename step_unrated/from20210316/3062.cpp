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
int len(char s[]) {
    int p;
    for (p = 0; s[p] != 0; p++);
    return p;
}
void swap(char& a, char& b) {
    char t = a;
    a = b;
    b = t;
}
void inverse(char s[]) {
    int l = len(s);
    for (int i = 0; i < l / 2; i++) {
        swap(s[i], s[l - i - 1]);
    }
}
int atoi(char s[]) {
    int r = 0;
    for (int p = 0; s[p] != 0; p++) {
        r += s[p] - '0';
        r *= 10;
    }
    return r / 10;
}
void itoa(int num, char s[]) {
    int p = 0;
    while (num > 0) {
        s[p++] = num % 10 + '0';
        num /= 10;
    }
    s[p] = 0; // NULL 추가
    inverse(s);
}
bool isReversable(char s[]) {
    int l = len(s);
    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l - i - 1]) {
            return false;
        }
    }
    return true;
}
MAIN_START
    int T;
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &T);
    printd("Input - T: %d", T);
    for (int i = 0; i < T; i++) {
        char str[10];
        scanf("%s", str);
        printd("num: %s", str);
        int a = atoi(str);
        inverse(str);
        printd("inv: %s", str);
        int b = atoi(str);
        int sum = a + b;
        printd("sum: %d", sum);
        itoa(sum, str);
        printd("sumStr: %s", str);
        if(isReversable(str)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    printd("--------------------------");
MAIN_END

/*
수 뒤집기 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	3366	1690	1500	52.891%
문제
수 124를 뒤집으면 421이 되고 이 두 수를 합하면 545가 된다. 124와 같이 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되는지 테스트 하는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄에 하나의 정수 N(10 ≤ N ≤ 100000)이 주어진다.

출력
각 테스트 케이스에 대해서 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되면 YES를 아니면 NO를 한 줄에 하나씩 출력한다.

예제 입력 1 
4
13
58
120
5056
예제 출력 1 
YES
NO
YES
NO
*/
