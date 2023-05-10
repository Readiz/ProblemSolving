#include <stdio.h>

bool isDebug = false;

int M, N, V;
int map[1001][1001] = {0, };
bool visited[1001] = {false, };

int QueueSize = 0;
int Queue[1000] = {0, };
void enqueue(int num) {
    Queue[QueueSize++] = num;
}
int dequeue() {
    int start = Queue[0];
    for (int i = 0; i < QueueSize - 1; i++) {
        Queue[i] = Queue[i + 1];
    }
    QueueSize--;
    return start;
}

void visitedReset() {
    for (int i = 1; i <= 1000; i++)
        visited[i] = false;
}

void DFS(int from) {
    visited[from] = true;
    printf("%d ", from);
    for (int to = 1; to <= N; to++) {
        if (!visited[to] && map[from][to]) {
            DFS(to);
        }
    }
}

void DFSStart() {
    DFS(V);
    printf("\n");
}

void BFSStart() {
    enqueue(V);
    visited[V] = true;
    printf("%d ", V);

    while (QueueSize != 0) {
        int from = dequeue();
        for (int to = 1; to <= N; to++) {
            if (!visited[to] && map[from][to]) {
                enqueue(to);
                visited[to] = true;
                printf("%d ", to);
            }
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // 입력으로 주어지는 간선은 양방향
        map[a][b] = 1;
        map[b][a] = 1;
    }
    DFSStart();
    visitedReset();
    BFSStart();
    return 0;
}



/*
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/
