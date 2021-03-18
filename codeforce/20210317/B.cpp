#include <stdio.h>
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define INF 0x7FFFFFFF
void SWAP(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (true) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i > j) break;
        SWAP(arr[i], arr[j]);
        i++; j--;
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}
int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; tc++) {
        int N, M;
        scanf("%d %d", &N, &M);
        int A[100000] = {0, };
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        quickSort(A, 0, N - 1);
        int count = 0; // group count
        
        for (int i = 0; i < N; i++) {
            if (A[i] == INF) continue;
            int firstNum = A[i];
            int lastNum = A[i];
            for (int j = i + 1; j < N; j++) {
                if (A[j] == INF) continue;
                if ((lastNum + A[j]) % M == 0) {
                    lastNum = A[j];
                    A[j] = INF;
                    j = i + 1; // reset position
                } else if ((firstNum + A[j]) % M == 0) {
                    firstNum = A[j];
                    A[j] = INF;
                    j = i + 1; // reset position
                }
            }
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
