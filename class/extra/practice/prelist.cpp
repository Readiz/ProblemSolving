#include <stdio.h>


// 일반적으로 100만개 정도의 Node는 선언 가능하다.
#define MAX_SIZE 1'000'000

struct Node {
    int key;
    Node* next;
};
Node np[MAX_SIZE];
int nSize = 0;

int dStack[MAX_SIZE];
int dSize = 0;

Node* new_Node() {
    if (dSize > 0) {
        return &np[dStack[--dSize]];
    }
    return &np[nSize++];
}

void delNode(Node* node) {
    int idx = node - np; // 배열의 현재 자신의 위치를 알 수 있는 법! 포인터 개념.
    dStack[dSize++] = idx;
}

void printStack() {
    printf("Stack Size: %d / ", dSize);
    for (register int i = 0; i < dSize; i++) {
        printf("%d ", dStack[i]);
    }
    printf("\n");
}

int main() {

    for (register int i = 0; i < 100; i++) {
        Node* a = new_Node();
        a->key = i * 10;
    }
    for (register int i = 0; i < 100; i++) {
        delNode(&np[--nSize]);
    }

    for (register int i = 0; i < 50; i++) {
        Node* a = new_Node();
        a->key = i + 100;
    }

    printStack();

    printf("%d\n", np[0].key);
}