#include <stdio.h>

int N;
int map[101][101] = {0, };
bool isVisited[101] = {false, };
int queueStart = 0;
int queueEnd = 0;
int queue[200];
void enqueue(int x) {
    queue[queueEnd] = x;
    queueEnd++;
}
int dequeue() {
    queueStart++;
    return queue[queueStart - 1];
}
int getQueueSize() {
    return queueEnd - queueStart;
}

int BFS() {
    enqueue(1);
    isVisited[1] = true;
    int count = 0;

    while (getQueueSize() > 0) {
        int n = dequeue();
        for (int i = 1; i <= N; i++) {
            if (!isVisited[i] && map[n][i] == 1) {
                enqueue(i);
                isVisited[i] = true;
                count++;
            }
        }
    }
    return count;
}

int main() {
    scanf("%d", &N);
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    printf("%d\n", BFS());
    return 0;
}