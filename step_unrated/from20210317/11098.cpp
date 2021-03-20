#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("11098_input.txt", "rt", stdin); }
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

    int T;
    scanf("%d", &T);
    printd("--------------------------");
    for (int tc = 0; tc < T; tc++) {
        int P;
        scanf("%d", &P);
        char maxName[25] = {0, };
        int maxVal = -1;
        for (int i = 0; i < P; i++) {
            int tmpVal;
            char tmpName[25];
            scanf("%d", &tmpVal);
            printd("curMax: %d curVal: %d", maxVal, tmpVal);
            if (tmpVal > maxVal) {
                maxVal = tmpVal;
                scanf("%s", maxName);
            } else {
                scanf("%s", tmpName);
            }
        }
        printf("%s\n", maxName);
    }
MAIN_END


/*
첼시를 도와줘! 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	2476	1600	1445	67.147%
문제
구단이 성적을 내지 못한다면 답은 새 선수 영입뿐이다. 이것은 오늘날 유럽 리그에서 가장 흔한 전략이고, 노르웨이의 로젠버그 팀은 이러한 전략이 성공한 대표적 예시다. 그들은 많은 스카우터들을 지구 곳곳에 파견해 가능성 있는 루키를 찾는다.

현재 첼시는 프리미어 리그에서 헤매고 있고, 결국 새로운 선수를 사기로 결정했다. 하지만 그들은 스카우터를 기다리기 지쳤고, 훨씬 더 효율적인 전략을 개발해냈다. "만약 무언가 팔리고 있다면, 그것에는 합당한 이유가 있다"는 배룸의 명언이 바로 그것이다. 축구에서 이 말은 곧 가장 비싼 선수가 가장 좋은 선수라는 이야기가 된다. 

이에 따라 새로운 선수를 찾는 방법은 단순히 구단들에게 전화를 걸어 그들의 가장 비싼 선수를 사는게 되었다. 당신의 임무는 첼시가 리스트에서 가장 비싼 선수를 찾아낼 수 있도록 돕는 것이다.

입력
첫 번째 줄에는 테스트 케이스의 개수 n이 주어진다 (n≤100). 

각 테스트 케이스의 첫 번째 줄 p는 고려해야될 선수의 수이다 (1≤p≤100).  

그 아래 p개의 줄에는 선수의 정보가 표시된다. 

각각의 줄은 선수의 가격 C 와 이름을 입력한다 (C<2*109).

모든 선수의 가격은 서로 다르다. 
선수의 이름은 20자 이하여야 하며, 사이에 공백이 있어서는 안 된다.
 

출력
각각의 테스트 케이스에서 가장 비싼 선수의 이름을 출력해야한다.

예제 입력 1 
2
3
10 Iversen
1000000 Nannskog
2000000 Ronaldinho
2
1000000 Maradona
999999 Batistuta
예제 출력 1 
Ronaldinho
Maradona
*/
