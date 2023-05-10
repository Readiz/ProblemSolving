// 중앙 피벗 Quick Sort
// 가장 안정적인 O(nlogn) 정렬 알고리즘.
// 좌측 포인터(i), 우측 포인터(j) 를 도입해서,
// 중앙 Pivot 값보다 좌 / 
#include <stdio.h>
#define INF 987654321
#define MAX_HEAP_SIZE 10000

void SWAP(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// right가 Size가 아님에 주의. 마지막 실제 존재하는 원소를 가리킬 수 있어야 함.
// 즉, quickSort(arr, 0, size - 1); -> arr[0] 와 arr[size - 1] 둘 다 유효해야함.
void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (true) {
        while (arr[i] < pivot) i++; // 좌측포인터를 움직여서 pivot 보다 더 큰놈이 좌측에 있으면, 그 위에서 대기
        while (arr[j] > pivot) j--; // 우측포인터를 움직여서, pivot보다 더 작은놈이 우측에 있으면, 그 위에서 대기
        // i, j 포인터가 엇갈리면, break. 
        if (i > j) break;
        // 엇갈리기 전이면, SWAP을 반복한다.
        SWAP(arr[i], arr[j]);
        i++; j--; // 다음 swap 거리를 찾아보자
    }
    // 엇갈린 기준으로 break 하였으니(좌측은 j, 우측은 i), 엇갈린 기준으로 배열은 분할정복한다.
    if (left < j) quickSort(arr, left, j); // left < j 가 될 때만 quickSort를 반복해야함. (안그러면 무한 재귀 탐)
    if (i < right) quickSort(arr, i, right); // i < right 가 될 때만 quickSort를 반복해야함. (재귀 탈출 조건)
}
int pseudo_rand() {
    static int seed = 3;
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}
int main() {
    int data[1000];
    int dataSize = 40;
    for (int i = 0; i < dataSize; i++) {
        data[i] = pseudo_rand() % 100;
    }
    printf("Original Inputs: ");
    for (int i = 0; i < dataSize; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    quickSort(data, 0, dataSize - 1);
    printf("Sorted: ");
    for (int i = 0; i < dataSize; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
