#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
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
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef long long ll;
int N, targetS;
int curS = 0;
int count = 0;
int A[20];
bool visited[20] = {false, };

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
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

// DArray가 사실 Stack 그 자체임.
template<class T>
class Stack {
    DArray<T> db;
public:
    Stack() {
    };
    void push(T n) {
        db.push(n);
    }
    T& pop() {
        return db.pop();
    }
    int getSize() {
        return db.size;
    }
    int print() {
        for (int i = 0; i < db.size; i++) {
            printf("%d ", db[i]);
        }
    }
};
Stack<int> s;

void DFS(int curSelect, int selected, int overallSelected) {
    if (selected == overallSelected) {
        if (isDebug) {
            printf("[DEBUG] ");
            s.print();
            printf(" / curSum: %d, targetS: %d", curS, targetS);
            printf("\n");
        }
        if (curS == targetS) {
            count++;
            return;
        } else {
            return;
        }
    }
    for (int i = curSelect; i < N; i++) {
        if (!visited[i]) {
            curS += A[i];
            visited[i] = true;
            s.push(i);
            DFS(i, selected + 1, overallSelected);
            s.pop();
            visited[i] = false;
            curS -= A[i];
        }
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d", &N, &targetS);
    printd("N: %d, targetS: %d", N, targetS);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int arrayMakeLength = N;
    count = 0;
    while (arrayMakeLength > 0) { // 공집합 포함 X
        curS = 0;
        for (int k = 0; k < N; k++) {
            visited[k] = false;
        }
        DFS(0, 0, arrayMakeLength);
        arrayMakeLength--;
    }
    printf("%d\n", count);
MAIN_END

// 연속되지 않더라도 부분수열.. DFS 사용.

/*
부분수열의 합 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	34788	16033	10155	44.204%
문제
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

예제 입력 1 
5 0
-7 -3 -2 5 8
예제 출력 1 
1
*/
