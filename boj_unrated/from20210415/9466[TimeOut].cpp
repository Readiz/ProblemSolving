#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        char fname[100];
        char* ftailname = "_input.txt";
        int p;
        for (p = 0; fbasename[p] != 0; p++) fname[p] = fbasename[p];
        int t;
        for (t = 0; ftailname[t] != 0; t++) fname[p++] = ftailname[t];
        fname[p] = 0;
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int N;
        scanf("%d", &N);
        int A[100001] = {0, };
        for (R int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        // 순환 체크 스타트
        for (R int i = 1; i <= N; i++) {
            // i : 시작점
            bool visited[100001] = {false, };
            int stack[100001] = {0, };
            int stackSize = 0;
            int p = i;
            visited[p] = true;
            stack[stackSize++] = p;
            bool loopValid = true;
            printd("Checking i: %d...", i);
            if (A[p] == -1) continue;
            while(A[p] != i) {
                printd("%d -> %d", p, A[p]);
                p = A[p];
                if (p == -1 || p == 0) { // 이미 짝이 지어지거나 망한 경우이므로 break
                    loopValid = false;
                    break;
                }
                if (visited[p] != true) {
                    visited[p] = true;
                    stack[stackSize++] = p;
                } else {
                    // 순환이 생긴 것이므로 종료
                    loopValid = false;
                    break;
                }
            }
            if (loopValid && A[p] == i) {
                printd("%d -> %d", p, A[p]);
                printd("Loop is valid! make visited members granted...");
                // 유효한 경우 유효하다는 표식을 남긴다.
                for (R int k = 0; k < stackSize; k++) {
                    A[stack[k]] = -1;
                }
                // for (R int k = 1; k <= N; k++) {
                //     if (visited[k] == true) {
                //         printd("%d is granted!", k);
                //         A[k] = -1;
                //     }
                // }
            } else {
                // 유효하지 않은 경우 제외한다.
                // 0 : 쌍을 이루지 못한 경우
                A[i] = 0;
            }
        }

        if (isDebug) printf("[DEBUG] ");
        int count = 0;
        for (R int i = 1; i <= N; i++) {
            if (A[i] != -1) {
                count++;
            }
            if (isDebug) {
                printf("%d ", A[i]);
            }
        }
        if (isDebug) printf("\n");
        printf("%d\n", count);

    }

MAIN_END


/*
텀 프로젝트 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
3 초	256 MB	31007	7620	4886	24.707%
문제
이번 가을학기에 '문제 해결' 강의를 신청한 학생들은 텀 프로젝트를 수행해야 한다. 프로젝트 팀원 수에는 제한이 없다. 심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다. 프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다. (단, 단 한 명만 선택할 수 있다.) 혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.

학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.

예를 들어, 한 반에 7명의 학생이 있다고 하자. 학생들을 1번부터 7번으로 표현할 때, 선택의 결과는 다음과 같다.

1	2	3	4	5	6	7
3	1	3	7	3	4	6
위의 결과를 통해 (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.

주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다. 각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)

출력
각 테스트 케이스마다 한 줄에 출력하고, 각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.

예제 입력 1 
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8
예제 출력 1 
3
0
*/
