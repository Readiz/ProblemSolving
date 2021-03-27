#include <stdio.h>
#ifndef ONLINE_JUDGE
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
char s[5000001] = {0, };
MAIN_START
    int N;
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &N);
    printd("Input - N: %d", N);
    scanf("%s", s);
    printd("%s", s);
    printd("--------------------------");
    int startPos = -1;
    unsigned long long sum = 0;
    s[N] = 0;
    for (int p = 0; p <= N; p++) {
        if (startPos == -1) { // 숫자 시작 전이면
            if (s[p] >= '0' && s[p] <= '9') {
                startPos = p; // 기록하고 계속 진행
                continue;
            }
        } else {
            if (s[p] < '0' || s[p] > '9') { // 숫자가 끝났으면
                s[p] = 0; // 문자열의 끝을 만들어주고..
                printd("Found! %d", atoi(&s[startPos]));
                sum += (unsigned long long) atoi(&s[startPos]); // 숫자 구해서 더 해준다.
                startPos = -1;
            }
        }
    }
    printf("%llu\n", sum);
MAIN_END


/*
히든 넘버 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	3878	1179	874	29.329%
문제
단어에 숫자가 숨어있다. 이 숫자를 히든 넘버라고 한다. 알파벳 대/소문자와 숫자로 이루어진 단어가 주어졌을 때, 모든 히든 넘버의 합을 구하는 프로그램을 작성하시오.

단어와 히든 넘버는 아래와 같은 성질을 갖는다.

연속된 숫자는 한 히든 넘버이다.
두 히든 넘버 사이에는 글자가 적어도 한 개 있다.
히든 넘버는 6자리를 넘지 않는다.
입력
첫째 줄에 단어의 길이 n (1 ≤ n ≤ 5,000,000)이 주어진다. 둘째 줄에는 단어가 주어진다. 단어는 알파벳 대/소문자와 숫자(0-9)로 이루어져 있다. 

출력
입력으로 주어진 단어에 숨어있는 모든 히든 넘버의 합을 출력한다. 만약, 히든 넘버가 없는 경우에는 0을 출력한다.

예제 입력 1 
14
ab13c9d07jeden
예제 출력 1 
29
*/
