#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

typedef unsigned long long ull;

int A[1'000'000];
int T[1'000'000];
int N;
ull ans = 0;

void merge(int start, int end) {
    int mid = (start + end) >> 1;
    int p1 = start;
    int p2 = mid + 1;
    int rp = start;

    while (p1 <= mid && p2 <= end) {
        int val1 = A[p1];
        int val2 = A[p2];

        if (val1 <= val2) {
            T[rp++] = val1;
            p1++;
        } else {
            T[rp++] = val2;
            p2++;
            ans += mid - p1 + 1; // swap 케이스 수 (inversion)
        }
    }

    // 어느 한 쪽이 끝났을 때
    while (p1 <= mid) {
        T[rp++] = A[p1++];
    }
    while (p2 <= end) {
        T[rp++] = A[p2++];
    }

    for (R int i = start; i <= end; i++) {
        A[i] = T[i];
    }
}

// 집합범위: [start, end]
void mergeSort(int start, int end) {
    if (start >= end) return;
    int mid = (start + end) >> 1;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, end);
}

int main() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%d", &A[i]);
    }
    // 정렬 과정 중에, 수가 뒤집혀야하는 숫자를 저장한다.
    // bubble sort는 최종정렬까지 숫자 뒤집히는 수의 총 합이다.
    mergeSort(0,N-1); // O(n log n)

    FOR(i,0,N) {
        _D("%d ", A[i]);
    }
    _D("\n");

    printf("%llu\n", ans);
}

// SegTree로도 풀수있긴 함
/*
문제
N개의 수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 이 수열에 대해서 버블 소트를 수행할 때, Swap이 총 몇 번 발생하는지 알아내는 프로그램을 작성하시오.

버블 소트는 서로 인접해 있는 두 수를 바꿔가며 정렬하는 방법이다. 예를 들어 수열이 3 2 1 이었다고 하자. 이 경우에는 인접해 있는 3, 2가 바뀌어야 하므로 2 3 1 이 된다. 다음으로는 3, 1이 바뀌어야 하므로 2 1 3 이 된다. 다음에는 2, 1이 바뀌어야 하므로 1 2 3 이 된다. 그러면 더 이상 바꿔야 할 경우가 없으므로 정렬이 완료된다.

입력
첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다. 다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다. 각각의 A[i]는 0 ≤ |A[i]| ≤ 1,000,000,000의 범위에 들어있다.

출력
첫째 줄에 Swap 횟수를 출력한다
*/
