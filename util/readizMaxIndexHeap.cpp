#include <stdio.h>

struct Data {
    int a;
    int b;
};

#define MAX_SIZE (1024*1024)
#define parent(n) (n>>1)
#define leftChild(n) (n<<1)
#define rightChild(n) ((n<<1)|1)

struct HeapResult {
    int originalIdx;
    int priority;
    Data data;
};

#define INT_MIN 0x80000000
#define R register

class MaxHeap {
    int originalIdx[MAX_SIZE];
    int newIdx[MAX_SIZE];
    int priority[MAX_SIZE];
    Data data[MAX_SIZE];
    int lastPtr;
public:
    MaxHeap() {
        // Heap의 Idx는 1부터 쓰는게 편함
        lastPtr = 1;
        for (R int i = 0; i < MAX_SIZE; i++) {
            priority[i] = INT_MIN;
        }
    }

    HeapResult pop() {
        HeapResult r;
        int p = 1;
        r.originalIdx = this->originalIdx[p];
        r.priority = this->priority[p];
        r.data = this->data[p];

        this->priority[p] = INT_MIN;
        swap(--lastPtr, p);
        checkDown(p);
        return r;
    }
    void push(int idx, int priority, Data data) {
        int p = lastPtr;
        originalIdx[p] = idx;
        newIdx[idx] = p;
        this->priority[p] = priority;
        this->data[p] = data;
        checkUp(lastPtr++);
    }
    void checkDown(int idx) {
        while (priority[leftChild(idx)] > priority[idx] || priority[rightChild(idx)] > priority[idx]) {
            if (priority[leftChild(idx)] > priority[rightChild(idx)]) {
                swap(leftChild(idx), idx);
                idx = leftChild(idx);
            } else {
                swap(rightChild(idx), idx);
                idx = rightChild(idx);
            }
        }
    }
    void checkUp(int idx) {
        while (idx > 1) {
            // 부모가 자식보 작으면 swap
            if (priority[parent(idx)] < priority[idx]) {
                swap(parent(idx), idx);
            } else {
                break;
            }
            idx = parent(idx);
        }
    }
    void swap(int idx1, int idx2) {
        int tmpOriIdx = originalIdx[idx1];
        int tmpNewIdx = newIdx[idx1];
        int tmpPriority = priority[idx1];
        Data tmpData = data[idx1];

        originalIdx[idx1] = originalIdx[idx2];
        newIdx[idx1] = newIdx[idx2];
        priority[idx1] = priority[idx2];
        data[idx1] = data[idx2];

        originalIdx[idx2] = tmpOriIdx;
        newIdx[idx2] = tmpNewIdx;
        priority[idx2] = tmpPriority;
        data[idx2] = tmpData;
    }

    // Idx를 다루는 추가 method
    void updateDirect(int oriIdx, int priority, Data data) {
        int p = newIdx[oriIdx];
        this->priority[p] = priority;
        this->data[p] = data;
        
        checkDown(p);
        checkUp(p);
    }

};

MaxHeap h;


int pseudo_rand() {
    static int seed = 3;
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int main() {
    int data[1000];
    int dataSize = 10;
    for (int i = 0; i < dataSize; i++) {
        data[i] = pseudo_rand() % 100;
        h.push(i, data[i], {-i, i*2});
        printf("%d ", data[i]);
    }
    printf("\n");

    // for (int i = 0; i < dataSize; i++) {
    //     HeapResult hr = h.pop();
    //     printf("%d ", hr.priority);
    // }
    // printf("\n");

    // update test
    printf("[TEST] %d -> %d\n", data[0], 0);
    h.updateDirect(0, 0, {0, 0});
    
    for (int i = 0; i < dataSize; i++) {
        HeapResult hr = h.pop();
        printf("%d ", hr.priority);
    }
    printf("\n");
    return 0;
}