// 동점처리를 자리수로 하는 버전

#include <stdio.h>

#define printd(...) // printf(__VA_ARGS__)
#define MAX_INT 0x7FFFFFFF
#define MAX_LONG 0x7FFFFFFFFFFFFFFF
#define R register
#define parent(n) (n>>1)
#define left(n) (n<<1)
#define right(n) ((n<<1)|1)
#define MAX_SIZE 200002
typedef long long ll;
class MinHeap {
    ll value[MAX_SIZE];
    int oriIdx[MAX_SIZE];
    int newIdx[MAX_SIZE];
    int lastptr;
public:
    MinHeap() {
        // 1부터 시작하는게 여러모로 편하다.
        lastptr = 1;
        for (R int i = 0; i < MAX_SIZE; i++) {
            value[i] = MAX_LONG;
        }
    }
    void push(int originalIndex, int value) {
        int p = lastptr;
        // 이 부분이 핵심, 실제 값을 우선순위에 맞게 조작함
        this->value[p] = (ll)value * 100001 + originalIndex;
        oriIdx[p] = originalIndex;
        newIdx[originalIndex] = p;
        checkUp(lastptr++);
    }
    int pop() {
        int p = 1;
        ll r = value[p];
        value[p] = MAX_LONG;
        swap(p, lastptr--);
        checkDown(p);
        return (r / 100001);
    }
    int topOriginalIdx() {
        return oriIdx[1];
    }
    void updateValueAtOriginalIdx(int originalIdx, int value) {
        this->value[newIdx[originalIdx]] = (ll)value * 100001 + originalIdx;
        checkUp(newIdx[originalIdx]);
        checkDown(newIdx[originalIdx]);
    }
    void checkUp(int idx) {
        while (idx > 1) {
            if (value[parent(idx)] > value[idx]) {
                swap(parent(idx), idx);
                idx = parent(idx);
            } else {
                break;
            }
        }
    }
    void checkDown(int idx) {
        while (idx < lastptr) {
            if (value[left(idx)] > value[idx] && value[right(idx)] > value[idx])
                break;
            if (value[left(idx)] > value[right(idx)]) {
                swap(right(idx), idx);
                idx = right(idx);
            } else {
                swap(left(idx), idx);
                idx = left(idx);
            }
        }
    }
    void swap(int idx1, int idx2) {
        ll tmpValue = value[idx1];
        int tmpOriIdx = oriIdx[idx1];

        value[idx1] = value[idx2];
        oriIdx[idx1] = oriIdx[idx2];

        value[idx2] = tmpValue;
        oriIdx[idx2] = tmpOriIdx;

        newIdx[oriIdx[idx1]] = idx1;
        newIdx[oriIdx[idx2]] = idx2;
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
    int M;
    scanf("%d", &M);
    for (R int i = 0; i < M; i++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int a, b;
            scanf("%d %d", &a, &b);
            h.updateValueAtOriginalIdx(a, b);
        } else {
            printf("%d\n", h.topOriginalIdx());
        }
    }
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
