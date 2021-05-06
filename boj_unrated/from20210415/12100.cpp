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
typedef unsigned long long ull;
typedef long long ll;

int brd[20][20] = {0, };
int oriBrd[20][20] = {0, };
int N;
int max = -1;

void printBrd() {
    for (R int i = 0; i < N; i++) {
        printf("---");
    }
    printf("\n");
    for (R int i = 0; i < N; i++) {
        for (R int j = 0; j < N; j++) {
            if (brd[i][j] != 0) {
                printf("%2d ", brd[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
void copyBrd(int t[][20], int s[][20]) {
    for (R int i = 0; i < N; i++) {
        for (R int j = 0; j < N; j++) {
            t[i][j] = s[i][j];
        }
    }
}
void rotateBrd(int b[][20], int n) { // n: 시계반대방향으로 돌아가는 횟수
    if (n < 0) {
        rotateBrd(b, 4 + n);
        return;
    }
    if (n == 0) return;
    // 회전 시작
    int tmp[20][20] = {0, };
    copyBrd(tmp, b);

    // 돌린다
    for (R int i = 0; i < N; i++) {
        for (R int j = 0; j < N; j++) {
            b[i][j] = tmp[j][N - i - 1];
        }
    }

    rotateBrd(b, n - 1);
}

void brdLeft() {
    bool isMerged[20][20] = {false, }; // 한번 합쳐진 녀석들을 다시 합쳐지지 못하게 한다.
    for (R int i = 0; i < N; i++) {
        for (R int j = 1; j < N; j++) {
            // 0이 아닌 녀석을 찾을 떄까지 반복..
            if (brd[i][j] != 0) {
                // 찾았으면, 최대한 왼쪽으로 보내려고 해본다.
                int originJ = j;
                while (j > 0) {
                    if (brd[i][j - 1] == 0) { // 왼쪽이 비었으면, 그냥 쭉 들고 간다.
                        brd[i][j - 1] = brd[i][j];
                        brd[i][j] = 0;
                    } else if (!isMerged[i][j - 1] && !isMerged[i][j] && brd[i][j - 1] == brd[i][j]) { // 합칠 수 있는 숫자이고, 아직 왼쪽에 있던 애가 합쳐지지 않았었을 경우(합치기 가능한 상태)
                        isMerged[i][j - 1] = true;
                        brd[i][j - 1] += brd[i][j];
                        if (max < brd[i][j - 1]) max = brd[i][j - 1]; // 합쳐질 떄, max 값 업데이트
                        brd[i][j] = 0;
                    }
                    j--;
                }
                j = originJ;
            }
        }
    }
}

void brdUp() {
    rotateBrd(brd, 1);
    brdLeft();
    rotateBrd(brd, -1);
}

void brdDown() {
    rotateBrd(brd, -1);
    brdLeft();
    rotateBrd(brd, 1);
}

void brdRight() {
    rotateBrd(brd, 2);
    brdLeft();
    rotateBrd(brd, -2);
}

void moveBrd(int i) {
    switch (i) {
        case 0:
            brdLeft();
            break;
        case 1:
            brdUp();
            break;
        case 2:
            brdRight();
            break;
        case 3:
            brdDown();
            break;
    }
}
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d", &N);
    max = -1;
    printd("N: %d", N);

    for (R int i = 0; i < N; i++) {
        for (R int j = 0; j < N; j++) {
            int tmp;
            scanf("%d", &tmp);
            oriBrd[i][j] = tmp;
            if (tmp > max) max = tmp; // 초기 max 값 세팅..
        }
    }

    for (R int a = 0; a < 4; a++) {
        for (R int b = 0; b < 4; b++) {
            for (R int c = 0; c < 4; c++) {
                for (R int d = 0; d < 4; d++) {
                    for (R int e = 0; e < 4; e++) { // 최대 다섯번까지 움직여준다.
                        copyBrd(brd, oriBrd); // 첫번쨰 꺼 움직이기 전에 리셋해주고..
                        int maxStart = max;
                        moveBrd(a);
                        moveBrd(b);
                        moveBrd(c);
                        moveBrd(d);
                        moveBrd(e);
                        int maxEnd = max;
                        if (isDebug && maxStart != maxEnd) {
                            printd("%d -> %d, with %d, %d, %d, %d, %d move..", maxStart, maxEnd, a, b, c, d, e);
                            copyBrd(brd, oriBrd);
                            printBrd();
                            moveBrd(a);
                            printBrd();
                            moveBrd(b);
                            printBrd();
                            moveBrd(c);
                            printBrd();
                            moveBrd(d);
                            printBrd();
                            moveBrd(e);
                            printBrd();
                        }
                    }
                }
            }
        }
    }

    printd("Max: %d", max);
    printf("%d\n", max);
MAIN_END


/*
2048 (Easy) 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	46147	12462	7034	24.650%
문제
2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 게임이다. 이 링크를 누르면 게임을 해볼 수 있다.

이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다. 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다. 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. (실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)

		
<그림 1>	<그림 2>	<그림 3>
<그림 1>의 경우에서 위로 블록을 이동시키면 <그림 2>의 상태가 된다. 여기서, 왼쪽으로 블록을 이동시키면 <그림 3>의 상태가 된다.

			
<그림 4>	<그림 5>	<그림 6>	<그림 7>
<그림 4>의 상태에서 블록을 오른쪽으로 이동시키면 <그림 5>가 되고, 여기서 다시 위로 블록을 이동시키면 <그림 6>이 된다. 여기서 오른쪽으로 블록을 이동시켜 <그림 7>을 만들 수 있다.

	
<그림 8>	<그림 9>
<그림 8>의 상태에서 왼쪽으로 블록을 옮기면 어떻게 될까? 2가 충돌하기 때문에, 4로 합쳐지게 되고 <그림 9>의 상태가 된다.

			
<그림 10>	<그림 11>	<그림 12>	<그림 13>
<그림 10>에서 위로 블록을 이동시키면 <그림 11>의 상태가 된다. 

<그림 12>의 경우에 위로 블록을 이동시키면 <그림 13>의 상태가 되는데, 그 이유는 한 번의 이동에서 이미 합쳐진 블록은 또 합쳐질 수 없기 때문이다.

	
<그림 14>	<그림 15>
마지막으로, 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다. 예를 들어, 위로 이동시키는 경우에는 위쪽에 있는 블록이 먼저 합쳐지게 된다. <그림 14>의 경우에 위로 이동하면 <그림 15>를 만든다.

이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다. 0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 블록은 적어도 하나 주어진다.

출력
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.

예제 입력 1 
3
2 2 2
4 4 4
8 8 8
예제 출력 1 
16
*/
