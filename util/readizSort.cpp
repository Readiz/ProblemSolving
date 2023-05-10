#include <stdio.h>
#include <time.h>

int seed = 5;
short pseudo_rand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int MAX_NUM;
#define MAX_VAL 1000000
#define ROOT_MAX_VAL 1000
#define R register

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int A[1'000'000];
int T[1'000'000];

void merge(int start, int mid, int end) {
    int p1 = start;
    int p2 = mid;
    int rp = start;

    while (p1 < mid && p2 < end) {
        int val1 = A[p1];
        int val2 = A[p2];

        if (val1 < val2) {
            T[rp++] = val1;
            p1++;
        } else {
            T[rp++] = val2;
            p2++;
        }
    }

    // 어느 한 쪽이 끝났을 때
    while (p1 < mid) {
        T[rp++] = A[p1++];
    }
    while (p2 < end) {
        T[rp++] = A[p2++];
    }

    for (R int i = start; i < end; i++) {
        A[i] = T[i];
    }
}

// 집합범위: [start, end)
void mergeSort(int start, int end) {
    if (end - start <= 1) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    merge(start, mid, end);
}

// 집합범위: [start, end]
void quickSort(int start, int end) {
    if (end <= start) return;
    // printf("Q: %d ~ %d\n", start, end);

    int i = start;
    int j = end; // 실제 원소를 가르켜야함
    int pivot = A[(i + j) / 2];

    while (true) {
        // 이미 조건을 만족하는 놈들은 건너 뛴다
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;
        if (i > j) break; // 양쪽 포인터가 엇갈리면 종료
        
        // XOR Bitwise SWAP은 서로 같으면 안됨
        if (A[i] != A[j]) A[i] ^= A[j] ^= A[i] ^= A[j];
        i++; j--; // 다음 항 강제로 찾으러 떠남
    }
    
    // 다음 조건 설정을 눈여겨 보자.
    quickSort(start, j); // 이미 엇갈린 상태이므로, j 까지로 설정하고 정렬하면 됨
    quickSort(i, end); // 마찬가지로 이미 엇갈린 상태이므로, i부터 설정하면 됨
}

#define parent(x) (x >> 1)
#define lchild(x) (x << 1)
#define rchild(x) ((x << 1) | 1)
#define INT_MAX 0x7FFFFFFF
class Heap {
public:
    int d[1'000'000 * 2];
    int s;
    Heap(int size) {
        for (R int i = 0; i < size * 2; i++) {
            d[i] = INT_MAX;
        }
        s = 1; // 다음에 삽입될 위치
    }
    void push(int data) {
        int p = s;
        d[s++] = data;
        while(p > 1) {
            int pp = parent(p);
            if (d[p] < d[pp]) {
                d[p] ^= d[pp] ^= d[p] ^= d[pp];
                p = pp;
            } else {
                break;
            }
        }
    }
    int pop() {
        int r = d[1];
        d[1] = INT_MAX;
        s--;
        d[1] ^= d[s] ^= d[1] ^= d[s];

        int p = 1;
        while (p <= s) {
            int lp = lchild(p);
            int rp = rchild(p);
            if (d[p] <= d[lp] && d[p] <= d[rp]) break;
            else {
                if (d[lp] <= d[rp]) {
                    d[p] ^= d[lp] ^= d[p] ^= d[lp];
                    p = lp;
                } else {
                    d[p] ^= d[rp] ^= d[p] ^= d[rp];
                    p = rp;
                }
            }
        }
        return r;
    }
};

// 집합범위: [start, end)
void heapSort(int start, int end) {
    Heap h(end - start);
    for (R int i = start; i < end; i++) {
        h.push(A[i]);
    }
    for (R int i = start; i < end; i++) {
        A[i] = h.pop();
    }
}

// 집합범위: [start, end)
void countSort(int start, int end) {
    int C[MAX_VAL + 1] = {0, };
    for (R int i = start; i < end; i++) {
        C[A[i]]++;
    }
    int tp = 0;
    for (R int i = 0; i <= MAX_VAL; i++) {
        int rep = C[i];
        for (R int j = 0; j < rep; j++) {
            T[tp++] = i;
        }
    }
    for (R int i = 0; i < tp; i++) {
        A[start++] = T[i];
    }
}

