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
template<class T>
void SWAP(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// right가 Size가 아님에 주의. 마지막 실제 존재하는 원소를 가리킬 수 있어야 함.
// 즉, quickSort(arr, 0, size - 1); -> arr[0] 와 arr[size - 1] 둘 다 유효해야함.
template<class T>
void quickSort(T arr[], int left, int right) {
    int i = left;
    int j = right;
    T pivot = arr[(left + right) / 2];

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

int data[1500 * 1500];
int N;
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d", &N);

    for (int i = 0; i < N * N; i++) {
        int tmp;
        scanf("%d", &tmp);
        data[i] = tmp;
    }

    quickSort(data, 0, N * N - 1);
    // for (int i = 0; i < N * N; i++) {
    //     printf("%d ", data[i]);     
    // }
    // printf("\n");
    printf("%d\n", data[N * N - N]);
MAIN_END

/*
N번째 큰 수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	12 MB (하단 참고)	7165	2902	1945	40.759%
문제
N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다. N=5일 때의 예를 보자.

12	7	9	15	5
13	8	11	19	6
21	10	26	31	16
48	14	28	35	25
52	20	32	41	49
이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오. 표에 채워진 수는 모두 다르다.

입력
첫째 줄에 N(1 ≤ N ≤ 1,500)이 주어진다. 다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다. 표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수이다.

출력
첫째 줄에 N번째 큰 수를 출력한다.

예제 입력 1 
5
12 7 9 15 5
13 8 11 19 6
21 10 26 31 16
48 14 28 35 25
52 20 32 41 49
예제 출력 1 
35
*/
