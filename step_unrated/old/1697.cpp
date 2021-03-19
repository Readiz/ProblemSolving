#include <stdio.h>

typedef struct _pair {
    int N;
    int tryNum;
} Pair;

int QueueStartPos = 0;
int QueueEndPos = 0;
Pair Queue[200002];
void enqueue(int N, int tryNum) {
    Queue[QueueEndPos].N = N;
    Queue[QueueEndPos].tryNum = tryNum;
    // printf("[DEBUG] Queue[%d] = %d, %d\n", QueueSize, Queue[QueueSize].N, Queue[QueueSize].tryNum);
    QueueEndPos++;
    if (QueueEndPos > 200000) printf("[DEBUG] WARING!! QUEUE SIZE is too big!\n");
}
void dequeue(int& N, int& tryNum) {
    N = Queue[QueueStartPos].N;
    tryNum = Queue[QueueStartPos].tryNum;
    QueueStartPos++;
}

int N, K;
bool visited[200002] = {false, };

int BFSStart() {
    enqueue(N, 0);
    visited[N] = true;

    while (QueueStartPos != QueueEndPos) {
        int N, cNum;
        dequeue(N, cNum);
        if (N == K) {
            return cNum;
        } else {
            if (N * 2 <= K * 2 && !visited[N * 2]) {
               enqueue(N * 2, cNum + 1);
               visited[N * 2] = true;
            }
            if (N + 1 <= K && !visited[N + 1]) {
               enqueue(N + 1, cNum + 1);
               visited[N + 1] = true;
            }
            if (N - 1 >= 0 && !visited[N - 1]) {
               enqueue(N - 1, cNum + 1);
               visited[N - 1] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d\n", BFSStart());
    return 0;
}

/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1 
5 17
예제 출력 1 
4
힌트
수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.
*/
