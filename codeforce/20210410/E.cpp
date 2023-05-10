#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        init();
    }
    void init() {
        if (n) delete[] n;
        size = 0;
        capacity = 100;
        n = new T[capacity];
    }
    void push(T item) {
        // 공간 다 찼을 경우.. 늘린다.
        if (size == capacity) {
            capacity *= 2; // 두배로 늘린다.
            T* newNodes = new T[capacity];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i]; // 기존 값 복사
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = item;
    }
    T& pop() {
        return n[--size];
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    ~DArray() {
        delete[] n;
    }
};

DArray<int> stack;

int N, L, R, S;
int K;
int sum;
bool visited[501];
bool DFS(int step) {
    if (step == K) {
        if (sum == S) {
            return true;
        }
        else {
            return false;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            stack.push(i);
            sum += i;
            bool r = DFS(step + 1);
            sum -= i;
            if (r) return true;
            stack.pop();
            visited[i] = false;
        }
    }
    return false;
}

bool DFSStart() {
    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        stack.push(i);
        sum += i;
        bool r = DFS(1);
        sum -= i;
        if (r) return true;
        stack.pop();
        visited[i] = false;
    }
    return false;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        scanf("%d %d %d %d", &N, &L, &R, &S);
        K = R - L + 1;
        printd("K: %d", K);
        sum = 0;
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
        }
        stack.init();
        bool r = DFSStart();
        if (r) {
            bool stackPrinted = false;
            int printCnt = 0;
            for (int idx = 1; idx <= N; idx++) {
                if (!visited[idx]) {
                    printf("%d ", idx);
                    printCnt++;
                }
                if (printCnt == L - 1 && !stackPrinted) {
                    stackPrinted = true;
                    for (int i = 0; i < stack.size; i++) {
                        printf("%d ", stack[i]);
                    }
                }
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
MAIN_END
