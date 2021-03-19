#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int N, M;
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
// 오름차순 정렬된 배열에서 특정 수 찾기..
int find(int arr[], int start, int end, int num) {
    int mid = (start + end) / 2;
    if (arr[mid] == num) {
        return mid;
    } else if (arr[mid] > num) {
        if (mid == end) return -1;
        return find(arr, start, mid, num);
    } else {
        if (mid == start) return -1;
        return find(arr, mid, end, num);
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d %d", &N ,&M);
    printd("N: %d, M: %d", N, M);
    printd("--------------------------");
    int A[1000000] = {0, };
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        A[i] = tmp;
    }
    quickSort(A, 0, N - 1);
    // printd("%d", find(A, 0, N, 15));
    // printd("%d", find(A, 0, N, 17));
    // printd("%d", find(A, 0, N, 10));
    // printd("%d", find(A, 0, N, 20));
    // printd("%d", find(A, 0, N, 16));
    // printd("%d", find(A, 0, N, -1));
    // printd("%d", find(A, 0, N, 100));
    // return 0;

    int h = A[N - 1];
    int pos = find(A, 0, N, h);
    int affected = N - pos;
    int sum = 0;
    printd("h: %d, affected: %d, sum: %d", h, affected, sum);
    while(true) {
        if (sum >= M) break;
        h--;
        int newPos = find(A, 0, N, h);
        if (newPos != -1) {
            affected = N - newPos;
            pos = newPos;
        }
        sum += affected;
        printd("h: %d, affected: %d, sum: %d", h, affected, sum);
    }
    printf("%d\n", h);
MAIN_END


/*
나무 자르기 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	62574	17933	11271	25.947%
문제
상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.

목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다) 절단기에 설정할 수 있는 높이는 양의 정수 또는 0이다.

상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M보다 크거나 같기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

출력
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

예제 입력 1 
4 7
20 15 10 17
예제 출력 1 
15
*/