// 집합범위: [start, end)
// 2-order bucket sort (바구니 2개만 사용)
// -> 이론상 count sort의 2배 시간 소요 + alpha (오버헤드)
void bucketSort(int start, int end) {
    // 추가 메모리 소모: sqrt(MAX_VAL) 만큼: Count 배열로 bucket n 배의 메모리 낭비를 줄일 수 있음
    int C_L[ROOT_MAX_VAL + 2] = {0, };
    int C_H[ROOT_MAX_VAL + 2] = {0, };

    for (R int i = start; i < end; i++) {
        int tmp = A[i];
        C_L[tmp % ROOT_MAX_VAL]++;
        C_H[tmp / ROOT_MAX_VAL]++;
    }

    // 카운트를 누적합으로 변경
    int acc = 0;
    for (R int i = 0; i <= ROOT_MAX_VAL; i++) {
        acc += C_L[i];
        C_L[i] = acc;
    }
    for (R int i = ROOT_MAX_VAL; i >= 0; i--) {
        C_L[i + 1] = C_L[i];
    }
    C_L[0] = 0;
    acc = 0;
    for (R int i = 0; i <= ROOT_MAX_VAL; i++) {
        acc += C_H[i];
        C_H[i] = acc;
    }
    for (R int i = ROOT_MAX_VAL; i >= 0; i--) {
        C_H[i + 1] = C_H[i];
    }
    C_H[0] = 0;

    // 낮은 자리부터 계산
    for (R int i = start; i < end; i++) {
        int tmp = A[i] % ROOT_MAX_VAL;
        T[C_L[tmp]++] = A[i];
    }
    int bp = 0;
    for (R int i = start; i < end; i++) {
        int tmp = T[bp] / ROOT_MAX_VAL;
        A[start + (C_H[tmp]++)] = T[bp++];
    }
}


// 집합범위: [start, end)
void bubbleSort(int start, int end) {
    for (R int i = 0; i < end; i++) {
        for (R int j = i + 1; j < end; j++) {
            if (A[i] > A[j]) {
                // simple swap
                A[i] ^= A[j] ^= A[i] ^= A[j];
            }
        }
    }
}

// 집합범위: [start, end)
void insertSort(int start, int end) {
    for (R int i = 1; i < end; i++) {
        R int j = i;
        int cur = A[j]; // 현재 위치에 놈을 적절한 곳이 나올때까지 끌고가서
        while (--j >= 0 && cur < A[j]) {
            A[j + 1] = A[j]; // [참고] memory locality가 높아져서 속도가 빠른 이유임
        }
        A[j + 1] = cur; // 삽입한다. (루프 나오면서 j가 하나 감소하니 1을 더한 위치에 넣는 것)
    }
}

void resetData() {
    // printf("[DATA]\n");
    seed = 5;
    for (R int i = 0; i < MAX_NUM; i++) {
        int tmp = (pseudo_rand() << 16 + pseudo_rand()) % MAX_VAL;
        A[i] = abs(tmp);
        // printf("%d\n", A[i]);
    }
}

bool checkValid() {
    int last = A[0];
    for (R int i = 1; i < MAX_NUM; i++) {
        if (last > A[i]) {
            return false;
        }
        last = A[i];
    }
    return true;
}

int main() {
    printf("----- Readiz's Sort World! -----\n");
    clock_t st, et;

    MAX_NUM = 1'000'000;
    printf("\n----- nlogn Algorithms (N: %d) -----\n", MAX_NUM);

    resetData();
    st = clock();
    mergeSort(0, MAX_NUM);
    et = clock();
    if (checkValid()) {
        printf("MergeSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[50000], A[100000], A[400000], A[999999]);
    } else {
        printf("Validation failed!\n");
    }

    resetData();
    st = clock();
    quickSort(0, MAX_NUM - 1);
    et = clock();
    if (checkValid()) {
        printf("QuickSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[50000], A[100000], A[400000], A[999999]);
    } else {
        printf("Validation failed!\n");
    }

    resetData();
    st = clock();
    heapSort(0, MAX_NUM);
    et = clock();
    if (checkValid()) {
        printf("HeapSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[50000], A[100000], A[400000], A[999999]);
    } else {
        printf("Validation failed!\n");
    }

    printf("\n----- n + k Algorithms (N: %d, k: %d) -----\n", MAX_NUM, MAX_VAL);
    resetData();
    st = clock();
    countSort(0, MAX_NUM);
    et = clock();
    if (checkValid()) {
        printf("CountSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[50000], A[100000], A[400000], A[999999]);
    } else {
        printf("Validation failed!\n");
    }

    // BucketSort (Order: 2)
    resetData();
    st = clock();
    bucketSort(0, MAX_NUM);
    et = clock();
    if (checkValid()) {
        printf("BucketSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[50000], A[100000], A[400000], A[999999]);
    } else {
        printf("Validation failed!\n");
    }

    MAX_NUM = 100'000;
    printf("\n----- n^1.5 Algorithms (N: %d) -----\n", MAX_NUM);
    // [TODO] shell sort: root 사용하는 대표적인 알고리즘.. out-order.

    MAX_NUM = 100'000;
    printf("\n----- n^2 Algorithms (N: %d) -----\n", MAX_NUM);

    resetData();
    st = clock();
    insertSort(0, MAX_NUM);
    et = clock();
    if (checkValid()) {
        printf("InsertSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[10000], A[20000], A[30000], A[99999]);
    } else {
        printf("Validation failed!\n");
    }

    resetData();
    st = clock();
    bubbleSort(0, MAX_NUM);
    et = clock();
    if (checkValid()) {
        printf("BubbleSort: %d ms\n", (int)(et - st) * 1000 / (int)CLOCKS_PER_SEC);
        printf("%d %d %d %d %d...\n", A[0], A[10000], A[20000], A[30000], A[99999]);
    } else {
        printf("Validation failed!\n");
    }
    

    return 0;
}
