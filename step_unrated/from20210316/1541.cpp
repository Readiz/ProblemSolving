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
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    char str[100] = {0, };
    scanf("%s", str);
    printd("Input - %s", str);
    int l = len(str);
    int p = 0;
    int sum = 0;
    bool isMinusFound = false; // (-) 찾은 뒤로는 기호 상관없이 숫자 나오는거 쭉 다 빼면 됨.
    bool isNextMinusFound = false; // 찾고나서 바로 빼면 안되니 딜레이 주는 역할임
    for (int i = 0; i <= l; i++) {
        if (str[i] == '-' || str[i] == '+' || str[i] == 0) {
            if (str[i] == '-') {
                isNextMinusFound = true;
            }
            str[i] = 0;
            if (!isMinusFound) {
                sum += atoi(&str[p]);
            } else {
                sum -= atoi(&str[p]);
            }
            p = i + 1;
            if (isNextMinusFound) isMinusFound = true;
        }
    }
    printf("%d\n", sum);
    printd("--------------------------");
MAIN_END

/*
잃어버린 괄호 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	23760	11273	9147	47.875%
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1 
55-50+40
예제 출력 1 
-35
*/
