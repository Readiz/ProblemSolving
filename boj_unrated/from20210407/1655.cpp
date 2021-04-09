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
#define INT_MIN 0x80000000
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

    int top() {
        return db[0];
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

class MaxHeap {
    MinHeap mHeap;
public:
    void push(int num) {
        mHeap.push(num * (-1));
    }
    int pop() {
        return (-1) * mHeap.pop();
    }
    int top() {
        return (-1) * mHeap.top();
    }
    int getSize() {
        return mHeap.getSize();
    }
};


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int N;
    scanf("%d", &N);
    printd("N: %d", N);

    MinHeap minHeap;
    MaxHeap maxHeap;
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        printd("PUSH: %d", tmp);

        // 균형을 맞추면서 넣어주고
        if (minHeap.getSize() >= maxHeap.getSize()) {
            maxHeap.push(tmp);
        } else {
            minHeap.push(tmp);
        }
        // maxHeap의 데이터가 더 작아지도록 swap한다.
        while(maxHeap.top() > minHeap.top()) {
            int a = maxHeap.pop();
            int b = minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        // maxHeap의 top이 가급적 작은 중간값.
        printf("%d\n", maxHeap.top());
    }
MAIN_END



/*
가운데를 말해요 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.1 초 (하단 참고)	128 MB	17099	4889	3798	31.897%
문제
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 수빈이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 그 다음 N줄에 걸쳐서 수빈이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력
한 줄에 하나씩 N줄에 걸쳐 수빈이의 동생이 말해야하는 수를 순서대로 출력한다.
*/
