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
    int K, D, A;
    scanf("%d/%d/%d", &K, &D, &A);
    printd("Input - K: %d, D: %d, A: %d", K, D, A);
    printd("--------------------------");
    if (K + A < D || D == 0) {
        printf("hasu\n");
    } else {
        printf("gosu\n");
    }
    return 0;
MAIN_END


/*
Darius님 한타 안 함? 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	715	469	432	67.290%
문제


아무래도 우리 팀 다리우스가 고수인 것 같다. 그의 를 보고 그가 「진짜」인지 판별해 보자.

이거나, 이면 그는 「가짜」이고, 그렇지 않으면 「진짜」이다.

입력
가 주어진다.

출력
그가 「진짜」이면 gosu, 「가짜」이면 hasu를 출력한다.

제한

예제 입력 1 
0/5/3
예제 출력 1 
hasu
예제 입력 2 
12/4/5
예제 출력 2 
gosu
예제 입력 3 
0/0/1
예제 출력 3 
hasu
*/
