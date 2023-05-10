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
typedef unsigned long long ull;

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        n = NULL;
        init();
    }
    void init(int newCap = 100) {
        if (n != NULL) {
            delete[] n;
        }
        size = 0;
        capacity = newCap;
        n = new T[capacity];
    }
    void push(T item) { // call by value..
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
    DArray<T>& operator= (DArray<T>& src) {
        this->init();
        for (int i = 0; i < src.size; i++) {
            this->push(src[i]);
        }
        return *this;
    }
    
    void print() {
        for (int i = 0; i < size; i++) {
            printf("%d ", n[i]);
        }
    }
    ~DArray() {
        if (n != NULL) {
            delete[] n;
        }
    }
};


// fib 숫자 메모 (문제조건에 맞는 10억 이하의..)
int fib[44] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733};
int N;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {
        scanf("%d", &N);
        printd("N: %d", N);

        DArray<int> s; // 스택 대용 DArray

        while (N != 0) {
            int p;
            for (p = 0; p < 44; p++) {
                if (fib[p] > N) break;
            }
            p--;
            printd("remained N: %d / fib[%d]: %d", N, p, fib[p]);
            N -= fib[p];
            s.push(fib[p]);
        }
        if (isDebug) { printf("[DEBUG] "); s.print(); printf("\n"); }
        while (s.size > 0) {
            printf("%d ", s.pop());
        }
        printf("\n");
    }
MAIN_END

// 그리디 문제임. 무조건 현재 수보다 작은 fib 수를 한개 포함하는 조합을 찾을 수 있음.
// -> DFS로 접근하면 시간초과 남.. 찾다가 지침..
/* fib 구하기..
    int p = 2;
    int pprev = 0, prev = 1, cur = 1;
    while (p < 1000) {
        pprev = prev;
        prev = cur;
        cur = pprev + prev;
        fib[p++] = cur;
    }
    for (int i = 0; i < 1000; i++) {
        printf("%d, ", fib[i]);
    }
*/

/*
피보나치 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	2346	1279	1041	54.106%
문제
피보나치 수 ƒK는 ƒK = ƒK-1 + ƒK-2로 정의되며 초기값은 ƒ0 = 0과 ƒ1 = 1 이다. 양의 정수는 하나 혹은 그 이상의 서로 다른 피보나치 수들의 합으로 나타낼 수 있다는 사실은 잘 알려져 있다. 

하나의 양의 정수에 대한 피보나치 수들의 합은 여러 가지 형태가 있다. 예를 들어 정수 100은 ƒ4 + ƒ6 + ƒ11 = 3 + 8 + 89 또는 ƒ1 + ƒ3 + ƒ6 + ƒ11 = 1 + 2 + 8 + 89, 또는 ƒ4 + ƒ6 + ƒ9 + ƒ10 = 3 + 8 + 34 + 55 등으로 나타낼 수 있다. 이 문제는 하나의 양의 정수를 최소 개수의 서로 다른 피보나치 수들의 합으로 나타내는 것이다. 

하나의 양의 정수가 주어질 때, 피보나치 수들의 합이 주어진 정수와 같게 되는 최소 개수의 서로 다른 피보나치 수들을 구하라. 

입력
입력 데이터는 표준입력을 사용한다. 입력은 T 개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 테스트 데이터의 수를 나타내는 정수 T 가 주어진다. 각 테스트 데이터에는 하나의 정수 n이 주어진다. 단, 1 ≤ n ≤ 1,000,000,000. 

출력
출력은 표준출력을 사용한다. 하나의 테스트 데이터에 대한 해를 하나의 줄에 출력한다. 각 테스트 데이터에 대해, 피보나치 수들의 합이 주어진 정수에 대해 같게 되는 최소수의 피보나치 수들을 증가하는 순서로 출력한다. 

예제 입력 1 
4
100
200
12345
1003
예제 출력 1 
3 8 89
1 55 144
1 34 377 987 10946
3 13 987
*/
