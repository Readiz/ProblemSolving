#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define MAX_HEAP_SIZE 300
#define INT_MAX 0x7FFFFFFF
typedef unsigned long long ull;
typedef long long ll;

struct Node {
    int pos;
    int val;
};

template <class T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

class MinHeap {
    Node db[MAX_HEAP_SIZE] = {0, }; // 넉넉하게 생성..
    int size = 0;
public:
    MinHeap() {
        for (int i = 0; i < MAX_HEAP_SIZE; i++) {
            db[i].val = INT_MAX;
        }
    }
    void reset() {
        size = 0;
        for (int i = 0; i < MAX_HEAP_SIZE; i++) {
            db[i].val = INT_MAX;
        }
    }
    void push(Node num) {
        int idx = size;
        db[idx] = num;
        size++;
        update(idx);
    }

    Node pop() {
        Node result = db[0];
        db[0] = db[size - 1];
        db[size - 1].val = INT_MAX; // 더미 값 추가
        size--;

        downdate(0);

        return result;
    }

    Node top() {
        return db[0];
    }

    void update(int idx) {
        int p = (idx - 1) / 2; // Parent
        while (idx > 0) {
            if (db[p].val > db[idx].val) {
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
            if (db[idx].val > db[lChildIdx].val || db[idx].val > db[rChildIdx].val) {
                if (db[lChildIdx].val < db[rChildIdx].val) {
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
    void reset() {
        mHeap.reset();
    }
    void push(Node num) {
        Node inverse = num;
        inverse.val *= -1;
        mHeap.push(inverse);
    }
    Node pop() {
        Node r = mHeap.pop();
        r.val *= -1;
        return r;
    }
    Node top() {
        Node r = mHeap.top();
        r.val *= -1;
        return r;
    }
    int getSize() {
        return mHeap.getSize();
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        int n, m;
        scanf("%d %d", &n, &m); // n: 체크포인트 수, m: 경우의 수
        int l[100][100] = {0, };
        int max[100] = {0, }; // 각 열의 max 값
        int min[100] = {0, }; // 각 열의 min 값
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &l[i][j]);
            }
        }
        MinHeap minHeap;
        // 초기값 세팅
        for (int i = 0; i < m; i++) {
            Node a = {i, l[0][i]};
            minHeap.push(a); // 최소값부터 나오도록 넣어둔다..
            printf("%d ", l[0][i]); // 첫줄은 그냥 출력 - 나머지를 여기에 맞춘다.
        }
        printf("\n");
        for (int i = 1; i < n; i++) {
            MaxHeap maxHeap;
            for (int j = 0; j < m; j++) {
                Node a = {j, l[i][j]};
                maxHeap.push(a);
            }
            int tmpCur[100]; // Heap에 넣었다 뺐다 하기 위한 임시 저장장소..
            int tmpCompare[100];
            for (int j = 0; j < m; j++) {
                Node cur, compare; // cur 현재 위치의 최소값, compare: 업데이트 가능성 있는 값
                cur = minHeap.pop();
                tmpCur[cur.pos] = cur.val;
                compare = maxHeap.pop();
                tmpCompare[cur.pos] = compare.val; // 현재 최소인 위치에 최대값을 덮어쓴다.
                if (cur.val > compare.val) { // 업데이트
                    tmpCur[cur.pos] = compare.val;
                }
            }
            minHeap.reset();
            for (int j = 0; j < m; j++) {
                Node a = {j, tmpCur[j]};
                minHeap.push(a); // 최소값부터 나오도록 넣어둔다..
            }
            // 재 조정된 위치로 출력
            for (int j = 0; j < m; j++) {
                printf("%d ", tmpCompare[j]);
            }
            printf("\n");
        }
    }
MAIN_END
