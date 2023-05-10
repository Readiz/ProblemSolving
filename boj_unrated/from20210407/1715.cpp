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
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

#define INT_MAX 0x7FFFFFFF
#define MAX_HEAP_SIZE 200000
#define MAX(a, b) {(a > b) ? (a) : (b)}

typedef unsigned long long ull;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

class MinHeap {
    int db[MAX_HEAP_SIZE] = {0, }; // 넉넉하게 생성..
    int size = 0;
public:
    MinHeap() {
        for (int i = 0; i < MAX_HEAP_SIZE; i++) {
            db[i] = INT_MAX;
        }
    }
    void push(int num) {
        int idx = size;
        db[idx] = num;
        size++;
        update(idx);
    }

    int pop() {
        int result = db[0];
        db[0] = db[size - 1];
        db[size - 1] = INT_MAX; // 더미 값 추가
        size--;

        downdate(0);

        return result;
    }

    void update(int idx) {
        int p = (idx - 1) / 2; // Parent
        while (idx > 0) {
            if (db[p] > db[idx]) {
                swap(db[p], db[idx]);
            } else {
                break;
            }
            idx = p;
            p = (p - 1) / 2;
        }
    }

    void downdate(int idx) {
        while (idx < size) {
            int lChildIdx = (idx + 1) * 2 - 1;
            int rChildIdx = (idx + 1) * 2;
            // 부모가 더 크면, 더 작은 놈과 swap
            if (db[idx] > db[lChildIdx] || db[idx] > db[rChildIdx]) {
                if (db[lChildIdx] < db[rChildIdx]) {
                    swap(db[idx], db[lChildIdx]);
                    idx = lChildIdx;
                } else {
                    swap(db[idx], db[rChildIdx]);
                    idx = rChildIdx;
                }
            } else {
                break;
            }
        }

    }

    int getSize() {
        return size;
    }

    void print() {
        // for (int i = 0; i < 10; i++) {
        //     printf("%d ", db[i]);
        // }
        // printf("\n");
    }
};


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int N;
    scanf("%d", &N);
    printd("N: %d", N);

    MinHeap h;
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        h.push(tmp);
    }
    printd("Heap size: %d", h.getSize());

    ull sum = 0ULL;
    h.print();
    while (h.getSize() != 1) {
        int a = h.pop();
        int b = h.pop();
        int c = a + b;
        sum += (ull) c;
        printd("Add %d...", c);
        h.push(c);
        h.print();
    }

    printf("%llu\n", sum);
    
MAIN_END



/*
카드 정렬하기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	11747	4129	3330	36.314%
문제
정렬된 두 묶음의 숫자 카드가 있다고 하자. 각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는 A+B 번의 비교를 해야 한다. 이를테면, 20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.

매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면 (10 + 20) + (30 + 40) = 100번의 비교가 필요하다. 그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면 (10 + 40) + (50 + 20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.

N개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100,000) 이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다. 숫자 카드 묶음의 크기는 1,000보다 작거나 같은 양의 정수이다.

출력
첫째 줄에 최소 비교 횟수를 출력한다.

예제 입력 1 
3
10
20
40
예제 출력 1 
100
*/
