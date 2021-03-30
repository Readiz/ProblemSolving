#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
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
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);
    #define MAIN_END return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

typedef long long ll;
#define MAX_VALUE 0x7FFFFFFFFFFFFFFF
#define MIN_VALUE (MAX_VALUE * (-1) - 1)

template<class T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

class Node {
public:
    ll value;
    ll originalValue;
    Node(): value(0), originalValue(0) {}
    Node(ll value, ll originalValue): value(value), originalValue(originalValue) {} 
    Node& operator= (Node& n) {
        this->value = n.value;
        this->originalValue = n.originalValue;
        return *this;
    }
    bool operator< (Node& n) {
        if (this->value != n.value) {
            return this->value < n.value;
        } else {
            return this->originalValue < n.originalValue;
        }
    }
    bool operator> (Node& n) {
        if (this->value != n.value) {
            return this->value > n.value;
        } else {
            return this->originalValue > n.originalValue;
        }
    }
};

template<class T>
class DArray {
    int capacity;
    int size;
    T* n;
public:
    DArray() {
        size = 0;
        capacity = 10;
        n = new T[capacity];
    }
    void push(T tNode) {
        if (size == capacity) { // 이미 DArray가 다 찼을 경우, 늘린다.
            T* newNodes = new T[capacity * 2];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i];
            }
            delete[] n;
            n = newNodes;
            capacity *= 2;
        }
        n[size] = tNode;
        size++;
    }
    void pop() { // 마지막 노드를 지운다.
        size--;
    }
    T& operator[] (int idx) {
        if (idx >= size) {
            printd("[ERROR] DArray overflow! cannot access to idx: %d", idx);
        }
        return n[idx];
    }
    ~DArray() {
        delete[] n;
    }
};

template<class T>
class MinHeap {
    DArray<T> n;
    int size;
public:
    MinHeap() {
        size = 0;
    }
    void push(T newNode) {
        int p = size;
        n.push(newNode);
        size++;
        update(p);
    }
    T pop() {
        T returnNode = top();
        if (size == 0) return returnNode;

        n[0] = n[size - 1];
        size--;
        n[size].value = MAX_VALUE;

        n.pop();

        downdate(0);
        return returnNode;
    }

    T top() {
        if (size == 0) {
            Node n;
            return n;
            // printd("[POP] size: 0! return dummy value..");
        } else {
            return n[0];
            // printd("[POP] %lld, id: %d", num, id);
        }
    }

    void update(int p) {
        while (p > 0) { // 부모 노드 전파 확인
            int parent = (p - 1) / 2;
            if (n[p] < n[parent]) { // 최소힙은 부모가 항상 작게 유지되어야 한다.
                swap(n[p], n[parent]);
                p = parent;
            } else {
                break;
            }
        }
    }

    void downdate(int p) {
        while (p < size) { // 자식 전파 확인
            int lp = (p + 1) * 2 - 1;
            int rp = (p + 1) * 2;
            if (lp >= size && rp >= size) break;
            if (rp >= size) { // 왼쪽 까지만 남았을 경우 (rp는 범위 초과)
                if (n[lp] < n[p]) {
                    swap(n[lp], n[p]);
                }
                // Leaf이 있는 경우는 더 이상 아래로 내려가지 못하는 경우이므로, 종료.
                break;
            }
            // 두 자식 다 남아있을 경우, 더 작은 놈과 swap (Min Heap은 가급적 작은애가 부모로 있어야함)
            if (n[lp] < n[p] || n[rp] < n[p]) {
                if (n[lp] < n[rp]) {
                    swap(n[lp], n[p]);
                    p = lp;
                } else {
                    swap(n[rp], n[p]);
                    p = rp;
                }
            } else { // 이미 힙 구조가 완성되어 있는 상태이므로, 종료.
                break;
            }
        }
    }

    void print() {
        // for (int i = 0; i < size; i++) {
        //     printf("%lld, ", n[i].value);
        // }
        // printf("\n");
    }
    ~MinHeap() {
    }
};

#define ABS(x) (((x) < 0) ? ((x) * (-1)):(x))

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int K;
    scanf("%d", &K);

    // Heap 초기화
    MinHeap<Node> minHeap;
    for (int k = 0; k < K; k++) {
        int val;
        scanf("%d", &val);
        printd("Input: %d", val);
        if (val == 0) {
            // Pop
            Node n = minHeap.pop();
            printf("%lld\n", n.originalValue);
        } else {
            // 절대값 Push
            Node n(ABS(val), val);
            minHeap.push(n);
        }
    }
MAIN_END


/*
절댓값 힙 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (추가 시간 없음) (하단 참고)	256 MB	11091	5929	4922	55.856%
문제
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

예제 입력 1 
18
1
-1
0
0
0
1
1
-1
-1
2
-2
0
0
0
0
0
0
0
예제 출력 1 
-1
1
0
-1
-1
1
1
-2
2
0
*/
