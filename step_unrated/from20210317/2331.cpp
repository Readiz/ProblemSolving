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

int calc(int num, int P) {
    int r = 0;
    while (num != 0) {
        int a = num % 10;
        int s = 1;
        for (int i = 0; i < P; i++) {
            s *= a;
        }
        r += s;
        num /= 10;
    }
    return r;
}

int search(int arr[], int k, int max) {
    for (int i = 0; i <= max; i++) {
        if (arr[i] == k) {
            return i;
        }
    }
    return 0;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int A, P;
    scanf("%d %d", &A, &P);
    printd("--------------------------");
    int arr[100000] = {0, };
    int p = 1;
    arr[0] = A;
    bool visited[400000] = {false, };
    visited[A] = true;
    for (p = 1; p < 100000; p++) {
        arr[p] = calc(arr[p - 1], P);
        if (visited[arr[p]]) break; // 반복되는 숫자 찾았으면 return
        visited[arr[p]] = true;
    }
    printd("Found!! %d @ %d", arr[p], p);
    int tIdx = search(arr, arr[p], p);
    for (int i = 0; i < tIdx; i++) {
        printd("%d ", arr[i]);
    }
    printf("%d\n", tIdx);
    return 0;
MAIN_END

/*
반복수열 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	9181	4118	3020	44.004%
문제
다음과 같이 정의된 수열이 있다.

D[1] = A
D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합
예를 들어 A=57, P=2일 때, 수열 D는 {57, 74(=5^2+7^2=25+49), 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, …}이 된다. 그 뒤에는 앞서 나온 수들(57부터가 아니라 58부터)이 반복된다.

이와 같은 수열을 계속 구하다 보면 언젠가 이와 같은 반복수열이 된다. 이때, 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 구하는 프로그램을 작성하시오. 위의 예에서는 {57, 74, 65, 61}의 네 개의 수가 남게 된다.

입력
첫째 줄에 A(1 ≤ A ≤ 9999), P(1 ≤ P ≤ 5)가 주어진다.

출력
첫째 줄에 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 출력한다.

예제 입력 1 
57 2
예제 출력 1 
4
*/
