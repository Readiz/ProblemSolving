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


int N;
char A[101][101];
bool cmp(int i) {
    for (int j = 0; j < N; j++) {
        if (A[i][j] != A[j][i]) {
            return false;
        }
    }
    return true;
}
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    scanf("%d", &N);
    printd("Input - N: %d", N);
    printd("--------------------------");
    for (int i = 0; i < N; i++) {
        scanf("%s", A[i]);
    }
    for (int i = 0; i < N; i++) {
        if (!cmp(i)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
MAIN_END


/*
사토르 마방진 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	264	204	191	80.252%
문제
사토르 마방진에 대해 들어본 적이 있는가? 사토르 마방진은 간단히 말하면 "가로로 읽었을 때와 세로로 읽었을 때 똑같이 읽히는 단어 집합"이다. 예시로는 다음과 같은 것들이 있다.

라팔아
팔렸니
아니오
호반우
반기는
우는나
술을 좋아하는 드립이는 전날 과음한 나머지 수학 수업 시간에 졸다가 선생님에게 걸려버렸고, 단어 집합들이 사토르 마방진인지 아닌지 판단해야 하는 숙제를 받았다.

하지만 N × N 크기의 큰 단어 집합이 사토르 마방진인지 눈으로 확인하는 것은 쉽지 않았다.

불쌍한 드립이는 숙제를 다 끝내기 전까지 집에 갈 수 없다. N × N 크기의 단어 집합이 주어지면, 주어진 단어 집합이 사토르 마방진인지 아닌지 판단하는 프로그램을 작성하자.

드립이를 도와주자!

입력
첫째 줄에 단어의 길이 N이 주어진다. (2 ≤ N ≤ 100)

둘째 줄부터 N개의 줄에 걸쳐 단어 집합의 각 행의 단어들이 공백 없이 주어진다. 단어들은 알파벳 대문자로만 이루어져 있다.

출력
주어진 단어 집합이 사토르 마방진이면 "YES", 아니면 "NO"를 출력한다. (따옴표 제외)

예제 입력 1 
3
AAB
ACD
BDE
예제 출력 1 
YES
예제 입력 2 
4
APPL
PPAP
PADD
LPOV
예제 출력 2 
NO
*/
