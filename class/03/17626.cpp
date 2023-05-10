#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        char fname[100];
        char ftailname[11] = "_input.txt";
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
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int sum = 0;
int N;
int minCount = 0x7FFFFFFF;

int DFS(int depth, int from) {
    if (sum == N) {
        return depth;
    }
    // 네 수의 제곱 합이 아닌 경우는 return
    if (depth == 4) {
        return -1;
    }
    for (int i = from; i * i >= 1; i--) {
        if (sum + i * i > N) continue;
        sum += i * i;
        int r = DFS(depth + 1, i);
        if (r != -1 && r < minCount) {
            minCount = r;
            printd("min count updated: r", r);
        }
        sum -= i * i;
    }
    return -1;
}

void DFSStart() {
    for (int i = 225; i * i >= 1; i--) {
        if (sum + i * i > N) continue;
        sum += i * i;
        int r = DFS(1, i);
        if (r != -1 && r < minCount) {
            minCount = r;
            printd("min count updated: r", r);
        }
        sum -= i * i;
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    scanf("%d", &N);
    printd("N: %d", N);
    printd("--------------------------");
    sum = 0;
    minCount = 0x7FFFFFFF;
    DFSStart();
    printf("%d\n", minCount);
MAIN_END

/*
집합 실패분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1.5 초	4 MB (하단 참고)	29837	9173	6414	30.158%
문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 
입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.
*/
