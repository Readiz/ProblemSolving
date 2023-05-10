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
void itoa(int num, char s[]) {
    int p = 0;
    while (num > 0) {
        s[p++] = num % 10 + '0';
        num /= 10;
    }
    s[p] = 0; // NULL 추가
    inverse(s);
}
void trimFirst15(char s[]) {
    for (int i = 0; i < 15; i++) {
        s[i] = s[i + 15];
    }
}
int find(char s[], char t[]) {
    int l = len(t);
    int i;
    bool isAllMatched = false;
    for (i = 0; i < len(s) - l + 1; i++) {
        isAllMatched = true;
        for (int j = 0; j < l; j++) {
            if (s[i + j] == t[j]) continue;
            isAllMatched = false;
        }
        if (isAllMatched) break;
    }
    if (isAllMatched) return i;
    return -1;
}
MAIN_START
    int N;
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &N);
    printd("Input - N: %d", N);
    char buf[30] = {0, };
    char tmp[10] = {0, };
    int p = 0;
    int base = 1;
    for (int i = 1; i <= N; i++) {
        itoa(i, tmp);
        int l = len(tmp);
        itoa(i, &buf[p]);
        p = p + l;
        if (p > 20) {
            trimFirst15(buf);
            p -= 15;
            base += 15;
        }
        itoa(N, tmp);
        int r = find(buf, tmp);
        if (r > -1) {
            printd("%s", buf);
            printf("%d\n", base + r);
            break;
        }
    }

    printd("--------------------------");
MAIN_END

/*
수 이어 쓰기 3 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	665	349	284	60.426%
문제
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수에서 N이 등장하는 위치를 알고 싶다. 물론 1부터 N까지의 수를 이어 쓰는 것이므로 수의 가장 끝부분에서 N이 항상 등장하게 되지만, 그보다 일찍 등장하는 경우도 있다.

예를 들어 N=151인 경우, 다음과 같이 앞에서 20번째 숫자부터 151이 등장하게 된다.

1234567891011121314151617181920212223...

N이 주어졌을 때, N이 가장 먼저 등장하는 위치를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 100,000)이 주어진다.

출력
첫째 줄에 N이 가장 먼저 등장하는 위치를 출력한다. 앞에서부터 몇 번째인지를 출력하면 된다.

예제 입력 1 
34
예제 출력 1 
3
*/
