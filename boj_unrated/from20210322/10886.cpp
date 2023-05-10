#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("10886_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("--------------------------");
    int cuteCount = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1) {
            cuteCount++;
        } else {
            cuteCount--;
        }
    }
    if (cuteCount < 0) {
        printf("Junhee is not cute!\n");
    } else {
        printf("Junhee is cute!\n");
    }
MAIN_END

/*
0 = not cute / 1 = cute 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	2 MB	9923	6626	6126	67.991%
문제
준희는 자기가 팀에서 귀여움을 담당하고 있다고 생각한다. 하지만 연수가 볼 때 그 의견은 뭔가 좀 잘못된 것 같았다. 그렇기에 설문조사를 하여 준희가 귀여운지 아닌지 알아보기로 했다.

입력
첫 번째 줄에 설문조사를 한 사람의 수 N (1 ≤ N ≤ 101, N은 홀수)가 주어진다.

다음 N개의 줄에는 각 줄마다 각 사람이 설문 조사에 어떤 의견을 표명했는지를 나타내는 정수가 주어진다. 0은 준희가 귀엽지 않다고 했다는 뜻이고, 1은 준희가 귀엽다고 했다는 뜻이다.

출력
준희가 귀엽지 않다는 의견이 더 많을 경우 "Junhee is not cute!"를 출력하고 귀엽다는 의견이 많을 경우 "Junhee is cute!"를 출력하라.

예제 입력 1 
3
1
0
0
예제 출력 1 
Junhee is not cute!
힌트
팀 내에서 설문조사를 진행하면 아마 위와 같은 결과를 얻게 될 것이다.
*/
