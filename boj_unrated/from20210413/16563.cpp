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

template<class T>
class DArray {
    T* n;
    int capacity;
    int mul;
public:
    int size;
    DArray() {
        n = NULL;
        mul = 1;
        init();
    }
    void init(int newCap = 4) {
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
        mul *= item;
    }
    T& pop() {
        mul /= n[size - 1];
        return n[--size];
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    int getMul() {
        return mul;
    }
    DArray<T>& operator= (DArray<T>& src) {
        this->init();
        for (int i = 0; i < src.size; i++) {
            this->push(src[i]);
        }
        return *this;
    }
    ~DArray() {
        if (n != NULL) {
            delete[] n;
        }
    }
};

int primesMap[5'000'001] = {-1, -1, 0, }; // -1: 소수 아님 / 1: 소수 / 0: 결정안됨
int primes[2'000'000] = {0, };
void eratos(int N) {
    int p = 0;
    for (register int i = 2; i <= N; i++) {
        if (primesMap[i] == 0) {
            primesMap[i] = 1; // 처음 도달하면, 소수
            primes[p++] = i;
        }
        if (primesMap[i] != 1) continue;
        for (register int j = i + i; j <= N; j += i) {
            if (primesMap[j] == 0) { // 아직 업뎃 전이면, 업뎃.
                primesMap[j] = -1; // 채에서 쳐내기~
            }
        }
    }
}

// 작은 합성수에 대한 메모
DArray<int> composites[1'000'000];

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    eratos(5'000'000);
    printd("Eratos completed!");
    int T;
    scanf("%d", &T);
    printd("TC Num: %d", T);
    for (register int tc = 0; tc < T; tc++) {
        register int N;
        scanf("%d", &N);
        printd("N: %d", N);
        int leastCheck = 2;
        int primePtr = 0;
        DArray<int> s; // 메모를 위한 스택
        while(N > 1) {
            if (primesMap[N] == 1) {
                printf("%d ", N);
                break;
            // 남은 수가 메모 된 경우임
            } else if (N < 1'000'000 && composites[N].size != 0) {
                for (int i = 0; i < composites[N].size; i++) {
                    printf("%d ", composites[N][i]);
                }
                // printd("Answer can confirmed by memo! N: %d", N);
                break;
            } else {
                // 현재 조합 메모
                if (N % leastCheck == 0) {
                    s.push(leastCheck);
                    if (s.size > 2 && s.getMul() < 1'000'000) {
                        if (composites[s.getMul()].size == 0) {
                            composites[s.getMul()] = s;
                        }
                    }
                    printf("%d ", leastCheck);
                    N /= leastCheck;
                } else {
                    leastCheck = primes[primePtr++];
                }
            }
        }
        printf("\n");
    }
MAIN_END


/*
어려운 소인수분해 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	1945	537	318	24.537%
문제
지원이는 대회에 출제할 문제에 대해서 고민하다가 소인수분해 문제를 출제해야겠다고 마음을 먹었다. 그러나 그 이야기를 들은 동생의 반응은 지원이의 기분을 상하게 했다.

"소인수분해? 그거 너무 쉬운 거 아니야?"

지원이는 소인수분해의 어려움을 알려주고자 엄청난 자신감을 가진 동생에게 2와 500만 사이의 자연수 N개를 주고 소인수분해를 시켰다. 그러자 지원이의 동생은 기겁하며 쓰러졌다. 힘들어하는 지원이의 동생을 대신해서 여러분이 이것도 쉽다는 것을 보여주자!

입력
첫째 줄에는 자연수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 자연수 ki (2 ≤ ki ≤ 5,000,000, 1 ≤ i ≤ N)가 N개 주어진다.

출력
N줄에 걸쳐서 자연수 ki의 소인수들을 오름차순으로 출력하라.

예제 입력 1 
5
5 4 45 64 54
예제 출력 1 
5
2 2
3 3 5
2 2 2 2 2 2
2 3 3 3
*/
