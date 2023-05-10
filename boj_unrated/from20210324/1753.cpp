#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("1753_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

#define INF 0x7FFFFFFF

class Node {
public:
    int id = -1;
    int curDistance = INF;
};

// 힙 구조의 PQ.
// 다익스트라의 경우 최소힙을 쓰므로 최소힙으로 구현한다.
// 문제에서 간선의 수는 최대 30만개 이므로 여유있게 40만으로 최대치를 잡았다. (자식까지 접근했을 때 에러 방지..)
class PriorityQueue {
    Node n[400000];
    int getParent(int idx) {
        return (idx - 1) / 2;
    }
    void swap(int aIdx, int bIdx) {
        int tmpId = n[aIdx].id;
        int tmpCurDistance = n[aIdx].curDistance;
        n[aIdx].id = n[bIdx].id;
        n[aIdx].curDistance = n[bIdx].curDistance;
        n[bIdx].id = tmpId;
        n[bIdx].curDistance = tmpCurDistance;
    }
public:
    int size = 0;
    PriorityQueue () { }
    void push(int id, int curDistance) {
        printd("push: %d, curDis: %d", id, curDistance);
        int p = size;
        // 맨 끝에 데이터를 추가
        n[p].id = id;
        n[p].curDistance = curDistance;
        size++;
        while (p != 0) {
            int pParent = getParent(p);
            // 부모가 더 크면 swap.
            if (n[p].curDistance < n[pParent].curDistance) {
                swap(p, pParent);
                p = pParent;
            } else { // 부모가 이미 더 작다면, 더이상 loop 돌 필요 없다.
                break;
            }
        }
        // printf("After Push: ");
        // for (int i = 0; i < 10; i++) {
        //     printf("%d(%d) ", n[i].id, n[i].curDistance);
        // }
        // printf("\n");
    }
    void pop(int& id, int& curDistance) {
        // pop의 경우 항상 맨 첫번째 idx에 있는 원소가 최소임이 보장된다.
        id = n[0].id;
        curDistance = n[0].curDistance;
        printd("pop: %d, curDis: %d", id, curDistance);
        n[0].id = -1;
        n[0].curDistance = INF;
        swap(0, --size); // 맨 뒤 원소를 처음으로 옮기고, 비교 시작.
        // printf("After Pop: ");
        // for (int i = 0; i < 10; i++) {
        //     printf("%d(%d) ", n[i].id, n[i].curDistance);
        // }
        // printf("\n");
        int p = 0;
        while (p < size) {
            int pLeft = (p + 1) * 2 - 1;
            int pRight = (p + 1) * 2;
            // printd("%d: %d / %d: %d", pLeft, n[pLeft].curDistance, pRight, n[pRight].curDistance);
            // 부모가 더 크면 바꿔야 함
            if (n[p].curDistance > n[pLeft].curDistance || n[p].curDistance > n[pRight].curDistance) {
                if (n[pLeft].curDistance > n[pRight].curDistance) {
                    swap(p, pRight);
                    p = pRight;
                } else {
                    swap(p, pLeft);
                    p = pLeft;
                }
            } else { // 이미 자식이 둘다 더 크면 더이상 내려가면서 비교할 필요 없음
                break;
            }
        }
    }
};

PriorityQueue pq;

class DArray {
    int capacity = 10;
    int size = 0;
    Node* n;
    int findPtr;
public:
    DArray() {
        n = new Node[capacity];
    }
    void push(int idx, int curDistance) {
        if (size == capacity) { // 이미 DArray가 다 찼을 경우, 늘린다.
            Node* newNodes = new Node[capacity * 2];
            for (int i = 0; i < size; i++) {
                newNodes[i].id = n[i].id;
                newNodes[i].curDistance = n[i].curDistance;
            }
            delete[] n;
            n = newNodes;
            capacity *= 2;
        }
        n[size].id = idx;
        n[size++].curDistance = curDistance;
    }
    int find(int idx) {
        // 최초 find 시 정렬해서 이진탐색 하면 성능 개선 여지 있음
        for (int i = 0; i < size; i++) {
            if (n[i].id == idx) return n[i].curDistance;
        }
        return -1;
    }
    void findStart() {
        // DArray의 시작부터 찾기 시작한다..
        findPtr = 0;
    }
    void findNext(int& idx, int& curDistance) {
        if (findPtr < size) {
            idx = n[findPtr].id;
            curDistance = n[findPtr].curDistance;
            findPtr++;
        } else { // 끝까지 다 돌았을 경우
            idx = -1;
            curDistance = -1;
        }
    }
};


int V, E, K;
DArray W[20001];
int D[20001] = {INF, }; // 시작정점 부터 현재 최신 노드들의 거리. 초기값은 INF로 세팅되어야 함
bool visited[20001] = {false, };

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    scanf("%d %d", &V, &E);
    printd("--------------------------");
    for (int i = 1; i <= V; i++) {
        D[i] = INF;
    }
    scanf("%d", &K);
    printd("V: %d / E: %d / K: %d", V, E, K);
    D[K] = 0; // 시작 정점은 0으로 세팅
    // 간선 정보 업데이트
    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        W[a].push(b, c);
    }
    pq.push(K, 0);
    visited[K] = true;
    while (pq.size > 0) {
        int curIdx, curDistance;
        pq.pop(curIdx, curDistance);

        W[curIdx].findStart();
        int nextIdx, nextCurDistance;
        W[curIdx].findNext(nextIdx, nextCurDistance);
        while (nextIdx != -1) {
            if (!visited[nextIdx]) { // 연결되어 있는 노드들에 대해..
                int newDistance = D[curIdx] + nextCurDistance;
                // 새로운 거리가 기존 거리보다 짧으면, 업데이트.
                // [Note] 당연히 맨 처음의 거리는 INF이므로, 맨 처음 한번은 무조건 업데이트 됨.
                if (newDistance < D[nextIdx]) {
                    D[nextIdx] = newDistance;
                    pq.push(nextIdx, D[nextIdx]); // 업데이트 된 녀석은 신규 방문 대상임
                }
            }
            W[curIdx].findNext(nextIdx, nextCurDistance);
        }
    }
    for (int i = 1; i <= V; i++) {
        if (D[i] != INF) {
            printf("%d\n", D[i]);
        } else {
            printf("INF\n");
        }
    }
MAIN_END

/*
다익스트라 대표문제..

최단경로 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	84315	22549	10868	23.459%
문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000)
모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 
둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다.
이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다.
서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

예제 입력 1 
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1 
0
2
3
7
INF
*/
