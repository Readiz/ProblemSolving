#include <stdio.h>

#define printd(...) // printf(__VA_ARGS__)
#define MAX_INT 0x7FFFFFFF
#define R register
#define parent(n) (n>>1)
#define left(n) (n<<1)
#define right(n) ((n<<1)|1)
#define MAX_SIZE 200002
class MinHeap {
    int value[MAX_SIZE];
    int oriIdx[MAX_SIZE];
    int newIdx[MAX_SIZE];
    int lastptr;
public:
    MinHeap() {
        // 1부터 시작하는게 여러모로 편하다.
        lastptr = 1;
        for (R int i = 0; i < MAX_SIZE; i++) {
            value[i] = MAX_INT;
        }
    }
    void push(int originalIndex, int value) {
        int p = lastptr;
        this->value[p] = value;
        oriIdx[p] = originalIndex;
        newIdx[originalIndex] = p;

        printd("[add] oriIdx: %d, val: %d\n", originalIndex, value);

        checkUp(lastptr++);
    }
    int pop() {
        int p = 1;
        int r = value[p];
        value[p] = MAX_INT;
        swap(p, lastptr--);
        checkDown(p);
        return r;
    }
    int topOriginalIdx() {
        return oriIdx[1];
    }
    void updateValueAtOriginalIdx(int originalIdx, int value) {
        printd("[update] %d, newIdx: %d, value: %d->%d\n", originalIdx, newIdx[originalIdx], this->value[newIdx[originalIdx]], value);
        this->value[newIdx[originalIdx]] = value;
        checkUp(newIdx[originalIdx]);
        checkDown(newIdx[originalIdx]);
    }
    void checkUp(int idx) {
        while (idx > 1) {
            if (value[parent(idx)] > value[idx]) {
                swap(parent(idx), idx);
                idx = parent(idx);
            } else if (value[parent(idx)] == value[idx]) {
                if (oriIdx[parent(idx)] > oriIdx[idx]) {
                    swap(parent(idx), idx);
                    idx = parent(idx);
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    void checkDown(int idx) {
        while (idx < lastptr) {
            if (value[left(idx)] > value[right(idx)]) {
                if (value[right(idx)] == value[idx]) {
                    if (oriIdx[right(idx)] < oriIdx[idx]) {
                        swap(right(idx), idx);
                        idx = right(idx);
                    } else {
                        break;
                    }
                } else {
                    if (value[idx] > value[right(idx)]) {
                        swap(right(idx), idx);
                        idx = right(idx);
                    } else {
                        break;
                    }
                }
            } else if (value[left(idx)] < value[right(idx)]) {
                if (value[left(idx)] == value[idx]) {
                    if (oriIdx[left(idx)] < oriIdx[idx]) {
                        swap(left(idx), idx);
                        idx = left(idx);
                    } else {
                        break;
                    }
                } else {
                    if (value[idx] > value[left(idx)]) {
                        swap(left(idx), idx);
                        idx = left(idx);
                    } else {
                        break;
                    }
                }
            } else { // left == right 일때
                if (value[left(idx)] > value[idx]) break;
                if (value[left(idx)] == value[idx]) {
                    if (oriIdx[left(idx)] > oriIdx[idx] && oriIdx[right(idx)] > oriIdx[idx]) break;
                    else if (oriIdx[left(idx)] < oriIdx[right(idx)]) {
                        swap(left(idx), idx);
                        idx = left(idx);
                    } else {
                        swap(right(idx), idx);
                        idx = right(idx);
                    }
                } else {
                    if (oriIdx[left(idx)] < oriIdx[right(idx)]) {
                        swap(left(idx), idx);
                        idx = left(idx);
                    } else {
                        swap(right(idx), idx);
                        idx = right(idx);
                    }
                }
            }
        }
    }
    void swap(int idx1, int idx2) {
        int tmpValue = value[idx1];
        int tmpOriIdx = oriIdx[idx1];

        value[idx1] = value[idx2];
        oriIdx[idx1] = oriIdx[idx2];

        value[idx2] = tmpValue;
        oriIdx[idx2] = tmpOriIdx;

        newIdx[oriIdx[idx1]] = idx1;
        newIdx[oriIdx[idx2]] = idx2;
    }
    void print() {
        printd("[HEAP] ");
        for (R int i = 1; i < lastptr; i++) {
            printd("%2d ", value[i]);
        }
        printd("\n");
        printd("[ORII] ");
        for (R int i = 1; i < lastptr; i++) {
            printd("%2d ", oriIdx[i]);
        }
        printd("\n");
        printd("[NEWI] ");
        for (R int i = 1; i < lastptr; i++) {
            printd("%2d ", newIdx[i]);
        }
        printd("\n");
    }
};

MinHeap h;

int main() {
    int N;
    scanf("%d", &N);
    for (R int i = 1; i <= N; i++) {
        int val;
        scanf("%d", &val);
        h.push(i, val);
    }
    h.print();
    int M;
    scanf("%d", &M);
    for (R int i = 0; i < M; i++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int a, b;
            scanf("%d %d", &a, &b);
            h.updateValueAtOriginalIdx(a, b);
            h.print();
        } else {
            printf("%d\n", h.topOriginalIdx());
        }
    }
    // for (R int i = 1; i <= N; i++) {
    //     printf("%d ", h.pop());
    // }
}

/*
수열과 쿼리 15
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초 (하단 참고)	512 MB	2648	1330	979	56.492%
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

1 i v : Ai를 v로 바꾼다. (1 ≤ i ≤ N, 1 ≤ v ≤ 10^9)
2 : 수열에서 크기가 가장 작은 값의 인덱스를 출력한다. 그러한 값이 여러개인 경우에는 인덱스가 작은 것을 출력한다.
수열의 인덱스는 1부터 시작한다.

입력
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 10^9)

셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)

넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

출력
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.

예제 입력 1 
5
5 4 3 2 1
5
2
1 5 3
2
1 4 3
2
예제 출력 1 
5
4
3
*/
