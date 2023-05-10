#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("16964_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

class Stack {
    int size = 0;
    int data[100001];
public:
    void push(int num) {
        data[size++] = num;
    }
    int pop() {
        return data[--size];
    }
    int peek() {
        return data[size - 1];
    }
    int getSize() {
        return size;
    }
};

class DArray {
    int capacity = 10;
    int size = 0;
    int* data;
public:
    DArray() {
        data = new int[capacity];
    }
    void push(int num) {
        if (size < capacity) {
            data[size++] = num;
        } else {
            int* newData = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
            data[size++] = num;
        }
    }
    bool find(int num) {
        // 최초 find 시 정렬해서 이진탐색 하면 성능 개선 여지 있음
        for (int i = 0; i < size; i++) {
            if (data[i] == num) return true;
        }
        return false;
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("--------------------------");
    DArray A[100001];
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        A[a].push(b);
        A[b].push(a); // 문제 조건에서 양방향 그래프라고 하였음..
    }
    int root;
    Stack stack;
    scanf("%d", &root);
    stack.push(root);
    int visitCnt = 1;
    bool isAllTravsered = true;
    printd("root: %d", root);
    if (root != 1) printf("0\n"); // 1로 시작하는 것이 문제의 조건!
    else {
        while (visitCnt++ < N) {
            int idx;
            scanf("%d", &idx);
            printd("check %d...", idx);
            int parent = stack.peek();
            if (A[idx].find(parent)) {
                // 우선 이전 방문한 노드의 부모가 맞아야 함
                // idx 노드가 자식이 있으면, Stack에 추가하여 업데이트
                stack.push(idx);
                printd("%d is the child of %d, add to stack.", idx, parent);
            } else {
                printd("%d is not the child of %d, pop stack...", idx, parent);
                // 부모가 아니라면, pop 해본다.
                stack.pop();
                while (stack.getSize() > 0) {
                    int parent = stack.peek();
                    if (A[idx].find(parent)) {
                        stack.push(idx);
                        printd("%d is the child of %d, add to stack.", idx, parent);
                        break;
                    }
                    stack.pop();
                    printd("%d is not the child of %d, pop stack...", idx, parent);
                }
                if (stack.getSize() == 0) {
                    isAllTravsered = false;
                    break;
                }
            }
        }
        if (isAllTravsered) printf("1\n");
        else printf("0\n");
    }
MAIN_END


/*
DFS 스페셜 저지 실패분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	1317	471	361	42.471%
문제
BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다. 스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다. 오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.

정점의 개수가 N이고, 정점에 1부터 N까지 번호가 매겨져있는 양방향 그래프가 있을 때, DFS 알고리즘은 다음과 같은 형태로 이루어져 있다.

1
2
3
4
5
6
7
8
9
10
11
12
void dfs(int x) {
    if (check[x] == true) {
        return;
    }
    check[x] = true;
    // x를 방문
    for (int y : x와 인접한 정점) {
        if (check[y] == false) {
            dfs(y);
        }
    }
}
이 문제에서 시작 정점은 1이기 때문에 가장 처음에 호출하는 함수는 dfs(1)이다. DFS 방문 순서는 dfs함수에서 // x를 방문 이라고 적힌 곳에 도착한 정점 번호를 순서대로 나열한 것이다.

트리가 주어졌을 때, 올바른 DFS 방문 순서인지 구해보자.

입력
첫째 줄에 정점의 수 N(2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에는 트리의 간선 정보가 주어진다. 마지막 줄에는 DFS 방문 순서가 주어진다. DFS 방문 순서는 항상 N개의 정수로 이루어져 있으며, 1부터 N까지 자연수가 한 번씩 등장한다.

출력
입력으로 주어진 DFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.
*/
