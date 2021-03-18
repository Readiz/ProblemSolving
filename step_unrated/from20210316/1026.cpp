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
int N;
int A[50] = {0, };
int B[50] = {0, };

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void sort(int arr[]) {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void inverse(int arr[]) {
    for (int i = 0; i < N / 2; i++) {
        swap(arr[i], arr[N - i - 1]);
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d", &N);
    printd("Input - N: %d", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }
    printd("--------------------------");

    sort(A);
    sort(B);
    inverse(B);

    int S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i] * B[i];
    }
    printf("%d\n", S);
MAIN_END


/*
보물 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	24322	14377	12333	62.506%
문제
옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.

길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

S = A[0]×B[0] + ... + A[N-1]×B[N-1]

S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.

S의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 A에 있는 N개의 수가 순서대로 주어지고, 셋째 줄에는 B에 있는 수가 순서대로 주어진다. N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수이다.

출력
첫째 줄에 S의 최솟값을 출력한다.

예제 입력 1 
5
1 1 1 6 0
2 7 8 3 1
예제 출력 1 
18
*/

