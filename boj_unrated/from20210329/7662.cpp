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
    ll value = 0;
    Node() {}
    Node(ll value): value(value) {} 
    Node& operator= (Node& n) {
        this->value = n.value;
        return *this;
    }
    bool operator< (Node& n) {
        return this->value < n.value;
    }
    bool operator> (Node& n) {
        return this->value > n.value;
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

class MinHeap {
    DArray<Node> n;
    int size;
public:
    MinHeap() {
        size = 0;
    }
    void push(ll num) {
        int p = size;
        Node newNode(num);
        n.push(newNode);
        size++;

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
    void pop(ll& num) {
        if (size == 0) {
            num = MAX_VALUE;
            // printd("[POP] size: 0! return dummy value..");
            return;
        } else {
            num = n[0].value;
            // printd("[POP] %lld, id: %d", num, id);
        }
        n[0] = n[size - 1];
        size--;
        n[size].value = MAX_VALUE;

        n.pop();

        int p = 0;
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
    void top(ll& num) {
        if (size == 0) {
            num = MAX_VALUE;
            // printd("[TOP] size: 0! return dummy value..");
            return;
        } else {
            num = n[0].value;
            // printd("[TOP] %lld, id: %d", num, id);
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

class MaxHeap {
    DArray<Node> n;
    int size;
public:
    MaxHeap() {
        size = 0;
    }
    void push(ll num) {
        int p = size;
        Node newNode(num);
        n.push(newNode);
        size++;

        while (p > 0) { // 부모 노드 전파 확인
            int parent = (p - 1) / 2;
            if (n[p] > n[parent]) { // 최대힙은 부모가 항상 크게 유지되어야 한다.
                swap(n[p], n[parent]);
                p = parent;
            } else {
                break;
            }
        }
    }
    void pop(ll& num) {
        if (size == 0) {
            num = MIN_VALUE;
            // printd("[POP] size: 0! return dummy value..");
            return;
        } else {
            num = n[0].value;
            // printd("[POP] %lld, id: %d", num, id);
        }
        n[0] = n[size - 1];
        size--;
        n[size].value = MIN_VALUE;
        n.pop();

        int p = 0;
        while (p < size) { // 자식 전파 확인
            int lp = (p + 1) * 2 - 1;
            int rp = (p + 1) * 2;
            if (lp >= size && rp >= size) break;
            if (rp >= size) { // 왼쪽 까지만 남았을 경우 (rp는 범위 초과)
                if (n[lp] > n[p]) {
                    swap(n[lp], n[p]);
                }
                // Leaf이 있는 경우는 더 이상 아래로 내려가지 못하는 경우이므로, 종료.
                break;
            }
            // 두 자식 다 남아있을 경우, 더 큰 놈과 swap (Max Heap은 가급적 큰애가 부모로 있어야함)
            if (n[lp] > n[p] || n[rp] > n[p]) {
                if (n[lp] < n[rp]) {
                    swap(n[rp], n[p]);
                    p = rp;
                } else {
                    swap(n[lp], n[p]);
                    p = lp;
                }
            } else { // 이미 힙 구조가 완성되어 있는 상태이므로, 종료.
                break;
            }
        }
    }
    void top(ll& num) {
        if (size == 0) {
            num = MIN_VALUE;
            // printd("[TOP] size: 0! return dummy value..");
            return;
        } else {
            num = n[0].value;
            // printd("[TOP] %lld, id: %d", num, id);
        }
    }
    void print() {
        // for (int i = 0; i < size; i++) {
        //     printf("%lld, ", n[i].value);
        // }
        // printf("\n");
    }
    ~MaxHeap() {
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {
        int K;
        scanf("%d", &K);
        // Heap 초기화
        MinHeap minHeap;
        MinHeap dMinHeap;
        MaxHeap maxHeap;
        MaxHeap dMaxHeap;
        for (int i = 0; i < K; i++) {
            // push 시, minHeap, maxHeap, visited에 동시 삽입.
            // 이후, pop 시점에, 만약 visited에 설정된 원소면, 무시하고 한번 더 뽑는 로직 사용.
            char cmd[3] = {0, };
            int val;
            scanf("%s", cmd);
            if (cmd[0] == 'I') {
                scanf("%d", &val);
                printd("[PUSH CMD] %lld", val);
                minHeap.push(val);
                maxHeap.push(val);
            } else if (cmd[0] == 'D') {
                scanf("%d", &val);
                ll num, cnum;
                if (val == -1) { // 최소힙에서 하나 뺀다
                    printd("[POP CMD] POP MIN HEAP");
                    // 빼기 전에, 이미 다른 힙에서 빠진 녀석인지 확인한다.
                    minHeap.top(num);
                    dMinHeap.top(cnum);
                    while (num != MAX_VALUE && num == cnum) { // 뺀 놈을 소진 시키자.
                        minHeap.pop(num);
                        dMinHeap.pop(cnum);
                        minHeap.top(num);
                        dMinHeap.top(cnum);
                    }
                    // 이미 뺀거 다 빼고도 더 남았으면, 실제로 빼고 뺐다고 신호를 넣는다.
                    if (num != MAX_VALUE) {
                        minHeap.pop(num);
                        dMaxHeap.push(num);
                        printd("[POP CMD] POPed num: %lld", num);
                        printd("[MIN HEAP]");
                        minHeap.print();
                        printd("[dMAX HEAP]");
                        dMaxHeap.print();
                    } else {
                        printd("[POP CMD] Empty! Cannot pop item");
                    }
                } else { // 최대힙에서 하나 뺀다
                    printd("[POP CMD] POP MAX HEAP");
                    // 빼기 전에, 이미 다른 힙에서 빠진 녀석인지 확인한다.
                    maxHeap.top(num);
                    dMaxHeap.top(cnum);
                    while (num != MIN_VALUE && num == cnum) { // 뺀 놈을 소진 시키자.
                        maxHeap.pop(num);
                        dMaxHeap.pop(cnum);
                        maxHeap.top(num);
                        dMaxHeap.top(cnum);
                    }
                    // 이미 뺀거 다 빼고도 더 남았으면, 실제로 빼고 뺐다고 신호를 넣는다.
                    if (num != MIN_VALUE){
                        maxHeap.pop(num);
                        dMinHeap.push(num);
                        printd("[POP CMD] POPed num: %lld", num);
                        printd("[MAX HEAP]");
                        maxHeap.print();
                        printd("[dMMIN HEAP]");
                        dMinHeap.print();
                    } else {
                        printd("[POP CMD] Empty! Cannot pop item");
                    }
                }
            }
        }
        // 과정 후 결과 확인
        printd("[END] Now checking final result...");
        printd("[END] 1. Getting Max Val...");
        ll num, cnum;
        ll max = MIN_VALUE, min = MAX_VALUE;
        maxHeap.top(num);
        dMaxHeap.top(cnum);
        while (num != MIN_VALUE && num == cnum) { // 뺀 놈을 소진 시키자.
            maxHeap.pop(num);
            dMaxHeap.pop(cnum);
            maxHeap.top(num);
            dMaxHeap.top(cnum);
        }
        if (num != MIN_VALUE) max = num;
        printd("[END] 2. Getting Min Val...");
        minHeap.top(num);
        dMinHeap.top(cnum);
        while (num != MAX_VALUE && num == cnum) { // 뺀 놈을 소진 시키자.
            minHeap.pop(num);
            dMinHeap.pop(cnum);
            minHeap.top(num);
            dMinHeap.top(cnum);
        }
        if (num != MAX_VALUE) min = num;
        if (max == MIN_VALUE || min == MAX_VALUE) {
            printf("EMPTY\n");
        } else {
            printf("%lld %lld\n", max, min);
        }
    }
MAIN_END


/*
이중 우선순위 큐 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
6 초	256 MB	11578	2793	2002	24.005%
문제
이중 우선순위 큐(dual priority queue)는 전형적인 우선순위 큐처럼 데이터를 삽입, 삭제할 수 있는 자료 구조이다. 전형적인 큐와의 차이점은 데이터를 삭제할 때 연산(operation) 명령에 따라 우선순위가 가장 높은 데이터 또는 가장 낮은 데이터 중 하나를 삭제하는 점이다. 이중 우선순위 큐를 위해선 두 가지 연산이 사용되는데, 하나는 데이터를 삽입하는 연산이고 다른 하나는 데이터를 삭제하는 연산이다. 데이터를 삭제하는 연산은 또 두 가지로 구분되는데 하나는 우선순위가 가장 높은 것을 삭제하기 위한 것이고 다른 하나는 우선순위가 가장 낮은 것을 삭제하기 위한 것이다. 

정수만 저장하는 이중 우선순위 큐 Q가 있다고 가정하자. Q에 저장된 각 정수의 값 자체를 우선순위라고 간주하자. 

Q에 적용될 일련의 연산이 주어질 때 이를 처리한 후 최종적으로 Q에 저장된 데이터 중 최댓값과 최솟값을 출력하는 프로그램을 작성하라.

입력
입력 데이터는 표준입력을 사용한다. 입력은 T개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)가 주어진다. 이어지는 k 줄 각각엔 연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n이 주어진다. ‘I n’은 정수 n을 Q에 삽입하는 연산을 의미한다. 동일한 정수가 삽입될 수 있음을 참고하기 바란다. ‘D 1’는 Q에서 최댓값을 삭제하는 연산을 의미하며, ‘D -1’는 Q 에서 최솟값을 삭제하는 연산을 의미한다. 최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨을 유념하기 바란다.

만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시해도 좋다. Q에 저장될 모든 정수는 32-비트 정수이다. 

출력
출력은 표준출력을 사용한다. 각 테스트 데이터에 대해, 모든 연산을 처리한 후 Q에 남아 있는 값 중 최댓값과 최솟값을 출력하라. 두 값은 한 줄에 출력하되 하나의 공백으로 구분하라. 만약 Q가 비어있다면 ‘EMPTY’를 출력하라.
*/
