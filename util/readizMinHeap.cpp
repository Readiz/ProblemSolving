// 최소힙 구현. 빈 공간은 INF 데이터로 차 있어야 함.
// Push / Pop: log(n) 로 보장.
// 정렬 없이 바로 값을 사용 가능. 우선순위 큐 등에 사용.
// 다익스트라에서 거리 제일 짧은 거리의 노드를 먼저 가져오는데에 유용. 
#include <stdio.h>
#define INF 987654321
#define MAX_HEAP_SIZE 10000

void SWAP(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int sizeHeap = 0;
int Heap[MAX_HEAP_SIZE];
void initHeap() {
    for (int i = 0; i < MAX_HEAP_SIZE; i++) {
        Heap[i] = INF;
    }
}
int getParent(int p) {
    return (p - 1) / 2;
}
int popHeap() {
    int r = Heap[0];
    SWAP(Heap[0], Heap[sizeHeap - 1]);
    Heap[--sizeHeap] = INF;
    int p = 0;
    while (p < sizeHeap) {
        int lChild = (p + 1) * 2 - 1;
        int rChild = (p + 1) * 2;
        if (Heap[p] > Heap[lChild] || Heap[p] > Heap[rChild]) { // 자식이 더 작으면 바꿔야 하는 케이스임
            if (Heap[lChild] < Heap[rChild]) { // 더 작은 자식이랑 바꾼다.
                SWAP(Heap[p], Heap[lChild]);
                p = lChild;
            } else {
                SWAP(Heap[p], Heap[rChild]);
                p = rChild;
            }
        } else { // 더 이상 자식까지 갈 필요 없음 (부모가 두 자식보다 더 작다.)
            break;
        }
    }
    return r;
}
void pushHeap(int num) {
    int p = sizeHeap;
    Heap[sizeHeap++] = num;
    while (p > 0) {
        int parent = getParent(p);
        if (Heap[p] < Heap[parent]) { // 부모가 더 작아야 함
            SWAP(Heap[p], Heap[parent]);
        }
        p = getParent(p);
    }
}
int pseudo_rand() {
    static int seed = 3;
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}
int main() {
    initHeap();
    int data[1000];
    int dataSize = 40;
    for (int i = 0; i < dataSize; i++) {
        data[i] = pseudo_rand() % 100;
    }
    printf("Original Inputs: ");
    for (int i = 0; i < dataSize; i++) {
        printf("%d ", data[i]);
        pushHeap(data[i]);
    }
    printf("\n");
    printf("Heap Arr: ");
    for (int i = 0; i < sizeHeap; i++) {
        printf("%d ", Heap[i]);
    }
    printf("\n");
    printf("Sorted: ");
    while (sizeHeap > 0) {
        printf("%d ", popHeap());
    }
    printf("\n");
    return 0;
}
