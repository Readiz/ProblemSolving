#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;

void SWAP(ull& a, ull& b) {
    ull tmp = a;
    a = b;
    b = tmp;
}
void quickSort(ull arr[], int left, int right) {
    int i = left;
    int j = right;
    ull pivot = arr[(left + right) / 2];

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
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int N;
    scanf("%d", &N);
    ull arr[2000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, N - 1);

    ull minD = 0xFFFFFFFFFFFFFFFF;
    // 시작 포인터를 설정하고, 좌 우 로 훑는 녀석과, 우 좌로 훑는 녀석을 생각한다..
    for (int startP = 0; startP < N; startP++) {
        ull overallDLeft = 0ULL, overallDRight = 0ULL;

        // 시작 좌측으로 출발하는 녀석
        ull curMin = arr[startP];
        ull curMax = arr[startP];
        for (int p = startP; p >= 0; p--) {
            curMin = arr[p]; // 업데이트
            overallDLeft += curMax - curMin;
        }
        // 리셋하여 다시 출발~
        curMin = arr[startP];
        curMax = arr[startP];
        // 시작 우측으로 출발하는 녀석
        for (int p = startP; p < N; p++) {
            curMax = arr[p]; // 업데이트
            overallDRight += curMax - curMin;
        }
        ull numOfLeft = startP;
        ull numOfRight = N - startP - 1;

        // i) 좌측 갔다가 우측 가는 녀석의 총 합
        ull overallDCase1 = overallDLeft + overallDRight + (arr[startP] - arr[0]) * numOfRight;
        // ii) 우측 갔다가 좌측 가는 녀석의 총 합
        ull overallDCase2 = overallDRight + overallDLeft + (arr[N - 1] - arr[startP]) * numOfLeft;

        if (overallDCase1 < overallDCase2) {
            if (minD > overallDCase1) {
                minD = overallDCase1;
                printd("startP: %d, min is updated to %llu", startP, minD);
            }
        } else {
            if (minD > overallDCase2) {
                minD = overallDCase2;
                printd("startP: %d, min is updated to %llu", startP, minD);
            }
        }
    }
    printf("%llu\n", minD);
MAIN_END
