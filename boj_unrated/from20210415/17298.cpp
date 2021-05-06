#include <stdio.h>
#include <stack>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
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
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int A[1'000'000] = {0, };
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int N;
    scanf("%d", &N);
    printd("N: %d", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    stack<int> min; // 자료구조 사용 연습..
    stack<int> ans;
    min.push(-1);
    for (int i = N - 1; i >= 0; i--) {
        int a = A[i];
        printd("checking A[%d] = %d...", i, a);
        if (min.size() > 0 && a < min.top()) { // 현재 min 보다 작은 경우, top이 답임
            ans.push(min.top());
            min.push(a);
        } else if (min.size() == 0) {
            // 더이상 각 볼게 없으면, 포기하고 -1을 삽입한다.
            ans.push(-1);
            min.push(a);
        } else {
            // 그 다음 각을 본다.
            if (min.size() > 0) {
                min.pop();
                i++;
            }
        }
    }
    // while (s.size() > 0) {
    //     printf("%d / idx: %d\n", s.top().first, s.top().second);
    //     s.pop();
    // }
    while (ans.size() > 0) {
        printf("%d ", ans.top());
        ans.pop();
    }
    printf("\n");
MAIN_END


/*
오큰수 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	14454	4890	3610	34.131%
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.
*/
